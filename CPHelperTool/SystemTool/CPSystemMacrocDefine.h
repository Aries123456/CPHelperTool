//
//  CPSystemMacrocDefine.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

#import "CPSystemUitil.h"

/**
 *  去除performSelector警告
 *
 *  @param code 需要屏蔽警告的代码
 *
 *  @return
 */
#define CPSystemRemovePerformSelectorLeakWarning(code)                    \
_Pragma("clang diagnostic push")                                        \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")     \
code;                                                                   \
_Pragma("clang diagnostic pop")

/**
 *  当前App的版本号 float型
 */
#define CPSystemAppFloatVersion [CPSystemUitil appFloatVersion]

/**
 *  当前App的版本号 字符串型
 */
#define CPSystemAppStringVersion [CPSystemUitil appStringVersion]

/**
 *  当前AppBundle版本号
 */
#define CPSystemAppBundleIntVersion [CPSystemUitil appBundleIntVersion]

/**
 *  当前AppBundle版本号
 */
#define CPSystemAppBundleStringVersion [CPSystemUitil appBundleStringVersion]

/**
 *  当前App的bundleIdentifier
 */
#define CPSystemAppBundleIdentifier [CPSystemUitil appBundleIdentifier]

/**
 *  屏幕绝对画布
 */
#define CPSystemScreenBounds [CPSystemUitil screenBounds]

/**
 *  获取系统版本号
 */
#define CPSystemFloatVersion [CPSystemUitil currentSystemFloatVersion]

/**
 *  Description
 */
#define CPSystemStringVersion [CPSystemUitil currentSystemStringVersion]

/**
 *  Description
 */
#define CPSystemName [CPSystemUitil currentSystemName]

/**
 *  获取系统版本号
 */
#define CPSystemVersion [CPSystemUitil currentSystemVersion]

/**
 *  当前屏幕缩放倍数 float
 */
#define CPScreenScale [CPSystemUitil currentScreenScale]

/**
 *  当前屏幕缩放倍数 字符串
 */
#define CPScreenStringScale [CPSystemUitil currentScreenStringScale]

/**
 *  系统是否超过5.0
 */
#define CPSystemIsOver5 [CPSystemUitil isSystemVersionOver:5.0]

/**
 *  系统是否超过6.0
 */
#define CPSystemIsOver6 [CPSystemUitil isSystemVersionOver:6.0]

/**
 *  系统是否超过7.0
 */
#define CPSystemIsOver7 [CPSystemUitil isSystemVersionOver:7.0]

/**
 *  系统是否超过8.0
 */
#define CPSystemIsOver8 [CPSystemUitil isSystemVersionOver:8.0]

/**
 *  系统是否超过9.0
 */
#define CPSystemIsOver9 [CPSystemUitil isSystemVersionOver:9.0]

/**
 *  系统是否超过11.0
 */
#define CPSystemIsOver11 [CPSystemUitil isSystemVersionOver:11.0]

/**
 *  获取屏幕大小
 */
#define CPSystemScreenSize [CPSystemUitil deviceScreenSize]

/**
 *  750获取等比宽
 */
#define CPGeometricWidth(originalWidth) [CPSystemUitil geometricWidthOriginalWidth:originalWidth]

/**
 *  750获取等比高
 */
#define CPGeometricHeight(originalHeight) [CPSystemUitil geometricHeightOriginalHeight:originalHeight]

/**
 *  750获取等比Y
 */
#define CPGeometricY(originalY) [CPSystemUitil geometricYOriginalY:originalY]

/**
 *  750获取等比X
 */
#define CPGeometricX(originalX) [CPSystemUitil geometricXOriginalX:originalX]

/**
 *  获取屏幕宽度
 */
#define CPSystemScreenWidth [CPSystemUitil deviceScreenSize].width
/**
 *  获取屏幕高度
 */
#define CPSystemScreenHeight [CPSystemUitil deviceScreenSize].height
/**
 *  获取TableView实际高度
 */
#define CPSystemScreenHeightForMainTabBar CPSystemScreenHeight-123.0f

#define CPSystemScreenHeightForsubTabBar CPSystemScreenHeight-49.0f

/**
 *  是否iPhone4
 */
#define CPSystemiPhone4 [CPSystemUitil iPhone4Device]

/**
 *  是否iPhone5
 */
#define CPSystemiPhone5 [CPSystemUitil iPhone5Device]

/**
 *  是否iPhone6
 */
#define CPSystemiPhone6 [CPSystemUitil iPhone6Device]

/**
 *  是否iPhoneX
 */
#define CPSystemiPhoneX [CPSystemUitil iPhoneXDevice]

/**
 *  是否iPhone6 plus
 */
#define CPSystemiPhone6Plus [CPSystemUitil iPhone6PlusDevice]

/**
 *  是否iPad
 */
#define CPSystemiPad [CPSystemUitil iPadDevice]

/**
 *  系统UINavigationBar高度
 */
#define CPSystemNavigationBarHeight [CPSystemUitil naivationBarHeight]

/**
 *  Y轴增量
 */
#define CPSystemOriginYDelta 20.f

/**
 *  AppDelegate
 */
#define CPApplicationDelegate [UIApplication shareApplication].delegate

/**
 *  创建对象弱引用
 */
#define CPWeakObject(anObject)  __weak __typeof(anObject)

/**
 *  创建对象强引用
 */
#define CPStrongObject(anObject) __strong __typeof(anObject)

/**
 *  创建self弱引用
 */
#define CPWeakSelf CPWeakObject(self)

/**
 *  创建self强引用
 */
#define CPStrongSelf CPStrongObject(CPWeakSelf)

/**
 *  系统通知中心
 */
#define CPNotificationCenter [CPSystemUitil defaultCenter]

/**
 *  系统通知中心发noti名字的通知
 */
#define CPNotificationPost(noti) [CPSystemUitil postNoti:noti]

/**
 *  系统通知中心发noti名字的通知，携带参数对象object
 */
#define CPNotificationPostObj(noti,object) [CPSystemUitil postNoti:noti withObject:object]

/**
 *  系统通知中心发noti名字的通知，携带参数对象object ,携带用户自定义信息userInfo
 */
#define CPNotificationPostObjUserInfo(noti,object,userInfo) [CPSystemUitil postNoti:noti withObject:object withUserInfo:userInfo]

/**
 *  注册通知
 */
#define CPNotificationAdd(_noParamsFunc, _notifyName)  [[NSNotificationCenter defaultCenter] \
addObserver:self \
selector:@selector(_noParamsFunc) \
name:_notifyName \
object:nil];

/**
 *  获取mainBundle
 */
#define CPMainBundle [NSBundle mainBundle]

/**
 *  获取mainBundle内名字为fileName的文件的路径
 */
#define CPMainBundlePath(fileName) [CPSystemUitil mainBundlePath:fileName]

/**
 *  获取路径为bundlePath的指定bundle中文件名为fileName的文件路径
 */
#define CPBundlePath(bundlePath,fileName) [CPSystemUitil bundle:bundlePath file:fileName]


/**
 *  运行时给一个对象添加一个成员，添加的associateKey必须是一个静态常量字符串 static NSString * const associateKey = @"";
 */
#define CPAssociateOriginWithObject(originObj,associateObj,associateKey) [CPSystemUitil originObject:originObj associateObject:associateObj byKey:associateKey]

/**
 *  通过key获取运行时加入的成员
 */
#define CPGetAssociateObject(originObj,associateKey) [CPSystemUitil associateObjectFromOrigin:originObj byKey:associateKey]

/**
 *  移除辅助成员
 */
#define CPAssociateRemove(originObj) [CPSystemUitil associateRemoveFromOrigin:originObj]

/**
 *  照相机是否可用
 */
#define CPCameraIsAvailable [CPSystemUitil cameraAvailable]

/**
 *  前置摄像头是否可用
 */
#define CPFrontCameraAvailable [CPSystemUitil frontCameraAvailable]

/**
 *  照相机闪光灯是否可用
 */
#define CPCameraFlashAvailable [CPSystemUitil cameraFlashAvailable]

/**
 *  是否支持发短信
 */
#define CPSystemCanSendSMS [CPSystemUitil canSendSMS]

/**
 *  是否支持打电话
 */
#define CPSystemCanMakePhoneCall [CPSystemUitil canMakePhoneCall]

/**
 *  App是否有权限访问照片库
 */
#define CPAppCanAccessPhotoLibrary [CPSystemUitil isAppPhotoLibraryAccessAuthorized]

/**
 *  App是否有权限访问相机
 */
#define CPAppCanAccessCamera [CPSystemUitil isAppCameraAccessAuthorized]

/**
 *  获取屏幕Y轴起始点
 */
#define CPAppSelfViewFrameOrangeY [CPSystemUitil getSelfViewFrameOrangeY]

/**
 *  系统是否 >=7.0 <7.1
 */
#define CPSystemVersionIs7 [CPSystemUitil isSystemVersionIs7]

/**
 *  打开手电筒
 */
#define CPOpenFlashlight [CPSystemUitil openFlashlight]

/**
 *  关闭手电筒
 */
#define CPCloseFlashlight [CPSystemUitil closeFlashlight]

#define WEAKSELF typeof(self) __weak weakSelf = self;
#define STRONGSELF typeof(weakSelf) __strong strongSelf = weakSelf;

/**
 *  打印
 */
#ifdef DEBUG
#define CPLog(fmt,...)NSLog((@"%s [Line%d]" fmt),__PRETTY_FUNCTION__,__LINE__,##__VA_ARGS__)
#else
#define CPLog(...)
#endif


/**
 *  完美解决Xcode NSLog打印不全的宏 亲测目前支持到8.2bate版
 */
#ifdef DEBUG
//#define NSLog(format, ...) printf("class: <%p %s:(%d) > method: %s \n%s\n", self, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] )
#define NSLog(...) printf("%f %s\n",[[NSDate date]timeIntervalSince1970],[[NSString stringWithFormat:__VA_ARGS__]UTF8String]);
#else
#define NSLog(format, ...)
#endif

