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
    NATMessageTypeText         = 0, //纯文本消息
    NATMessageTypeImage        = 1, //图片消息
    NATMessageTypeAudio        = 2, //音频消息
    NATMessageTypeVideo        = 3, //视频消息
    NATMessageTypeLink         = 4, //链接消息
    NATMessageTypeMixed        = 5, //混合消息，包含以上消息类型中的两种或多种
    NATMessageTypeOther        = 6, //其他消息，留作备用
};

typedef NS_ENUM(NSInteger, NATMessageSenderType) {
    NATMessageSenderTypeUser  = 0, //消息发送者为用户
    NATMessageSenderTypeAgent = 1, //消息发送者为agent
};

@interface NATDialogResponse : NSObject

/**
 若response为用户发送成功的消息，则发送时传入或生成的requestId将会通过此处传回
 */
@property (nonatomic, copy ) NSString             *requestId;

/**
 为回复消息下发的id
 */
@property (nonatomic, copy  ) NSString            *messageId;

/**
 服务器为对话下发的对话id
 */
@property (nonatomic, copy  ) NSString            *sessionId;

/**
 消息的创建时间戳,毫秒级
 */
@property (nonatomic, assign) double              createTime;

/**
 消息接收者的userId
 */
@property (nonatomic, copy  ) NSString            *userId;

/**
 回复消息的agentId
 */
@property (nonatomic, copy  ) NSString            *agentId;

/**
 消息类型
 */
@property (nonatomic, assign) NATMessageType      messageType;

/**
 消息发送者类型
 */
@property (nonatomic, assign) NATMessageSenderType senderType;

/**
 消息的标题，混合消息时有值
 */
@property (nonatomic, copy  ) NSString            *title;

/**
 消息的文本内容
 */
@property (nonatomic, copy  ) NSString            *content;

/**
 消息的图片资源地址
 */
@property (nonatomic, copy  ) NSString            *imageUrl;

/**
 消息的音频资源地址
 */
@property (nonatomic, copy  ) NSString            *audioUrl;

/**
 消息的视频资源地址
 */
@property (nonatomic, copy  ) NSString            *videoUrl;

/**
 消息含有网络链接时的地址字段
 */
@property (nonatomic, copy  ) NSString            *linkUrl;

/**
 推荐回复agent本条消息的候选内容列表
 */
@property (nonatomic, copy  ) NSArray<NSString *>   *candidates;
/**
 消息的其他附加信息，留作备用
 */
@property (nonatomic, copy  ) NSString            *otherData;

@end
