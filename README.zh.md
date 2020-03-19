
## FlexLib2
[english](https://github.com/zionfong/FlexLib2/blob/master/README.md)

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

## XML文件写法




## 支持的flex属性



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

