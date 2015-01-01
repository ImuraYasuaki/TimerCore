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
        unsigned int timerId;
        time_t fireDatetime;
        std::string message;

    public:
        Timer() { this->fireDatetime = 0; }
        Timer(const Timer &other) {
            this->fireDatetime = other.getFireDatetime();
            this->message = other.getMessage();
            this->timerId = other.getTimerId();
        }
        static const unsigned int UnregisteredTimerID = -1;

        time_t getFireDatetime() const { return this->fireDatetime; }
        void setFireDatetime(const time_t &datetime);

        const std::string &getMessage() const { return this->message; }
        void setMessage(const std::string message) { this->message = message; }

        unsigned int getTimerId() const { return this->timerId; }
        void setTimerId(const unsigned int timerId) { this->timerId = timerId; }

        bool operator==(const Timer &other) const { return (this->timerId == other.timerId) || (this->message == other.getMessage() && this->fireDatetime == other.getFireDatetime()); };
        bool operator!=(const Timer &other) const { return !(*this == other); };

        bool isFinish() const;
    };

}

#endif
