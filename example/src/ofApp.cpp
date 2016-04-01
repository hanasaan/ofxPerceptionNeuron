#include "ofMain.h"
#include "ofxPerceptionNeuron.h"

class ofApp : public ofBaseApp{
    
    ofxPerceptionNeuron::DataReader neuron;
    ofEasyCam cam;
public:
    void setup()
    {
        ofSetVerticalSync(true);
        ofSetFrameRate(60);
        
        ofSetLogLevel(OF_LOG_VERBOSE);
        neuron.connect("10.0.0.100", 7001);
    }
    
    void update()
    {
        neuron.update();
    }
    
    void draw()
    {
        ofClear(0);
        cam.begin();
        neuron.debugDraw();
        ofDrawAxis(100);
        cam.end();
    }
    
    void keyPressed(int key) {}
};

//========================================================================
int main( ){
    ofSetupOpenGL(1280,720,OF_WINDOW);            // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
}
