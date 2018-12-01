//
//  NADialogManager.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/31.
//  Copyright © 2018 Naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NADialogRequest.h"
#import "NADialogResponse.h"

@class NADialogRequest,NADialogResponse;

typedef void (^NADialogRequestCompletion) (BOOL success, NSError *error);

@protocol NADialogFlowDelegate <NSObject>

- (void)didReceiveResponse:(NADialogResponse *)response;

@end

@interface NADialogManager : NSObject

@property (nonatomic, weak) id<NADialogFlowDelegate> delegate;

+ (instancetype)sharedInstance;

- (void)sendDialogRequest:(NADialogRequest *)request compeltion:(NADialogRequestCompletion)completion;

@end
