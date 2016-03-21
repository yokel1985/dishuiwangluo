//
//  LoadingData.hpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#ifndef LoadingData_hpp
#define LoadingData_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class LoadingData :public Ref
{
public:
    Node* mUILayer = nullptr;
    Node* mScene = nullptr;
    static LoadingData* getInstance();
    void load();
    void show();
    void hide(Layer * layer);
    Layer * _layer;
private:
    void loadPNG(float dt);
    
    void imageAsyncCallback(cocos2d::Texture2D* texture);
};
#endif /* LoadingData_hpp */
