//
//  ViewController.m
//  KerfuSDKDemo
//
//  Created by 方懿 on 2018/11/30.
//  Copyright © 2018 Naturali. All rights reserved.
//

#import "ViewController.h"

#import <KerfuSDK.h>

@interface ViewController () <KFSpeechRecognizerDelegate,KFDialogFlowDelegate>


@property (weak, nonatomic) IBOutlet UITextField *agentIdLabel;
@property (weak, nonatomic) IBOutlet UITextField *queryInput;
@property (weak, nonatomic) IBOutlet UILabel *hintLabel;
@property (weak, nonatomic) IBOutlet UIButton *startRecordButton;
@property (weak, nonatomic) IBOutlet UIButton *stopRecordButton;
@property (weak, nonatomic) IBOutlet UIButton *searchButton;
@property (weak, nonatomic) IBOutlet UITextView *receiveTextView;
@property (weak, nonatomic) IBOutlet UIButton *linkButton;
@property (weak, nonatomic) IBOutlet UIImageView *receiveImageView;

@property (nonatomic, strong) KFSpeechRecognizer *recognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //注册sdk
    [KerfuSDK registerAppId:@"your_app_id"
                     appKey:@"your_app_key"
                  appSecret:@"you_app_secret"];
    //设置userId,发送消息的用户id
    [KerfuSDK setUserId:@"your_user_id"];
    
    //创建语音识别器并设置代理对象，回调将通过代理对象返回。
    self.recognizer = [[KFSpeechRecognizer alloc] initWithDelegate:self];
    
    //设置对话流的代理对象，用于接收对话消息.
    [KFDialogManager sharedInstance].delegate = self;
    
    
    //如果用户需要添加动态实体，可如下方式添加
    KFDynamicEntityValue *value1 = [KFDynamicEntityValue new];
    value1.keyword = @"邬霄云";
    value1.aliases = @[@"alias1",@"alias2"];
    
    KFDynamicEntityValue *value2 = [KFDynamicEntityValue new];
    value2.keyword = @"杜海超";
    value2.aliases = @[@"alias3",@"alias4"];
    
    KFDynamicEntityValue *value3 = [KFDynamicEntityValue new];
    value3.keyword = @"程功";
    value2.aliases = @[@"alias5",@"alias4"];
    
    KFDynamicEntity *entity = [KFDynamicEntity new];
    entity.typeName = @"Naturali-BD.客户端测试用动态实体";
    entity.values = @[value1,value2,value3];
    
    [KerfuSDK addDynamicEntities:@[entity]];
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
    KFDialogRequest *request = [[KFDialogRequest alloc] init];
    request.query = query;
    request.agentId = self.agentIdLabel.text;
    [[KFDialogManager sharedInstance] sendDialogRequest:request compeltion:^(BOOL success, NSError *error, NSString *reqId) {
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
- (void)didReceiveResponse:(KFDialogResponse *)response {
    //接收对话流消息，可能包含文本和多媒体资源地址.
    self.receiveTextView.text = response.content;
    [self.linkButton setTitle:response.linkUrl forState:UIControlStateNormal];
    
    NSData *imageData = [NSData dataWithContentsOfURL:[NSURL URLWithString:response.imageUrl]];
    self.receiveImageView.image = [UIImage imageWithData:imageData];
}

- (IBAction)endConversationAction:(id)sender {
    [[KFDialogManager sharedInstance] endConversationWithAgentId:self.agentIdLabel.text compeltion:^(BOOL success, NSError *error, NSString *requestId) {
        NSLog(@"conversation end:%@ , \nerror:%@",success ? @"yes" : @"no", error);
    }];
}

@end
