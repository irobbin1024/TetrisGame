//
//  Tetromino.h
//  Tetris
//
//  Created by 赖隆斌 on 14-2-26.
//
//

#ifndef __Tetris__Tetromino__
#define __Tetris__Tetromino__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

// 所有形状及其变形的定义
enum TetrominoSubType{
    O1 = 0, I1 = 1, I2 = 2, LA1 = 3, LA2 = 4, LA3 = 5, LA4 = 6, LB1 = 7, LB2 = 8, LB3 = 9, LB4 = 10, SA1 = 11, SA2 = 12, SB1 = 13, SB2 = 14, T1 = 15, T2 = 16, T3 = 17, T4 = 18
};

class Tetromino{
    
public:
    static Tetromino * create(TetrominoSubType subType);
    
    void initTetromino();
    // GamePoint 游戏坐标 10 * 20
    // Point 像素坐标
    static CCPoint PointConvertToGamePoint(CCPoint p, CCSize shapeSize);
    static CCPoint GamePointConvertToPoint(CCPoint p, CCSize shapeSize);
    
    bool moveTetromino();
    void moveLeft();
    void moveRight();
    bool pointOnLeft(CCPoint p);
    bool pointOnRight(CCPoint p);
    bool pointOnDown(CCPoint p);
    bool pointOnTetromino(CCPoint p);
    
    void relocation();
    void deForm();
    bool collide(Tetromino * t);
    
    CCArray * getBlocks();
protected:
    //================私有属性定义=================
    // 各个方块
    CCSprite * b1;
    CCSprite * b2;
    CCSprite * b3;
    CCSprite * b4;
    
    int row;
    int col;
    
    TetrominoSubType subType;

    
    //================私有方法定义===================
    
    bool bottonHasSomething();
    bool leftHasSomething();
    bool rightHasSomething();
    
    // 每个形状的重定位方法
    void I1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void I2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    
    void LA1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LA2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LA3_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LA4_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LB1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LB2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LB3_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void LB4_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void O_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void SA1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void SA2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void SB1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void SB2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    
    void T1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void T2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void T3_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    void T4_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point);
    
private:
    

};

#endif /* defined(__Tetris__Tetromino__) */
