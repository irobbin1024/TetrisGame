//
//  Hero.h
//  TetrisGame
//
//  Created by 赖隆斌 on 14-4-10.
//
//

#ifndef __TetrisGame__Hero__
#define __TetrisGame__Hero__

#include <iostream>


#define SCORE_OF_ROW 10
#define SCORE_KEY "score"

class Hero {
public:
    static long getMaxScore();
    static void setMaxScore(long score);
    
    void goal();
    long getScore();
private:
    long _score = 0;
};

#endif /* defined(__TetrisGame__Hero__) */
