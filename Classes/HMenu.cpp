//
//  HMenu.cpp
//  Tetris
//
//  Created by 赖隆斌 on 14-2-25.
//
//

#include "HMenu.h"
#include "SimpleAudioEngine.h"
#include "HAbout.h"
#include "HScore.h"
#include "WorldScene.h"
#include "RetryGameScene.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene * HMenu::scene() {
    CCScene * scene = CCScene::create();
    HMenu * layer = HMenu::create();
    scene->addChild(layer);
    return scene;
}

bool HMenu::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    // 播放背景音乐
    // SimpleAudioEngine::sharedEngine()->playBackgroundMusic("other/menuMusic.mp3", true);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    
    // 添加背景图像
    CCSprite * background = CCSprite::create("menu_background.jpg");
    background->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(background);
    
    CCLabelTTF * menuPlayLabel = CCLabelTTF::create("Play", "Helvetica-Bold", 60);
    CCMenuItemLabel * menuPlay = CCMenuItemLabel::create(menuPlayLabel, this, menu_selector(HMenu::playIsPressed));
    menuPlay->setPosition(ccp(0, 220));
    
    CCLabelTTF * menuScoreLabel = CCLabelTTF::create("Score", "Helvetica-Bold", 60);
    CCMenuItemLabel * menuScore = CCMenuItemLabel::create(menuScoreLabel, this, menu_selector(HMenu::scoreIsPressed));
    menuScore->setPosition(ccp(0, 150));
    
    CCLabelTTF * menuAboutLabel = CCLabelTTF::create("About", "Helvetica-Bold", 60);
    CCMenuItemLabel * menuAbout = CCMenuItemLabel::create(menuAboutLabel, this, menu_selector(HMenu::aboutIsPressed));
    menuAbout->setPosition(ccp(0, 80));

    
    CCMenu * menu = CCMenu::create(menuPlay, menuScore, menuAbout, NULL);
    this->addChild(menu);
    
    return true;
}

void HMenu::playIsPressed() {
    CCDirector::sharedDirector()->replaceScene(CCTransitionSplitRows::create(1.5, World::scene()));
}

void HMenu::scoreIsPressed() {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(1.5, HScore::scene()));
    //CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, RetryGameScene::scene()));
}

void HMenu::aboutIsPressed() {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(1.5, HAbout::scene()));
}