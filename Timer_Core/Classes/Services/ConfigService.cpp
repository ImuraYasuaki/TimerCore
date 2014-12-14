//
//  ConfigService.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#include "ConfigService.h"

// utils
#include "pathutil.h"

/*!
 @todo プラットフォーム側から受け取る必要がある */
const char *ConfigService::DefaultStorageDirectory = "/Users/myuon/Library/TimerC";

const char *ConfigService::SavedTimerFileName = "timers.tc";

void ConfigService::getSavedTimerPath(std::string &path) {
    std::string directory(ConfigService::DefaultStorageDirectory);
    if (!pathutil::isExistsPath(directory)) {
        bool isExistsDirectory = pathutil::createDirectory(directory);
        if (!isExistsDirectory) {
            return;
        }
    }
    std::string fileName(ConfigService::SavedTimerFileName);
    path = directory + "/" + fileName;
}
