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

@end

NS_ASSUME_NONNULL_END
