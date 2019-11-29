//
//  Shogunate.h
//  Pods-WarOfShogunateFramework_Example
//
//  Created by RaStar on 2019/11/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Shogunate : NSObject

/// 单例
+ (instancetype)instance;

/// 初始化SDK
/// @param registerType 初始化状态
- (void)registerShogunateSDK:(void (^)(BOOL type))registerType;

/// 上报即将开始游戏 - 请于‘didFinishLaunchingWithOptions’中实现
- (void)uploadGameWillStart;

/// 上报即将关闭游戏 - 请于‘applicationWillTerminate’中实现
- (void)uploadGameWillClose;

/// 显示登录页面
/// @param userInfo 登录信息返回
- (void)showLoginView:(void(^)(int uid, NSString *token))userInfo;

/// c创建角色上报
/// @param roleID 角色ID
/// @param roleName 角色名
/// @param roleLevel 角色等级
/// @param serverID 服务器ID
/// @param serverName 服务器名
/// @param vip VIP等级 - 最低为0
/// @param partyName 工会名称 - 若无请传空字符串 @""
- (void)uploadCreateRole:(NSString *)roleID RoleName:(NSString *)roleName RoleLevel:(int)roleLevel ServerID:(int)serverID ServerName:(NSString *)serverName VIPLevel:(int)vip PartyName:(NSString *)partyName;

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

@end

NS_ASSUME_NONNULL_END
