#ifndef __UTIL_H__
#define __UTIL_H__

//#include <boost/random.hpp>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <time.h>
#include <vector>
#include <tinyxml2/tinyxml2.h>
#include "cocos2d.h"

struct mCameraChange{
    int _changeX ;
    int _changeY;
    int _changeZ;
};

void gsAddCustomEvent (const std::string & 	eventName,
                       const std::function< void(cocos2d::EventCustom *)> &callback );
void gsDispatchEvent(const std::string & 	eventName,void* data);
int randInt(int min, int max) ;
void split(const std::string& s, char delim, std::vector<std::string>& ret);
void splitTyped(const std::string& s, char delim, std::vector<int>& ret);
void showLog(const std::string& log);
std::string getstring ( const int n );

bool CocosLoadXMLDoc(const std::string& file, tinyxml2::XMLDocument& doc);



#endif
