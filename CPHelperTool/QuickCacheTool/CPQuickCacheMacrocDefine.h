//
//  CPQuickCacheMacrocDefine.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

/**
 *  文件描述
 *
 *  这个工具类宏定义封装了对
 *  NSUserDefault,NSCache,NSFileManager
 *  NSKeyedArchieve,NSDocumentDirectory,NSCacheDirectory的便捷操作
 */

#import "CPQuickCacheUitil.h"

/* 写宏定义的时候，前面变量参数的名字，多参数的时候不能方法名和后面调用方法的参数名字一样 */

/**
 *  检查一个valueObj,keyObj对象是否有一个是空的
 */
#define CPCheckKeyValueHasNull(keyObj,valueObj) [CPQuickCacheUitil checkValue:valueObj key:keyObj]

/**
 *  检查一个对象是否为空
 */
#define CPCheckObjectNull(object) [CPQuickCacheUitil isNullObject:object]

/**
 *  NSUserDefault 保存键值对 keyObj,valueObj
 */
#define CPUDFCache(keyObj,valueObj) [CPQuickCacheUitil userDefaultCache:valueObj key:keyObj]

/**
 *  NSUserDefault 删除键keyObj对应的值
 */
#define CPUDFRemove(keyObj) [CPQuickCacheUitil userDefaultRemove:keyObj]

/**
 *  NSUserDefault 获取键keyObj对应的值
 */
#define CPUDFGetValue(keyObj) [CPQuickCacheUitil userDefaultGetValue:keyObj]

/**
 *  NSUserDefault 判断键keyObject对应的值是否为空
 */
#define CPUDFEmptyValue(keyObj) [CPQuickCacheUitil userDefaultEmptyValue:keyObj]

/**
 *  NSCache 存储键值对 keyObj,valueObj
 */
#define CPNSCacheSet(keyObj,valueObj) [CPQuickCacheUitil systemMemoryCacheSet:valueObj key:keyObj]

/**
 *  NSCache 删除键keyObj对应的值
 */
#define CPNSCacheRemove(keyObj) [CPQuickCacheUitil systemMemoryCacheRemove:keyObj]

/**
 *  NSCache 获取键keyObj对应的值
 */
#define CPNSCacheGetValue(keyObj) [CPQuickCacheUitil systemMemoryCacheGetValue:keyObj]

/**
 *  NSCache 判断键keyObject对应的值是否为空
 */
#define CPNSCacheEmptyValue(keyObj) [CPQuickCacheUitil systemMemoryCacheEmptyValue:keyObj]

/**
 *  获取系统默认文件管理
 */
#define CPFileManager [CPQuickCacheUitil fileManager]

/**
 *  指定路径pathObj是否存在文件
 */
#define CPFileIsExist(pathObj) [CPQuickCacheUitil fileExist:pathObj]

/**
 *  指定路径pathObj是否存在目录
 */
#define CPFileDirectoryIsExist(pathObj) [CPQuickCacheUitil directoryExist:pathObj]

/**
 *  读取某个路径的二进制数据，返回 NSData
 */
#define CPFileRead(pathObj) [CPQuickCacheUitil readFromFile:pathObj]

/**
 *  将二进制数据写入文件 dataObj:NSData pathObj:NSString
 */
#define CPFileWrite(dataObj,pathObj) [CPQuickCacheUitil writeFileData:dataObj toPath:pathObj]

/**
 *  在指定路径创建目录，返回BOOL结果
 */
#define CPFileDirectoryCreate(pathObj) [CPQuickCacheUitil createDirectory:pathObj]

/**
 *  删除指定路径文件
 */
#define CPFileDeleteFile(path) [CPQuickCacheUitil deleteFileAtPath:path]

/**
 *  删除指定目录
 */
#define CPFileDeleteDirectory(path) [CPQuickCacheUitil deleteDirectoryAtPath:path]

/**
 *  从fromFilePath复制文件到toFilePath,shouldRemove标示是否删除复制源文件
 */
#define CPFileCopyFileIsRemove(fromFilePath,toFilePath,shouldRemove) [CPQuickCacheUitil copyFileFromPath:fromFilePath toPath:toFilePath isRemoveOld:shouldRemove]

/**
 *  将某个对象归档到指定路径
 */
#define CPArchieveObject(object,filePath) [CPQuickCacheUitil archieveObject:object toFilePath:filePath]

/**
 *  从指定路径读取被归档过的对象
 */
#define CPUnArchieveObject(fromFilePath) [CPQuickCacheUitil unarchieveFromPath:fromFilePath]

/**
 *  获取NSDocumentDirectory目录
 */
#define CPAppDocumentDirectory [CPQuickCacheUitil documentDirectory]

/**
 *  获取NSCacheDirectory目录
 */
#define CPAppCacheDirectory [CPQuickCacheUitil cacheDirectory]

/**
 *  返回文件名为fileName在NSDocumentDirectory中的路径
 */
#define CPAppDoucmentPath(fileName) [CPQuickCacheUitil documentDirectoryPath:fileName]

/**
 *  返回文件名为fileName在NSCacheDirectory中的路径
 */
#define CPAppCachePath(fileName) [CPQuickCacheUitil cacheDirectoryPath:fileName]

/**
 *  将object对象用fileName名字保存到NSDocumentDirectory目录下
 */
#define CPAppDocumentSave(object,fileName) [CPQuickCacheUitil documentDirectorySave:object withFileName:fileName]

/**
 *  将object对象用fileName名字保存到NSCacheDirectory目录下
 */
#define CPAppCacheSave(object,fileName) [CPQuickCacheUitil cacheDirectorySave:object withFileName:fileName]

/**
 *  删除NSDocumentDirectory目录下名为fileName的文件
 */
#define CPAppDocumentDelete(fileName)  [CPQuickCacheUitil documentDirectoryDelete:fileName]

/**
 *  删除NSCacheDirectory目录下名为fileName的文件
 */
#define CPAppCacheDelete(fileName) [CPQuickCacheUitil cacheDirectoryDelete:fileName]
