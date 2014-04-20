#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Tetromino.h"
#include "Hero.h"

#define COLS 10
#define ROWS 15
#define SCORE_LABEL_TAG 101
#define PASUMENU_MENU_TAG 102

class World : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(World);
    
    static World * shareWorld();
    
    Tetromino * getCurrentTetromino();
    
    CCArray * getDeadTetronimo();
    
    CCSprite * getSpriteWithPoint(CCPoint p);
    
    void lostGame();
    
    // 返回主菜单 回调
    void backMenu();
    
    // 重试 回调
    void retry();
    
    // 分享 回调
    void share();
    
    void produceTetromino();
    
    void disappear();
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual void ccTouchMoved(cocos2d::CCTouch * touch, cocos2d::CCEvent * event);
    virtual bool ccTouchBegan(cocos2d::CCTouch * touch, cocos2d::CCEvent * event);
    virtual void ccTouchEnded(cocos2d::CCTouch * touch, cocos2d::CCEvent * event);
    
    

private:
    
    cocos2d::CCArray * deadTetromino;
    
    Tetromino * currentTetromino;
    
    Hero * _hero;
    
    void addDeadTetromino(Tetromino * t);
    
    bool isGameOver();
    
    
    void update(float time);
    
    void moveCurrentTetromino();
    
    // 单个方块死亡动画
    void playBitDead(CCSprite * bit);
    // 死亡动画播放完执行回调删除方块
    void playBitDeadCallback(CCNode * node);
    // 更新分数信息
    void updateAndShowScore();
    // 暂停 回调
    void pauseCallback();
    // 恢复 回调
    void playCallback();

    virtual ~World();
};

#endif // __HELLOWORLD_SCENE_H__
