//
//  BackgroundLayer.h
//  TetrisGame
//
//  Created by 赖隆斌 on 14-4-10.
//
//

#ifndef __TetrisGame__BackgroundLayer__
#define __TetrisGame__BackgroundLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BackgroundLayer : public CCLayer {
private:
    std::string bg_img = "game_background.png";
public:
    virtual bool init();
    
    CREATE_FUNC(BackgroundLayer);
};

#endif /* defined(__TetrisGame__BackgroundLayer__) */
