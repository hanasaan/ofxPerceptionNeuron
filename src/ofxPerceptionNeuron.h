//
//  Created by Yuya Hanai, https://github.com/hanasaan/
//
#pragma once

#include "ofMain.h"

namespace ofxPerceptionNeuron
{
    class DataReader;
    
    struct Joint
    {
        string name;
        ofVec3f offset;
        
        ofMatrix4x4 transform;
        ofMatrix4x4 global_transform;
        
        vector<Joint*> children;
        Joint* parent = nullptr;
    };
    
    class Skeleton
    {
    protected:
        friend class DataReader;
        string name;
        vector<Joint> joints;
        map<string, Joint*> joints_map;
    public:
        void debugDraw() const;
        string getName() const { return name; }
        const vector<Joint>& getJoints() const { return joints; }
        const Joint& getJointByName(string name) const {
            const auto& it = joints_map.find(name);
            if (it != joints_map.end()) {
                return *it->second;
            }
        }
    };
    
    class DataReader
    {
    protected:
        class Impl;
        shared_ptr<Impl> impl;
        vector<Skeleton> skeletons;
        map<string, Skeleton*> skeletons_map;
    public:
        DataReader();
        void connect(string ip, int port);
        void disconnect();
        void update();
        bool isConnected() const;
        bool isFrameNew() const;
        void debugDraw() const;
        const vector<Skeleton>& getSkeletons() const { return skeletons; }
        const Skeleton& getSkeletonByName(string name) const;
    };
}
