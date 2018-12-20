//
//  NIMessage.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/22.
//  Copyright © 2018 naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 消息类型
 */
typedef NS_ENUM(NSInteger, NATMessageType) {
    NATMessageTypeText         = 0,
    NATMessageTypeImage        = 1,
    NATMessageTypeAudio        = 2,
    NATMessageTypeVideo        = 3,
    NATMessageTypeLink         = 4,
    NATMessageTypeMixed        = 5,
    NATMessageTypeOther        = 6,
};

@interface NATDialogResponse : NSObject

@property (nonatomic, copy  ) NSString            *messageId;
@property (nonatomic, assign) double              createTime;
@property (nonatomic, copy  ) NSString            *userId;
@property (nonatomic, copy  ) NSString            *agentId;
@property (nonatomic, assign) NATMessageType      messageType;
@property (nonatomic, copy  ) NSString            *title;
@property (nonatomic, copy  ) NSString            *content;
@property (nonatomic, copy  ) NSString            *imageUrl;
@property (nonatomic, copy  ) NSString            *audioUrl;
@property (nonatomic, copy  ) NSString            *videoUrl;
@property (nonatomic, copy  ) NSString            *linkUrl;
@property (nonatomic, copy  ) NSString            *otherData;

@end
