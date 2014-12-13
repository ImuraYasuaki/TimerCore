//
//  strutil.h
//  Timer_Core
//
//  Created by myuon on 2014/11/29.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef __Timer_Core__strutil__
#define __Timer_Core__strutil__

#include <stdlib.h>

namespace strutil {

    bool isEmpty(const char *string) {
        if (!string) {
            return true;
        }
        if (strlen(string) == 0) {
            return true;
        }
        return false;
    }

////////////////////////////////////////////////////////////////////////////////
#pragma mark - MacOS or iOS
#if (TARGET_OS_MAC || TARGET_OS_IPHONE)

    BOOL isEmpty(NSString *string) {
        return strutil::isEmpty([string UTF8String]);
    }

#endif
}

#endif /* defined(__Timer_Core__strutil__) */
