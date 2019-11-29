# WarOfShogunate


## 项目介绍

WarOfShogunate 仅供 **WarOfShogunate** 项目使用的Framework 。

请勿用于官网包对接。

## 版本说明

|版本号|日期|版本说明|作者|
|:-:|:-:|:-:|:-:|
|0.1.4|2019.11.29|详细说明如下|Vincent|

1. 版本更新为 v0.1.4
2. 新增部分：
    - 增加新版本数据打点上报
    - 登录页面增加下拉列表以显示历史账号
    - 登录页面下拉列表增加左滑删除账号
3. 修改部分
    - 更改对接方式为 Cocoapods
    - 更改头文件中 ‘uploadGameWillStart’ 方法为必接
    - 更改头文件中 ‘uploadGameWillClose’ 方法为必接
4. 移除部分
    - 移除手动增加Framework配置相关
    - 移除环境变量配置
    - 移除对应的资源依赖配置


## 安装教程

#### CocoaPods
由于日常对接过程中常常遇见配置相关问题，目前此版本 RaStarSimpleSDK，仅仅支持 [CocoaPods](https://cocoapods.org/) 依赖管理。

[CocoaPods](https://cocoapods.org/) 是Objective-C及Swift的一个依赖管理器，它可以自动化引入并简化在项目中使用例如 RaStarSimpleSDK 等第三方库的过程。

如未安装此依赖管理器，可在 终端 中直接执行以下命令：

	$ gem install cocoapods
	
#### Podfile

要使用 CocoaPods 将 WarOfShogunate 集成到 **Xcode** 项目中，请在工程目录下的 *PodFile* 文件中指定此SDK，完成后，对应的 *PodFile* 文件应入下所示：

	source 'https://github.com/CocoaPods/Specs.git'
	#使用Frameworks
	use_frameworks!
    #此版本SDK 由 iOS 10.0 开始支持
	platform :ios, '10.0'
	
	#此处 target 应为对应工程的 target name
	target 'TargetName' do
		pod 'WarOfShogunate',
		#如还依赖其他库，可在此加入对应 pod 语句
	end

[iOS 版本占有率查询 个人](https://david-smith.org/iosversionstats/)

[iOS 版本占有率查询 Apple 官方](https://developer.apple.com/support/app-store/)


编写完成对应的 *PodFile* 后，请于终端内部进入当前文件夹并执行以下安装语句：

	$ pod install

等待命令执行完成后，当前文件夹内容应如下所示:

![工程文件目录](http://img01.gzchukai.cn/p_upload/2018/1213/1544667615110101.png)

此时打开 **.xcworkspace** 进行开发。
