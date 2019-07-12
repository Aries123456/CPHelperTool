//
//  CPSystemUitil.m
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

#import "CPSystemUitil.h"
#import <objc/runtime.h>
#import <AVFoundation/AVFoundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
@implementation CPSystemUitil

+ (CGFloat)appFloatVersion
{
    NSDictionary *infoDict = [[NSBundle mainBundle]infoDictionary];
    return [infoDict[@"CFBundleShortVersionString"] floatValue];
}

+ (NSString *)appStringVersion
{
    NSDictionary *infoDict = [[NSBundle mainBundle]infoDictionary];
    return infoDict[@"CFBundleShortVersionString"];
}

+ (NSString *)appBundleStringVersion
{
    NSDictionary *infoDict = [[NSBundle mainBundle]infoDictionary];
    return infoDict[@"CFBundleVersion"];
}

+ (NSInteger)appBundleIntVersion
{
    NSDictionary *infoDict = [[NSBundle mainBundle]infoDictionary];
    return [infoDict[@"CFBundleVersion"] unsignedIntegerValue];
}

+ (NSString *)appBundleIdentifier
{
    return [[NSBundle mainBundle]bundleIdentifier];
}

+ (BOOL)isSystemVersionOver:(CGFloat)versionValue
{
    return [CPSystemUitil currentSystemFloatVersion] >= versionValue;
}

+ (CGRect)screenBounds
{
    return [UIScreen mainScreen].bounds;
}

+ (CGFloat)currentSystemFloatVersion
{
    return [[UIDevice currentDevice].systemVersion floatValue];
}

+ (NSString *)currentSystemStringVersion
{
    return [UIDevice currentDevice].systemVersion;
}

+ (NSString *)currentSystemName
{
    return [UIDevice currentDevice].systemName;
}

+ (CGFloat)currentScreenScale
{
    return [UIScreen mainScreen].scale;
}

+ (NSString *)currentScreenStringScale
{
    return [NSString stringWithFormat:@"%d",(int)[UIScreen mainScreen].scale];
}

+ (BOOL)iPadDevice
{
    return UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad;
}

+ (BOOL)iPhone4Device
{
    return CGSizeEqualToSize((CGSize){320,480}, [CPSystemUitil deviceScreenSize]);
}

+ (BOOL)iPhone5Device
{
    return CGSizeEqualToSize((CGSize){320,568}, [CPSystemUitil deviceScreenSize]);
    
}

+ (BOOL)iPhone6Device
{
    return CGSizeEqualToSize((CGSize){375,667}, [CPSystemUitil deviceScreenSize]);
}

+ (BOOL)iPhone6PlusDevice
{
    return CGSizeEqualToSize((CGSize){414,736}, [CPSystemUitil deviceScreenSize]);
}

+ (BOOL)iPhoneXDevice
{
    if (CGSizeEqualToSize((CGSize){375,812}, [CPSystemUitil deviceScreenSize]))
    {//X XS
        return YES;
    }else if (CGSizeEqualToSize((CGSize){414,896}, [CPSystemUitil deviceScreenSize]))
    {//XR XSMAX
        return YES;
    }else
    {
        return NO;
    }
}

+ (CGFloat)geometricWidthOriginalWidth:(CGFloat)originalWidth
{
    return originalWidth / 375 * CPSystemScreenWidth;
}

+ (CGFloat)geometricHeightOriginalHeight:(CGFloat)originalHeight
{
    if (CPSystemiPhoneX) {
        return originalHeight * CPSystemScreenHeight / 812;
    }else
    {
        return originalHeight * CPSystemScreenHeight / 667;
    }
}

+ (CGFloat)geometricYOriginalY:(CGFloat)originalY
{
    if (CPSystemiPhoneX) {
        return originalY * CPSystemScreenHeight / 812;
    }else
    {
        return originalY * CPSystemScreenHeight / 667;
    }
}

+ (CGFloat)geometricXOriginalX:(CGFloat)originalX
{
    return originalX * CPSystemScreenWidth / 375;
}

+ (CGSize)deviceScreenSize
{
    return [UIScreen mainScreen].bounds.size;
}

+ (CGFloat)naivationBarHeight
{
    return 44.f;
}

+ (NSNotificationCenter *)defaultCenter
{
    return [NSNotificationCenter defaultCenter];
}

+ (void)postNoti:(NSString *)notiName
{
    [CPSystemUitil postNoti:notiName withObject:nil];
}

+ (void)postNoti:(NSString *)notiName withObject:(id)obj
{
    [CPSystemUitil postNoti:notiName withObject:obj withUserInfo:nil];
}

+ (void)postNoti:(NSString *)notiName withObject:(id)obj withUserInfo:(NSDictionary *)infoDict
{
    if (CPStringIsNull(notiName)) {
        CPLog(@"CPSystemUitil 不可以发送空的通知名:%@",notiName);
        return;
    }
    [[CPSystemUitil defaultCenter]postNotificationName:notiName object:obj userInfo:infoDict];
}

+ (NSString *)mainBundlePath:(NSString*)fileName
{
    if (CPStringIsNull(fileName)) {
        return nil;
    }
    NSArray *fileArray = [fileName componentsSeparatedByString:@"."];
    if (fileArray.count < 2) {
        return nil;
    }
    return [CPMainBundle  pathForResource:fileArray[0] ofType:fileArray[1]];
}

+ (NSString *)bundle:(NSString *)bundle file:(NSString *)file
{
    if (CPStringIsNull(bundle)||CPStringIsNull(file)) {
        return nil;
    }
    return [bundle stringByAppendingPathComponent:file];
}

+ (void)showNetworkIndicatorActivity:(BOOL)state
{
    [[UIApplication sharedApplication]setNetworkActivityIndicatorVisible:state];
}

+ (void)originObject:(id)originObject associateObject:(id)anObject byKey:(NSString *const)associateKey
{
    if (CPCheckObjectNull(originObject) || CPCheckObjectNull(anObject)) {
        return;
    }
    
    objc_setAssociatedObject(originObject, &associateKey, anObject, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

+ (id)associateObjectFromOrigin:(id)originObject byKey:(NSString *const)associateKey
{
    if (CPCheckObjectNull(originObject) || CPStringIsNull(associateKey)) {
        return nil;
    }
    id associateObj = objc_getAssociatedObject(originObject, &associateKey);
    return associateObj;
}

+ (void)associateRemoveFromOrigin:(id)originObject
{
    if (CPCheckObjectNull(originObject)) {
        return;
    }
    objc_removeAssociatedObjects(originObject);
}

+ (BOOL)cameraAvailable
{
    return [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera];
}

+ (BOOL)frontCameraAvailable
{
    return [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceFront];
}

+ (BOOL)cameraFlashAvailable
{
    return [UIImagePickerController isFlashAvailableForCameraDevice:UIImagePickerControllerCameraDeviceRear];
}

+ (BOOL)canSendSMS
{
    return [[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"sms://"]];
}

+ (BOOL)canMakePhoneCall
{
    return [[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"tel://"]];
}

+ (BOOL)isAppCameraAccessAuthorized
{
    /* iOS7以上才有相机隐私控制 */
    if (!CPSystemIsOver7) {
        return YES;
    }
    
    NSString *mediaType = AVMediaTypeVideo;
    
    AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:mediaType];
    
    if (authStatus !=  AVAuthorizationStatusAuthorized) {
        
        return authStatus == AVAuthorizationStatusNotDetermined;
        
    }else{
        
        return YES;
    }
}

+ (BOOL)isAppPhotoLibraryAccessAuthorized
{
    ALAuthorizationStatus authStatus = [ALAssetsLibrary authorizationStatus];
    
    if (authStatus != ALAuthorizationStatusAuthorized) {
        
        return authStatus == ALAuthorizationStatusNotDetermined;
        
    }else{
        
        return YES;
    }
}

/**
 *  获取屏幕Y轴起始点
 */
+(double)getSelfViewFrameOrangeY
{
    double orangeY = 0.0;
    
    float verson = [[UIDevice currentDevice].systemVersion floatValue];
    if (verson >= (float)7.0 && verson < (float)7.1) {
        // 7.0 ViewY轴源点从屏幕顶部开始
        orangeY = 20 + 46;
    }
    
    return orangeY;
}

/**
 *  系统是否 >=7.0 <7.1
 */
+(BOOL)isSystemVersionIs7
{
    BOOL result = NO;
    
    float verson = [[UIDevice currentDevice].systemVersion floatValue];
    if (verson >= (float)7.0 && verson < (float)7.1) {
        // 7.0
        result = YES;
    }
    
    return result;
}

/** 打开手电筒 */
+ (void)openFlashlight
{
    AVCaptureDevice *captureDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    NSError *error = nil;
    if ([captureDevice hasTorch]) {
        BOOL locked = [captureDevice lockForConfiguration:&error];
        if (locked) {
            captureDevice.torchMode = AVCaptureTorchModeOn;
            [captureDevice unlockForConfiguration];
        }
    }
}

/** 关闭手电筒 */
+ (void)closeFlashlight
{
    AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    if ([device hasTorch]) {
        [device lockForConfiguration:nil];
        [device setTorchMode: AVCaptureTorchModeOff];
        [device unlockForConfiguration];
    }
}

@end
