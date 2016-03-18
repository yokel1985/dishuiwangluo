
#ifndef xml_hpp
#define xml_hpp
#include <stdio.h>
#include "cocos2d.h"
#include"tinyxml2/tinyxml2.h"

using namespace tinyxml2;

USING_NS_CC;

class xml: public Ref{

public:
    
    XMLElement * mRootNode ;
    void init(std::string filename);
    std::string xmlName = "role";
    std::string getValueById(std::string name,int key,std::string value);
    float getIntById(std::string name,int key,std::string value);
    //bool loadXDataTable();
    static xml* getInstance();
};

#endif /* xml_hpp */
