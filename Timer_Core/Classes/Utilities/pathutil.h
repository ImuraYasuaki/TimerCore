//
//  pathutil.h
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#pragma once

#ifndef Timer_Core_pathutil_h
#define Timer_Core_pathutil_h

#include <sys/stat.h>

namespace pathutil {

    bool isExistsPath(const char *path) {
        struct stat buffer;
        int result = stat(path, &buffer);
        return result != -1;
    }
    
    bool isExistsPath(const std::string &path) {
        return isExistsPath(path.c_str());
    }

    bool createDirectory(const std::string &path) {
        if (path.empty()) {
            return false;
        }
        if (isExistsPath(path)) {
            return false;
        }
        int result = mkdir(path.c_str(), 0777);
        return result == 0;
    }

}

#endif
