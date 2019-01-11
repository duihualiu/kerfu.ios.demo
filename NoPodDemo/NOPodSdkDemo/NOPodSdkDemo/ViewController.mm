//
//  ViewController.m
//  NaturaliSDKDemo
//
//  Created by 方懿 on 2018/11/30.
//  Copyright © 2018 Naturali. All rights reserved.
//

#import "ViewController.h"

#import "NaturaliSDK.h"

@interface ViewController () <NATSpeechRecognizerDelegate,NADialogFlowDelegate>


@property (weak, nonatomic) IBOutlet UITextField *agentIdLabel;
@property (weak, nonatomic) IBOutlet UITextField *queryInput;
@property (weak, nonatomic) IBOutlet UILabel *hintLabel;
@property (weak, nonatomic) IBOutlet UIButton *startRecordButton;
@property (weak, nonatomic) IBOutlet UIButton *stopRecordButton;
@property (weak, nonatomic) IBOutlet UIButton *searchButton;
@property (weak, nonatomic) IBOutlet UITextView *receiveTextView;
@property (weak, nonatomic) IBOutlet UIButton *linkButton;
@property (weak, nonatomic) IBOutlet UIImageView *receiveImageView;

@property (nonatomic, strong) NATSpeechRecognizer *recognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //注册sdk
    [NaturaliSDK registerAppId:@"yourAppId"
                        appKey:@"yourAppKey"
                     appSecret:@"yourAppSecret"];
    //设置userId,发送消息的用户id
    [NaturaliSDK setUserId:@"yourUserId"];
    
    //创建语音识别器并设置代理对象，回调将通过代理对象返回。
    self.recognizer = [[NATSpeechRecognizer alloc] initWithDelegate:self];
    
    //设置对话流的代理对象，用于接收对话消息.
    [NATDialogManager sharedInstance].delegate = self;
    
    
    //如果用户需要添加动态实体，可如下方式添加
    NATDynamicEntityValue *value1 = [NATDynamicEntityValue new];
    value1.keyword = @"keyword1";
    value1.aliases = @[@"alias1",@"alias2"];
    
    NATDynamicEntityValue *value2 = [NATDynamicEntityValue new];
    value2.keyword = @"keyword2";
    value2.aliases = @[@"alias3",@"alias4"];
    
    NATDynamicEntity *entity = [NATDynamicEntity new];
    entity.typeName = @"typeName1";
    entity.values = @[value1,value2];
    
    [NaturaliSDK addDynamicEntities:@[entity]];
}

- (IBAction)touchButtonDown:(id)sender {
    if (!self.agentIdLabel.text.length) {
        NSLog(@"未输入agentId");
        return;
    }
    
    NSString * query = _queryInput.text;
    
    if (!query.length) {
        NSLog(@"您没说话");
        return;
    }
    
    //发送对话流消息,至少需要文本和agentId参数
    NATDialogRequest *request = [[NATDialogRequest alloc] init];
    request.query = query;
    request.agentId = self.agentIdLabel.text;
    [[NATDialogManager sharedInstance] sendDialogRequest:request compeltion:^(BOOL success, NSError *error, NSString *reqId) {
        if (error) {
            NSLog(@"发送对话发生错误：\n%@",error);
        } else if (success) {
            NSLog(@"发送成功");
        }
    }];
}

- (IBAction)startRecord:(id)sender {
    NSLog(@"touch start record button");
    self.queryInput.text = nil;
    //开始语音录制
    [self.recognizer startRecording];
    
    //下面的方法为语音直接调用对话流
    //    [self.recognizer startDialogRecordingWithAgentId:self.agentIdLabel.text];
}

- (IBAction)stopRecord:(id)sender {
    NSLog(@"touch stop record button");
    //结束语音录制
    [self.recognizer stopRecording];
}


- (IBAction)openApp:(id)sender {
    NSString *linkUrl = [self.linkButton titleForState:UIControlStateNormal];
    if (linkUrl.length) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:linkUrl] options:@{} completionHandler:nil];
    }
}

#pragma mark - speech recognizer delegate
- (void)onCompleted:(NSError *)error {
    //语音录制结束，若无异常，则error为nil
    NSLog(@"speech recognizer complete with error : %@",error);
}

- (void)onResult:(NSString *)result isDone:(BOOL)isDone voiceUrl:(NSString *)voiceUrl {
    //实时监听语音录制的识别结果，当语音录制结束时，isDone为true
    self.queryInput.text = result;
}

#pragma mark - dialog manager delegate
- (void)didReceiveResponse:(NATDialogResponse *)response {
    //接收对话流消息，可能包含文本和多媒体资源地址.
    self.receiveTextView.text = response.content;
    [self.linkButton setTitle:response.linkUrl forState:UIControlStateNormal];
    
    NSData *imageData = [NSData dataWithContentsOfURL:[NSURL URLWithString:response.imageUrl]];
    self.receiveImageView.image = [UIImage imageWithData:imageData];
}

@end
