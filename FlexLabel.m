//
//  FlexLabel.m
//  FlexLib
//
//  Created by Zion on 2020/3/16.
//

#import "FlexLabel.h"
#import "FlexUtils.h"

@implementation FlexLabel

- (void)setVerticalAlignment:(FlexVerticalAlignment)verticalAlignment {
    _verticalAlignment = verticalAlignment;
    [self setNeedsDisplay];
}

FLEXSET(verticalAlignment) {
    [self setVerticalAlignment:[sValue integerValue]];
}

FLEXSET(text) {
    self.text = sValue;
}

// align text block according to vertical alignment settings
- (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines {
   CGRect rect = [super textRectForBounds:bounds limitedToNumberOfLines:numberOfLines];
    CGRect result;
    switch (_verticalAlignment) {
       case FlexVerticalAlignmentTop:
          result = CGRectMake(bounds.origin.x,
                              bounds.origin.y,
                              rect.size.width,
                              rect.size.height);
           break;

       case FlexVerticalAlignmentCenter:
          result = CGRectMake(bounds.origin.x,
                              bounds.origin.y + (bounds.size.height - rect.size.height) / 2,
                              rect.size.width,
                              rect.size.height);
          break;

       case FlexVerticalAlignmentBottom:
          result = CGRectMake(bounds.origin.x,
                              bounds.origin.y + (bounds.size.height - rect.size.height),
                              rect.size.width,
                              rect.size.height);
          break;

       default:
          result = bounds;
          break;
    }
    return result;
}

-(void)drawTextInRect:(CGRect)rect {
    CGRect textRect = [self textRectForBounds:rect limitedToNumberOfLines:self.numberOfLines];
    [super drawTextInRect:textRect];
}


@end
