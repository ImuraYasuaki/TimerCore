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

- (void)testSetAction_noTime {
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set"]];
    [action perform];

    XCTAssert(YES, @"Pass");
}

- (void)testSetAction_noMessageInvalidDate {
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set", @"YYYY-MM-dd HH:mm"]];
    [action perform];
    
    XCTAssert(YES, @"Pass");
}

- (void)testSetAction_noMessageNotEnoughDate {
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set", @"2014-12-13"]];
    [action perform];

    XCTAssert(YES, @"Pass");
}

- (void)testSetAction_noMessage {
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set", @"2014-12-13 12:30"]];
    [action perform];

    XCTAssert(YES, @"Pass");
}

- (void)testSetAction_noMessageCurrentDate {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"YYYY-MM-DD HH:mm"];
    NSString *now = [formatter stringFromDate:[NSDate date]];
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set", now]];
    [action perform];
    
    XCTAssert(YES, @"Pass");
}

- (void)testSetAction_noMessageAfter30m {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"YYYY-MM-DD HH:mm"];
    NSString *now = [formatter stringFromDate:[NSDate dateWithTimeIntervalSinceNow:60 * 30]];
    TimerAction *action = [TimerAction timerActionWithArguments:@[@"set", now]];
    [action perform];
    
    XCTAssert(YES, @"Pass");
}

@end
