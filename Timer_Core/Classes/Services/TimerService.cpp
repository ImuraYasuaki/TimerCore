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

// models
#include "Timer.h"

const std::string &TimerService::getFinishedMarkString() {
    static std::string string("# ");
    return string;
}

const std::string &TimerService::getMessageMarkString() {
    static std::string string(" -m ");
    return string;
}

void TimerService::getTimer(const std::string &path, std::list<Timer> &results) {
    if (path.empty()) {
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
        std::string::size_type messageMarkPosition = line.find(getMessageMarkString());
        Timer timer;
        if (messageMarkPosition != std::string::npos) {
            std::string::size_type start = messageMarkPosition + getMessageMarkString().length();
            std::string::size_type end = line.length() - messageMarkPosition;
            std::string message = line.substr(start, end);
            timer.setMessage(message);
        }
        std::string::size_type start = getFinishedMarkString().length();
        std::string::size_type end = (messageMarkPosition == std::string::npos ? line.length() : messageMarkPosition) - getFinishedMarkString().length();
        std::string timeText = line.substr(start, end);

        /*! @todo このやり方はさすがに・・・かな？ */
        long time = atol(timeText.c_str());
        timer.setFireDatetime(time);

        results.push_back(timer);
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
    stream.close();
}

const std::string &TimerService::getTimerFormat(const Timer &timer, std::string &result) {
    result.clear();

    result += timer.isFinish() ? getFinishedMarkString() : "  ";
    result += std::to_string(timer.getFireDatetime());
    if (!timer.getMessage().empty()) {
        result += getMessageMarkString() + timer.getMessage();
    }
    return result;
}
