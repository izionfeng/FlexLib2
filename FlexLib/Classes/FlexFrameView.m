/**
 * Copyright (c) 2017-present, zhenglibao, Inc.
 * email: 798393829@qq.com
 * All rights reserved.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "FlexRootView.h"
#import "FlexFrameView.h"
#import "YogaKit/UIView+Yoga.h"

@interface FlexFrameView()
{
}
@end

@implementation FlexFrameView

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.useFrame = YES;
    }
    return self;
}
-(instancetype)initWithFlex:(NSString*)flexname
                      Frame:(CGRect)frame
                      Owner:(NSObject*)owner
{
    self = [self initWithFrame:frame];
    
    if(self){        
        if(owner == nil)
            owner = self;
        
        self.useFrame = YES;
        
        [self loadWithNodeFile:flexname Owner:owner];
        
        [self onInit];
    }
    return self;
}
- (void)dealloc
{
}
-(FlexRootView*)rootView
{
    return self;
}
- (void)onInit
{
}

- (void)setFrame:(CGRect)frame
{
    CGSize oldSize = self.frame.size ;
    
    [super setFrame:frame];
    
    if (!self.inLayouting && !CGSizeEqualToSize(oldSize, frame.size)) {
        [self setNeedsLayout];
    }
}

- (void)layoutSubviews
{
    CGSize oldSize = self.frame.size ;
    
    [super layoutSubviews];
    
    if(self.onFrameChange!=nil &&
       !CGSizeEqualToSize(oldSize, self.frame.size))
    {
        self.onFrameChange(self.frame);
    }
}

- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize
{
    return [self calculateSize:targetSize];
}
- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize withHorizontalFittingPriority:(UILayoutPriority)horizontalFittingPriority verticalFittingPriority:(UILayoutPriority)verticalFittingPriority
{
    return [self calculateSize:targetSize];
}
@end
