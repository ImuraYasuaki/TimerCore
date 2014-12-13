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

void TimerService::getTimer(const std::string &path, std::list<Timer> &results) {
    if (path.empty()) {
        return;
    }
    if (!pathutil::isExistsPath(path.c_str())) {
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
}
