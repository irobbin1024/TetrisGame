//
//  HMenu.h
//  Tetris
//
//  Created by 赖隆斌 on 14-2-25.
//
//

#ifndef __Tetris__HMenu__
#define __Tetris__HMenu__

#include <iostream>
#include "cocos2d.h"

class HMenu : public cocos2d::CCLayer
{
public :
    virtual bool init();
    static cocos2d::CCScene * scene();
    CREATE_FUNC(HMenu);
    
private:
    void playIsPressed();
    void scoreIsPressed();
    void aboutIsPressed();
};

#endif /* defined(__Tetris__HMenu__) */
