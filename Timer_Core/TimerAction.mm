//
//  TimerAction.m
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#import "TimerAction.h"

// models
#include "Timer.h"

// services
#include "TimerService.h"
#include "ConfigService.h"

// others
#include "TimerCommandArgumentParser.h"

@interface TimerAction ()
+ (NSString *)name;
@end

@interface HelpAction : TimerAction
@end

@implementation HelpAction

+ (instancetype)timerActionWithArguments:(NSArray *)arguments
{
    HelpAction *action = [[HelpAction alloc] init];
    return action;
}

+ (NSString *)name
{
    return [NSString stringWithCString:command::action::HelpActionName encoding:NSUTF8StringEncoding];
}

- (void)perform
{
    const char *text = "-- Help:\n"
    "  you can use timer.\n"
    "  if you set time to 'Timer', you can receive notification on the Time.\n"
    "\n"
    "  Actions:\n"
    "    Set:    'timer set \"2015-01-01 13:30\" -message \"Lunch with friends\" '\n"
    "      you can get timerID.\n"
    "      timerID is like '201501011330'.\n"
    "\n"
    "    Remove: 'timer remove <timerID>'\n"
    "      you can remove setted timer, if exists timerID.\n";
    printf("%s", text);
}

@end

////////////////////////////////////////////////////////////////////////////////

@interface ListAction : TimerAction
@end

@implementation ListAction

+ (instancetype)timerActionWithArguments:(id)arguments {
    ListAction *action = [[ListAction alloc] init];
    return action;
}

+ (NSString *)name {
    return [NSString stringWithCString:command::action::ListRegisteredTimerActionName encoding:NSUTF8StringEncoding];
}

- (void)perform {
    std::string path("");
    ConfigService::getSavedTimerPath(path);
    std::list<Timer> timers;
    TimerService::getTimer(path, timers);

    printf("count: %d\n", (int)timers.size());
}

@end

////////////////////////////////////////////////////////////////////////////////

@interface SetAction : TimerAction
@property (nonatomic, strong) NSDate *time;
@property (nonatomic, strong) NSString *message;
+ (NSDateFormatter *)dateFormatter;
+ (NSDate *)dateWithDateTimeText:(NSString *)datetimeText;
+ (const char *)noTimeErrorMessage;
@end

@implementation SetAction

+ (instancetype)timerActionWithArguments:(NSArray *)arguments {
    SetAction *action = [[SetAction alloc] init];
    NSUInteger timeIndex = [arguments indexOfObject:[self name]] + 1;
    if (timeIndex < [arguments count]) {
        NSString *datetimeText = arguments[timeIndex];
        [action setTime:[self dateWithDateTimeText:datetimeText]];

        if (![action time]) {
            return action;
        }
        NSUInteger messageIndex = timeIndex + 1;
        if (messageIndex < [arguments count]) {
            [action setMessage:arguments[messageIndex]];
        }
    }
    return action;
}

+ (NSString *)name {
    return [NSString stringWithCString:command::action::RegisterTimerActionName encoding:NSUTF8StringEncoding];
}

- (void)perform {
    if (![self time]) {
        printf("%s", [self.class noTimeErrorMessage]);
        return;
    }
    std::string path;
    ConfigService::getSavedTimerPath(path);

    Timer timer;
    timer.setFireDateTime([self.time timeIntervalSince1970]);
    timer.setMessage(self.message ? [self.message UTF8String] : "");
    TimerService::registerTimer(path, timer);

    NSString *datetimeText = [[self.class dateFormatter] stringFromDate:self.time];
    NSLog(@"setted timer.\n  %@", datetimeText);
}

+ (NSDateFormatter *)dateFormatter {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"YYYY-MM-DD HH:mm"];
    return formatter;
}

+ (NSDate *)dateWithDateTimeText:(NSString *)datetimeText {
    NSDate *datetime = [[self dateFormatter] dateFromString:datetimeText];
    return datetime;
}

+ (const char *)noTimeErrorMessage {
    const char *text = "-- Error:\n"
    "  you must set time for set command.\n"
    "  format is \"YYYY-MM-DD HH:mm\".\n"
    "  also:\n"
    "  you can use 'message'.\n"
    "    example: 'timer set YYYY-MM-DD HH:mm \"Go home now !\"'\n";
    return text;
}

@end

////////////////////////////////////////////////////////////////////////////////

@implementation TimerAction

+ (instancetype)timerActionWithArguments:(NSArray *)arguments
{
    command::action::Type type = command::getAction(arguments);
    switch (type) {
        case command::action::Type::RegisterTimer: return [SetAction timerActionWithArguments:arguments];
        case command::action::Type::List: return [ListAction timerActionWithArguments:arguments];
        case command::action::Type::Help:
        default:
            return [HelpAction timerActionWithArguments:arguments];
    }
}

+ (NSString *)name
{
    return nil;
}

- (NSString *)name
{
    return [[self class] name];
}

- (void)perform
{
    
}

@end
