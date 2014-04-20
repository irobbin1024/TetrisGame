#import "RootViewController.h"
#import "UMSocialWechatHandler.h"
#import "UMSocial.h"
#include "ShareManger.h"



ShareManger * ShareManger::_instance = NULL;

ShareManger * ShareManger::instance() {
    if (_instance == NULL) {
        _instance = new ShareManger;
        
        // 由于微信是必须设置的key。所以这边初始化时设置为友盟官方Key
        [UMSocialWechatHandler setWXAppId:[NSString stringWithUTF8String:UM_WEBCHAT_KEY] url:nil];
    }
    return _instance;
}

void ShareManger::show(ShareMessage * message) {
    if (message == NULL || _appKey.empty()) {
        return;
    }
    
    registerOpenPlatformKey();
    
    [UMSocialConfig setSupportedInterfaceOrientations:UIInterfaceOrientationMaskAll];
    [UMSocialSnsService presentSnsIconSheetView:_uiViewController
                                         appKey:[NSString stringWithUTF8String:_appKey.c_str()]
                                      shareText:[NSString stringWithUTF8String:message->getText().c_str()]
                                     shareImage:message->getImage()
                                shareToSnsNames:[NSArray arrayWithObjects:UMShareToWechatTimeline, UMShareToWechatFavorite, UMShareToSina,UMShareToQzone, nil]
                                       delegate:message->getDelegate()];
}

void ShareManger::registerAppKey() {
    [UMSocialData setAppKey:[NSString stringWithUTF8String:_appKey.c_str()]];
}

void ShareManger::registerOpenPlatformKey() {
    if (!_webchatKey.empty()) {
        [UMSocialWechatHandler setWXAppId:[NSString stringWithUTF8String:_webchatKey.c_str()] url:nil];
    }
    
    if (!_sinaKey.empty()) {
        
    }
    
    if (!_qqKey.empty()) {
        
    }
}


void ShareManger::setUIViewController(UIViewController *uiViewController) {
    _uiViewController = uiViewController;
}

void ShareManger::setAppKey(std::string appKey) {
    _appKey = appKey;
    registerAppKey();
}

void ShareManger::setSinaKey(std::string sinaKey) {
    _sinaKey = sinaKey;
}
void ShareManger::setWebchatKey(std::string webchatKey) {
    _webchatKey = webchatKey;
}
void ShareManger::setQQKey(std::string qqKey) {
    _qqKey = qqKey;
}

