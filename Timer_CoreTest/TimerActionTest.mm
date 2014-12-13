//
//  TimerActionTest.m
//  Timer_Core
//
//  Created by myuon on 2014/12/13.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "TimerAction.h"

@interface TimerActionTest : XCTestCase

@end

@implementation TimerActionTest

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testListAction {
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"list"]];
    [action perform];

    XCTAssert(YES, @"Pass");
}

- (void)testSetAction {
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set"]];
    [action perform];

    XCTAssert(YES, @"Pass");
}

@end
