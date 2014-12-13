//
//  TimerCommandArgumentParser.h
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef __Timer_Core__TimerCommandArgumentParser__
#define __Timer_Core__TimerCommandArgumentParser__

#include <stdio.h>

class Timer;

namespace command {

    namespace action {
        enum Type {
            Help,
            RegisterTimer,
            RemoveTimer,
            List,
            /* will implements ...
             */
        };

        static const char *HelpActionName = "help";
        static const char *RegisterTimerActionName = "set";
        static const char *RemoveTimerActionName = "remove";
        static const char *ListRegisteredTimerActionName = "list";
    }

    NSArray *getArguments(int argc, const char **argv);

    command::action::Type getAction(NSArray *arguments);

}

#endif /* defined(__Timer_Core__TimerCommandArgumentParser__) */
