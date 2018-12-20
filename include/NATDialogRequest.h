//
//  NADialogRequest.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/26.
//  Copyright © 2018 naturali. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NATDialogRequest : NSObject

@property (nonatomic, copy) NSString *query;

@property (nonatomic, copy) NSString *audioFilePath;
@property (nonatomic, copy) NSString *imageFilePath;
@property (nonatomic, copy) NSString *videoFilePath;

@property (nonatomic, copy) NSString *audioUrl;
@property (nonatomic, copy) NSString *imageUrl;
@property (nonatomic, copy) NSString *videoUrl;

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *agentId;
@property (nonatomic, copy) NSString *extraData;

@end

