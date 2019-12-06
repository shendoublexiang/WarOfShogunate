# WarOfShogunate


## 项目介绍

WarOfShogunate 仅供 **WarOfShogunate** 项目使用的Framework 。

请勿用于官网包对接。

## 版本说明

|版本号|日期|版本说明|作者|
|:-:|:-:|:-:|:-:|
|0.1.4|2019.11.29|详细说明如下|Vincent|
|0.1.6|2019.12.06|详细说明如下|Vincent|

1. 版本更新为 v0.1.6
2. 新增部分：
    - 增加新版本数据打点上报
    - 登录页面增加下拉列表以显示历史账号
    - 登录页面下拉列表增加左滑删除账号
    - 新增退出登录接口
    - 新增AppID只读属性
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
		pod 'WarOfShogunate',:git=>'https://github.com/shendoublexiang/WarOfShogunate.git'
		#如还依赖其他库，可在此加入对应 pod 语句
	end

[iOS 版本占有率查询 个人](https://david-smith.org/iosversionstats/)

[iOS 版本占有率查询 Apple 官方](https://developer.apple.com/support/app-store/)


编写完成对应的 *PodFile* 后，请于终端内部进入当前文件夹并执行以下安装语句：

	$ pod install

等待命令执行完成后，当前文件夹内容应如下所示:

![工程文件目录](http://img01.rastargame.com/p_upload/2019/1129/1575013684488909.png)

此时打开 **.xcworkspace** 进行开发。

## 使用说明

由于此 SDK 使用 CocosPod 依赖引用，故首次打开时需要引入资源文件、系统依赖库及预编译进而使库文件可以正常使用，具体流程如下：

#### 引入资源文件

由于SDK内部使用的自身及第三方工具中包含资源文件，故需要在项目工程的 **Copy Bundle Resources** 中引入第三方及自身资源，具体流程如下：

1. 前往设置 -> **‘Build Phases’**
2. 在 **Copy Bundle Resources** 中引入第三方及自身资源文件
3. 由于资源文件非系统标准，故在点击加号后需要点击 **Add Other...** 以进入自定义文件选择器
4. 在弹出的文件中分别前往并选中 **Pods/IQKeyboardManager/IQKeyboardManager/Resource/IQKeyboardManager.xcassets** 、**Pods/SVProgressHUD/SVProgressHUD/SVProgressHUD.bundle** 、 **Pods/WarOfShogunate/WarOfShogunateFramework.framework/WarOfShogunateFramework.bundle**

最终如下图所示：

![添加资源文件](http://img01.rastargame.com/p_upload/2019/1202/1575257476258210.png)

#### 引入系统依赖库

由于 SDK 使用到 内购，数据上报，Safari 等，故需要添加对应的系统依赖库，具体流程如下：

1. 前往设置 -> **‘Build Phases’**
2. 在 **‘Link Binary With Libraries’** 中添加 ‘StoreKit'、‘AdSupport’、‘SafariServices’ 三个系统依赖，如下图所示：

![添加依赖库](http://img01.rastargame.com/p_upload/2019/1129/1575015211435145.png)


#### 预编译

1. 在引入资源文件后才可进行预编译操作。 
2. 选择编译类型为： **Generic iOS Device**。
3. 工具栏 -> Product -> Build （或是用快捷键：Command + B）进行编译。

编译成功后文件目录树如图所示：

![编译成功目录树](http://img01.rastargame.com/p_upload/2019/1129/1575014045882878.png)


## 属性说明

新增加只读属性 AppKey 用于获取当前SDK中内置的 **AppID**


``` objc
/// AppKey
@property (nonatomic, copy, readonly)NSString *ShogunateAppKey;
```

## 接口说明

#### 数据相关

请于说明所示位置实现对应的方法

``` objc

/// 上报即将开始游戏 - 请于‘didFinishLaunchingWithOptions’中实现
- (void)uploadGameWillStart;

/// 上报即将关闭游戏 - 请于‘applicationWillTerminate’中实现
- (void)uploadGameWillClose;

/// c创建角色上报
/// @param roleID 角色ID
/// @param roleName 角色名
/// @param roleLevel 角色等级
/// @param serverID 服务器ID
/// @param serverName 服务器名
/// @param vip VIP等级 - 最低为0
/// @param partyName 工会名称 - 若无请传空字符串 @""
- (void)uploadCreateRole:(NSString *)roleID RoleName:(NSString *)roleName RoleLevel:(int)roleLevel ServerID:(int)serverID ServerName:(NSString *)serverName VIPLevel:(int)vip PartyName:(NSString *)partyName;

```

#### 初始化

请于合适位置调用初始化接口 - 初始化接口必须在登录之前调用

``` objc
/// 初始化SDK
/// @param registerType 初始化状态
- (void)registerShogunateSDK:(void (^)(BOOL type))registerType;
```

#### 登录

请于合适位置调用登录接口 - 其中uid仅供参考具体请使用服务端Token返回

``` objc
/// 显示登录页面
/// @param userInfo 登录信息返回
- (void)showLoginView:(void(^)(int uid, NSString *token))userInfo;
```

#### 退出登录

请于合适位置调用退出登录接口 - 收到成功回调后请手动调用登录

``` objc
/// 切换登录 - 收到成功回调后需要手动调用登录接口，此方法仅讲SDK内部存储的玩家数据置零
/// @param logoutType 是否退登成功
- (void)logoutAction:(void(^)(BOOL isLogout))logoutType;
```

#### 发起内购

内购结果由服务端通知，前端仅提供弹窗提示

``` objc
/// 发起内购
/// @param orderNumber 订单号
/// @param order 金额
/// @param orderName 商品名称
/// @param roleName 角色名称
/// @param roleID 角色ID
/// @param roleLevel 角色等级
/// @param serverID 服务器ID
/// @param serverName 服务器名称
/// @param extra 附加字段 - 若无请传空字符串 @""
- (void)createOrderNumber:(NSString *)orderNumber Order:(int)order OrderName:(NSString *)orderName  RoleName:(NSString *)roleName RoleID:(NSString *)roleID RoleLevel:(int)roleLevel ServerID:(int)serverID ServerName:(NSString *)serverName Extra:(NSString *)extra;
```
