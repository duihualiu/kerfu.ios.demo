//
//  NADialogRequest.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/26.
//  Copyright © 2018 naturali. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NADialogRequest : NSObject

@property (nonatomic, copy) NSString *query;
@property (nonatomic, copy) NSData   *audioData;
@property (nonatomic, copy) NSString *userId;//与服务号对话的用户ID或者聊天群组ID.
@property (nonatomic, copy) NSString *serviceId;
@property (nonatomic, copy) NSData   *extraData;

@end

