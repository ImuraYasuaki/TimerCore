//
//  timeutil.h
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef Timer_Core_timeutil_h
#define Timer_Core_timeutil_h

#include <time.h>
#include <ctime>

namespace timeutil {

    /*! @abstract Epoc秒を取得する */
    inline static time_t getCurrentEpocTime() {
        return std::time(nullptr);
    }

    inline static bool isPast(time_t time) {
        time_t currentTime = getCurrentEpocTime();
        return difftime(currentTime, time) > 0;
    }

}

#endif
