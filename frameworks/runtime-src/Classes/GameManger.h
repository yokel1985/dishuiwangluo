//
//  GameManger.h
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#ifndef GameManger_hpp
#define GameManger_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class GameManager :public Ref
{
public:
    bool init(){
        return true;
    }
    CREATE_FUNC(GameManager);
    static GameManager *getInstance();
    void initBattleScene();
    void toLuaScene();
};
#endif /* GameManger_h */
