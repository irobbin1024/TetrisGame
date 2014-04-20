//
//  HScore.cpp
//  Tetris
//
//  Created by 赖隆斌 on 14-2-25.
//
//

#include "HScore.h"
#include "cocos2d.h"
#include "HMenu.h"
#include "Hero.h"

using namespace cocos2d;

CCScene * HScore::scene() {
    CCScene * scene = CCScene::create();
    HScore * layer = HScore::create();
    scene->addChild(layer);
    return scene;
}

bool HScore::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite * background = CCSprite::create("score_background.jpg");
    background->setPosition(ccp(size.width * 0.5, size.height * 0.5));
    
    this->addChild(background);
    
    std::string score = CCUserDefault::sharedUserDefault()->getStringForKey(SCORE_KEY, "-1");
    if (atoi(score.c_str()) == -1) {
       score = "0";
    }
    
    CCLabelTTF * scoreInfo = CCLabelTTF::create(score.c_str(), "Helvetica-Bold", 50);
    scoreInfo->setPosition(ccp(size.width * 0.5 + 140, size.height * 0.5 + 145));
    scoreInfo->setColor(ccc3(255, 0, 0));
    this->addChild(scoreInfo);
    
    CCLabelTTF * menuReturnLabel = CCLabelTTF::create("Return", "Helvetica-Bold", 50);
    CCMenuItemLabel * menuReturn = CCMenuItemLabel::create(menuReturnLabel, this, menu_selector(HScore::backMenu));
    menuReturn->setPosition(ccp(0, -100));
    
    
    CCMenu * menu = CCMenu::create(menuReturn, NULL);
    this->addChild(menu);

    
    return true;
}

void HScore::backMenu() {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(1.5, HMenu::scene()));
}

