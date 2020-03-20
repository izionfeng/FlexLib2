
## FlexLib2

flexbox最初是web端布局方案，现在已经应用在多个平台。

Android、iOS都有单独的实现，Android的实现是google的[flexbox-layout](https://github.com/google/flexbox-layout.git)，iOS的实现是Facebook的[yoga](https://github.com/facebook/yoga.git)。

这里提供一种方案，使得同一份XML布局文件可以在Android和iOS上跨端使用。

## XML文件格式
完全依照Android写法。只需要添加少量代码，即可在iOS上展示同样的布局。


## 兼容[FlexLib](https://github.com/zhenglibao/FlexLib.git)
scripts目录提供了转换脚本，使用方法：

转换单个XML文件：
```ruby
 ./scripts/flex_xml_trans.py /path/old_style.xml
```
转换目录下所有XML文件：
```ruby
 ./scripts/flex_xml_trans.py /path
```
该项目Example里的XML文件，皆通过此脚本从FlexLib转换而来。


## 安装

通过pod方式安装FlexLib2，例子如下:

```ruby
pod 'FlexLib2'
```

## 支持的flexbox属性

采用namespace前缀app 双端通用的flexbox属性及值如下
| key                      | value                                                             |
|--------------------------|-------------------------------------------------------------------|
| flexDirection            | row/row\_reverse/column/column\_reverse                           |
| flexWrap                 | nowrap/wrap/wrap\_reverse                                         |
| alignItems               | flex\_start/flex\_end/center/baseline/stretch                     |
| alignContent             | flex\_start/flex\_end/center/space\_between/space\_around/stretch |
| layout\_alignSelf        | auto/flex\_start/flex\_end/center/baseline/stretch                |
| justifyContent           | flex\_start/flex\_end/center/space\_between/spce\_around          |

这几个属性iOS端的yoga不支持：layout_flexBasisPercent，layout_flexGrow，layout_flexShrink

## 宽/高/margin/padding

因为Android和iOS的布局尺寸单位不等同，所以有必要区分双端的相关属性。具体可以参考[这里](https://juejin.im/entry/5a37bd866fb9a04509099d25)。

下列表格展示双端通用的属性名，但使用的namespace不一样，属性值也有一些差异，比如Android值后面加dp，iOS值可以是数字，可以是一个百分数。

特别指出一下，android:width=match_parent相对应ios:width=100%，而要实现android:height=wrap_content，对app:layout_alignSelf或者父View的app:flexDirection进行赋值即可。


| key                  | android            | ios                         |
|----------------------|--------------------|-----------------------------|
| layout\_margin       | follow Android doc | float num value/percent num |
| layout\_marginStart  | follow Android doc | float num value/percent num |
| layout\_marginEnd    | follow Android doc | float num value/percent num |
| layout\_marginTop    | follow Android doc | float num value/percent num |
| layout\_marginBottom | follow Android doc | float num value/percent num |
| layout\_marginLeft   | follow Android doc | float num value/percent num |
| layout\_marginRight  | follow Android doc | float num value/percent num |
| padding              | follow Android doc | float num value/percent num |
| paddingStart         | follow Android doc | float num value/percent num |
| paddingEnd           | follow Android doc | float num value/percent num |
| paddingTop           | follow Android doc | float num value/percent num |
| paddingBottom        | follow Android doc | float num value/percent num |
| paddingLeft          | follow Android doc | float num value/percent num |
| paddingRight         | follow Android doc | float num value/percent num |
| layout\_width        | follow Android doc | float num value/percent num |
| layout\_minWidth     | follow Android doc | float num value/percent num |
| layout\_minHeight    | follow Android doc | float num value/percent num |
| layout\_maxWidth     | follow Android doc | float num value/percent num |
| layou\_maxHeight     | follow Android doc | float num value/percent num |


## ios特有属性

namespace ios，UIView支持的属性如下

| key                             | value                                                                                                                          |
|---------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| name                            | 变量名                                                                                                                            |
| onPress                         | 方法名                                                                                                                            |
| class                           | 类名                                                                                                                             |
| style                           | string                                                                                                                         |
| bgColor                         | \[Hex String\]/\[image name\]/black/white/clear/darkGray/lightGray/gray/red/green/blue/cyan/yellow/magenta/orange/purple/brown |
| font                            | \[system/bold/PingFangSC\-Medium/\.\.\.\]\|\[num value\]，例：PingFangSC\-Medium\|16                                              |
| borderWidth                     | float num value                                                                                                                |
| borderColor                     | 同bgColor                                                                                                                       |
| borderRadius                    | float num value                                                                                                                |
| shadowOffset                    | \[float num value/float num value\]，例：\[1\.0/2\.0\]                                                                            |
| shadowOapcity                   | float num value                                                                                                                |
| shadowRadius                    | float num value                                                                                                                |
| shadowColor                     | 同bgColor                                                                                                                       |
| contentMode                     | scaleToFill/scaleAspectFit/scaleAspectFill/redraw/center/top/bottom/left/right/topLeft/topRight/bottomLeft/bottomRight         |
| alpha                           | float num value                                                                                                                |
| hidden                          | true/false                                                                                                                     |
| clipsToBounds                   | true/false                                                                                                                     |
| tintColor                       | 同bgColor                                                                                                                       |
| tag                             | int num value                                                                                                                  |
| stickTop                        | true/false                                                                                                                     |
| layerBounds                     | \[float num value/float num value/float num value/float num value\]，例：\[1\.0/2\.0/3\.0/4\.0\]                                  |
| layerPosition                   | 同shadowOffset                                                                                                                  |
| layerZPosition                  | 同shadowOffset                                                                                                                  |
| layerAnchorPoint                | 同shadowOffset                                                                                                                  |
| layerAnchorPointZ               | float num value                                                                                                                |
| layerFrame                      | 同layerBounds                                                                                                                   |
| layerHidden                     | true/false                                                                                                                     |
| layerDoubleSided                | true/false                                                                                                                     |
| layerGeomertyFlipped            | true/false                                                                                                                     |
| layerMasksToBounds              | true/false                                                                                                                     |
| masksToBounds                   | true/false                                                                                                                     |
| layerContentsRect               | 同layerBounds                                                                                                                   |
| layerContentsGravity            | 同CALayer的contentsGravity                                                                                                       |
| layerContentsScale              | float num value                                                                                                                |
| layerContentsCenter             | 同layerBounds                                                                                                                   |
| layerContentsFormat             | 同CALayer的contentsFormat                                                                                                        |
| layerMinificationFilter         | 同CALayer的minificationFilter                                                                                                    |
| layerMagnificationFiltery       | 同CALayer的magnificationFilter                                                                                                   |
| layerMinificationFilterBias     | float num value                                                                                                                |
| layerOpaque                     | true/false                                                                                                                     |
| layerNeedsDisplayOnBoundsChange | true/false                                                                                                                     |
| layerDrawsAsynchronously        | true/false                                                                                                                     |
| layerAllowsEdgeAntialiasing     | true/false                                                                                                                     |
| layerBackgroundColor            | 同bgColor                                                                                                                       |
| layerCornerRadius               | float num value                                                                                                                |
| layerOpacity                    | float num value                                                                                                                |
| allowsGroupOpacity              | true/false                                                                                                                     |
| shouldRasterize                 | true/false                                                                                                                     |
| background                      | 同bgColor                                                                                                                       |
| rasterizationScale              | float num value                                                                                                                |
| layerName                       | string                                                                                                                         |
| userInteractionEnabled          | true/false                                                                                                                     |
| contentScaleFactor              | float num value                                                                                                                |
| multipleTouchEnabled            | true/false                                                                                                                     |
| exclusiveTouch                  | true/false                                                                                                                     |
| autoresizesSubviews             | true/false                                                                                                                     |
| opaque                          | true/false                                                                                                                     |
| clearsContextBeforeDrawing      | true/false                                                                                                                     |
|                                 |                                                                                                                                |



## 不支持的flex属性



## yoga与google flexbox的一些差异



## 一些小技巧



## 感谢
感谢[FlexLib](https://github.com/zhenglibao/FlexLib.git)作者[zhenglibao](798393829@qq.com)。



本项目基于FlexLib开发，关于基本使用方法、特性、性能，可以移步到[FlexLib](https://github.com/zhenglibao/FlexLib.git)进行了解。

## 联系方式
优先：提issues

email：zionfong@gmail.com


## 版权

FlexLib is available under the MIT license. See the LICENSE file for more info.

---

