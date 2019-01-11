//
//  NATDynamicEntity.h
//  NaturaliSDK
//
//  Created by 方懿 on 2019/1/10.
//  Copyright © 2019 Naturali. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NATDynamicEntityValue : NSObject

@property (nonatomic, copy) NSString *keyword;
@property (nonatomic, copy) NSArray<NSString *> *aliases;

@end

@interface NATDynamicEntity : NSObject

@property (nonatomic, copy) NSString *typeName;
@property (nonatomic, copy) NSArray<NATDynamicEntityValue *> *values;

@end

NS_ASSUME_NONNULL_END
