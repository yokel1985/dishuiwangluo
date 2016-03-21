//
//  LoadingData.cpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#include "LoadingData.h"
#include <string>
#include "ui/CocosGUI.h"
using namespace std;
const string loadingPNG[] = {};
 int INDEX = 0;
LoadingData* LoadingData::getInstance()
{
    static LoadingData _loadingData;
    return &_loadingData;
}

void LoadingData::load()
{
    
    
   

}

void LoadingData::show()
{
    
}

void LoadingData::hide(Layer * layer)
{
    
}

void LoadingData::loadPNG(float dt)
{
    Director::getInstance()->getTextureCache()->addImageAsync(loadingPNG[INDEX],CC_CALLBACK_1(LoadingData::imageAsyncCallback, this));
    INDEX++;
}

void LoadingData::imageAsyncCallback(cocos2d::Texture2D* texture)
{
    
}

