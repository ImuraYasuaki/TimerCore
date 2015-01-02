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

void core::Timer::setFireDatetime(const time_t &datetime) {
    this->fireDatetime = datetime;
}

bool core::Timer::isFinish() const {
    return timeutil::isPast(this->fireDatetime);
}

