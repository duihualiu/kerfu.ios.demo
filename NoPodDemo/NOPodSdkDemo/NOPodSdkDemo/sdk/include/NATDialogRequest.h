//
//  NADialogRequest.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/26.
//  Copyright © 2018 naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NATDialogRequest : NSObject

/**
 用户可给此属性赋值，应保证此值的唯一性，若未赋值，在请求发出时将自动生成requestId,并在请求的回调和接收发送成功的消息中传回，以达成请求与回复的匹配。
 */
@property (nonatomic, copy) NSString *requestId;

/**
 发送消息的用户id，若不传，则默认为NaturaliSDK.h中设置的userId
 */
@property (nonatomic, copy) NSString *userId;

/**
 平台的服务agentId
 */
@property (nonatomic, copy) NSString *agentId;

/**
 会话id，会话场景的id，服务器回复消息时会发放sessionId，若已通过收到的消息获得sessionId，则该会话中再次发送消息请求可传入该消息sessionId，若不传，则服务器根据userId和agentId等参数生成sessionId并在返回发送成功的消息时下发。
 */
@property (nonatomic, copy) NSString *sessionId;
/**
 发送消息的文本
 */
@property (nonatomic, copy) NSString *query;

/**
 音频资源的本地路径可为nil
 */
@property (nonatomic, copy) NSString *audioFilePath;

/**
 图片资源的本地路径，可为nil
 */
@property (nonatomic, copy) NSString *imageFilePath;

/**
 视频资源的本地路径，可为nil
 */
@property (nonatomic, copy) NSString *videoFilePath;

/**
 音频资源的url地址，可为nil
 */
@property (nonatomic, copy) NSString *audioUrl;

/**
 图片资源的url地址，可为nil
 */
@property (nonatomic, copy) NSString *imageUrl;

/**
 视频资源的url地址，可为nil
 */
@property (nonatomic, copy) NSString *videoUrl;

/**
 其他附加数据，预留为特殊对话备用
 */
@property (nonatomic, copy) NSString *extraData;

@end

