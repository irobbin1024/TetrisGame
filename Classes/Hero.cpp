//
//  Hero.cpp
//  TetrisGame
//
//  Created by 赖隆斌 on 14-4-10.
//
//

#include "Hero.h"
#include "cocos2d.h"

USING_NS_CC;

void Hero::setMaxScore(long score) {
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey(SCORE_KEY, -1) == -1) {
        CCUserDefault::sharedUserDefault()->setIntegerForKey(SCORE_KEY, 0);
    }
    CCUserDefault::sharedUserDefault()->setIntegerForKey(SCORE_KEY, score);

}

long Hero::getMaxScore() {
    return CCUserDefault::sharedUserDefault()->getIntegerForKey(SCORE_KEY, 0);
}

long Hero::getScore() {
    return _score;
}

void Hero::goal() {
    _score += SCORE_OF_ROW;
}

