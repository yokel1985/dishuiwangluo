#include "util.h"
#include <stdlib.h>
#include "tinyxml2/tinyxml2.h"
#include <time.h>
#include <sstream>
#include <stdlib.h>

//RandomGen g_random(time(NULL));

int randInt(int min, int max) {
    if (min == max) {
        return min;
    }
    return min + rand() % (max - min);
}


void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	elems.clear();
	std::stringstream ss(s);
	std::string item;	
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
void splitTyped(const std::string& s, char delim, std::vector<int>& ret) {
	ret.clear();
    std::vector<std::string> temp;
    split(s, delim, temp);
    for (size_t i = 0; i < temp.size(); i++) {
		if (!temp[i].empty()) {
			ret.push_back(atoi(temp[i].c_str()));
		}
    }
}

void showLog(const std::string& log) {
	CCLOG("%s", log.c_str());
}

std::string getstring ( const int n )

{
    
    std::stringstream newstr;
    newstr<<n;
    return newstr.str();
    
}

bool CocosLoadXMLDoc(const std::string& filename, tinyxml2::XMLDocument& doc)
{
	std::string data = cocos2d::FileUtils::getInstance()->getStringFromFile(filename);
	if (!data.empty())
	{
		if (0 != doc.Parse(data.c_str()))
		{
			CCLOG("-----------Load %s error-------------", filename.c_str());
			return false;
		}
	}
	else
	{
		CCLOG("can not get file data of %s", filename.c_str());
	}

	return true;
}



void gsAddCustomEvent (const std::string & 	eventName,
                     const std::function< void(cocos2d::EventCustom *)> &callback )
{
    auto _listener = cocos2d::EventListenerCustom::create(eventName,callback);
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_listener, 1);
    
}

void gsDispatchEvent(const std::string &eventName,void* data = 0)
{
    cocos2d::EventCustom event(eventName);
    if (data != 0) {
        event.setUserData(data);
    }
    
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
    
    //CC_SAFE_DELETE_ARRAY(data);
        
}

