//
//  CPStringUitil.m
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

#import "CPStringUitil.h"
#import <CommonCrypto/CommonDigest.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>

@implementation CPStringUitil
+ (BOOL)stringIsNull:(NSString *)string
{
    if (![string isKindOfClass:[NSString class]]) {
        return YES;
    }
    
    if (!string || [string isKindOfClass:[NSNull class]] || string.length == 0 || [string isEqualToString:@""]) {
        return YES;
    }else{
        return NO;
    }
}

+ (BOOL)stringIsAllWhiteSpace:(NSString *)string
{
    if (CPStringIsNull(string)) {
        return YES;
    }else{
        
        NSString *trimString = [string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        
        if (trimString.length > 0) {
            return NO;
        }else{
            return YES;
        }
    }
}

+ (BOOL)stringToBool:(NSString*)sourceString
{
    if (CPStringIsNull(sourceString)) {
        return NO;
    }else{
        return [sourceString boolValue];
    }
}

+ (NSInteger)stringToInt:(NSString*)sourceString
{
    if (CPStringIsNull(sourceString)) {
        return NSIntegerMax;
    }else{
        return [sourceString intValue];
    }
}

+ (CGFloat)stringToFloat:(NSString*)sourceString
{
    if (CPStringIsNull(sourceString)) {
        return CGFLOAT_MAX;
    }else{
        return [sourceString floatValue];
    }
}

+ (double)stringToDouble:(NSString*)sourceString
{
    if (CPStringIsNull(sourceString)) {
        return CGFLOAT_MAX;
    }else{
        return [sourceString doubleValue];
    }
}

+ (NSString *)boolToString:(BOOL)boolValue
{
    return [NSString stringWithFormat:@"%d",boolValue];
}

+ (NSString *)intToString:(NSInteger)intValue
{
    return [NSString stringWithFormat:@"%ld",(long)intValue];
}

+ (NSString *)floatToString:(CGFloat)floatValue
{
    return [NSString stringWithFormat:@"%f",floatValue];
}

+ (NSString *)doubleToString:(double)doubleValue
{
    return [NSString stringWithFormat:@"%lf",doubleValue];
}

+ (NSString*)stringFromFile:(NSString*)path
{
    if (CPStringIsNull(path)) {
        return nil;
    }
    return [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
}

+ (BOOL)sourceString:(NSString*)sourceString regexMatch:(NSString *)regexString
{
    if (CPStringIsNull(sourceString) || CPStringIsNull(regexString) ) {
        return NO;
    }
    
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regexString];
    return [emailTest evaluateWithObject:sourceString];
}

+ (BOOL)stringIsValidateEmailAddress:(NSString *)string
{
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    return [CPStringUitil sourceString:string regexMatch:emailRegex];
}

+ (BOOL)stringISValidateMobilePhone:(NSString *)string
{
    //手机号以13， 15，18开头，八个 \d 数字字符
    NSString *phoneRegex = @"^((13[0-9])|(15[^4,\\D])|(18[0,0-9]))\\d{8}$";
    return [CPStringUitil sourceString:string regexMatch:phoneRegex];
}

+ (BOOL)stringISValidateCarNumber:(NSString *)string
{
    NSString *carRegex = @"^[\u4e00-\u9fa5]{1}[a-zA-Z]{1}[a-zA-Z_0-9]{4}[a-zA-Z_0-9_\u4e00-\u9fa5]$";
    return [CPStringUitil sourceString:string regexMatch:carRegex];
}

+ (BOOL)stringIsValidateUrl:(NSString *)string
{
    NSString *checkRegex = @"^(([hH][tT]{2}[pP][sS]?)|([fF][tT][pP]))\\:\\/\\/[wW]{3}\\.[\\w-]+\\.\\w{2,4}(\\/.*)?$";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

+ (BOOL)stringIsAllChineseWord:(NSString *)string
{
    NSString *checkRegex = @"^[\u4e00-\u9fa5]+$";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

+ (BOOL)stringISValidatePersonCardNumber:(NSString *)string
{
    NSString *regex2 = @"^(\\d{14}|\\d{17})(\\d|[xX])$";
    return [CPStringUitil sourceString:string regexMatch:regex2];
}

+ (BOOL)stringIsValidatePhone:(NSString *)string
{
    NSString *phoneRegex = @"^(^0\\d{2}-?\\d{8}$)|(^0\\d{3}-?\\d{7}$)|(^\\(0\\d{2}\\)-?\\d{8}$)|(^\\(0\\d{3}\\)-?\\d{7}$)$";
    return [CPStringUitil sourceString:string regexMatch:phoneRegex];
}

+ (BOOL)stringIsValidateMailCode:(NSString *)string
{
    NSString *mailCodeRegex = @"^\\d{6}$";
    return [CPStringUitil sourceString:string regexMatch:mailCodeRegex];
}

+ (BOOL)stringJustHasNumberAndCharacter:(NSString *)string
{
    NSString *checkRegex = @"[a-z][A-Z][0-9]";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

+ (BOOL)stringIsOnlyNumberAndEnCode:(NSString *)string
{
    NSString *checkRegex = @"^[A-Za-z0-9]+$";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

+ (BOOL)stringChineseNumberCharacterOnly:(NSString *)string
{
    NSString *checkRegex = @"[a-zA-Z\u4e00-\u9fa5][a-zA-Z0-9\u4e00-\u9fa5]+";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

+ (BOOL)stringJustHasNumber:(NSString *)string
{
    NSString *checkRegex = @"^[0-9]*$";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

//验证位数 四位 有效 数字+ 2位小数
+ (BOOL)stringIsFourNumberWithSecond:(NSString *)string
{
    NSString *checkRegex = @"^(?=([0-9]{1,10}$|[0-9]{1,4}\\.))(0|[1-9][0-9]*)(\\.[0-9]{1,2})?$";
    return [CPStringUitil sourceString:string regexMatch:checkRegex];
}

+ (NSString*)currentTimeStampString
{
    NSDate *now = [NSDate date];
    NSTimeInterval timeInterval = [now timeIntervalSinceReferenceDate];
    
    NSString *timeString = [NSString stringWithFormat:@"%lf",timeInterval];
    timeString = [timeString stringByReplacingOccurrencesOfString:@"." withString:@""];
    
    return timeString;
    
}

+ (NSString *)unarchieveFromPath:(NSString *)filePath
{
    return CPUnArchieveObject(filePath);
}

+ (NSString *)MD5:(NSString *)string
{
    const char* aString = [string UTF8String];
    unsigned char result[16];
    CC_MD5(aString, (CC_LONG)strlen(aString), result);
    NSString* hash = [NSString stringWithFormat:@"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
                      result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7],
                      result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]];
    
    return [hash lowercaseString];
}

+ (NSString *)stringByTrimingLeadingWhiteSpace:(NSString *)string
{
    NSRange range = [string rangeOfString:@"^\\s*" options:NSRegularExpressionSearch];
    return [string stringByReplacingCharactersInRange:range withString:@""];
}

+ (NSString *)stringByTrimingTailingWhiteSpace:(NSString *)string
{
    NSRange range = [string rangeOfString:@"\\s*$" options:NSRegularExpressionSearch];
    return [string stringByReplacingCharactersInRange:range withString:@""];
}

+ (NSString *)stringByTrimingWhiteSpace:(NSString *)string
{
    return [string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
}

// 转化为UTF8编码
+ (NSString *)urlEncode:(id)object {
    
    if (CPCheckObjectNull(object)) {
        return nil;
    }
    
    NSString *string = (NSString*)object;
    NSString *encodedValue = (__bridge NSString*)CFURLCreateStringByAddingPercentEscapes(nil, (CFStringRef)string, nil, (CFStringRef)@"!*'();:@&=+$,/?%#[]", kCFStringEncodingUTF8);
    return encodedValue;
}

+ (NSString *)urlDecode:(id)object {
    if (CPCheckObjectNull(object)) {
        return nil;
    }
    NSString *string = (NSString*)object;
    NSString *encodedValue = (__bridge NSString*)CFURLCreateStringByReplacingPercentEscapes(NULL, (CFStringRef) string, CFSTR(""));
    return encodedValue;
}

+ (NSString *)encodeStringFromDict:(NSDictionary *)dict
{
    if (CPCheckObjectNull(dict)) {
        return nil;
    }
    
    NSMutableArray *parts = [NSMutableArray array];
    for (id key in dict) {
        @autoreleasepool {
            id value = [dict objectForKey: key];
            NSString *part = [NSString stringWithFormat: @"%@=%@",[CPStringUitil urlEncode:key],[CPStringUitil urlEncode:value]];
            [parts addObject: part];
        }
    }
    return [parts componentsJoinedByString: @"&"];//拼装字符串
}

+ (NSRange)stringRange:(NSString *)string
{
    if (CPStringIsNull(string)) {
        return NSMakeRange(NSNotFound, 0);
    }
    return NSMakeRange(0, string.length);
}

+ (NSString *)jsonStringFromNSDictionary:(NSDictionary *)dict
{
    NSString *res = nil;
    if (dict) {
        NSError *error = nil;
        NSData *data  = [NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:&error];
        if (!error) {
            res = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        }
    }
    return res;
}

+ (NSDictionary *)dictionaryFromJSONString:(NSString *)str
{
    NSDictionary *res = nil;
    if (str) {
        NSData *data = [str dataUsingEncoding:NSUTF8StringEncoding];
        NSError *error;
        id obj = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
        if (!error) {
            res = obj;
        }
    }
    return res;
}

+ (NSString *)jsonStringFromNSArray:(NSArray *)array
{
    NSString *res = nil;
    if (array) {
        
        if ( ![[array class] isSubclassOfClass:[NSArray class]] || [array count] == 0) {
            return @"[]";
        }
        
        NSError *error = nil;
        NSData *data  = [NSJSONSerialization dataWithJSONObject:array options:NSJSONWritingPrettyPrinted error:&error];
        if (!error) {
            res = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        }
    }
    return res;
}

+ (NSArray *)arrayFromJSONString:(NSString *)str
{
    NSArray *res = nil;
    if (str) {
        NSData *data = [str dataUsingEncoding:NSUTF8StringEncoding];
        NSError *error;
        id Obj = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
        if (!error) {
            res = Obj;
        }
    }
    return res;
}

////Unicode转UTF-8 中文表情 ✌️
+ (NSString*)replaceUnicode:(NSString*)aUnicodeString
{
    NSString *tempStr1 = [aUnicodeString stringByReplacingOccurrencesOfString:@"\\u"withString:@"\\U"];
    
    NSString *tempStr2 = [tempStr1 stringByReplacingOccurrencesOfString:@"\""withString:@"\\\""];
    
    NSString *tempStr3 = [[@"\""stringByAppendingString:tempStr2] stringByAppendingString:@"\""];
    
    NSData *tempData = [tempStr3 dataUsingEncoding:NSUTF8StringEncoding];
    
    NSString* returnStr = [NSPropertyListSerialization propertyListFromData:tempData
                           
                                                           mutabilityOption:NSPropertyListImmutable
                           
                                                                     format:NULL
                           
                                                           errorDescription:NULL];
    
    return [returnStr stringByReplacingOccurrencesOfString:@"\\r\\n"withString:@"\n"];
}

//是否包含emoji
+ (BOOL)stringIsContainEmoji:(NSString *)string
{
    __block BOOL containsEmoji = NO;
    
    [string enumerateSubstringsInRange:NSMakeRange(0,
                                                   [string length])
                               options:NSStringEnumerationByComposedCharacterSequences
                            usingBlock:^(NSString *substring,
                                         NSRange substringRange,
                                         NSRange enclosingRange,
                                         BOOL *stop)
     {
         const unichar hs = [substring characterAtIndex:0];
         // surrogate pair
         if (0xd800 <= hs &&
             hs <= 0xdbff)
         {
             if (substring.length > 1)
             {
                 const unichar ls = [substring characterAtIndex:1];
                 const int uc = ((hs - 0xd800) * 0x400) + (ls - 0xdc00) + 0x10000;
                 if (0x1d000 <= uc &&
                     uc <= 0x1f9c0)
                 {
                     containsEmoji = YES;
                 }
             }
         }
         else if (substring.length > 1)
         {
             const unichar ls = [substring characterAtIndex:1];
             if (ls == 0x20e3 ||
                 ls == 0xfe0f ||
                 ls == 0xd83c)
             {
                 containsEmoji = YES;
             }
         }
         else
         {
             // non surrogate
             if (0x2100 <= hs &&
                 hs <= 0x27ff)
             {
                 containsEmoji = YES;
             }
             else if (0x2B05 <= hs &&
                      hs <= 0x2b07)
             {
                 containsEmoji = YES;
             }
             else if (0x2934 <= hs &&
                      hs <= 0x2935)
             {
                 containsEmoji = YES;
             }
             else if (0x3297 <= hs &&
                      hs <= 0x3299)
             {
                 containsEmoji = YES;
             }
             else if (hs == 0xa9 ||
                      hs == 0xae ||
                      hs == 0x303d ||
                      hs == 0x3030 ||
                      hs == 0x2b55 ||
                      hs == 0x2b1c ||
                      hs == 0x2b1b ||
                      hs == 0x2b50)
             {
                 containsEmoji = YES;
             }
         }
         
         if (containsEmoji)
         {
             *stop = YES;
         }
     }];
    
    return containsEmoji;
}

//获取 Mac 地址
+ (NSString *)getMacAddress
{
    int mib[6];
    size_t len;
    char *buf;
    unsigned char *ptr;
    struct if_msghdr *ifm;
    struct sockaddr_dl *sdl;
    
    mib[0] = CTL_NET;
    mib[1] = AF_ROUTE;
    mib[2] = 0;
    mib[3] = AF_LINK;
    mib[4] = NET_RT_IFLIST;
    
    if ((mib[5] = if_nametoindex("en0")) == 0) {
        printf("Error: if_nametoindex error/n");
        return NULL;
    }
    
    if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
        printf("Error: sysctl, take 1/n");
        return NULL;
    }
    
    if ((buf = malloc(len)) == NULL) {
        printf("Could not allocate memory. error!/n");
        return NULL;
    }
    
    if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
        free(buf);
        printf("Error: sysctl, take 2");
        return NULL;
    }
    
    ifm = (struct if_msghdr *)buf;
    sdl = (struct sockaddr_dl *)(ifm + 1);
    ptr = (unsigned char *)LLADDR(sdl);
    
    // MAC地址带冒号
    // NSString *outstring = [NSString stringWithFormat:@"%02x:%02x:%02x:%02x:%02x:%02x", *ptr, *(ptr+1), *(ptr+2),
    // *(ptr+3), *(ptr+4), *(ptr+5)];
    
    // MAC地址不带冒号
    NSString *outstring = [NSString
                           stringWithFormat:@"%02x%02x%02x%02x%02x%02x", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4), *(ptr + 5)];
    
    free(buf);
    
    return [outstring uppercaseString];
}

//字符串去除小数点
+ (NSString *)filterDecimalPoint:(NSString *)pointString
{
    if ([pointString containsString:@"."])
    {
        NSRange range = [pointString rangeOfString:@"."];
        pointString = [pointString substringToIndex:range.location];
    }
    return pointString;
}

+ (NSString *)hexadecimalFromDecimalSystem:(NSString *)decimalSystem
{
    char hexChar[6];
    sprintf(hexChar, "%lx", (long)decimalSystem.integerValue);
    NSString *hexString = [NSString stringWithCString:hexChar encoding:NSUTF8StringEncoding];
    if (hexString.length < 2) {
        hexString = [NSString stringWithFormat:@"0%@",hexString];
    }
    return hexString.uppercaseString;
}

+ (NSString *)decimalSystemFromHexadecimal:(NSString *)hexadecimal
{
    const char *hexChar = [hexadecimal cStringUsingEncoding:NSUTF8StringEncoding];
    int hexNumber;
    sscanf(hexChar, "%x", &hexNumber);
    return [NSString stringWithFormat:@"%d",hexNumber];
}

@end
