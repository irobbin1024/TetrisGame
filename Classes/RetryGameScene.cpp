//
//  RetryGameScene.cpp
//  TetrisGame
//
//  Created by 赖隆斌 on 14-4-17.
//
//

#include "RetryGameScene.h"
#include "WorldScene.h"

CCScene * RetryGameScene::scene() {
    CCScene * scene = CCScene::create();
    RetryGameScene * layer = RetryGameScene::create();
    scene->addChild(layer);
    return scene;
}

bool RetryGameScene::init() {
    
    
    this->setColor(ccWHITE);

    this->schedule(schedule_selector(RetryGameScene::retry), 0.5, 0, 2);
    return true;
}

void RetryGameScene::retry() {
    CCDirector::sharedDirector()->replaceScene(CCTransitionSplitRows::create(1.0, World::scene()));
}