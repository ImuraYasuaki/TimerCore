//
//  Timer.h
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef Timer_Core_Timer_h
#define Timer_Core_Timer_h

#include <string>

class Timer {
private:
    long fireDateTime;
    std::string message;

public:
    Timer() { fireDateTime = 0; }

    long getFireDateTime() const { return fireDateTime; }
    void setFireDateTime(long dateTime);

    const std::string &getMessage() const { return this->message; }
    void setMessage(const std::string message) {this->message = message; }

    bool isFinish();
};

#endif
