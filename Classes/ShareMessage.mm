//
//  ShareMessage.cpp
//  test_ad_share
//
//  Created by 赖隆斌 on 14-4-15.
//
//

#include "ShareMessage.h"

bool ShareMessage::init() {
    
    return true;
}

void ShareMessage::setText(std::string text) {
    this->_text = text;
}

std::string ShareMessage::getText() {
    return _text;
}

void ShareMessage::setImage(UIImage * image) {
    this->_image = image;
}

UIImage * ShareMessage::getImage() {
    return _image;
}

void ShareMessage::setDelegate(id <UMSocialUIDelegate> delegate) {
    this->_delegate = delegate;
}

id<UMSocialUIDelegate> ShareMessage::getDelegate() {
    return _delegate;
}
