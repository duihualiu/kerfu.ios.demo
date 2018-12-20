//
//  NADialogManager.h
//  DemoSDK
//
//  Created by 方懿 on 2018/10/31.
//  Copyright © 2018 Naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NATDialogRequest.h"
#import "NATDialogResponse.h"

@class NATDialogRequest,NATDialogResponse;

typedef void (^NADialogRequestCompletion) (BOOL success, NSError *error);

@protocol NADialogFlowDelegate <NSObject>

- (void)didReceiveResponse:(NATDialogResponse *)response;

@end

@interface NATDialogManager : NSObject

@property (nonatomic, weak) id<NADialogFlowDelegate> delegate;

+ (instancetype)sharedInstance;

- (void)keepConnection;

- (void)sendDialogRequest:(NATDialogRequest *)request compeltion:(NADialogRequestCompletion)completion;

@end
