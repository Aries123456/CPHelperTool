//
//  CPStringMacrocDefine.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

/**
 *  文件描述
 *
 *  这个工具宏封装了大部分字符串常用的便捷方法
 */

#import "CPStringUitil.h"

/**
 *  字符串是否为空
 */
#define CPStringIsNull(string) [CPStringUitil stringIsNull:string]

/**
 *  字符串是否全为空格
 */
#define CPStringIsAllWhiteSpace(string) [CPStringUitil stringIsAllWhiteSpace:string]

/**
 *  字符串转NSInteger
 */
#define CPStringToInt(string) [CPStringUitil stringToInt:string]

/**
 *  字符串转CGFloat
 */
#define CPStringToFloat(string) [CPStringUitil stringToFloat:string]

/**
 *  字符串转double
 */
#define CPStringToDouble(string) [CPStringUitil stringToDouble:string]

/**
 *  字符串转Bool
 */
#define CPStringToBool(string) [CPStringUitil stringToBool:string]

/**
 *  int转字符串
 */
#define CPStringFromInt(int) [CPStringUitil intToString:int]

/**
 *  float转字符串
 */
#define CPStringFromFloat(float) [CPStringUitil floatToString:float]

/**
 *  double转字符串
 */
#define CPStringFromDouble(double) [CPStringUitil doubleToString:double]

/**
 *  bool转字符串
 */
#define CPStringFromBool(bool) [CPStringUitil boolToString:bool]

/**
 *  字符串是否合法邮箱
 */
#define CPStringIsEmail(string) [CPStringUitil stringIsValidateEmailAddress:string]

/**
 *  字符串是否合法手机号码
 */
#define CPStringIsMobilePhone(string) [CPStringUitil stringISValidateMobilePhone:string]

/**
 *  字符串是否合法url
 */
#define CPStringIsUrl(string) [CPStringUitil stringIsValidateUrl:string]

/**
 *  字符串是否合法座机
 */
#define CPStringIsPhone(string) [CPStringUitil stringIsValidatePhone:string]

/**
 *  字符串是否合法邮政编码
 */
#define CPStringIsMailCode(string) [CPStringUitil stringIsValidateMailCode:string]

/**
 *  字符串是否合法身份证号
 */
#define CPStringIsPersonCardNumber(string) [CPStringUitil stringISValidatePersonCardNumber:string]

/**
 *  字符串是否合法车牌号
 */
#define CPStringIsCarNumber(string) [CPStringUitil stringISValidateCarNumber:string]

/**
 *  字符串是否只有中文字符
 */
#define CPStringChineseOnly(string) [CPStringUitil stringIsAllChineseWord:string]

/**
 *  字符串是否只有英文字符
 */
#define CPStringCharNumOnly(string) [CPStringUitil stringJustHasNumberAndCharacter:string]

/**
 *  字符串是否只包含字符，中文，数字
 */
#define CPStringCharNumChineseOnly(string) [CPStringUitil stringChineseNumberCharacterOnly:string]

/**
 *  字符串是否纯数字
 */
#define CPStringNumOnly(string) [CPStringUitil stringJustHasNumber:string]

//^(?=([0-9]{1,10}$|[0-9]{1,4}\.))(0|[1-9][0-9]*)(\.[0-9]{1,2})?$ 验证位数 四位 有效 数字+ 2位小数
#define CPStringIsFourNumberWithSecond(string) [CPStringUitil stringIsFourNumberWithSecond:string]

/**
 字符串是否只包含数字 字母
 */
#define CPStringNumOnlyAndEn(string) [CPStringUitil stringIsOnlyNumberAndEnCode:string]

/**
 *  从文件中读取出字符串
 */
#define CPStringFromFile(path) [CPStringUitil stringFromFile:path]

/**
 *  从归档路径读取出字符串
 */
#define CPStringUnArchieve(path) [CPStringUitil unarchieveFromPath:path]

/**
 *  获取一个当前时间戳字符串
 */
#define CPStringCurrentTimeStamp [CPStringUitil currentTimeStampString]

/**
 *  将字符串转为MD5字符串
 */
#define CPStringToMD5(string) [CPStringUitil MD5:string]

/**
 *  返回去除字符串首的空格的字符串
 */
#define CPStringClearLeadingWhiteSpace(string) [CPStringUitil stringByTrimingLeadingWhiteSpace:string]

/**
 *  返回去除字符串结尾的空格的字符串
 */
#define CPStringClearTailingWhiteSpace(string) [CPStringUitil stringByTrimingTailingWhiteSpace:string]

/**
 *  返回去除字符串中所有的空格的字符串
 */
#define CPStringClearAllWhiteSpace(string) [CPStringUitil stringByTrimingWhiteSpace:string]

/**
 *  Url编码对象,通常是字符串,返回编码后的字符串
 */
#define CPStringEncodeString(string) [CPStringUitil urlEncode:string]

/**
 *  Url解码
 */
#define CPStringDecodeString(string) [CPStringUitil urlDecode:string]

/**
 *  Url编码一个字典,键值对用@链接,返回编码后的字符串
 */
#define CPStringEncodeDict(aDict) [CPStringUitil encodeStringFromDict:aDict]

/**
 *  返回字符串范围
 */
#define CPStringRange(string) [CPStringUitil stringRange:string]

/**
 *  根据字典返回json字符串 失败就是nil
 */
#define CPJSONStringFromNSDict(dict) [CPStringUitil jsonStringFromNSDictionary:dict]

/**
 *  根据json字符串返回字典 失败就是nil
 */
#define CPDictionaryFromJSONString(string) [CPStringUitil dictionaryFromJSONString:string]

/**
 *  根据json字符串返回array 失败就是nil
 */
#define CPJSONStringFromNSArray(array) [CPStringUitil jsonStringFromNSArray:array]

/**
 *  根据array返回json字符串 失败就是nil
 */
#define CPArrayFromJSONString(string) [CPStringUitil arrayFromJSONString:string]

/**
 *  Unicode转UTF-8 中文表情 ✌️
 */
#define CPReplaceUnicodeString(string) [CPStringUitil replaceUnicode:string]

/**
 *  是否包含emoji标签
 *  @return YES 包含 NO 不包含
 */
#define CPStringIsContainEmoji(string) [CPStringUitil stringIsContainEmoji:string]

/**
 *  获取 MAC 地址
 *  @return YES 包含 NO 不包含
 */
#define CPStringGetMacAddress [CPStringUitil getMacAddress]

/**
 *  字符串去除小数点
 */
#define CPStringFilterDecimalPoint(string) [CPStringUitil filterDecimalPoint:string]
