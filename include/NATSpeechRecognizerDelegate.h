//
//  NATSpeechRecognizerDelegate.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/30.
//  Copyright © 2018 naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NATSpeechRecognizerDelegate <NSObject>

@required

/**
 录音转文字完成或者过程因错误中断都会回调此函数。

 @param error 若因某些错误中断，则返回error对象，若转文字过程完成，则返回nil。
 */
- (void)onCompleted:(NSError *)error;

/**
 录音过程输出的文字

 @param result 随着语音的录制持续输出匹配度最高的结果.
 @param isDone 当调用"stopRecording"后，语音录制过程结束，此时转文字输出isDone值为YES,否则为NO.
 */
- (void)onResult:(NSString *)result isDone:(BOOL)isDone;

@optional

/*!
 *  开始录音
 *  当调用了`startRecording`函数之后，如果没有发生错误则会回调此函数。
 */
- (void)onBeginOfSpeech;

/*!
 *  停止录音
 *  当调用了`stopRecording`函数之后，会回调此函数
 */
- (void)onEndOfSpeech;

/*!
 *  取消识别回调
 *  当调用了`cancel`函数之后，会回调此函数

 */
- (void)onCancel;

@end

