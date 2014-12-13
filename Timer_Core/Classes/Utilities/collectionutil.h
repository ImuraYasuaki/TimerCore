//
//  collectionutil.h
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef Timer_Core_collectionutil_h
#define Timer_Core_collectionutil_h

namespace collectionutil {

////////////////////////////////////////////////////////////////////////////////
#pragma mark - MacOS or iOS
#if (TARGET_OS_MAC || TARGET_OS_IPHONE)

    BOOL isEmpty(NSArray *array) {
        if (!array) {
            return YES;
        }
        if ([array count] == 0) {
            return YES;
        }
        return NO;
    }

#endif

}

#endif
