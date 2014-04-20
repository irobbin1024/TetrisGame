//
//  MyDMInterstitialAdControllerDelegate.h
//  test_youmi
//
//  Created by 赖隆斌 on 14-4-16.
//
//

#import <Foundation/Foundation.h>
#import "DMInterstitialAdController.h"

@interface MyDMInterstitialAdControllerDelegate : NSObject <DMInterstitialAdControllerDelegate> 
// Sent when an ad request success to loaded an ad
- (void)dmInterstitialSuccessToLoadAd:(DMInterstitialAdController *)dmInterstitial;
// Sent when an ad request fail to loaded an ad
- (void)dmInterstitialFailToLoadAd:(DMInterstitialAdController *)dmInterstitial withError:(NSError *)err;
// Sent when the ad is clicked
- (void)dmInterstitialDidClicked:(DMInterstitialAdController *)dmInterstitial;

// Sent just before presenting an interstitial
- (void)dmInterstitialWillPresentScreen:(DMInterstitialAdController *)dmInterstitial;
// Sent just after dismissing an interstitial
- (void)dmInterstitialDidDismissScreen:(DMInterstitialAdController *)dmInterstitial;

// Sent just before presenting the user a modal view
- (void)dmInterstitialWillPresentModalView:(DMInterstitialAdController *)dmInterstitial;
// Sent just after dismissing the modal view.
- (void)dmInterstitialDidDismissModalView:(DMInterstitialAdController *)dmInterstitial;
// Sent just before the application will background or terminate because the user's action
// (Such as the user clicked on an ad that will launch App Store).
- (void)dmInterstitialApplicationWillEnterBackground:(DMInterstitialAdController *)dmInterstitial;
@end
