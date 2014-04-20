//
//  ADManger.cpp
//  test_youmi
//
//  Created by 赖隆斌 on 14-4-16.
//
//

#include "ADManger.h"
#include "MyDMInterstitialAdControllerDelegate.h"

ADManger * ADManger::_instance = NULL;

ADManger * ADManger::instance() {
    if (_instance == NULL) {
        _instance = new ADManger;
        
        // 初始化尺寸
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
        {
            _instance->adSize = DOMOB_AD_SIZE_300x250;
        }
        else
        {
            _instance->adSize = DOMOB_AD_SIZE_600x500;
        }
        
        _instance->initWithPublisherId = INIT_WITH_PUBLISHERID;
        _instance->placementId = PLACEMENTID;
        _instance->dmDelegate = [[MyDMInterstitialAdControllerDelegate alloc] init];
        

    }
    return _instance;
}

void ADManger::setUIViewController(UIViewController *uiViewController) {
    this->_uiViewController = uiViewController;
    
    initInterstitial();
}

void ADManger::initInterstitial() {
    // 没有视图控制器无法初始化
    if (_uiViewController == NULL) {
        return;
    }
    _dmInterstitial = [[DMInterstitialAdController alloc] initWithPublisherId:[NSString stringWithUTF8String:this->initWithPublisherId.c_str()]
                                                                             placementId:[NSString stringWithUTF8String:this->placementId.c_str()]
                                                                      rootViewController:this->_uiViewController
                                                                                    size:adSize];
    // 预加载广告资源
    loadAD();
    _dmInterstitial.delegate = dmDelegate;
}

void ADManger::show() {
    if (_dmInterstitial == nil) {
        CCLOG("没有初始化");
        return;
    }
    if (_dmInterstitial.isReady)
    {
        // present advertisement view
        [_dmInterstitial present];
        //
    }
    else
    {
        // if !ready load again
        [_dmInterstitial loadAd];
    }
}

void ADManger::loadAD() {
    [_dmInterstitial loadAd];
}

void ADManger::setDMDelegate(NSObject<DMInterstitialAdControllerDelegate> * _delegate) {
    dmDelegate = _delegate;
}
void ADManger::setADSize(CGSize size) {
    adSize = size;
}
void ADManger::setInitWithPublisherId(std::string id) {
    initWithPublisherId = id;
}
void ADManger::setPlacementId(std::string id) {
    placementId = id;
}


