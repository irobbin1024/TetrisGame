//
//  BackgroundLayer.cpp
//  TetrisGame
//
//  Created by 赖隆斌 on 14-4-10.
//
//

#include "BackgroundLayer.h"


bool BackgroundLayer::init() {
    CCSprite * bgSprite = CCSprite::create(this->bg_img.c_str());
    bgSprite->setPosition(ccp(bgSprite->getContentSize().width * 0.5, bgSprite->getContentSize().height * 0.5));
    this->addChild(bgSprite);
    return true;
}