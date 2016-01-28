#include "ofApp.h"

//--------------------------------------------------------------
bool hotelComp(Hotel a, Hotel b){
    return a.rating >= b.rating;
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(24);
    ofSetVerticalSync(true);
    
    num_hotels = 20;

	hotelCsv.loadFile(ofToDataPath("hotel-cond.csv"));
    gpiCsv.loadFile(ofToDataPath("national-gpi.csv"));

    vector<string> country_names;

    for(int i = 0; i < num_hotels; i++){
    	string name = gpiCsv.getString(gpiCsv.numRows -1 -i, 0);
    	float ranking = gpiCsv.getFloat(gpiCsv.numRows -1 -i, 1);
    	vector<Hotel> blank;
        
        Country temp = {name, ranking, blank};

        d_countries.push_back(temp);

    	country_names.push_back(name);
    }

    for(int i = 1; i < hotelCsv.numRows; i++){
    	string tar_country = hotelCsv.getString(i, 1);
    	for(int j = 0; j < num_hotels; j++){
    		if(d_countries[j].name == tar_country){
                d_countries[j].best_hotels.push_back({
                        hotelCsv.getString(i, 0),
    					hotelCsv.getFloat(i, 2),
    					hotelCsv.getFloat(i, 3),
    					hotelCsv.getFloat(i, 4)});
    		}
    	}
    }
    
    for(int i = 0; i < num_hotels; i++){
        //ofSort(d_countries[i].best_hotels, &ofApp::hotelComp);
        //sort(d_countries[i].best_hotels.begin(), d_countries[i].best_hotels.end(), hotelComp);
    }
    
    cout << d_countries.size() << " countries accounted for" << endl;
    cout << "lengths " << d_countries[0].best_hotels.size() << ", "
                       << d_countries[1].best_hotels.size() << ", "
                       << d_countries[2].best_hotels.size() << ", "
                       << d_countries[3].best_hotels.size() << ", "
                       << d_countries[4].best_hotels.size() << ", "
                       << d_countries[5].best_hotels.size() << ", "
                       << d_countries[6].best_hotels.size() << ", "
                       << d_countries[8].best_hotels.size() << ", "
                       << d_countries[9].best_hotels.size() << ", "
                       << d_countries[10].best_hotels.size() << ", "
                       << d_countries[11].best_hotels.size() << ", "
                       << d_countries[12].best_hotels.size() << ", " << endl;

    d_countries[4].name = "C.A.R";
    d_countries[7].name = "D.R.C";
    


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    
    ofSetColor(75,75,75);
    
    int diff_width = ofGetWidth()/21;
    int diff_height = ofGetHeight()/21;
    int list_offset = 50;
    
    ofDrawBitmapString("Danger Hotel: a guide to hotels in the world's 20 most dangerous countries", 20, 20);
    ofDrawBitmapString("The Global Peace Index, maintained by IEP, ranks 162 nations in order of their stability. These nations have the 20 worst GPI ratings of any nation.", 20, 35);
    
    int focus_i = -1;
    int focus_j = -1;
    
    for(int i = 0; i < num_hotels; i++){
        
        ofDrawBitmapString(ofToString(d_countries[i].gpi_ranking), 10, 60 + diff_height * i);
        ofDrawBitmapString(d_countries[i].name, 40, 60 + diff_height * i);
        
        for(int j = 0; j < d_countries[i].best_hotels.size(); j++){
            if( ofBaseApp::mouseX > 150 + (j * 15) &&
                ofBaseApp::mouseX < 150 + (j * 15) + 12 &&
                ofBaseApp::mouseY > 50 + diff_height * i &&
                ofBaseApp::mouseY < 50 + diff_height * i + 12){
                ofSetColor(255,50,50);
                focus_i = i;
                focus_j = j;
            } else {
                ofSetColor(100, 100, 100);
            }
               
            ofDrawRectangle(150 + (j * 15), 50 + diff_height * i, 12, 12);
         /*Hotel hot = d_countries[i].best_hotels[j];
         int offset = 50 + list_offset * j;
         ofDrawBitmapString(hot.name, 20 + (i * diff_width), offset + 10);
         ofDrawBitmapString(ofToString(hot.latitude) + "/" + ofToString(hot.longitude),
         20 + (i * diff_width), offset + 20);
         ofDrawBitmapString(ofToString(hot.rating) + " Stars",
         20 + (i * diff_width), offset + 30);
         }*/
        }
        ofSetColor(75,75,75);
    }
    
    if (focus_i >= 0){
        Hotel foc = d_countries[focus_i].best_hotels[focus_j];
        int base_x = 150 + (focus_j * 15);
        int base_y = 50 + diff_height * focus_i;
        
        ofDrawBitmapStringHighlight(foc.name, base_x + 20, base_y - 20);
        ofDrawBitmapStringHighlight(ofToString(foc.latitude) + "/" + ofToString(foc.longitude),
                                    base_x + 20, base_y);
        ofDrawBitmapStringHighlight(ofToString(foc.rating) + " Stars", base_x + 20, base_y + 20);
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
