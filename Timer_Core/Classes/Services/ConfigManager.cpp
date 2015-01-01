//
//  ConfigManager.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#include "ConfigManager.h"

// utils
#include "pathutil.h"

/*!
 @todo プラットフォーム側から受け取る必要がある */
const char *ConfigManager::DefaultStorageDirectory = "/Users/myuon/Library/TimerC";

const char *ConfigManager::SavedTimerFileName = "timers.tc";

void ConfigManager::getSavedTimerPath(std::string &path) {
    std::string directory(ConfigManager::DefaultStorageDirectory);
    std::string fileName(ConfigManager::SavedTimerFileName);
    ConfigManager::getSavedTimerPath(directory, fileName, path);
}

void ConfigManager::getSavedTimerPath(const std::string &directory, const std::string &fileName, std::string &path) {
    if (!pathutil::isExistsPath(directory)) {
        bool isExistsDirectory = pathutil::createDirectory(directory);
        if (!isExistsDirectory) {
            return;
        }
    }
    const char lastChar = directory.at(directory.length() - 1);
    path = directory;
    if (lastChar != '/') {
        path += "/";
    }
    path += fileName;
}
