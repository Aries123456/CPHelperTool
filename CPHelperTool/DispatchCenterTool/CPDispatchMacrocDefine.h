//
//  CPDispatchMacrocDefine.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

/**
 *  文件描述
 *
 *  这个工具类宏可以方便在各种队列中执行block,提供便捷的使用方法
 *  是对GCD的一个简单封装
 */

#import "CPDispatchCenterUitil.h"

/**
 *  主线程异步执行block
 */
#define CPAsyncMainQueue(block) [CPDispatchCenterUitil asyncMainQueue:block]

/**
 *  主线程延迟second秒异步执行block
 */
#define CPAsyncMainQueueDelay(second,block) [CPDispatchCenterUitil asyncMainQueue:block delay:second]

/**
 *  全局后台线程异步执行block
 */
#define CPAsyncGlobalBackgroundQueue(block) [CPDispatchCenterUitil asyncGlobalBackgroundQueue:block]

/**
 *  全局后台线程延迟second秒异步执行block
 */
#define CPAsyncGlobalBackgroundQueueDelay(second,block) [CPDispatchCenterUitil asyncGlobalBackgroundQueue:block delay:second]

/**
 *  全局高优先级线程异步执行block
 */
#define CPAsyncGlobalHighQueue(block) [CPDispatchCenterUitil asyncGlobalHighQueue:block]

/**
 *  全局高优先级线程延迟second秒异步执行block
 */
#define CPAsyncGlobalHighQueueDelay(second,block) [CPDispatchCenterUitil asyncGlobalHighQueue:block delay:second]

/**
 *  全局低优先级线程异步执行block
 */
#define CPAsyncGlobalLowQueue(block) [CPDispatchCenterUitil asyncGlobalLowQueue:block]

/**
 *  全局低优先级线程延迟second秒异步执行block
 */
#define CPAsyncGlobalLowQueueDelay(second,block) [CPDispatchCenterUitil asyncGlobalLowQueue:block delay:second]

/**
 *  全局默认线程异步执行block
 */
#define CPAsyncGlobalDefaultQueue(block) [CPDispatchCenterUitil asyncGlobalDefaultQueue:block]

/**
 *  全局默认线程延迟second秒异步执行block
 */
#define CPAsyncGlobalDefaultQueueDelay(second,block) [CPDispatchCenterUitil asyncGlobalDefaultQueue:block delay:second]

/**
 *  在queue线程队列异步执行block
 */
#define CPAsync(queue,block)  [CPDispatchCenterUitil asyncQueue:queue action:block]

/**
 *  在queue线程序延迟second秒异步执行block
 */
#define CPAsyncDelay(queue,second,block)  [CPDispatchCenterUitil asyncQueue:queue action:block delay:second]

/**
 *  只执行一次block,创建单例使用
 */
#define CPDispatchOnce(onceToken,block) [CPDispatchCenterUitil dispatchOnce:onceToken action:block]

/**
 *  主线程异步
 */
#define CPAsyncMainThread(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
/**
 *  全局异步执行
 */
#define CPAsyncOpenGlobal(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block);
