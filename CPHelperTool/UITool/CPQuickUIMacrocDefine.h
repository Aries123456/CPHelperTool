//
//  CPQuickUIMacrocDefine.h
//  CatPaw
//
//  Created by lk on 2017/6/19.
//  Copyright © 2017年 lk. All rights reserved.
//

/**
 *  UI相关的快速访问工具宏
 */

#import "CPQuickUIUitil.h"

/**
 *  将0-360的角度转换为圆角度表示
 *
 *  @param degree
 *
 *  @return 真实的角度表示
 */
#define CPDegreeToRadius(degree) (degree * M_PI / 180)
/**
 *  获取角度对应的NSNumber对象
 */
#define CPDegreeToRadiusValue(degree) @(CPDegreeToRadius(degree))


/**
 *  快速得到RGB颜色
 */
#define CPQuickRGBColor(redValue,greenValue,blueValue) [CPQuickUIUitil colorFromRed:redValue green:greenValue blue:blueValue]

/**
 *  快速获取随机颜色
 */
#define CPQuickAndomRGBColor [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1];

/**CPDegreeToRadiusValue
 *  获取带alpha值的RGB颜色
 */
#define CPQuickRGBColorAlpha(redValue,greenValue,blueValue,alpha) [CPQuickUIUitil colorFromRed:redValue green:greenValue blue:blueValue withAlpha:alpha]
/**
 *  设置字体大小
 */
#define CPQuickSetFont(fontSize) [CPQuickUIUitil fontWithSize:fontSize];
/**
 *  从16进制字符中得到颜色
 */
#define CPQuickHexColor(hexString) [CPQuickUIUitil colorFromHexString:hexString]
/**
 *  从16进制字符中得到颜色 可自定义透明度
 */
#define CPQuickHexColorWithAlpha(hexString,_alpha_) [CPQuickUIUitil colorFromHexString:hexString alpha:_alpha_]
/**
 *  从一个View获取翻转的文本绘制的图形上下文CGContextRef
 */
#define CPContextRefTextMatrixFromView(aView) [CPQuickUIUitil getTextCTMContextRefFromView:aView]

/**
 *  快速获取图片
 */
#define CPQuickImage(imageName) [CPQuickUIUitil imageWithName:imageName]

/**
 *  修正图片方向
 *
 */
#define CPFixOretationImage(aImage) [CPQuickUIUitil fixOretationImage:aImage]

/**
 *  创建圆角图片
 */
#define CPRoundCornerImage(aImage,cornerSize,boardSize) [CPQuickUIUitil createRoundCornerImage:aImage withCornerSize:cornerSize withBoardSize:boardSize]

/**
 *  组合图片
 */
#define CPQuickCombineImage(backgroundImage,maskImage) [CPQuickUIUitil combineImage:backgroundImage withMaskImage:maskImage]

/**
 *  返回圆形图片,默认用白色作为遮挡颜色
 */
#define CPCycleImage(aImage) [CPQuickUIUitil roundImage:aImage]

/**
 *  截取Rect部分的图片
 */
#define CPPartImage(aImage,rect) [CPQuickUIUitil partImage:aImage withRect:rect]

/**
 *  返回纠正方向后得图片
 */
#define CPCorrectOrientationImage(aImage) [CPQuickUIUitil correctImageOrientation:aImage]

/**
 *  返回一个纠正了方向并且进行了scale倍数缩放的图片
 */
#define CPCorrectOrientationImageWithScale(aImage,scale) [CPQuickUIUitil correctImageOrientation:aImage withScaleSize:scale]

/**
 *  返回ALAsset纠正方向后并且进行了scale倍数缩放的fullResolutionImage图片
 */
#define CPCorrectOrientationALAssetFullResolutionImageWithScale(aALAsset,scale) [CPQuickUIUitil  correctFullSolutionImageFromALAsset:aALAsset withScaleSize:scale]

/**
 *  返回ALAsset纠正方向后的fullResolutionImage图片
 */
#define CPCorrectOrientationALAssetFullResolutionImage(aALAsset) [CPQuickUIUitil correctFullSolutionImageFromALAsset:aALAsset]

/**
 *  获取一个View的截图
 */
#define CPScreenShotFromView(aView) [CPQuickUIUitil viewScreenShot:aView]

/**
 *  获取一个Layer的截图
 */
#define CPScreenShotFromLayer(aLayer) [CPQuickUIUitil layerScreenShot:aLayer]

/**
 *  按照aColor颜色创建一张size大小的图片
 *
 */
#define CPQuickImageByColorWithSize(aColor,size) [CPQuickUIUitil imageForColor:aColor withSize:size]

/**
 *  创建一个线性渐变图片
 *
 *  @param colors    按顺序渐变颜色数组
 *  @param size      需要创建的图片的大小
 *
 *  最大只支持三种颜色，起始位置颜色，中间颜色，结束颜色
 *  依次位置为 0,0.5,1.0
 *  超过3种颜色也只取前三种颜色为渐变色
 *
 *  @return 返回渐变颜色图片
 */
#define CPLinearGradientImageByColorsWithSize(colors,size) [CPQuickUIUitil gradientLinearImageFromColors:colors withImageSize:size]

/**
 *  创建线性渐变图片
 *
 *  @param fromColor 起始发颜色
 *  @param toColor   中间颜色
 *  @param size      图片大小
 *
 *  @return 渐变图片
 */
#define CPLinearGradientImageFromColorToColor(fromColor,toColor,size) [CPQuickUIUitil gradientLinearImageFromColor:fromColor withToColor:toColor withImageSize:size]

/**
 *  创建球形渐变图片
 *
 *  @param fromColor 中心颜色
 *  @param toColor   外层颜色
 *  @param size      图片大小
 *
 *  @return 渐变图片
 */
#define CPRadialGradientImageFromColorToColor(fromColor,toColor,size) [CPQuickUIUitil gradientRadialImageFromColor:fromColor withToColor:toColor withImageSize:size]

/**
 *  创建球形渐变图片
 *
 *  @param colors 颜色值数组
 *  @param size 图片大小
 *
 *  @return 渐变图片
 */
#define CPRadialGradientImageByColorsWithSize(colors,size) [CPQuickUIUitil gradientRadialImageFromColors:colors withImageSize:size]

/**
 *  创建网格线图片
 *
 *  @param lineGap 格线距离
 *  @param color   格线颜色
 *  @param size    图片大小
 *
 *  @return 网格线图片
 */
#define CPGridImageByLineGapAndColorWithSize(lineGap,color,size) [CPQuickUIUitil gridImageByHoriLineGap:lineGap withVerticalLineGap:lineGap withLineColor:color withImageSize:size]

/**
 *  创建水平网格线图片
 *
 *  @param lineGap 格线距离
 *  @param color   格线颜色
 *  @param size    图片大小
 *
 *  @return 网格线图片
 */
#define CPGridImageHorizByLineGapAndColorWithSize(lineGap,color,size) [CPQuickUIUitil gridImageHorizonByLineGap:lineGap withLineColor:color withImageSize:size]

/**
 *  创建垂直网格线图片
 *
 *  @param lineGap 格线距离
 *  @param color   格线颜色
 *  @param size    图片大小
 *
 *  @return 网格线图片
 */
#define CPGridImageVerticalByLineGapAndColorWithSize(lineGap,color,size) [CPQuickUIUitil gridImageVerticalByLineGap:lineGap withLineColor:color withImageSize:size]

/**
 *  快速从文件夹读取图片
 */
#define CPQuickImageByFilePath(filePath) [CPQuickUIUitil imageWithFilePath:filePath]

/**
 *  快速从归档路径读取图片
 */
#define CPQuickUnArchievedImage(filePath) [CPQuickUIUitil imageUnArchievedFromFilePath:filePath]

/**
 *  获取拉伸的图片
 *
 *  @param image      原图片
 *  @param leftOffset 左边起始位置
 *  @param topOffset  顶部起始位置
 *
 *  @return 返回拉伸后的图片
 */
#define CPImageStrecth(image,leftOffset,topOffset) [CPQuickUIUitil stretchImage:image withTopOffset:topOffset withLeftOffset:leftOffset]

/**
 *  获取重设大小拉伸后的图片
 *
 *  @param image  原图片
 *  @param top    顶部起始位置
 *  @param bottom 底部起始位置
 *  @param left   左边起始位置
 *  @param right  右边起始位置
 *
 *  @return 重设大小拉伸后后的图片
 */
#define CPImageResize(image,top,bottom,left,right) [CPQuickUIUitil resizeImage:image withEdgeTop:top withEdgeBottom:bottom withEdgeLeft:left withEdgeRight:right]

/**
 *  以duration持续时间执行一个UIView动画block
 */
#define CPAnimationWithDuration(duration,block) [CPQuickUIUitil animationDuration:duration action:block]

/**
 *  延迟second秒，以duration持续时间执行一个UIView动画block
 */
#define CPAnimationDelayWithDuration(second,duration,block) [CPQuickUIUitil animationDelay:second animationDuration:duration action:block]

/**
 *  默认隐藏显示视图动画
 */
#define CPAnimationHiddenShowView(view) [CPQuickUIUitil defaultHiddenShowView:view]

/**
 *  指定duration时长隐藏显示动画
 */
#define CPAnimationHiddenShowViewDuration(view,duration) [CPQuickUIUitil hiddenShowView:view withDuration:duration]

/**
 *  默认显示隐藏视图动画
 */
#define CPAnimationShowHiddenView(view) [CPQuickUIUitil defaultShowHiddenView:view]

/**
 *  指定duration时长显示隐藏动画
 */
#define CPAnimationShowHiddenViewDuration(view,duration) [CPQuickUIUitil showHiddenView:view withDuration:duration]

/**
 *  默认隐藏视图动画
 */
#define CPAnimationHiddenView(view) [CPQuickUIUitil defaultHiddenView:view]

/**
 *  指定duration时长隐藏动画
 */
#define CPAnimationHiddenViewDuration(view,duration) [CPQuickUIUitil hiddenView:view withDuration:duration]

/**
 *  默认显示视图动画
 */
#define CPAnimationShowView(view) [CPQuickUIUitil defaultShowView:view]

/**
 *  指定duration时长显示视图动画
 */
#define CPAnimationShowViewDuration(view,duration) [CPQuickUIUitil showView:view withDuration:duration]

/**
 *  指定duration时间长度，从当前视图alpha到目标alpha
 */
#define CPAnimationShowAlphaViewDuration(view,alpha,duration) [CPQuickUIUitil showView:view finalAlpha:alpha withDuration:duration]

/**
 *  移动当前视图到指定rect的动画,不支持便捷写法的CGRect  CGRect{20,20,20,20} 这种写法是不支持的需要使用CGRectMake
 */
#define CPAnimationMoveViewRect(view,rect,duration) [CPQuickUIUitil moveView:view newRect:rect withDuration:duration]

/**
 *  x轴增量移动动画
 */
#define CPAnimationMoveViewX(view,xDetal,duration) [CPQuickUIUitil moveViewX:view originXDetal:xDetal withDuration:duration]

/**
 *  y轴增量移动动画
 */
#define CPAnimationMoveViewY(view,yDetal,duration) [CPQuickUIUitil moveViewY:view originYDetal:yDetal withDuration:duration]

/**
 *  width增量变化动画
 */
#define CPAnimationMoveViewWidth(view,detal,duration) [CPQuickUIUitil moveViewWidth:view widthDetal:detal withDuration:duration]

/**
 *  height增量变化动画
 */
#define CPAnimationMoveViewHeight(view,detal,duration) [CPQuickUIUitil moveViewHeight:view heightDetal:detal withDuration:duration]

/**
 *  移动到指定x轴点动画
 */
#define CPAnimationMoveViewToX(view,toX,duration) [CPQuickUIUitil moveViewToX:view toOriginX:toX withDuration:duration]

/**
 *  移动到指定y轴点动画
 */
#define CPAnimationMoveViewToY(view,toY,duration) [CPQuickUIUitil moveViewToY:view toOriginY:toY withDuration:duration]

/**
 *  指定视图width到目标宽度的动画
 */
#define CPAnimationMoveViewToWidth(view,width,duration) [CPQuickUIUitil moveViewToWidth:view toWidth:width withDuration:duration]

/**
 *  指定视图height到目标高度的动画
 */
#define CPAnimationMoveViewToHeight(view,height,duration) [CPQuickUIUitil moveViewToHeight:view toHeight:height withDuration:duration]

/**
 *  移动视图中心动画 不支持便捷写法的CGPoint  (CGPoint){20,20} 这种写法是不支持的需要使用CGPointMake
 */
#define CPAnimationMoveViewCenter(view,center,duration) [CPQuickUIUitil moveViewCenter:view newCenter:center withDuration:duration]

/**
 *  缩放视图大小动画,不支持便捷写法的CGSize  (CGSize){20,20} 这种写法是不支持的,需要使用CGSizeMake
 */
#define CPAnimationMoveViewSize(view,size,duration) [CPQuickUIUitil moveViewSize:view newSize:size withDuration:duration]

/**
 *  从左开始翻转视图动画
 */
#define CPAnimationLeftFlipView(view,duration,block,completion) [CPQuickUIUitil flipViewFromLeft:view withDuration:duration action:block completionBlock:completion]

/**
 *  从右开始翻转视图动画
 */
#define CPAnimationRightFlipView(view,duration,block,completion) [CPQuickUIUitil flipViewFromRight:view withDuration:duration action:block completionBlock:completion]

/**
 *  从顶部开始翻转视图动画
 */
#define CPAnimationTopFlipView(view,duration,block,completion) [CPQuickUIUitil flipViewFromTop:view withDuration:duration action:block completionBlock:completion]

/**
 *  从底部开始翻转视图动画
 */
#define CPAnimationBottomFlipView(view,duration,block,completion) [CPQuickUIUitil flipViewFromBottom:view withDuration:duration action:block completionBlock:completion]

/**
 *  向上翻页动画
 */
#define CPAnimationPageUpView(view,duration,block,completion) [CPQuickUIUitil pageUpViewFromBottom:view withDuration:duration action:block completionBlock:completion]

/**
 *  向下翻页动画
 */
#define CPAnimationPageDownView(view,duration,block,completion) [CPQuickUIUitil pageDownViewFromTop:view withDuration:duration action:block completionBlock:completion]

/**
 *  立体翻转动画
 */
#define CPAnimationCubeView(view,duration,block,completion) [CPQuickUIUitil cubeView:view withDuration:duration  action:block completionBlock:completion]

/**
 *  绕X轴倾斜视图degree角度  degree范围:0-360
 */
#define CPAnimationViewRotateX(view,degree,duration) [CPQuickUIUitil rotationViewX:view withDegree:degree withDuration:duration]

/**
 *  绕Y轴倾斜视图degree角度  degree范围:0-360
 */
#define CPAnimationViewRotateY(view,degree,duration) [CPQuickUIUitil rotationViewY:view withDegree:degree withDuration:duration]

/**
 *  绕Z轴倾斜视图degree角度  degree范围:0-360
 */
#define CPAnimationViewRotateZ(view,degree,duration) [CPQuickUIUitil rotationViewZ:view withDegree:degree withDuration:duration]

/**
 *  translationX动画
 */
#define CPAnimationViewTranslationX(view,originX,duration) [CPQuickUIUitil translationViewX:view withOriginX:originX withDuration:duration]

/**
 *  translationY动画
 */
#define CPAnimationViewTranslationY(view,originY,duration) [CPQuickUIUitil translationViewY:view withOriginY:originY withDuration:duration]

/**
 *  translationZ动画
 */
#define CPAnimationViewTranslationZ(view,originZ,duration) [CPQuickUIUitil translationViewZ:view withOriginZ:originZ withDuration:duration]

/**
 *  scaleX动画
 */
#define CPAnimationViewScaleX(view,size,duration) [CPQuickUIUitil scaleViewX:view withScaleSize:size withDuration:duration]

/**
 *  scaleY动画
 */
#define CPAnimationViewScaleY(view,size,duration) [CPQuickUIUitil scaleViewY:view withScaleSize:size withDuration:duration]

/**
 *  scaleZ动画
 */
#define CPAnimationViewScaleZ(view,size,duration) [CPQuickUIUitil scaleViewZ:view withScaleSize:size withDuration:duration]

/**
 *  将视图绕X轴倾斜degree角度，degree范围 -360到360
 */
#define CPView3DRotateX(view,degree) [CPQuickUIUitil view3DRotateX:view withDegree:degree]

/**
 *  将视图绕Y轴倾斜degree角度，degree范围 -360到360
 */
#define CPView3DRotateY(view,degree) [CPQuickUIUitil view3DRotateY:view withDegree:degree]

/**
 *  将视图绕Z轴倾斜degree角度，degree范围 -360到360
 */
#define CPView3DRotateZ(view,degree) [CPQuickUIUitil view3DRotateZ:view withDegree:degree]

/**
 *  X轴变换
 */
#define CPView3DTranslateX(view,value) [CPQuickUIUitil view3DTranslateX:view withValue:value]

/**
 *  Y轴变换
 */
#define CPView3DTranslateY(view,value) [CPQuickUIUitil view3DTranslateY:view withValue:value]

/**
 *  Z轴变换
 */
#define CPView3DTranslateZ(view,value) [CPQuickUIUitil view3DTranslateZ:view withValue:value]

/**
 *  X轴方向缩放,代表一个缩放比例，一般都是 0 --- 1 之间的数字
 */
#define CPView3DScaleX(view,value) [CPQuickUIUitil view3DScaleX:view withValue:value]

/**
 *  Y轴方向缩放,代表一个缩放比例，一般都是 0 --- 1 之间的数字
 */
#define CPView3DScaleY(view,value) [CPQuickUIUitil view3DScaleY:view withValue:value]

/**
 *  Z轴方向缩放,整体比例变换时，也就是m11（sx）== m22（sy）时，若m33（sz）>1，图形整体缩小，若0<1，
 *  图形整体放大，若m33（sz）<0，发生关于原点的对称等比变换
 */
#define CPView3DScaleZ(view,value) [CPQuickUIUitil view3DScaleZ:view withValue:value]

/**
 *  重复某个block
 */
#define CPRepeatAction(repeatBlock) [CPQuickUIUitil repeatDoAction:repeatBlock]

/**
 *  延迟second秒开始重复某个动作
 */
#define CPRepeatActionDelay(second,repeatBlock) [CPQuickUIUitil repeatDoAction:repeatBlock withDelay:second]

/**
 *  重复某个动作duration时长
 */
#define CPRepeatActionDuration(duration,repeatBlock) [CPQuickUIUitil repeatDoAction:repeatBlock withRepeatDuration:duration]

/**
 *  延迟某个动作second秒，并且只执行duration时长
 */
#define CPRepeatActionDelayDuration(second,duration,repeatBlock) [CPQuickUIUitil repeatDoAction:repeatBlock withDelay:second withRepeatDuration:duration]

/**
 *  根据blockIdentifier停止某个block重复动作
 */
#define CPStopRepeatAction(blockIdentifier) [CPQuickUIUitil stopRepeatAction:blockIdentifier]

/**
 *  X轴上以moveXDetal偏移量一个来回,moveXDetal > 0
 */
#define CPAnimationViewXCycle(view,moveXDetal,duration) [CPQuickUIUitil animationViewXCycle:view withXMoveDetal:moveXDetal withDuration:duration]

/**
 *  Y轴上以moveYDetal偏移量一个来回,moveYDetal > 0
 */
#define CPAnimationViewYCycle(view,moveYDetal,duration) [CPQuickUIUitil animationViewYCycle:view withYMoveDetal:moveYDetal withDuration:duration]

/**
 *  Z轴上以moveZDetal偏移量一个来回,moveZDetal > 0
 */
#define CPAnimationViewZCycle(view,moveZDetal,duration) [CPQuickUIUitil animationViewZCycle:view withZMoveDetal:moveZDetal withDuration:duration]

/**
 *  绕X轴上以degree角度为偏移量一个来回,degree: 0-360
 */
#define CPAnimationViewRotateXCycle(view,degree,duration) [CPQuickUIUitil animationViewRotateXCycle:view withXRotateDetal:degree withDuration:duration]

/**
 *  绕Y轴上以degree角度为偏移量一个来回,degree: 0-360
 */
#define CPAnimationViewRotateYCycle(view,degree,duration) [CPQuickUIUitil animationViewRotateYCycle:view withYRotateDetal:degree withDuration:duration]

/**
 *  绕Z轴上以degree角度为偏移量一个来回,degree: 0-360
 */
#define CPAnimationViewRotateZCycle(view,degree,duration) [CPQuickUIUitil animationViewRotateZCycle:view withZRotateDetal:degree withDuration:duration]

/**
 *  fromValue到toValue的position移动CAAnimation
 *  animationKey 为 @"CP_animation_position"
 *
 */
#define CPCAAnimationPosition(aLayer,fromValue,toValue,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer positionCenterWithFromValue:fromValue withToValue:toValue withRepeatCount:repeatCount  withDuration:duration]

/**
 *  fromValue到toValue的position.x移动CAAnimation
 *  animationKey 为 @"CP_animation_position.x"
 */
#define CPCAAnimationPositionX(aLayer,fromValue,toValue,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer positionXWithFromValue:fromValue withToValue:toValue withRepeatCount:repeatCount withDuration:duration]

/**
 *  fromValue到toValue的position.y移动CAAnimation
 *  animationKey 为 @"CP_animation_position.y"
 */
#define CPCAAnimationPositionY(aLayer,fromValue,toValue,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer positionYWithFromValue:fromValue withToValue:toValue withRepeatCount:repeatCount withDuration:duration]

/**
 *  按照value移动postion的CAAnimation
 *  animationKey 为 @"CP_animation_by_position"
 */
#define CPCAAnimationPositionByValue(aLayer,value,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer positionCenterByValue:value  withRepeatCount:repeatCount  withDuration:duration]

/**
 *  按照value移动postion.x的CAAnimation
 *  animationKey 为 @"CP_animation_by_position.x"
 */
#define CPCAAnimationPositionXByValue(aLayer,value,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer positionXByValue:value withRepeatCount:repeatCount withDuration:duration]

/**
 *  按照value移动postion.y的CAAnimation
 *  animationKey 为 @"CP_animation_by_position.y"
 */
#define CPCAAnimationPositionYByValue(aLayer,value,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer positionYByValue:value withRepeatCount:repeatCount withDuration:duration]

/**
 *  按照指定路径做动画
 */
#define CPAnimationPathByValue(aLayer,aPath,value,repeatCount,duration) [CPQuickUIUitil animationLayer:aLayer path:aPath ByValue:value  withRepeatCount:repeatCount  withDuration:duration]
