//
//  NATSpeechRecognizer.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/30.
//  Copyright © 2018 naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NATSpeechRecognizerDelegate.h"

@interface NATSpeechRecognizer : NSObject

/*!
 *  设置委托对象
 */
@property(nonatomic,weak) id<NATSpeechRecognizerDelegate> delegate;

/**
 初始化方法，需传入delegate对象以监听状态及返回
 */
- (instancetype)initWithDelegate:(id<NATSpeechRecognizerDelegate>)delegate;

/*!
 *  开始识别
 *  @return 成功返回YES；失败返回NO
 */
- (BOOL)startRecording;

/*!
 *  停止录音
 *  调用此函数会停止录音，并开始进行语音识别
 */
- (void)stopRecording;

/*!
 *  取消本次会话
 */
- (void)cancelRecording;


/**
 直接以语音形式发起与对应agent对话的请求,发送成功的消息及收到的回复均会回调NADialogFlowDelegate的"didReceiveResponse:"方法.
 传入的agentId或sessionId至少一个不为空.

 @param agentId 传入需要对话的agentId
 @param sessionId 传入需要对话的sessionId
 @return 成功返回YES；失败返回NO
 */
- (BOOL)startDialogRecordingWithAgentId:(NSString *)agentId;

@end

