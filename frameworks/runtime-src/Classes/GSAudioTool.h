//
//  GSAudioTool.hpp
//
//  Created by apple on 15/10/23.
//
//

#ifndef GSAudioTool_hpp
#define GSAudioTool_hpp

#include <stdio.h>

#include "cocos2d.h"

#include "AudioEngine.h"

#include"cocostudio/CCComAudio.h"

USING_NS_CC;

using namespace cocostudio;

class GSAudioTool
{
public:
    static GSAudioTool * getInstance();
    ComAudio* getAudioByName(Node* node);
    void playEffect(Node* node);
    void pauseEddect(Node * node);
    void resumeEffect(Node * node);
    void stopEffect(Node * node);
    void playNodeSound(Node * node);
    void playSoundDelay(Node* node);
   
};
#endif /* GSAudioTool_hpp */
