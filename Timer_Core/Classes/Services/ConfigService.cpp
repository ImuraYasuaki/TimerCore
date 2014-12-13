//
//  ConfigService.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#include "ConfigService.h"

const char *ConfigService::DefaultStorageDirectory = "~/Library/TimerC";

const char *ConfigService::SavedTimerFileName = "timers.tc";

void ConfigService::getSavedTimerPath(std::string &path) {
    std::string directory(ConfigService::DefaultStorageDirectory);
    std::string fileName(ConfigService::SavedTimerFileName);
    path = directory + "/" + fileName;
}
