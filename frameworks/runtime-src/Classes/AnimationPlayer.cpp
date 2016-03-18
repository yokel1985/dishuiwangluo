//
//  AnimationPlayer.cpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#include "AnimationPlayer.h"

using namespace cocostudio::timeline;

Node * AnimationPlayer::createNodeByCSBName(std::string fileName)
{
    auto node = CSLoader::createNode(fileName);
    return node;
}

std::string AnimationPlayer::getNodeName(std::string name, int tag)
{
    return "";
}

 ActionTimeline * AnimationPlayer::createTimeByCSBName(std::string fileName)
{
    return CSLoader::createTimeline(fileName);
}

 Node* AnimationPlayer::createCSBTimeAndPlay(std::string filename,bool isfoever)
{
    auto node = createNodeByCSBName(fileName);
    auto timeLine = createTimeByCSBName(fileName);
    timeLine->gotoFrameAndPlay(0,isfoever);
    node->runAction(timeLine);
    return node;
}

 Node* AnimationPlayer::createCSBTimeAndPlayAll(std::string filename,bool isfoever)
{
    return nullptr;
}

void  AnimationPlayer::playCSBTimeAllByNode(Node * node , bool isfoever)
{
    
}
