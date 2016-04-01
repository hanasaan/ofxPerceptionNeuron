//
//  Created by Yuya Hanai, https://github.com/hanasaan/
//
#include "ofxPerceptionNeuron.h"

#define __OS_XUN__
#define NEURONDATAREADER_EXPORTS

#include "NeuronDataReader.h"
#include "ofxBvhMod.h"
#include "BvhTemplate.h"

namespace ofxPerceptionNeuron
{
    struct BvhData
    {
        int avater_index = 0;
        string avater_name;
        bool with_disp = false;
        bool with_ref = false;
        vector<float> raw_data;
    };
    
#pragma mark - DataReader::Impl
    class DataReader::Impl
    {
    public:
        SOCKET_REF sock = nullptr;
        
        FrameDataReceived f;
        SocketStatusChanged s;
        
        std::mutex data_lock;
        
        struct SwappableBvhData
        {
            BvhData back;
            BvhData front;
            void swap() {
                std::swap(back, front);
            }
            bool newdata = false;
            shared_ptr<ofxBvh> bvh;
            
            SwappableBvhData() {
                bvh = make_shared<ofxBvh>(bvh_header_template);
            }
            
            void update() {
                bvh->update(front.raw_data);
            }
            
            void draw() {
                bvh->draw();
            }
        };
        
        map<uint32_t, SwappableBvhData> data;
        bool newdata = false;
    public:
        Impl()
        {
            f = FrameDataReceived(frameDataReceived);
            if (f) {
                BRRegisterFrameDataCallback(this, f);
            }

            s = SocketStatusChanged(socketStatusChanged);
            if (s) {
                BRRegisterSocketStatusCallback(this, s);
            }
        }
        
        ~Impl()
        {
            disconnect();
        }
        
        static void frameDataReceived(void * customObject, SOCKET_REF sockRef, BvhDataHeader * header, float * data)
        {
            Impl* self = reinterpret_cast<Impl*>(customObject);
            cerr << header->AvatarIndex << ", " << header->AvatarName << ", " << header->DataCount << "," << header->WithDisp << "," << header->WithReference << "," << ofGetElapsedTimeMillis() << endl;
            
            self->data_lock.lock();
            SwappableBvhData& d = self->data[header->AvatarIndex];
            BvhData& b = d.back;
            b.avater_index = header->AvatarIndex;
            b.avater_name = (string)((const char*)header->AvatarName);
            b.with_disp = header->WithDisp;
            b.with_ref = header->WithReference;
            d.newdata = true;
            b.raw_data.clear();
            b.raw_data.insert(b.raw_data.end(), data, data + header->DataCount);
            self->data_lock.unlock();
        }
        
        static void socketStatusChanged(void * customObject, SOCKET_REF sockeRef, SocketStatus status, char * message)
        {
            ofLogVerbose("ofxPerceptionNeuron") << message << endl;
        }

        
        void connect(string ip, int port)
        {
            if (sock == nullptr) {
                sock = BRConnectTo(const_cast<char*>(ip.c_str()), port);
            }
        }
        
        bool isConnected() const {
            if (sock == nullptr) {
                return false;
            }
            SocketStatus ss = BRGetSocketStatus(sock);
            return ss == CS_Running;
        }
        
        void disconnect()
        {
            if (sock != nullptr) {
                BRCloseSocket(sock);
                sock = nullptr;
            }
        }
        
        void update()
        {
            data_lock.lock();
            for (auto& p : data) {
                if (p.second.newdata) {
                    p.second.swap();
                    p.second.update();
                    p.second.newdata = false;
                }
            }
            data_lock.unlock();
        }
        
        void draw()
        {
            for (auto& p : data) {
                p.second.draw();
            }
        }
    };
    
#pragma mark - Skeleton
    void Skeleton::debugDraw() const
    {
        ofVec3f vn;
        ofPushStyle();
        ofNoFill();
        for (auto & p : joints) {
            ofPushMatrix();
            ofMultMatrix(p.global_transform);
            if (p.name.find("Hand") == string::npos &&
                p.name.find("Site") == string::npos) {
                ofDrawBox(10);
                ofDrawAxis(15);
            } else {
                ofDrawBox(1);
                ofDrawAxis(1.5);
            }
            for (auto & q : p.children) {
                ofVec3f& v = q->offset;
                ofDrawLine(vn, v);
            }
            ofPopMatrix();
            
        }
        ofPopStyle();
    }
    
#pragma mark - DataReader
    DataReader::DataReader()
    {
        impl = make_shared<Impl>();
    }
    
    void DataReader::connect(string ip, int port)
    {
        impl->connect(ip, port);
    }
    
    bool DataReader::isConnected() const
    {
        return impl->isConnected();
    }
    
    void DataReader::update()
    {
        impl->update();
        
        // copy
        if (skeletons.size() != impl->data.size()) {
            skeletons.resize(impl->data.size());
        }
        for (int i=0; i<skeletons.size(); ++i) {
            auto & bvh = impl->data[i].bvh;
            auto & s = skeletons[i];
            skeletons_map[impl->data[i].front.avater_name] = &s;
            if (s.joints.size() != bvh->getNumJoints()) {
                s.joints.resize(bvh->getNumJoints());
                for (int j=0; j<s.joints.size(); ++j) {
                    auto* bvhj = bvh->getJoint(j);
                    auto& sj = s.joints[j];
                    sj.name = bvhj->getName();
                    s.joints_map[bvhj->getName()] = &sj;

                }
                for (int j=0; j<s.joints.size(); ++j) {
                    auto* bvhj = bvh->getJoint(j);
                    auto& sj = s.joints[j];
                    if (bvhj->getParent()) {
                        string pname = bvhj->getParent()->getName();
                        sj.parent = s.joints_map[pname];
                    }
                    sj.children.clear();
                    for (auto& c : bvhj->getChildren()) {
                        if (c) {
                            string cname = c->getName();
                            if (s.joints_map.find(cname) != s.joints_map.end()) {
                                sj.children.push_back(s.joints_map[cname]);
                            }
                        }
                    }
                }
            }
            for (int j=0; j<s.joints.size(); ++j) {
                auto* bvhj = bvh->getJoint(j);
                auto& sj = s.joints[j];
                sj.global_transform = bvhj->getGlobalMatrix();
                sj.transform = bvhj->getMatrix();
                sj.offset = bvhj->getOffset();
            }
        }
    }
    
    void DataReader::disconnect()
    {
        impl->disconnect();
    }
    
    void DataReader::debugDraw() const
    {
//        impl->draw();
        for (auto & p : skeletons) {
            p.debugDraw();
        }
    }

    const Skeleton& DataReader::getSkeletonByName(string name) const
    {
        const auto& it = skeletons_map.find(name);
        if (it != skeletons_map.end()) {
            return *it->second;
        }
    }

}