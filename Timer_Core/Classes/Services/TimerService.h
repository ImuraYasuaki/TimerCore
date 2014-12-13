//
//  TimerService.h
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef __Timer_Core__TimerService__
#define __Timer_Core__TimerService__

#include <list>
#include <string>

class Timer;

class TimerService {
private:
    TimerService() {}

public:
    static void getTimer(const std::string &path, std::list<Timer> &results);

    static void registerTimer(const std::string &path, const Timer &timer);

    static const std::string &getTimerFormat(const Timer &timer, std::string &result);
};

#endif /* defined(__Timer_Core__TimerService__) */
