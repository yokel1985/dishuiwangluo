//
//  MainGameScene.hpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#ifndef MainGameScene_hpp
#define MainGameScene_hpp

#include <stdio.h>
#include "GameManager"
#include "cocos2d.h"
using namespace cocos2d;

class MainGameScene :public Scene
{
    virtual bool init() override;
    CREATE_FUNC(MainGameScene);
    
};
#endif /* MainGameScene_hpp */
