//
//  RXOSUserCenterConfig.h
//  RXUIKit-OS
//
//  Created by 陈汉 on 2023/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXOSUserCenterConfig : NSObject

/**
 * 透传给客服面板的参数 使用jsonString形式（客服用）
 */
@property (nonatomic, strong) NSString *transmit_args;
/**
 * 用户的游戏id（客服用）
 */
@property (nonatomic, strong) NSString *game_user_id;
/**
 * 用户昵称，不传默认取登录nickname（客服用）
 */
@property (nonatomic, strong) NSString *nickname;
/**
 * 用户头像（客服用）
 */
@property (nonatomic, strong) NSString *head_img_url;
/**
 * 在瑞雪客服系统设置的接入点名称 不填写默认为default（客服用）
 */
@property (nonatomic, strong) NSString *queue_name;
/**
 * 客服设置浅色模式，不设置默认为深色
 * @note 只在单独调用客服UI时生效
 * YES 为浅色，NO 为浅色模式
 */
@property (nonatomic, assign) BOOL setLightTheme;
/**
 * @note 不可用
 * 用户中心是否展示同步信息按钮，默认不展示
 * 用于同步三方信息
 * YES 为展示，NO 为不展示
 */
@property (nonatomic, assign) BOOL setSyncInfoEnable;
/**
 * 用户中心配置
 * 如不需要展示某一项可以将配置去掉，默认全展示
 * 配置用户中心入口结构如下：
 * @{@"btns" : @[@"real_name",                    实名认证
              @"privacy_policy",              隐私政策
              @"acount_cancel",              账号注销
              @"phone_management",    账号管理
              @"change_pwd"]                修改密码
 
 *   }
 */
@property (nonatomic, strong) NSDictionary *setConfigParams;

@end

NS_ASSUME_NONNULL_END
