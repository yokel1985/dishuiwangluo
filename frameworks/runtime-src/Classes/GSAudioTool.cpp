//
//  GSAudioTool.cpp
//  baiwanren
//
//  Created by apple on 15/10/23.
//
//

#include "GSAudioTool.h"

#include "vector"

#include "SimpleAudioEngine.h"

using namespace std;
USING_NS_CC;
using namespace CocosDenshion;


GSAudioTool * GSAudioTool::getInstance()
{
    static GSAudioTool _audioTool;
    return  &_audioTool;

}

ComAudio* GSAudioTool::getAudioByName(Node* node)
{
    auto mynode = node->getChildByTag(10002);
    if (!mynode) {
        return NULL;
    }
    return dynamic_cast<ComAudio*>(mynode->getComponent(mynode->getName()));

}

void GSAudioTool::playEffect(Node* node)
{
    if (node->isVisible()) {
        auto audio = this->getAudioByName(node);
        if (!audio) {
            return;
        }
        if (audio->isLoop()) {
            audio->stopBackgroundMusic();
            audio->playBackgroundMusic();
        }else
        {
            audio->playEffect();
        }
    }
}
void GSAudioTool::pauseEddect(Node * node)
{
    auto audio = this->getAudioByName(node);
    if (audio->isLoop()) {
        //
    }else
    {
        audio->pauseAllEffects();
    }
}
void GSAudioTool::resumeEffect(Node * node)
{
    auto audio = this->getAudioByName(node);
    if (audio->isLoop()) {
        //
    }else
    {
        audio->resumeAllEffects();
    }
}
void GSAudioTool::stopEffect(Node * node)
{
    auto audio = this->getAudioByName(node);
    if (audio->isLoop()) {
        audio->stopBackgroundMusic();
    }else
    {
        audio->stopAllEffects();
    }
}
void GSAudioTool::playNodeSound(Node * node)
{
    auto children = node->getChildren();
    //auto count = children.size();
    Vector<Node*>::const_iterator iter ;
    for (auto item:children) {
        auto tag = item->getTag();
        if (tag ==  10001) {
            auto audio = this->getAudioByName(item);
            audio->playEffect();
        }
    }
}
void GSAudioTool::playSoundDelay(Node* node)
{

}
