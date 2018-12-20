//
//  NaturaliSDK.h
//  NaturaliSDK
//
//  Created by 方懿 on 2018/11/30.
//  Copyright © 2018 Naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NATSpeechRecognizer.h"
#import "NATSpeechRecognizerDelegate.h"
#import "NATDialogManager.h"

@interface NaturaliSDK : NSObject

+ (instancetype)sharedInstance;
+ (void)registerAppId:(NSString *)inAppId appSecrit:(NSString *)appSecret;
+ (void)setUserId:(NSString *)userId;

@end
