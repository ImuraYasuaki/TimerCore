//
//  TimerCommandArgumentParser.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "TimerCommandArgumentParser.h"

#include "timeutil.h"
#include "strutil.h"
#include "collectionutil.h"

namespace command {

    NSArray *getArguments(int argc, const char **argv) {
        NSMutableArray *arguments = [NSMutableArray array];
        for (int i = 0; i < argc; i++) {
            if (strutil::isEmpty(argv[i])) {
                continue;
            }
            NSString *argument = [NSString stringWithCString:argv[i] encoding:NSUTF8StringEncoding];
            if (argument) {
                [arguments addObject:argument];
            }
        }
        return [arguments copy];
    }

    command::action::Type getAction(NSArray *arguments) {
        BOOL isHelpAction = [arguments containsObject:[NSString stringWithUTF8String:command::action::HelpActionName]];
        if (isHelpAction) {
            return command::action::Type::Help;
        }
        BOOL isListAction = [arguments containsObject:[NSString stringWithUTF8String:command::action::ListRegisteredTimerActionName]];
        if (isListAction) {
            return command::action::Type::List;
        }
        BOOL isSetAction = [arguments containsObject:[NSString stringWithUTF8String:command::action::RegisterTimerActionName]];
        if (isSetAction) {
            return command::action::Type::RegisterTimer;
        }
        return command::action::Type::Help;
    }

}
