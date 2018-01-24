//
//  ReuseQueue.h
//  ZMJGanttChart
//
//  Created by Jason on 2018/1/19.
//  Copyright © 2018年 Jason. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LOCK(...) [_lock lock]; \
__VA_ARGS__; \
[_lock unlock];

@class Address;

@interface ReuseQueue<__covariant Reusable> : NSObject
- (void)enqueue:(Reusable)reusableObject;
- (Reusable)dequeue;
- (Reusable)dequeueOrCreate;
@end

@interface ReusableCollection<__covariant Reusable> : NSObject <NSFastEnumeration>

- (BOOL)contains:(Address *)member;
- (void)insert:(Address *)newMember;
- (void)substract:(NSOrderedSet<Address *> *)other;

- (Reusable)objectForKeyedSubscript:(Address *)key;
- (void)setObject:(Reusable)obj forKeyedSubscript:(Address *)key;
@end