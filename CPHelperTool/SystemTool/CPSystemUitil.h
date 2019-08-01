//
//  CPSystemUitil.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPHelperTool.h"

@interface CPSystemUitil : NSObject

+ (CGFloat)geometricWidthOriginalWidth:(CGFloat)originalWidth;
+ (CGFloat)geometricHeightOriginalHeight:(CGFloat)originalHeight;
+ (CGFloat)geometricYOriginalY:(CGFloat)originalY;
+ (CGFloat)geometricXOriginalX:(CGFloat)originalX;

+ (CGFloat)appFloatVersion;

+ (NSString *)appStringVersion;

+ (NSString *)appBundleStringVersion;

+ (NSInteger)appBundleIntVersion;

+ (NSString *)appBundleIdentifier;

+ (CGFloat)currentSystemFloatVersion;

+ (NSString *)currentSystemStringVersion;

+ (NSString *)currentSystemName;

+ (CGFloat)currentScreenScale;

+ (NSString *)currentScreenStringScale;

+ (CGRect)screenBounds;

+ (BOOL)isSystemVersionOver:(CGFloat)versionValue;

+ (BOOL)iPadDevice;

+ (BOOL)iPhone4Device;

+ (BOOL)iPhone5Device;

+ (BOOL)iPhone6Device;

+ (BOOL)iPhone6PlusDevice;

+ (BOOL)iPhoneXDevice;

+ (CGSize)deviceScreenSize;

+ (CGFloat)naivationBarHeight;

+ (NSNotificationCenter *)defaultCenter;

+ (void)postNoti:(NSString *)notiName;

+ (void)postNoti:(NSString *)notiName withObject:(id)obj;

+ (void)postNoti:(NSString *)notiName withObject:(id)obj withUserInfo:(NSDictionary *)infoDict;

+ (NSString *)mainBundlePath:(NSString*)fileName;

+ (NSString *)bundle:(NSString *)bundle file:(NSString *)file;

+ (void)showNetworkIndicatorActivity:(BOOL)state;

+ (void)originObject:(id)originObject associateObject:(id)anObject byKey:(NSString * const)associateKey;

+ (id)associateObjectFromOrigin:(id)originObject byKey:(NSString * const)associateKey;

+ (void)associateRemoveFromOrigin:(id)originObject;

+ (BOOL)cameraAvailable;

+ (BOOL)frontCameraAvailable;

+ (BOOL)cameraFlashAvailable;

+ (BOOL)canSendSMS;

+ (BOOL)canMakePhoneCall;

+ (BOOL)isAppCameraAccessAuthorized;

+ (BOOL)isAppPhotoLibraryAccessAuthorized;

/**
 *  获取屏幕Y轴起始点
 */
+(double)getSelfViewFrameOrangeY;

/**
 *  系统是否 >=7.0 <7.1
 */
+(BOOL)isSystemVersionIs7;

/** 打开手电筒 */
+ (void)openFlashlight;
/** 关闭手电筒 */
+ (void)closeFlashlight;

/**获取UUID */
+(NSString *)getUUID;
/**数据存入钥匙串*/
+ (void)saveKeyChain:(NSString *)service data:(id)data;
/**读取钥匙串数据*/
+ (id)loadKeyChain:(NSString *)service;
/**删除钥匙串数据*/
+ (void)deleteKeyChain:(NSString *)service;
@end
