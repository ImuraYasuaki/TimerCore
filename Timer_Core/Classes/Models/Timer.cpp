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

void Timer::setFireDateTime(long dateTime) {
    if (timeutil::isPast(dateTime)) {
        return;
    }
    this->fireDateTime = dateTime;
}

bool Timer::isFinish() {
    return timeutil::isPast(this->fireDateTime);
}

