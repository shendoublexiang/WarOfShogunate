//
//  ViewController.m
//  WarOfShogunateDemo
//
//  Created by RaStar on 2019/11/29.
//  Copyright © 2019 vincent. All rights reserved.
//

#import "ViewController.h"
#import <WarOfShogunateFramework/Shogunate.h>

#import <SVProgressHUD/SVProgressHUD.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)initCheck {
    
    [[Shogunate instance] registerShogunateSDK:^(BOOL type) {
        if (type) {
            [SVProgressHUD showSuccessWithStatus:@"初始化成功"];
            [SVProgressHUD dismissWithDelay:2.5];
        } else{
            [SVProgressHUD showErrorWithStatus:@"初始化失败"];
            [SVProgressHUD dismissWithDelay:2.5];
        }
    }];
    
}
- (IBAction)loginCheck {
    
    [[Shogunate instance] showLoginView:^(int uid, NSString * _Nonnull token) {
        [SVProgressHUD showSuccessWithStatus:[NSString stringWithFormat:@"UID:%d\nToken:%@",uid,token]];
        [SVProgressHUD dismissWithDelay:2.5];
        
        [[Shogunate instance] uploadCreateRole:@"roleID" RoleName:@"roleName" RoleLevel:101 ServerID:1 ServerName:@"servername" VIPLevel:0 PartyName:@""];
        
    }];
    
}
- (IBAction)payCheck {
    
    [[Shogunate instance] createOrderNumber:[NSString stringWithFormat:@"%ld",(long)time(NULL)] Order:6 OrderName:@"测试-战争6元" RoleName:@"rolename" RoleID:@"roleid" RoleLevel:100 ServerID:10000 ServerName:@"sname" Extra:@"12"];
    
}

@end
