//
//  RetryGameScene.h
//  TetrisGame
//
//  Created by 赖隆斌 on 14-4-17.
//
//

#ifndef __TetrisGame__RetryGameScene__
#define __TetrisGame__RetryGameScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class RetryGameScene : public CCLayerRGBA {
public:
    public :
    virtual bool init();
    void retry();
    static cocos2d::CCScene * scene();
    CREATE_FUNC(RetryGameScene);
};

#endif /* defined(__TetrisGame__RetryGameScene__) */
