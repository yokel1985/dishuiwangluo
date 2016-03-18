//
//  xml.cpp

#include "xml.h"
#include <iostream>

using namespace std;
xml* xml::getInstance(){
    static xml  _mxml;
    return &_mxml;
}

void xml::init(std::string filename){
    string filePath = FileUtils::getInstance()->getStringFromFile("xml/role.xml");
	tinyxml2::XMLDocument * mDoc = new tinyxml2::XMLDocument();
    XMLError errorId = mDoc->Parse(filePath.c_str());
    
    if (errorId != 0) {
        
        CCLOG("xml路径错误！！！");
        CCLOG("%s",filePath.c_str());
        return;
    }
    mRootNode = mDoc->RootElement();
    //const XMLAttribute * attribute = mRootNode->FirstAttribute();
    XMLElement* dicEle = mRootNode->FirstChildElement();
    //auto * fist = mRootNode->FindAttribute();
    
    if (dicEle) {
        auto  attribute= dicEle->FirstAttribute();
        CCLOG("%d", attribute->IntValue());
        while (attribute) {
            CCLOG("attributename = %s,attributevalue = %s", attribute->Name(), attribute->Value());
            attribute = attribute->Next();
        }
    }
    //log("attributename = %s,attributevalue = %s", attribute->Name(), attribute->Value());
    
    //CCLOG(dicEle->GetText());
    
    delete mDoc;
    mDoc = NULL;

}
std::string xml::getValueById(string name,int key,string value)
{
    string filePath = FileUtils::getInstance()->getStringFromFile("xml/"+name+".xml");
	tinyxml2::XMLDocument * mDoc = new tinyxml2::XMLDocument();
    XMLError errorId = mDoc->Parse(filePath.c_str());
    
    if (errorId != 0) {
        
        CCLOG("xml路径错误！！！");
        CCLOG("%s",filePath.c_str());
        delete mDoc;
        mDoc = NULL;
        return 0;
    }
    mRootNode = mDoc->RootElement();
    std::string _value = "";
    if (mRootNode) {
        XMLElement* dicEle = mRootNode->FirstChildElement();
        while (dicEle) {
            auto  attribute = dicEle->FirstAttribute();
            CCLOG("%d", attribute->IntValue());
            int  id = attribute->IntValue();
            if (id == key) {
                while (attribute) {
                    string str = attribute->Name();
                    if (str== value) {
                        _value = attribute->Value();;
                        delete mDoc;
                        mDoc = NULL;
                        return _value;
                        
                    }
                    attribute = attribute->Next();
                }
            }
            
            dicEle = dicEle->NextSiblingElement();
            
        }
    }
    
    delete mDoc;
    mDoc = NULL;
    return "";
}


float xml::getIntById(string name,int key,string value)
{


    string filePath = FileUtils::getInstance()->getStringFromFile("xml/"+name+".xml");
	tinyxml2::XMLDocument * mDoc = new tinyxml2::XMLDocument();
    XMLError errorId = mDoc->Parse(filePath.c_str());
    
    if (errorId != 0) {
        
        CCLOG("xml路径错误！！！");
        CCLOG("%s",filePath.c_str());
        delete mDoc;
        mDoc = NULL;
        return 0;
    }
    mRootNode = mDoc->RootElement();
    float _value = 0;
    if (mRootNode) {
        XMLElement* dicEle = mRootNode->FirstChildElement();
        while (dicEle) {
            auto  attribute = dicEle->FirstAttribute();
            CCLOG("%d", attribute->IntValue());
            int  id = attribute->IntValue();
            if (id == key) {
                while (attribute) {
                    string str = attribute->Name();
                    if (str== value) {
                        _value = atof(attribute->Value());
                        delete mDoc;
                        mDoc = NULL;
                        return _value;
                        
                    }
                    attribute = attribute->Next();
                }
            }
            
            dicEle = dicEle->NextSiblingElement();
            
        }
    }
    
    delete mDoc;
    mDoc = NULL;
    return 0;


}