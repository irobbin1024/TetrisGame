//
//  ADManger.h
//  test_youmi
//
//  Created by 赖隆斌 on 14-4-16.
//
//

#ifndef __test_youmi__ADManger__
#define __test_youmi__ADManger__

#include <iostream>
#include "CocosGUI.h"
#import <UIKit/UIKit.h>
#import "DMInterstitialAdController.h"

class ADManger {

#define INIT_WITH_PUBLISHERID   "56OJyM1ouMGoULfJaL"
#define PLACEMENTID             "16TLwebvAchkAY6iOWkE6kpk"
    
public:
    static ADManger * instance(void);
    
    void loadAD();

protected:
    ADManger(void) {}
    virtual ~ADManger(void) {}
    static ADManger * _instance;
    
    // ========================
    // 根视图
    UIViewController * _uiViewController = NULL;
    // 多盟广告控制器
    DMInterstitialAdController *_dmInterstitial;
    // 多盟广告代理
    NSObject<DMInterstitialAdControllerDelegate> * dmDelegate;
    // 广告大小
    CGSize adSize;
    // Domob PublisherId
    std::string initWithPublisherId;
    // Domob PlacementId
    std::string placementId;
    
    // =========================
    void initInterstitial();
public:
    void show();
    
    // =========================
    // setter
    void setUIViewController(UIViewController * uiViewController);
    void setDMDelegate(NSObject<DMInterstitialAdControllerDelegate> * _delegate);
    void setADSize(CGSize size);
    void setInitWithPublisherId(std::string id);
    void setPlacementId(std::string id);
};



#endif /* defined(__test_youmi__ADManger__) */
