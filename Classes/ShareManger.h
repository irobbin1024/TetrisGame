//
//  ShareManger.h
//  test_ad_share
//
//  Created by 赖隆斌 on 14-4-15.
//
//

#ifndef __test_ad_share__ShareManger__
#define __test_ad_share__ShareManger__

#include <iostream>
#include "ShareMessage.h"

class ShareManger {
#define UM_WEBCHAT_KEY "wxd9a39c7122aa6516"
#define APP_KEY "5346405656240b070b101c6d"

public:
    static ShareManger * instance(void);
    // ========================
    // 展示分享
    void show(ShareMessage * message);
protected:
    ShareManger(void) {}
    virtual ~ShareManger(void) {}
    static ShareManger * _instance;
    
    //=========================
    // 根视图
    UIViewController * _uiViewController = NULL;
    //=========================
    // appKey
    std::string _appKey = "";
    // ========================
    // 平台Key
    std::string _sinaKey = "";
    std::string _webchatKey = "";
    std::string _qqKey = "";
public:
    // ========================
    // 注册appkey
    void registerAppKey();
    // ========================
    // 为友盟注册各开放平台key
    void registerOpenPlatformKey();
    
    void setUIViewController(UIViewController * uiViewController);
    void setAppKey(std::string appKey);
    void setSinaKey(std::string sinaKey);
    void setWebchatKey(std::string webchatKey);
    void setQQKey(std::string qqKey);
};

#endif /* defined(__test_ad_share__ShareManger__) */
