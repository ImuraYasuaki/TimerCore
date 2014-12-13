//
//  main.m
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#import <Foundation/Foundation.h>

// utils
#include "pathutil.h"

// models ?
#include "TimerCommandArgumentParser.h"
#import "TimerAction.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSArray *arguments = command::getArguments(argc, argv);
        TimerAction *action = [TimerAction timerActionWithArguments:arguments];
        [action perform];
    }
    return 0;
}
