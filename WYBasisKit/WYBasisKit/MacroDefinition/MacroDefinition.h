//
//  MacroDefinition.h
//  WYBasisKit
//
//  Created by jacke－xu on 16/9/4.
//  Copyright © 2016年 jacke-xu. All rights reserved.
//

#import <Availability.h>

#ifdef __OBJC__

#ifndef MacroDefinition_h
#define MacroDefinition_h

//NavBar高度 self.navigationController.navigationBar.frame.size.height
#define navBarHeight     44.f

//电池条高度
#define statusBarHeight  [[UIApplication sharedApplication] statusBarFrame].size.height

//导航栏高度
#define navViewHeight        (statusBarHeight+navBarHeight)

//tabBar高度
#define tabBarHeight         (iPhoneX ? (49.f+34.f) : 49.f)

//tabBar安全区域
#define tabbarSafetyZone         (iPhoneX ? 34.f : 0.f)

//导航栏安全区域
#define navBarSafetyZone         (iPhoneX ? 44.f : 0.f)

//屏幕宽
#define screenWidth     ([UIScreen mainScreen].bounds.size.width)
//屏幕高
#define screenHeight    ([UIScreen mainScreen].bounds.size.height-tabbarSafetyZone)

//cell宽
#define cellWidth       (self.bounds.size.width)

//cell高
#define cellHeigth      (self.bounds.size.height)

//keyWindow
#define keywindow          [UIApplication sharedApplication].keyWindow

//颜色方法简写
//颜色随机
#define randomColor        [UIColor colorWithRed:arc4random()%256/255.0 green:arc4random()%256/255.0 blue:arc4random()%256/255.0 alpha:1.0]

//自定义颜色
#define hexColor(color)        [UIColor hexColor:color]

// 获取RGB颜色
#define RGBA(r,g,b,a)      [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]

#define RGB(r,g,b)         RGBA(r,g,b,1.0f)

//字体方法简写  自定义字体网址：http://iosfonts.com
#define stmFont(font)                [UIFont systemFontOfSize:font]//系统
#define pxFont(font)                 [UIFont systemFontOfSize:font/2]//px字号
#define boldFont(font)               [UIFont boldSystemFontOfSize:font]//粗体
#define customFont(font, fontName)   [UIFont fontWithName:fontName size:font]//自定义


//block self
#define weakSelf(type)      __weak typeof(type) weak##type = type;
#define strongSelf(type)    __strong typeof(type) type = weak##type;

//G－C－D
//在子线程上运行的GCD
#define GCD_subThread(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)

//在主线程上运行的GCD
#define GCD_mainThread(block) dispatch_async(dispatch_get_main_queue(),block)

//只运行一次的GCD
#define GCD_onceThread(Block) static dispatch_once_t onceToken; dispatch_once(&onceToken, Block);

//DEBUG打印日志
#ifdef DEBUG
# define NSLog(FORMAT, ...) printf("\n\n[%s行号:%d]:\n%s\n\n",__FUNCTION__,__LINE__,[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String])
#else
# define NSLog(FORMAT, ...)
#endif

//由角度、弧度值转换
#define degreesToRadian(x) (M_PI * (x) / 180.0)        //度获取弧度
#define radianToDegrees(radian) (radian*180.0)/(M_PI)  //弧度获取角度


//获取app包路径
#define bundlePath     [[NSBundle mainBundle] bundlePath];

//获取app资源目录路径
#define appResourcePath         [[NSBundle mainBundle] resourcePath];

//获取app包的readme.txt文件路径
#define readmePath         [[NSBundle mainBundle] pathForResource:@"readme" ofType:@"txt"];

//app名字
#define AppName          [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"]

#define appStoreName     [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]

//应用标识
#define AppIdentifier    [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];

//应用商店版本号
#define AppStoreVersion   [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//应用构建版本号
#define AppVersion        [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]


//获取当前语言
#define currentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])


//判断是否是传入的iOS系统版本
#define iOSVersion(number)                [[[UIDevice currentDevice] systemVersion] floatValue] == number

//判断是否是传入的iOS系统版本及以上
#define iOSVersionAbove(number)                [[[UIDevice currentDevice] systemVersion] floatValue] >= number

//判断是否是传入的iOS系统版本及以下
#define iOSVersionBelow(number)                [[[UIDevice currentDevice] systemVersion] floatValue] <= number

//判断是否在传入的iOS系统版本之间
#define iOSVersionAmong(smallVersion,bigVersion)                (([[[UIDevice currentDevice] systemVersion] floatValue] >= smallVersion) && ([[[UIDevice currentDevice] systemVersion] floatValue] <= bigVersion))


//判断是竖屏还是横屏
#define UIDeviceOrientationIsPortrait(orientation)  ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown)//竖屏
#define UIDeviceOrientationIsLandscape(orientation) ((orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)//横屏

//判断是否 Retina屏、设备是否iphone几、是否是iPad
#define retina      ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)             //Retina屏

#define iPhoneSE     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone8     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone8Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhoneX    ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

#define is3x      iPhone8Plus ? YES : NO

#define iPad      ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)  //ipad

#define iPhone    ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) //iphone


//判断是真机还是模拟器
#if appleSimulator  //iPhone 模拟器
#endif

#if appleIphone     //iPhone 真机
#endif


#endif /* MacroDefinition_h */

#endif /* OBJC */
