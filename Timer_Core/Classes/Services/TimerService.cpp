//
//  TimerService.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#include "TimerService.h"

#include <iostream>
#include <fstream>

// utils
#include "pathutil.h"

// models
#include "Timer.h"

void TimerService::getTimer(const std::string &path, std::list<Timer> &results) {
    if (path.empty()) {
        return;
    }
    if (!pathutil::isExistsPath(path)) {
        return;
    }
    std::ifstream stream(path, std::ios::out);
    if (stream.bad()) {
        stream.close();
        return;
    }
    std::string line("");
    while (std::getline(stream, line)) {
        if (line.empty()) {
            continue;
        }
        printf("\"%s\"", line.c_str());
    }
}

void TimerService::registerTimer(const std::string &path, const Timer &timer) {
    if (path.empty()) {
        return;
    }
    std::ofstream stream(path, std::ios::binary|std::ios::app);
    std::string format("");
    TimerService::getTimerFormat(timer, format);
    stream << format << std::endl;
}

const std::string &TimerService::getTimerFormat(const Timer &timer, std::string &result) {
    result.clear();

    result += timer.isFinish() ? "# " : "  ";
    result += std::to_string(timer.getFireDateTime());

    return result;
}
