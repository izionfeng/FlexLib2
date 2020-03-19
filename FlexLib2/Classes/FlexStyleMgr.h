/**
 * Copyright (c) 2017-present, zhenglibao, Inc.
 * email: 798393829@qq.com
 * All rights reserved.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree.
 */



#import <UIKit/UIKit.h>

#define FlexMakeArtr(_name_, _value_) ([[FlexAttr alloc] initWithName:_name_ value:(_value_)])

@interface FlexAttr : NSObject<NSCoding>

@property(nonatomic,strong) NSString* name ;
@property(nonatomic,strong) NSString* value ;

- (instancetype)initWithName:(NSString *)name value:(NSString *)value;

-(BOOL)isValid;

@end

@interface FlexStyleMgr : NSObject

-(NSArray<FlexAttr*>*)getStyle:(NSString*)fileName
                     StyleName:(NSString*)styleName;

-(NSArray<FlexAttr*>*)getStyleByRefPath:(NSString*)ref;

+(instancetype)instance;

@end
