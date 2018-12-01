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

/*!
 *  返回识别对象的单例
 *
 *  @return 识别对象的单例
 */
+ (instancetype)sharedInstance;

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

@end

