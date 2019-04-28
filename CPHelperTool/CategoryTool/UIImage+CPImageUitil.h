//
//  UIImage+CPImageUitil.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (CPImageUitil)
/* 根据颜色创建图片 */
+ (UIImage *)imageForColor:(UIColor*)aColor withSize:(CGSize)aSize;

@end
