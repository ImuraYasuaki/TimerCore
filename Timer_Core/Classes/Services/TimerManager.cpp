//
//  TimerManager.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#include "TimerManager.h"

#include <iostream>
#include <fstream>

const std::string &TimerManager::getFinishedMarkString() {
    static std::string string("# ");
    return string;
}

const std::string &TimerManager::getMessageMarkString() {
    static std::string string(" -m ");
    return string;
}

void TimerManager::getTimer(const std::string &path, std::list<core::Timer> &results) {
    if (path.empty()) {
        return;
    }
    std::ifstream stream(path, std::ios::out);
    if (stream.bad()) {
        stream.close();
        return;
    }
    unsigned int lineNumber = 0;
    std::string line("");
    while (std::getline(stream, line)) {
        if (!line.empty()) {
            core::Timer timer;
            getTimer(lineNumber, line, timer);

            results.push_back(timer);
        }
        lineNumber++;
    }
}

void TimerManager::registerTimer(const std::string &path, const core::Timer &timer) {
    if (path.empty()) {
        return;
    }
    std::ofstream stream(path, std::ios::binary|std::ios::app);
    if (stream.bad()) {
        stream.close();
        return;
    }
    std::string format("");
    TimerManager::getTimerFormat(timer, format);
    stream << format << std::endl;
    stream.close();
}

void TimerManager::deleteTimer(const std::string &path, const core::Timer &timer) {
    if (path.empty()) {
        return;
    }
    std::ifstream inputStream(path, std::ios::binary|std::ios::out);
    if (inputStream.bad()) {
        inputStream.close();
        return;
    }
    unsigned int lineNumber = 0;
    std::string records("");
    std::string line("");
    while (std::getline(inputStream, line)) {
        if (!line.empty()) {
            core::Timer record;
            getTimer(lineNumber, line, record);

            if (record != timer) {
                records.append(line).append("\n");
            }
        }
        lineNumber++;
    }
    std::ofstream outputSteram(path, std::ios::binary|std::ios::trunc);
    outputSteram << records;
    outputSteram.close();
    inputStream.close();
}

const std::string &TimerManager::getTimerFormat(const core::Timer &timer, std::string &result) {
    result.clear();

    result += timer.isFinish() ? getFinishedMarkString() : "  ";
    result += std::to_string(timer.getFireDatetime());
    if (!timer.getMessage().empty()) {
        result += getMessageMarkString() + timer.getMessage();
    }
    return result;
}

void TimerManager::getTimer(const unsigned int lineNumber, const std::string &formattedText, core::Timer &timer) {
    std::string::size_type messageMarkPosition = formattedText.find(getMessageMarkString());
    if (messageMarkPosition != std::string::npos) {
        std::string::size_type start = messageMarkPosition + getMessageMarkString().length();
        std::string::size_type end = formattedText.length() - messageMarkPosition;
        std::string message = formattedText.substr(start, end);
        timer.setMessage(message);
    }
    std::string::size_type start = getFinishedMarkString().length();
    std::string::size_type end = (messageMarkPosition == std::string::npos ? formattedText.length() : messageMarkPosition) - getFinishedMarkString().length();
    std::string timeText = formattedText.substr(start, end);

    /*! @todo このやり方はさすがに・・・かな？ */
    long time = atol(timeText.c_str());
    timer.setFireDatetime(time);

    timer.setTimerId(lineNumber);
}
