//
//  TimerAction.h
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TimerAction : NSObject

+ (instancetype)timerActionWithArguments:(NSArray *)arguments;

- (NSString *)name;
- (void)perform;

@end
