//
//  Timer.cpp
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#include <stdio.h>

#include "Timer.h"
#include "timeutil.h"

void Timer::setFireDatetime(const time_t &datetime) {
    if (timeutil::isPast(datetime)) {
        return;
    }
    this->fireDatetime = datetime;
}

bool Timer::isFinish() const {
    return timeutil::isPast(this->fireDatetime);
}

