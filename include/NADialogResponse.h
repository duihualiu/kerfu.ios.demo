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
typedef NS_ENUM(NSInteger, NIMessageType) {
    NIMessageTypeText         = 0,
    NIMessageTypeImage        = 1,
    NIMessageTypeAudio        = 2,
    NIMessageTypeVideo        = 3,
    NIMessageTypeLink         = 4,
    NIMessageTypeMixed        = 5,
    NIMessageTypeOther        = 6,
};

@interface NADialogResponse : NSObject

@property (nonatomic, copy  ) NSString            *messageId;
@property (nonatomic, assign) double              createTime;
@property (nonatomic, copy  ) NSString            *userId;
@property (nonatomic, copy  ) NSString            *serviceId;
@property (nonatomic, assign) NIMessageType       messageType;
@property (nonatomic, copy  ) NSString            *title;
@property (nonatomic, copy  ) NSString            *content;
@property (nonatomic, copy  ) NSString            *imageUrl;
@property (nonatomic, copy  ) NSString            *audioData;
@property (nonatomic, copy  ) NSString            *videoUrl;
@property (nonatomic, copy  ) NSString            *linkUrl;
@property (nonatomic, copy  ) NSString            *otherData;

@end
