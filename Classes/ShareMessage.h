//
//  ShareMessage.h
//  test_ad_share
//
//  Created by 赖隆斌 on 14-4-15.
//
//

#ifndef __test_ad_share__ShareMessage__
#define __test_ad_share__ShareMessage__

#include <iostream>
#import <UIKit/UIImage.h>
#include "CocosGUI.h"
#include "cocos2d.h"
#import "UMSocial.h"

USING_NS_CC;

class ShareMessage : public CCObject{
public:
    virtual bool init();
    CREATE_FUNC(ShareMessage)
public:
    //===========================
    // 设置文本信息
    void setText(std::string text);
    std::string getText();
    
    //===========================
    // 设置图片信息
    void setImage(UIImage * image);
    UIImage * getImage();
    
    //===========================
    // 设置代理
    void setDelegate(id<UMSocialUIDelegate> delegate);
    id<UMSocialUIDelegate> getDelegate();
    
protected:
    std::string _text;
    UIImage * _image;
    id<UMSocialUIDelegate> _delegate;
};


#endif /* defined(__test_ad_share__ShareMessage__) */
