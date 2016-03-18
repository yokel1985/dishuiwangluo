//
//  AnimationPlayer.hpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#ifndef AnimationPlayer_hpp
#define AnimationPlayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class AnimationPlayer : public Ref
{
public:
    static Node* createNodeByCSBName(std::string fileName);
    std::string getNodeName(std::string name, int tag);
    static ActionTimeline *createTimeByCSBName(std::string fileName);
    static Node* createCSBTimeAndPlay(std::string filename,bool isfoever);
    static Node* createCSBTimeAndPlayAll(std::string filename,bool isfoever);
    void playCSBTimeAllByNode(Node * node , bool isfoever);

};

#endif /* AnimationPlayer_hpp */
