//
//  FlexLabel.h
//  FlexLib
//
//  Created by Zion on 2020/3/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, FlexVerticalAlignment) {
    FlexVerticalAlignmentCenter = 0,
    FlexVerticalAlignmentTop,
    FlexVerticalAlignmentBottom
};


@interface FlexLabel : UILabel

@property (nonatomic, assign) FlexVerticalAlignment verticalAlignment;

@end

NS_ASSUME_NONNULL_END
