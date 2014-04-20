#include "WorldScene.h"
#include "SimpleAudioEngine.h"
#include "Tetromino.h"
#include "HMenu.h"
#include "BackgroundLayer.h"
#include "RetryGameScene.h"
#include "Hero.h"
#include "ShareManger.h"
#include "ShareMessage.h"
#include "ADManger.h"

USING_NS_CC;

static World * world;

CCScene* World::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    World *layer = World::create();
    
    // background
    BackgroundLayer * bgLayer = BackgroundLayer::create();
    

    scene->addChild(bgLayer);
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

World * World::shareWorld() {
    if (world != NULL) {
        return world;
    }
    return NULL;
}

// on "init" you need to initialize your instance
bool World::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    
    world = this;
    _hero = new Hero;
  
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    // 播放背景音乐
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("other/gameMusic.mp3", true);
    
    // 显示分数label
    CCLabelTTF * scoreLabel = CCLabelTTF::create("", "Helvetica-Bold", 30);
    scoreLabel->setTag(SCORE_LABEL_TAG);
    this->addChild(scoreLabel);
    updateAndShowScore();
    
    
    deadTetromino = CCArray::create();
    CC_SAFE_RETAIN(deadTetromino);
    
    produceTetromino();
    
    
    return true;
}

void World::updateAndShowScore() {
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF * scoreLabel = (CCLabelTTF *)this->getChildByTag(SCORE_LABEL_TAG);
    CCString  scoreString = "";
    scoreString.initWithFormat("score：%ld", _hero->getScore());
    scoreLabel->setString(scoreString.getCString());
    scoreLabel->setPosition(ccp(scoreLabel->getContentSize().width * 0.5 + 20, size.height -  scoreLabel->getContentSize().height * 0.5 - 20));
}


void World::update(float time) {
}

void World::moveCurrentTetromino() {
   if (this->currentTetromino != NULL) {
        if (!this->currentTetromino->moveTetromino()) {
            addDeadTetromino(this->currentTetromino);
            currentTetromino = NULL;
            disappear();
            produceTetromino();
            
            if (isGameOver()) {
                if (_hero->getScore() > Hero::getMaxScore()) {
                    Hero::setMaxScore(_hero->getScore());
                }
                
                lostGame();
            }
        }
    }
}

void World::addDeadTetromino(Tetromino *t) {
    CCArray * blocks = t->getBlocks();
    CCObject * o;
    
    CCARRAY_FOREACH(blocks, o) {
        CCSprite * sp = (CCSprite *)o;
        this->deadTetromino->addObject(sp);
    }
}


CCArray * World::getDeadTetronimo() {
    return this->deadTetromino;
}

void World::produceTetromino() {
    TetrominoSubType type;
    //O1 = 0, I1 = 1, I2 = 2, LA1 = 3, LA2 = 4, LA3 = 5, LA4 = 6, LB1 = 7, LB2 = 8, LB3 = 9, LB4 = 10, SA1 = 11, SA2 = 12, SB1 = 13, SB2 = 14, T1 = 15, T2 = 16, T3 = 17, T4 = 18
    //int i = (int)(CCRANDOM_0_1() * 1000) % 19;
    int i = arc4random() % 19;
    switch (i) {
        case 0:
            type = O1;
            break;
        case 1:
            type = I1;
            break;
        case 2:
            type = I2;
            break;
        case 3:
            type = LA1;
            break;
        case 4:
            type = LA2;
            break;
        case 5:
            type = LA3;
            break;
        case 6:
            type = LA4;
            break;
        case 7:
            type = LB1;
            break;
        case 8:
            type = LB2;
            break;
        case 9:
            type = LB3;
            break;
        case 10:
            type = LB4;
            break;
        case 11:
            type = SA1;
            break;
        case 12:
            type = SA2;
            break;
        case 13:
            type = SB1;
            break;
        case 14:
            type = SB2;
            break;
        case 15:
            type = T1;
            break;
        case 16:
            type = T2;
            break;
        case 17:
            type = T3;
            break;
        case 18:
            type = T4;
            break;
            
        default:
            break;
    }
    
    Tetromino * t = Tetromino::create(type);
    this->currentTetromino = t;
    
    CCObject * o;
    CCArray * allSprite = this->currentTetromino->getBlocks();
    CCARRAY_FOREACH(allSprite, o) {
        CCSprite * sp = (CCSprite*)o;
        this->addChild(sp);
    }
}

void World::disappear() {
    int rows = 0;
    
    for (int row = 0; row < ROWS;) {
        bool canDisapear = true;
        for (int col = 0; col < COLS; col++) {
            CCSprite * sp = World::getSpriteWithPoint(ccp(col, row));
            if (sp == NULL) {
                canDisapear = false;
                continue;
            }
        }
        
        // 将第row行所有sprite移除
        // 可以消第 row 行。将 row + 1 行向下移动。
        if (canDisapear) {
            rows ++;
            
            for (int o = 0; o < COLS; o++) {
                CCSprite * s = World::getSpriteWithPoint(ccp(o, row));
                // 这边开始播放死亡动画(动画包含移除）
                // playBitDead(s);
                this->removeChild(s);
                this->deadTetromino->removeObject(s);
            }
            
            for (int row2 = row + 1; row2 < ROWS; row2++) {
                for (int col2 = 0; col2 < COLS; col2++) {
                    CCSprite * sp = World::getSpriteWithPoint(ccp(col2, row2));
                    if (sp != NULL) {
                        sp->setPosition(Tetromino::GamePointConvertToPoint(ccp(col2, row2 - 1), sp->getContentSize()));
                    }
                }
            }
            
            _hero->goal();
        } else {
            row ++;
        }
        
    }
    
    if (rows > 0) CCLog("disapear count %d", rows);
}

void World::playBitDead(cocos2d::CCSprite *bit) {
    
    CCFadeOut * faceOut = CCFadeOut::create(0.2);
    CCCallFuncN * callback = CCCallFuncN::create(this, callfuncN_selector(World::playBitDeadCallback));
    CCSequence * actions = CCSequence::create(faceOut, callback, NULL);
    
    bit->runAction(actions);
    
}

void World::playBitDeadCallback(CCNode * node) {
    //CCSprite * sp = (CCSprite *)this->getChildByTag(WILL_REMOVE_BIT_TAG);
    this->removeChild(node);
    this->deadTetromino->removeObject(node);
}

bool World::isGameOver() {
    bool isGameOver = false;
    
    for (int col = 0; col < COLS; col ++) {
        if (getSpriteWithPoint(ccp(col, ROWS - 1))) {
            isGameOver = true;
            break;
        }
    }
    
    return isGameOver;
}

Tetromino * World::getCurrentTetromino() {
    return currentTetromino;
}

CCSprite * World::getSpriteWithPoint(CCPoint p) {
    CCObject * o;
    CCArray * allDead =this->deadTetromino;
    
    CCARRAY_FOREACH(allDead , o) {
        CCSprite * sp = (CCSprite *)o;
        CCPoint oPoint = Tetromino::PointConvertToGamePoint(sp->getPosition(), sp->getContentSize());
        
        if (oPoint.x == p.x && oPoint.y == p.y) {
            return sp;
        }
    }
    
    return NULL;
}

//
////游戏失败
void World::lostGame(){
    //添加失败界面
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 190), size.width, size.height);
    CCSprite* sp = CCSprite::create("game_lost.png");
    sp->setScaleX(size.width / sp->getContentSize().width);
    sp->setScaleY(1.5);
    sp->setPosition(ccp(size.width*0.5,size.height*0.5));
    layer->addChild(sp);
    addChild(layer,100);
    
    //添加一个按钮用于返回Menu
    CCLabelTTF* ttback =CCLabelTTF::create("返回主菜单", "Helvetica-Bold", 40);
    CCMenuItemLabel* menuLabel= CCMenuItemLabel::create(ttback, this, menu_selector(World::backMenu));
    menuLabel->setPosition(ccp(-100,-200));
    
    //添加一个按钮用于重试
    CCLabelTTF* retry =CCLabelTTF::create("重试", "Helvetica-Bold", 40);
    CCMenuItemLabel* menuRetry= CCMenuItemLabel::create(retry, this, menu_selector(World::retry));
    menuRetry->setPosition(ccp(150,-200));
    
    // 分享
    CCLabelTTF* share =CCLabelTTF::create("分享", "Helvetica-Bold", 40);
    CCMenuItemLabel* menushare= CCMenuItemLabel::create(share, this, menu_selector(World::share));
    menushare->setPosition(ccp(50,-200));
    
    // 分数显示
    CCString  scoreString = "";
    scoreString.initWithFormat("您的分数是：%ld", _hero->getScore());
    CCLabelTTF * scoreLabel = CCLabelTTF::create(scoreString.getCString(), "Helvetica-Bold", 30);
    scoreLabel->setPosition(ccp(350, 370));
    
    
    CCMenu* menu =CCMenu::create(menuLabel,menuRetry, menushare, NULL);
    
    layer->addChild(menu,100);
    layer->addChild(scoreLabel);
    
    ADManger::instance()->show();
    
    //暂停游戏
    CCDirector::sharedDirector()->pause();
}

void World::retry() {
    this->unscheduleAllSelectors();
    //继续游戏
    CCDirector::sharedDirector()->resume();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, RetryGameScene::scene()));
    
}

//菜单项"返回主菜单"的回调函数
void World::backMenu(){
    this->unscheduleAllSelectors();
    //继续游戏
    CCDirector::sharedDirector()->resume();
    //切换到"菜单"场景
    CCDirector::sharedDirector()->replaceScene(HMenu::scene());
}

void World::share() {
    CCString sayString;
    sayString.initWithFormat("我在TetrisGame中达到了 %ld 的高分！！你能比我更高吗！", _hero->getScore());
    
    ShareManger * shareManger = ShareManger::instance();
    ShareMessage * message = ShareMessage::create();
    message->setText(sayString.getCString());
    message->setImage([UIImage imageNamed:@"menu_background.jpg"]);
    message->setDelegate(nil);
    
    shareManger->show(message);
}

void World::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    //CCLog("moved");
}

void World::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    
    if (currentTetromino->pointOnTetromino(touch->getLocation())) {
        currentTetromino->deForm();
    } else if (currentTetromino->pointOnDown(touch->getLocation())) {
        currentTetromino->moveTetromino();
    } else if (currentTetromino->pointOnLeft(touch->getLocation())) {
        currentTetromino->moveLeft();
    } else if (currentTetromino->pointOnRight(touch->getLocation())) {
        currentTetromino->moveRight();
    }
    
}


bool World::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event) {
    //CCLog("began");
    return true;
}

void World::onEnter() {
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
    
    this->schedule(schedule_selector(World::moveCurrentTetromino), 0.5);
    
    
}

void World::onExit() {
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
//    this->unschedule(schedule_selector(World::moveCurrentTetromino));
    //this->unscheduleAllSelectors();
}

World::~World() {
    CC_SAFE_RELEASE(this->deadTetromino);
}

