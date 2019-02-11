//
//  NATDynamicEntity.h
//  NaturaliSDK
//
//  Created by 方懿 on 2019/1/10.
//  Copyright © 2019 Naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KFDynamicEntityValue : NSObject

@property (nonatomic, copy) NSString *keyword;
@property (nonatomic, copy) NSArray<NSString *> *aliases;

@end

@interface KFDynamicEntity : NSObject

@property (nonatomic, copy) NSString *typeName;
@property (nonatomic, copy) NSArray<KFDynamicEntityValue *> *values;

@end

NS_ASSUME_NONNULL_END
