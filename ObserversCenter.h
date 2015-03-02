//
//  ObserversCenter.h
//
//  Created by Lin Yong on 15/3/2.
//  Copyright (c) 2015年 Lin Yong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLObservers.h"

///
// This class is to decouple the observers and the observered.
//
// Usage:
//
// 1. without key
// ADD_OBSERVER(ptl, observer)
// REMOVE_OBSERVER(ptl, observer)
// NOTIFY_OBSERVERS(ptl, func)
//
// 2. with a key
// ADD_OBSERVER_WITH_KEY(ptl, key, observer)
// REMOVE_OBSERVER_WITH_KEY(ptl, key, observer)
// NOTIFY_OBSERVERS_WITH_KEY(ptl, key, func)
///

@interface ObserversCenter : NSObject

+ (instancetype)defaultCenter;

- (PLObservers *)getObservers:(Protocol *)ptl;
- (PLObservers *)getObservers:(Protocol *)ptl forKey:(NSString *)key;

@end

#define ADD_OBSERVER(ptl, observer) {[[[ObserversCenter defaultCenter] getObservers:@protocol(ptl)] addObserver:observer];}
#define REMOVE_OBSERVER(ptl, observer) {[[[ObserversCenter defaultCenter] getObservers:@protocol(ptl)] removeObserver:observer];}
#define NOTIFY_OBSERVERS(ptl, func) {[(id<ptl>)[[ObserversCenter defaultCenter] getObservers:@protocol(ptl)] func];}

#define ADD_OBSERVER_WITH_KEY(ptl, key, observer) {[[[ObserversCenter defaultCenter] getObservers:@protocol(ptl) forKey:key] addObserver:observer];}
#define REMOVE_OBSERVER_WITH_KEY(ptl, key, observer) {[[[ObserversCenter defaultCenter] getObservers:@protocol(ptl) forKey:key] removeObserver:observer];}
#define NOTIFY_OBSERVERS_WITH_KEY(ptl, key, func) {[(id<ptl>)[[ObserversCenter defaultCenter] getObservers:@protocol(ptl) forKey:key] func];}
