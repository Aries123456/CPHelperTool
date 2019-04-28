//
//  CPQuickCacheUitil.m
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

#import "CPQuickCacheUitil.h"

@implementation CPQuickCacheUitil
+ (BOOL)isNullObject:(id)anObject
{
    if (!anObject || [anObject isKindOfClass:[NSNull class]]) {
        return YES;
    }else{
        return NO;
    }
}

+ (BOOL)checkValue:(id)value key:(id)key
{
    if(CPCheckObjectNull(value)||CPCheckObjectNull(key)){
        return YES;
    }else{
        return NO;
    }
}

+ (NSUserDefaults *)standDefault
{
    return [NSUserDefaults standardUserDefaults];
}

+ (void)userDefaultCache:(id<NSCoding>)value key:(id)key
{
    if (CPCheckKeyValueHasNull(key, value)) {
        return;
    }
    [[CPQuickCacheUitil standDefault]setObject:value forKey:key];
}

+ (void)userDefaultRemove:(id)key
{
    if (CPCheckObjectNull(key)) {
        return;
    }
    [[CPQuickCacheUitil standDefault]removeObjectForKey:key];
}

+ (id)userDefaultGetValue:(id)key
{
    if (CPCheckObjectNull(key)) {
        return nil;
    }
    return [[CPQuickCacheUitil standDefault]objectForKey:key];
}

+ (BOOL)userDefaultEmptyValue:(id)key
{
    return [CPQuickCacheUitil userDefaultGetValue:key] == nil;
}

+ (NSCache *)shareCache
{
    static NSCache *_CPNSCacheInstance = nil;
    static dispatch_once_t onceToken;
    
    CPDispatchOnce(onceToken, ^{
        
        if (!_CPNSCacheInstance) {
            _CPNSCacheInstance = [[NSCache alloc]init];
        }
        
    });
    
    return _CPNSCacheInstance;
}

+ (void)systemMemoryCacheSet:(id<NSCoding>)value key:(id)key
{
    if (CPCheckKeyValueHasNull(value, key)) {
        return;
    }
    [[CPQuickCacheUitil shareCache]setObject:value forKey:key];
}

+ (void)systemMemoryCacheRemove:(id)key
{
    if (CPCheckObjectNull(key)) {
        return;
    }
    [[CPQuickCacheUitil shareCache]removeObjectForKey:key];
}

+ (id)systemMemoryCacheGetValue:(id)key
{
    if (CPCheckObjectNull(key)) {
        return nil;
    }
    return [[CPQuickCacheUitil shareCache]objectForKey:key];
}

+ (BOOL)systemMemoryCacheEmptyValue:(id)key
{
    if (CPCheckObjectNull(key)) {
        return NO;
    }
    return [CPQuickCacheUitil systemMemoryCacheGetValue:key] == nil;
}

+ (NSFileManager *)fileManager
{
    return [NSFileManager defaultManager];
}

+ (BOOL)fileExist:(NSString*)path
{
    if (CPStringIsNull(path)) {
        return NO;
    }
    return [[CPQuickCacheUitil fileManager] fileExistsAtPath:path];
}

+ (BOOL)directoryExist:(NSString*)dirPath
{
    if (CPStringIsNull(dirPath)) {
        return NO;
    }
    BOOL isDir = YES;
    
    return [[CPQuickCacheUitil fileManager]fileExistsAtPath:dirPath isDirectory:&isDir];
}

+ (BOOL)createDirectory:(NSString*)dirPath
{
    if (CPCheckObjectNull(dirPath)) {
        return NO;
    }
    if (CPFileDirectoryIsExist(dirPath)) {
        return YES;
    }
    return [[CPQuickCacheUitil fileManager] createDirectoryAtPath:dirPath withIntermediateDirectories:YES attributes:nil error:nil];
}

+ (BOOL)writeFileData:(NSData*)data toPath:(NSString *)path
{
    if (CPCheckKeyValueHasNull(data, path)) {
        return NO;
    }
    
    return [data writeToFile:path atomically:YES];
}

+ (NSData *)readFromFile:(NSString *)path
{
    if (CPCheckObjectNull(path)) {
        return nil;
    }
    
    return [NSData dataWithContentsOfFile:path];
}

+ (BOOL)deleteFileAtPath:(NSString *)filePath
{
    if (CPStringIsNull(filePath)) {
        return NO;
    }
    return [CPFileManager removeItemAtPath:filePath error:nil];
}

+ (BOOL)deleteDirectoryAtPath:(NSString *)dirPath
{
    if (CPStringIsNull(dirPath)) {
        return NO;
    }
    return [CPFileManager removeItemAtPath:dirPath error:nil];
}

+ (BOOL)copyFileFromPath:(NSString *)fromPath toPath:(NSString *)toPath isRemoveOld:(BOOL)isRemove
{
    if (CPStringIsNull(fromPath) || CPStringIsNull(toPath) ) {
        return NO;
    }
    if (!CPFileIsExist(fromPath)) {
        return NO;
    }
    
    BOOL copyResult = [CPFileManager copyItemAtPath:fromPath toPath:toPath error:nil];
    if (copyResult) {
        
        if (isRemove) {
            return [CPFileManager removeItemAtPath:fromPath error:nil];
        }
        return YES;
        
    }else{
        return NO;
    }
}

+ (BOOL)archieveObject:(id<NSCoding>)anObject toFilePath:(NSString *)toPath
{
    if (CPCheckObjectNull(anObject) || CPStringIsNull(toPath)) {
        return NO;
    }
    NSData *archieveData = [NSKeyedArchiver archivedDataWithRootObject:anObject];
    if (archieveData) {
        
        return CPFileWrite(archieveData, toPath);
        
    }else{
        return NO;
    }
}

+ (id)unarchieveFromPath:(NSString *)filePath
{
    if (CPStringIsNull(filePath)) {
        return nil;
    }
    return [NSKeyedUnarchiver unarchiveObjectWithFile:filePath];
}

+ (NSString *)documentDirectory
{
    return [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
}

+ (NSString *)documentDirectoryPath:(NSString *)file
{
    if (CPStringIsNull(file)) {
        return nil;
    }
    return [[CPQuickCacheUitil documentDirectory]stringByAppendingPathComponent:file];
}

+ (NSString *)cacheDirectory
{
    return [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
}

+ (NSString *)cacheDirectoryPath:(NSString *)file
{
    if (CPStringIsNull(file)) {
        return nil;
    }
    return [[CPQuickCacheUitil cacheDirectory]stringByAppendingPathComponent:file];
}

+ (BOOL)cacheDirectorySave:(id<NSCoding>)anObject withFileName:(NSString *)file
{
    if (CPCheckObjectNull(anObject) || CPStringIsNull(file)) {
        return NO;
    }
    
    return CPArchieveObject(anObject, [CPQuickCacheUitil cacheDirectoryPath:file]);
}

+ (BOOL)cacheDirectoryDelete:(NSString *)file
{
    if (CPStringIsNull(file)) {
        return NO;
    }
    return CPFileDeleteFile([CPQuickCacheUitil cacheDirectoryPath:file]);
}


+ (BOOL)documentDirectorySave:(id<NSCoding>)anObject withFileName:(NSString *)file
{
    if (CPCheckObjectNull(anObject) || CPStringIsNull(file)) {
        return NO;
    }
    
    return CPArchieveObject(anObject, [CPQuickCacheUitil documentDirectoryPath:file]);
}

+ (BOOL)documentDirectoryDelete:(NSString *)file
{
    if (CPStringIsNull(file)) {
        return NO;
    }
    return CPFileDeleteFile([CPQuickCacheUitil documentDirectoryPath:file]);
}
@end
