//
//  HAbout.cpp
//  Tetris
//
//  Created by 赖隆斌 on 14-2-25.
//
//

#include "HAbout.h"
#include "cocos2d.h"
#include "HMenu.h"

using namespace cocos2d;

CCScene * HAbout::scene() {
    CCScene * scene = CCScene::create();
    HAbout * layer = HAbout::create();
    scene->addChild(layer);
    return scene;
}

bool HAbout::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    //设置背景
    CCSprite * background = CCSprite::create("menu_background.jpg");
    background->setPosition(ccp(size.width * 0.5, size.height * 0.5));
    this->addChild(background);
    
    CCLabelTTF * infoLabel = CCLabelTTF::create("制作：赖隆斌(fujaz) \n时间：2014年4月份 \n版权：Copyleft@fujaz \n联系：fujazbug@gmail.com", "Helvetica-Bold", 40);
    infoLabel->setPosition(ccp(size.width * 0.5, size.height * 0.5 + 180));
    this->addChild(infoLabel);
    
    CCLabelTTF * menuReturnLabel = CCLabelTTF::create("Return", "Helvetica-Bold", 60);
    CCMenuItemLabel * menuReturn = CCMenuItemLabel::create(menuReturnLabel, this, menu_selector(HAbout::backMenuScene));
    menuReturn->setPosition(ccp(0, 20));
    
    
    CCMenu * menu = CCMenu::create(menuReturn, NULL);
    this->addChild(menu);

    
    return true;
}

void HAbout::backMenuScene() {
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(1.5, HMenu::scene(), true));
}
