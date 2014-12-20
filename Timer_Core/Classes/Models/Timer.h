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

namespace core {

    class Timer {
    private:
        time_t fireDatetime;
        std::string message;

    public:
        Timer() { this->fireDatetime = 0; }
        Timer(const Timer &other) { this->fireDatetime = other.getFireDatetime(); this->message = other.getMessage(); }

        time_t getFireDatetime() const { return this->fireDatetime; }
        void setFireDatetime(const time_t &datetime);

        const std::string &getMessage() const { return this->message; }
        void setMessage(const std::string message) {this->message = message; }

        bool isFinish() const;
    };

}

#endif
