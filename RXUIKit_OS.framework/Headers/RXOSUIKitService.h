//
//  RXOSUIKitService.h
//  RXUIKit-OS
//
//  Created by 陈汉 on 2023/6/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <RXSDK_Pure/RXSDK_Pure.h>
#import "RXOSUILoginConfig.h"
#import "RXOSUserCenterConfig.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    AntiBtnType_logout, // 退出登录
    AntiBtnType_default // 知道了
} AntiBtnType; // 防沉迷按钮类型


@protocol RXOSUILoginDelegate <NSObject>
/**
 * 登录回调
 * @param response 返回数据，登录失败返回nil
 * @param error 错误返回，登录成功返回nil
 */
- (void)rxu_LoginCallBackWithResponse:(NSDictionary * _Nullable)response error:(RX_CommonRequestError *)error;

@end


@interface RXOSUIKitService : NSObject

@property (nonatomic, weak) id <RXOSUILoginDelegate> loginDelegate;

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 配置logo
 * @param logo 展示的logo
 * @param titleImage 展示的标题图片
 */
- (void)configLogo:(UIImage *)logo titleImage:(UIImage *)titleImage;

/**
 * 调用登录弹窗
 * 有登录记录会显示快捷登录页面
 * @param config 登录页基础配置
 * @param loginEvent 页面操作事件，可回调自定义参数
 * @param complete 登录结果
 */
- (void)setLoginViewWithConfig:(RXOSUILoginConfig *)config
                    loginEvent:(NSDictionary *(^)(NSDictionary *loginEvent, LoginType loginType))loginEvent
                      complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 调用登录弹窗
 * 不显示快捷登录页面
 * @param config 登录页基础配置
 * @param loginEvent 页面操作事件，可回调自定义参数
 * @param complete 登录结果
 */
- (void)setNormalLoginViewWithConfig:(RXOSUILoginConfig *)config
                          loginEvent:(NSDictionary *(^)(NSDictionary *loginEvent, LoginType loginType))loginEvent
                            complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

// 关闭登陆弹窗
- (void)closeLoginView;

/**
 * 协议声明
 * @param key 默认展示的条款key
 * @param legalData 法务信息api返回的数据
 */
- (void)setPrivacyViewWithKey:(NSString *)key
                    legalData:(NSDictionary *)legalData;

/**
 * 实名认证
 * @param canClose 是否展示关闭按钮，默认不展示
 */
- (void)setRealauthViewWithCanClose:(BOOL)canClose
                           complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 防沉迷
 * @param title 标题
 * @param des 内容
 * @param btnTitle 按钮标题，点击后block回调
 */
- (void)setAntiAdditionViewWithTitle:(NSString *)title
                                 des:(NSString *)des
                            btnTitle:(NSString *)btnTitle
                            complete:(void(^)(void))complete;

/**
 * 找回密码
 */
- (void)getBackPasswordWithComplete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 设置密码
 */
- (void)setPasswordWithComplete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 找回密码 扩展方式
 * @param params 页面配置信息
 * ！username 默认填充的账号    #NSString类型
 * ！account_type  账号类型提示 （1-通用提示 ，2-手机号提示，3-邮箱提示 [可选 默认 2]）    #NSInteger类型
 * ！password_hint 输入密码提示文本 [可选]    #NSString类型
 * @param requestParams 回调函数
 * ！params 会将手机号或邮箱，密码等参数返回，由客户端处理业务逻辑，SDK会根据 return 的 needBreak 参数决定是否继续执行
 * 详情请参考文档示例
 */
- (void)getBackPasswordWithParams:(NSDictionary *)params
                    requestParams:(NSMutableDictionary *(^)(NSMutableDictionary *params))requestParams
                         complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 用户中心
 * @param config 基础配置
 */
- (void)userCenterWithConfig:(RXOSUserCenterConfig *)config
                    complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 帮助中心
 * @param config 基础配置
 */
- (void)serviceCenterWithConfig:(RXOSUserCenterConfig *)config
                       complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 客服
 * @param config 基础配置
 */
- (void)chatServiceWithConfig:(RXOSUserCenterConfig *)config
                     complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 协议
 */
- (void)setPrivacyWithComplete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 申请注销
 * @param config 基础配置
 */
- (void)applyForDeregisterWithConfig:(RXOSUserCenterConfig *)config
                            complete:(void(^)(NSDictionary *response))complete;

/**
 * 撤销注销
 */
- (void)destroyAccountStatusView:(void(^)(DestroyClickType clickType))complete;

/**
 * 分享弹窗
 * @param shareInfo 分享数据，传nil则由SDK调用埋点数据
 * @param needReport 分享成功后是否需要自动上报
 */
- (void)shareWithShareInfo:(NSDictionary *)shareInfo
                needReport:(BOOL)needReport
                  complete:(void(^)(NSDictionary *response, RX_CommonRequestError *error))complete;

/**
 * 自定义webView
 * @param url 链接
 * @param title 标题
 */
- (void)openWebViewWithUrl:(NSString *)url
                     title:(NSString *)title;

@end

NS_ASSUME_NONNULL_END
