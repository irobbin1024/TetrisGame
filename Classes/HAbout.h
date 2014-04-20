//
//  HAbout.h
//  Tetris
//
//  Created by 赖隆斌 on 14-2-25.
//
//

#ifndef __Tetris__HAbout__
#define __Tetris__HAbout__

#include <iostream>
#include "cocos2d.h"

class HAbout : public cocos2d::CCLayer {
public :
    virtual bool init();
    static cocos2d::CCScene * scene();
    CREATE_FUNC(HAbout);
   
private :
    void backMenuScene();
};

#endif /* defined(__Tetris__HAbout__) */
