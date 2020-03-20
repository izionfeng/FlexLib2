#
# Be sure to run `pod lib lint FlexLib2.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'FlexLib2'
  s.version          = '1.2'
  s.summary          = 'a cross platform flex implement for ios'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
It's a layout framework based on yoga engine. The main purpose is to provide easy and fast usage.
                       DESC

  s.homepage         = 'https://github.com/zionfong/FlexLib2.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zionfong@gmail.com' => 'zionfong@gmail.com' }
  s.source           = { :git => 'https://github.com/zionfong/FlexLib2.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
#s.osx.deployment_target = '10.10'
  
  # ios
  s.ios.source_files = 'FlexLib2/Classes/**/*'
#  s.ios.resources = 'FlexLib2/Assets/*.xml'
  s.ios.resource_bundles = {
     'FlexLib' => ['FlexLib2/Assets/*']
  }
  s.ios.exclude_files = 'FlexLib2/Classes/GDataXMLNode.{h,m}'
  s.subspec 'no-arc' do |sna|
    sna.ios.requires_arc = false
    sna.ios.source_files = 'FlexLib2/Classes/GDataXMLNode.{h,m}'
  end
  
  # macosx
#s.osx.source_files = 'macosx/Classes/**/*'
#s.osx.resource_bundles = {
     #'FlexLib2' => ['macosx/Assets/*']
#}
#s.osx.exclude_files = 'macosx/Classes/GDataXMLNode.{h,m}'
#s.subspec 'osx-no-arc' do |sna|
#sna.osx.requires_arc = false
#sna.osx.source_files = 'macosx/Classes/GDataXMLNode.{h,m}'
#end

  s.dependency 'Yoga', '1.14.0'
  s.library = 'xml2'
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => '/usr/include/libxml2' }
end

