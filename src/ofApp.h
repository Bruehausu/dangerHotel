#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

using namespace wng;

typedef struct {
    string name;
    float latitude;
    float longitude;
    float rating;
} Hotel;

typedef struct {
	string name;
	float gpi_ranking;
    vector<Hotel> best_hotels;
} Country;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        bool hotelComp(Hotel a, Hotel b);

		vector<Country> d_countries;
		
        ofxCsv hotelCsv;
        ofxCsv gpiCsv;
    
        int num_hotels;
};
