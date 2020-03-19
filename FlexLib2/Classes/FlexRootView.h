/**
 * Copyright (c) 2017-present, zhenglibao, Inc.
 * email: 798393829@qq.com
 * All rights reserved.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree.
 */



#import <UIKit/UIKit.h>

// 布局完成事件通知
#define FLEXDIDLAYOUT @"FlexDidLayout"

@class FlexAttr;
@class FlexRootView;
@class FlexNode;

@interface UIView(FlexPublic)

@property(nonatomic,readonly) FlexRootView* rootView;
@property(nonatomic,readonly) NSObject* owner;

+(UIView*)buildFlexView:(Class)viewCls
                 Layout:(NSArray<NSString*>*)layoutAttrs
              ViewAttrs:(NSArray<NSString*>*)viewAttrs;

// 派生类重写此方法可以实现自定义创建view节点
-(BOOL)buildChildElements:(NSArray<FlexNode*>*)childElems
                    Owner:(NSObject*)owner
                 RootView:(FlexRootView*)rootView;

// 外部可以主动调用此函数让布局得到刷新
-(void)markDirty;

//该方法框架内部使用
-(void)markYogaDirty;

// 开启关闭布局
-(void)enableFlexLayout:(BOOL)enable;

//
-(BOOL)isFlexLayoutEnable;

// 设置视图属性
-(void)setViewAttr:(NSString*) name
             Value:(NSString*) value;
-(void)setViewAttrs:(NSArray<FlexAttr*>*)attrs;
-(void)setViewAttrStrings:(NSArray<NSString*>*)stringAttrs;

// 设置布局属性
-(void)setLayoutAttr:(NSString*) name
               Value:(NSString*) value;
-(void)setLayoutAttrs:(NSArray<FlexAttr*>*)attrs;
-(void)setLayoutAttrStrings:(NSArray<NSString*>*)stringAttrs;

-(UIView*)findByName:(NSString*)name;

// 在子窗口中查找所有特定类型的实例
-(void)findAllViews:(NSMutableArray*)result Type:(Class)type;

// 查找所有具有输入功能的view，并按坐标排序，从上到下，从左往右
-(NSArray<UIView*>*)findAllInputs;

-(UIView*)findFirstResponder;

@end

@interface FlexRootView : UIView

/**
 * 是否使用frame模式，默认NO
 * 如果为YES，则需要明确设置自身的frame,也就是self.frame必须是明确的有效值
 * 如果为NO，则使用距离父窗口四周的距离来决定自身大小
 */
@property(nonatomic,assign) BOOL useFrame;

/**
 * 宽和高是否有内容决定，默认为NO
 * 如果为NO，则表示外部必须明确指定宽度或者高度
 * 如果为YES，则表示无需指定宽度或者高度，当布局完成后，自动由内容撑开
 */
@property(nonatomic,assign) BOOL flexibleWidth;
@property(nonatomic,assign) BOOL flexibleHeight;

/**
 * 四周距离父窗口边界的距离,优先使用block，低优先级使用safeArea
 * 只有在useFrame=NO的情况下生效
 */
@property(nonatomic,assign) UIEdgeInsets safeArea;
@property(nonatomic,copy) UIEdgeInsets (^calcSafeArea)(void);

/**
 * 获取xml中的顶级窗口
 */
@property(nonatomic,readonly) UIView* topSubView;

/**
 * 获取owner
 */
@property(nonatomic,readonly) NSObject* owner;

/**
 * 当前是否正在布局
 */
@property(nonatomic,readonly) BOOL inLayouting;

/**
 * 用于执行layout动画
 */
@property(nonatomic,copy) void (^beginLayout)(void);
@property(nonatomic,copy) void (^endLayout)(void);

/**
 * 事件通知,布局完成事件也可以通过[NSNotificationCenter defaultCenter]
 * 注册FLEXDIDLAYOUT事件进行接收
 */
@property(nonatomic,copy) void (^onWillLayout)(void);
@property(nonatomic,copy) void (^onDidLayout)(void);

#pragma mark - 加载布局

// 从xml文件中加载布局
+(FlexRootView*)loadWithNodeFile:(NSString*)resName
                           Owner:(NSObject*)owner;
// 从data中加载布局
+(FlexRootView*)loadWithNodeData:(NSData*)data
                           Owner:(NSObject*)owner;

/**
 * 从数据中加载xml视图树
 */
-(BOOL)loadWithNodeData:(NSData*)data
                  Owner:(NSObject*)owner;
/**
 * 从xml文件中加载视图树
 */
-(BOOL)loadWithNodeFile:(NSString*)resName
                  Owner:(NSObject*)owner;

#pragma mark - 其他方法

-(void)markChildDirty:(UIView*)child;

// 注册事件通知，针对hidden, text, attributedText
-(void)registSubView:(UIView*)subView;

// 解除事件通知
-(void)removeWatchView:(UIView*)view;

-(void)layoutAnimation:(NSTimeInterval)duration;

-(CGSize)calculateSize;

-(CGSize)calculateSize:(CGSize)szLimit;

@end
