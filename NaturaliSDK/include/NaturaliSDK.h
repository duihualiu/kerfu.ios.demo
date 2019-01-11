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
#import "NATDynamicEntity.h"

@interface NaturaliSDK : NSObject

/**
 注册app于naturali开放平台上的参数

 @param appId 平台注册的appId
 @param appKey 平台发放的appKey
 @param appSecret 平台发放的appsSecret
 */
+ (void)registerAppId:(NSString *)appId
               appKey:(NSString *)appKey
            appSecret:(NSString *)appSecret;


/**
 设置用户id

 @param userId sdk集成者可使用自己app用户体系中的userId
 */
+ (void)setUserId:(NSString *)userId;

/**
 为设置的userId添加动态实体

 @param entities 动态实体数组
 */
+ (void)addDynamicEntities:(NSArray<NATDynamicEntity *> *)entities;

/**
 为指定的userId添加动态实体

 @param entities 动态实体数组
 @param userId 指定userId
 */
+ (void)addDynamicEntities:(NSArray<NATDynamicEntity *> *)entities forUserId:(NSString *)userId;

@end
