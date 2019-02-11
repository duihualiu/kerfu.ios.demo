//
//  NADialogManager.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/31.
//  Copyright © 2018 Naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KFDialogRequest.h"
#import "KFDialogResponse.h"

@class KFDialogRequest,KFDialogResponse;

typedef void (^NADialogRequestCompletion) (BOOL success, NSError *error, NSString *requestId);
typedef void (^NATDialogUploadProgress)(float uploadProgress, NSString *requestId);

@protocol KFDialogFlowDelegate <NSObject>

/**
 收到的消息的回调

 @param response 用户发送成功的消息及服务器回复的消息都会通过此方法回调给用户，同时存入本地历史消息中
 */
- (void)didReceiveResponse:(KFDialogResponse *)response;

@end

/**
 实现对话流专用的管理类
 */
@interface KFDialogManager : NSObject

/**
 需要设置实现NADialogFlowDelegate协议的代理对象,用以监听所有接收到的消息
 */
@property (nonatomic, weak) id<KFDialogFlowDelegate> delegate;


/**
 无论如何,请使用该类的单例对象并设置delegate对象监听消息
 */
+ (instancetype)sharedInstance;

/**
 调用本方法以保持服务器的消息连接
 */
- (void)keepConnection;

/**
 重置连接
 */
- (void)resetConnection;

/**
 发送消息

 @param request 需要发送消息对象
 @param completion 反馈消息是否发送成功，回复的消息将通过delegate监听接收
 */
- (void)sendDialogRequest:(KFDialogRequest *)request compeltion:(NADialogRequestCompletion)completion;

/**
 发送消息
 
 @param request 需要发送消息对象
 @param uploadProgress 若发送的消息包含多媒体资源，可传入此block监听资源上传的进度
 @param completion 反馈消息是否发送成功，回复的消息将通过delegate监听接收
 */
- (void)sendDialogRequest:(KFDialogRequest *)request uploadProgress:(NATDialogUploadProgress)uploadProgress compeltion:(NADialogRequestCompletion)completion;

/**
 向服务agent发送开始对话的信号

 @param agentId app在平台上注册的服务agentId
 @param completion 信号发送成功与否的回调，发送成功的话，delegate将接收到agent回复的欢迎语
 */
- (void)fetchWelcomeMessageWithAgentId:(NSString *)agentId compeltion:(NADialogRequestCompletion)completion;


/**
 结束与agent的对话上下文，再次发送对agnetId发送的消息可开始新的对话

 @param agentId 需要结束对话的agentId
 @param completion 结束请求成功与否的d回调.
 */
- (void)endConversationWithAgentId:(NSString *)agentId compeltion:(NADialogRequestCompletion)completion;

/**
 加载设定用户的历史消息列表
 */
- (NSArray<KFDialogResponse *> *)loadHistoryMessages;

/**
 删除对应messageId的消息，成功则返回true
 */
- (BOOL)deleteMessage:(NSString *)messageId;

@end
