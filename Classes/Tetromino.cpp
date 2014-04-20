//
//  Tetromino.cpp
//  Tetris
//
//  Created by 赖隆斌 on 14-2-26.
//
//

#include "Tetromino.h"
#include "WorldScene.h"
using namespace cocos2d;

Tetromino * Tetromino::create(TetrominoSubType subType) {
    Tetromino * newT = new Tetromino();
    newT->subType = subType;
    newT->initTetromino();
    return newT;
}


void Tetromino::initTetromino() {
    std::string picName;
    int r, c;
    switch (subType) {
        case I1:
            picName = "shap/dq.png";
            r = ROWS + 1;
            c = 5;
            break;
        case I2:
            picName = "shap/dq.png";
            r = ROWS + 1;
            c = 5;
            break;
            //---------------------------
        case LA1:
            picName = "shap/dzs.png";
            r = ROWS + 2;
            c = 5;
            break;
        case LA2:
            picName = "shap/dzs.png";
            r = ROWS + 3;
            c = 5;
            break;
        case LA3:
            picName = "shap/dzs.png";
            r = ROWS + 2;
            c = 5;
            break;
        case LA4:
            picName = "shap/dzs.png";
            r = ROWS + 3;
            c = 5;
            break;
            //----------------------------
            
        case LB1:
            picName = "shap/gray.png";
            r = ROWS + 2;
            c = 5;
            break;
        case LB2:
            picName = "shap/gray.png";
            r = ROWS + 3;
            c = 5;
            break;
        case LB3:
            picName = "shap/gray.png";
            r = ROWS + 1;
            c = 5;
            break;
        case LB4:
            picName = "shap/gray.png";
            r = ROWS + 3;
            c = 5;
            break;
            //-----------------------------
        case O1:
            picName = "shap/ls.png";
            r = ROWS + 2;
            c = 5;
            break;
            //-----------------------------
        case SA1:
            picName = "shap/mgs.png";
            r = ROWS + 1;
            c = 5;
            break;
        case SA2:
            picName = "shap/mgs.png";
            r = ROWS + 3;
            c = 5;
            break;
            //---------------------------
        case SB1:
            picName = "shap/red.png";
            r = ROWS + 2;
            c = 5;
            break;
        case SB2:
            picName = "shap/red.png";
            r = ROWS + 3;
            c = 5;
            break;
            //----------------------------
        case T1:
            picName = "shap/yellow.png";
            r = ROWS + 2;
            c = 5;
            break;
        case T2:
            picName = "shap/yellow.png";
            r = ROWS + 3;
            c = 5;
            break;
        case T3:
            picName = "shap/yellow.png";
            r = ROWS + 2;
            c = 5;
            break;
        case T4:
            picName = "shap/yellow.png";
            r = ROWS + 3;
            c = 5;
            break;
            
        default:
            break;
    }
    
    this->b1 = CCSprite::create(picName.c_str());
    this->b2 = CCSprite::create(picName.c_str());
    this->b3 = CCSprite::create(picName.c_str());
    this->b4 = CCSprite::create(picName.c_str());
    
    this->row = r;
    this->col = c;
    
    relocation();
}

void Tetromino::relocation() {
    CCPoint b1Point ;
    CCPoint b2Point ;
    CCPoint b3Point ;
    CCPoint b4Point ;
    
    switch (this->subType) {
        case I1:
            I1_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case I2:
            I2_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LA1:
            LA1_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LA2:
            LA2_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LA3:
            LA3_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LA4:
            LA4_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LB1:
            LB1_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LB2:
            LB2_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LB3:
            LB3_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case LB4:
            LB4_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case O1:
            O_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case SA1:
            SA1_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case SA2:
            SA2_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case SB1:
            SB1_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case SB2:
            SB2_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case T1:
            T1_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case T2:
            T2_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case T3:
            T3_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
        case T4:
            T4_relocation(& b1Point, & b2Point, & b3Point, & b4Point);
            break;
            
        default:
            break;
    }
    
    b1->setPosition(Tetromino::GamePointConvertToPoint(b1Point, b1->getContentSize()));
    b2->setPosition(Tetromino::GamePointConvertToPoint(b2Point, b2->getContentSize()));
    b3->setPosition(Tetromino::GamePointConvertToPoint(b3Point, b3->getContentSize()));
    b4->setPosition(Tetromino::GamePointConvertToPoint(b4Point, b4->getContentSize()));
}

bool Tetromino::collide(Tetromino *t) {
    // 1 在屏幕外面
    // 2 当前位置已有DeadTetromino
    
    
    CCArray * blocks = t->getBlocks();
    CCSprite * sp;
    CCObject * o;
    CCARRAY_FOREACH(blocks, o) {
        sp = (CCSprite*)o;
        CCPoint point = Tetromino::PointConvertToGamePoint(sp->getPosition(), sp->getContentSize());
        
        if (World::shareWorld()->getSpriteWithPoint(point)) {
            return true;
        }
        if (point.x < 0 || point.x > 9 || point.y < 0) {
            return true;
        }
        
    }
    return false;

}

bool Tetromino::moveTetromino() {
    if (bottonHasSomething() == true)
        return false;
    
    this->row --;
    relocation();
    
    return true;
}

// 向下碰撞检测
bool Tetromino::bottonHasSomething() {
    CCPoint b1GamePoint = Tetromino::PointConvertToGamePoint(b1->getPosition(), b1->getContentSize());
    CCPoint b2GamePoint = Tetromino::PointConvertToGamePoint(b2->getPosition(), b2->getContentSize());
    CCPoint b3GamePoint = Tetromino::PointConvertToGamePoint(b3->getPosition(), b3->getContentSize());
    CCPoint b4GamePoint = Tetromino::PointConvertToGamePoint(b4->getPosition(), b4->getContentSize());
    if ((b1GamePoint.y <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b1GamePoint.x, b1GamePoint.y - 1))) ||
        (b2GamePoint.y <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b2GamePoint.x, b2GamePoint.y - 1))) ||
        (b3GamePoint.y <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b3GamePoint.x, b3GamePoint.y - 1))) ||
        (b4GamePoint.y <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b4GamePoint.x, b4GamePoint.y - 1)))) {
        return true;
    } else {
        return false;
    }
}

bool Tetromino::leftHasSomething() {
    CCPoint b1GamePoint = Tetromino::PointConvertToGamePoint(b1->getPosition(), b1->getContentSize());
    CCPoint b2GamePoint = Tetromino::PointConvertToGamePoint(b2->getPosition(), b2->getContentSize());
    CCPoint b3GamePoint = Tetromino::PointConvertToGamePoint(b3->getPosition(), b3->getContentSize());
    CCPoint b4GamePoint = Tetromino::PointConvertToGamePoint(b4->getPosition(), b4->getContentSize());
    if ((b1GamePoint.x <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b1GamePoint.x - 1, b1GamePoint.y))) ||
        (b2GamePoint.x <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b2GamePoint.x - 1, b2GamePoint.y))) ||
        (b3GamePoint.x <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b3GamePoint.x - 1, b3GamePoint.y))) ||
        (b4GamePoint.x <= 0 || World::shareWorld()->getSpriteWithPoint(ccp(b4GamePoint.x - 1, b4GamePoint.y)))) {
        return true;
    } else {
        return false;
    }

}

bool Tetromino::rightHasSomething() {
    CCPoint b1GamePoint = Tetromino::PointConvertToGamePoint(b1->getPosition(), b1->getContentSize());
    CCPoint b2GamePoint = Tetromino::PointConvertToGamePoint(b2->getPosition(), b2->getContentSize());
    CCPoint b3GamePoint = Tetromino::PointConvertToGamePoint(b3->getPosition(), b3->getContentSize());
    CCPoint b4GamePoint = Tetromino::PointConvertToGamePoint(b4->getPosition(), b4->getContentSize());
    if ((b1GamePoint.x >= 9 || World::shareWorld()->getSpriteWithPoint(ccp(b1GamePoint.x + 1, b1GamePoint.y))) ||
        (b2GamePoint.x >= 9 || World::shareWorld()->getSpriteWithPoint(ccp(b2GamePoint.x + 1, b2GamePoint.y))) ||
        (b3GamePoint.x >= 9 || World::shareWorld()->getSpriteWithPoint(ccp(b3GamePoint.x + 1, b3GamePoint.y))) ||
        (b4GamePoint.x >= 9 || World::shareWorld()->getSpriteWithPoint(ccp(b4GamePoint.x + 1, b4GamePoint.y)))) {
        return true;
    } else {
        return false;
    }
}

void Tetromino::moveLeft() {
    if (leftHasSomething()) {
        return;
    }
    col --;
    relocation();
}

void Tetromino::moveRight() {
    if (rightHasSomething()) {
        return;
    }
    col ++;
    relocation();
}

CCArray * Tetromino::getBlocks() {
    CCArray * array = CCArray::create();
    array->addObject(b1);
    array->addObject(b2);
    array->addObject(b3);
    array->addObject(b4);
    return array;
}

bool Tetromino::pointOnLeft(cocos2d::CCPoint p) {
    if ((p.x - b1->getPosition().x < 0 ) &&
        (p.x - b2->getPosition().x < 0) &&
        (p.x - b3->getPosition().x < 0) &&
        (p.x - b4->getPosition().x < 0)) {
        return true;
    }
    return false;
}

bool Tetromino::pointOnRight(cocos2d::CCPoint p) {
    if ((p.x - b1->getPosition().x > 0 ) &&
        (p.x - b2->getPosition().x > 0) &&
        (p.x - b3->getPosition().x > 0) &&
        (p.x - b4->getPosition().x > 0)) {
        return true;
    }
    return false;
}

bool Tetromino::pointOnDown(cocos2d::CCPoint p) {
    if ((p.y - b1->getPosition().y < 0 ) &&
        (p.y - b2->getPosition().y < 0) &&
        (p.y - b3->getPosition().y < 0) &&
        (p.y - b4->getPosition().y < 0)) {
        return true;
    }
    return false;
}

bool Tetromino::pointOnTetromino(cocos2d::CCPoint p) {
    CCRect r1 = this->b1->boundingBox();
    CCRect r2 = this->b2->boundingBox();
    CCRect r3 = this->b3->boundingBox();
    CCRect r4 = this->b4->boundingBox();
    if (r1.containsPoint(p) ||
        r2.containsPoint(p) ||
        r3.containsPoint(p) ||
        r4.containsPoint(p)) {
        return true;
    } else {
        return false;
    }
}

CCPoint Tetromino::PointConvertToGamePoint(cocos2d::CCPoint p, CCSize shapeSize) {
    int x = (p.x - shapeSize.width * 0.5) / shapeSize.width;
    int y = (p.y + shapeSize.height * 0.5) / shapeSize.height;
    return CCPointMake(x, y - 1);
}

CCPoint Tetromino::GamePointConvertToPoint(cocos2d::CCPoint p, CCSize shapeSize) {
    float x = p.x * shapeSize.width + shapeSize.width * 0.5;
    float y = (p.y + 1) * shapeSize.height - shapeSize.height * 0.5;
    return CCPointMake(x, y);
}

void Tetromino::deForm() {
    CCLog("before row:%d col %d", this->row, this->col);
    Tetromino * newTetro = Tetromino::create(I1);
    newTetro->row = this->row;
    newTetro->col = this->col;
    
    switch (subType) {
        case I1:
            newTetro->subType = I2;
            newTetro->row++;
            newTetro->col++;
            break;
        case I2:
            newTetro->subType = I1;
            newTetro->row--;
            newTetro->col--;
            break;
        case LA1:
            newTetro->subType = LA2;
            newTetro->row++;
            //newTetro->col++;
            break;
        case LA2:
            newTetro->subType = LA3;
            newTetro->row--;
            //newTetro->col++;
            break;
        case LA3:
            newTetro->subType = LA4;
            newTetro->row++;
            newTetro->col++;
            break;
        case LA4:
            newTetro->subType = LA1;
            newTetro->row--;
            newTetro->col--;
            break;
        case LB1:
            newTetro->subType = LB2;
            newTetro->row++;
            newTetro->col--;
            break;
        case LB2:
            newTetro->subType = LB3;
            newTetro->row -= 2;
            //newTetro->col++;
            break;
        case LB3:
            newTetro->subType = LB4;
            newTetro->row += 2;
            //newTetro->col++;
            break;
        case LB4:
            newTetro->subType = LB1;
            newTetro->row--;
            newTetro->col++;
            break;
            
        case O1:
            newTetro->subType = O1;
            break;
            
        case SA1:
            newTetro->subType = SA2;
            newTetro->row++;
            //newTetro->col++;
            break;
        case SA2:
            newTetro->subType = SA1;
            newTetro->row--;
            //newTetro->col++;
            break;
            
        case SB1:
            newTetro->subType = SB2;
            newTetro->row++;
            newTetro->col++;
            break;
        case SB2:
            newTetro->subType = SB1;
            newTetro->row--;
            newTetro->col--;
            break;
            
        case T1:
            newTetro->subType = T2;
            //newTetro->row--;
            //newTetro->col++;
            break;
        case T2:
            newTetro->subType = T3;
            newTetro->row--;
            newTetro->col--;
            break;
        case T3:
            newTetro->subType = T4;
            newTetro->row++;
            newTetro->col++;
            break;
        case T4:
            newTetro->subType = T1;
            //newTetro->row--;
            //newTetro->col++;
            break;
            
        default:
            break;
    }
    
    newTetro->relocation();
    
    if (collide(newTetro)) {
        CCLog("collide");
        return;
    } else {
        this->subType = newTetro->subType;
        this->row = newTetro->row;
        this->col = newTetro->col;
        relocation();
    }
    
    CCLog("after row:%d col %d", this->row, this->col);
    
    delete newTetro;

}


void Tetromino::I1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row;
    b3Point->x = col + 2;
    
    b4Point->y = row;
    b4Point->x = col + 3;
    
}

void Tetromino::I2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 2;
    b3Point->x = col;
    
    b4Point->y = row - 3;
    b4Point->x = col;
    
}

void Tetromino::LA1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 1;
    b3Point->x = col + 1;
    
    b4Point->y = row - 1;
    b4Point->x = col + 2;
    
}
void Tetromino::LA2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row - 1;
    b3Point->x = col;
    
    b4Point->y = row - 2;
    b4Point->x = col;
    
}
void Tetromino::LA3_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row;
    b3Point->x = col + 2;
    
    b4Point->y = row - 1;
    b4Point->x = col + 2;
    
}
void Tetromino::LA4_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 2;
    b3Point->x = col;
    
    b4Point->y = row - 2;
    b4Point->x = col - 1;
    
}
void Tetromino::LB1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 1;
    b3Point->x = col - 1;
    
    b4Point->y = row - 1;
    b4Point->x = col - 2;
    
}
void Tetromino::LB2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row ;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 2;
    b3Point->x = col;
    
    b4Point->y = row - 2;
    b4Point->x = col + 1;
    
}
void Tetromino::LB3_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row + 1;
    b2Point->x = col;
    
    b3Point->y = row + 1;
    b3Point->x = col + 1;
    
    b4Point->y = row + 1;
    b4Point->x = col + 2;
    
}
void Tetromino::LB4_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row - 1;
    b3Point->x = col + 1;
    
    b4Point->y = row - 2;
    b4Point->x = col + 1;
    
}
void Tetromino::O_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row - 1;
    b3Point->x = col + 1;
    
    b4Point->y = row - 1;
    b4Point->x = col;
    
}
void Tetromino::SA1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row + 1;
    b3Point->x = col + 1;
    
    b4Point->y = row + 1;
    b4Point->x = col + 2;
    
}
void Tetromino::SA2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 1;
    b3Point->x = col + 1;
    
    b4Point->y = row - 2;
    b4Point->x = col + 1;
    
}
void Tetromino::SB1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row - 1;
    b3Point->x = col + 1;
    
    b4Point->y = row - 1;
    b4Point->x = col + 2;
    
}
void Tetromino::SB2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 1;
    b3Point->x = col - 1;
    
    b4Point->y = row - 2;
    b4Point->x = col - 1;
    
}

void Tetromino::T1_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col - 1;
    
    b3Point->y = row - 1;
    b3Point->x = col;
    
    b4Point->y = row - 1;
    b4Point->x = col + 1;
    
}
void Tetromino::T2_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 1;
    b3Point->x = col + 1;
    
    b4Point->y = row - 2;
    b4Point->x = col;
    
}
void Tetromino::T3_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row;
    b2Point->x = col + 1;
    
    b3Point->y = row;
    b3Point->x = col + 2;
    
    b4Point->y = row - 1;
    b4Point->x = col + 1;
    
}
void Tetromino::T4_relocation(CCPoint * b1Point, CCPoint * b2Point, CCPoint * b3Point, CCPoint * b4Point) {
    b1Point->y = row;
    b1Point->x = col;
    
    b2Point->y = row - 1;
    b2Point->x = col;
    
    b3Point->y = row - 1;
    b3Point->x = col - 1;
    
    b4Point->y = row - 2;
    b4Point->x = col;
    
}




