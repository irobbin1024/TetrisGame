//
//  HScore.h
//  Tetris
//
//  Created by 赖隆斌 on 14-2-25.
//
//

#ifndef __Tetris__HScore__
#define __Tetris__HScore__

#include <iostream>
#include "cocos2d.h"

class HScore : cocos2d::CCLayer {

public:
    virtual bool init();
    static cocos2d::CCScene * scene();
    CREATE_FUNC(HScore);
    
private:
    void backMenu();
};

#endif /* defined(__Tetris__HScore__) */
