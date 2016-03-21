//
//  GameManger.cpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#include "GameManger.h"
#include "lua_system.h"
#include "ui/CocosGUI.h"
#include "MainGameScene.h"
GameManager* GameManager::getInstance(){
    static GameManager  _mGameManager;
    return &_mGameManager;
}

void GameManager::initBattleScene(){
    Director::getInstance()->getRunningScene()->removeFromParentAndCleanup(true);
//    TextureCache::getInstance()->unbindAllImageAsync();
//    TextureCache::getInstance()->removeUnusedTextures();
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
   // auto battleScene = MainGameScene::create();
    CCLOG("%s","hahahaah 成功到c++");
    //Director::getInstance()->replaceScene(battleScene);
    
    toLuaScene();
}

void GameManager::toLuaScene(){
    Director::getInstance()->getRunningScene()->removeFromParentAndCleanup(true);
    TextureCache::getInstance()->removeUnusedTextures();
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
//    LuaSystem::getInstance()->callLuaFunc("cpptolua", 0);
//    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
//    TextureCache::getInstance()->unbindAllImageAsync();
    sleep(2);
    CCLOG("%s","hahahaah 成功到lua");
    LuaSystem::getInstance()->callLuaFunc("cpptolua", 0);

    
}