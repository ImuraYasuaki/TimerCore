//
//  pathutil.h
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef Timer_Core_pathutil_h
#define Timer_Core_pathutil_h

#include <sys/stat.h>

namespace pathutil {

    bool isExistsPath(const char *path) {
        struct stat buffer;
        int result = stat(path, &buffer);
        return result != -1;
    }

}

#endif
