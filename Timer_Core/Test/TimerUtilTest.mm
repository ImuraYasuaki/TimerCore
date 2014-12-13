//
//  TimerUtilTest.m
//  Timer_Core
//
//  Created by myuon on 2014/11/22.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#import <XCTest/XCTest.h>

#import "Timer.h"
#import "timeutil.h"

@interface TimerUtilTest : XCTestCase

@end

@implementation TimerUtilTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testCurrentEpocTime {
    time_t now = timeutil::getCurrentEpocTime();
    XCTAssert(now > 0, @"invalid current time");

    __block BOOL isFinish = NO;

    time_t delay = 2.5;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        time_t time = timeutil::getCurrentEpocTime();
        time_t diff = time - now;
        NSLog(@"diff: %zd", diff);
        XCTAssert(floor(delay) == diff, "time of different is invalid!");

        isFinish = YES;
    });
    while (!isFinish) {
        [[NSRunLoop mainRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:1.0f]];
    }
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
