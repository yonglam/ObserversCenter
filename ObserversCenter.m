//
//  ObserversCenter.m
//
//  Created by Lin Yong on 15/3/2.
//  Copyright (c) 2015年 Lin Yong. All rights reserved.
//

#import "ObserversCenter.h"

@interface ObserversCenter ()

@property (nonatomic) NSMutableDictionary *m_dicObservers;
@end

@implementation ObserversCenter

- (instancetype)init
{
    self = [super init];
    if (self) {
        _m_dicObservers = [NSMutableDictionary dictionary];
    }
    return self;
}

+ (instancetype)defaultCenter{
    static ObserversCenter *center = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        center = [[ObserversCenter alloc] init];
    });
    return center;
}

- (PLObservers *)getObservers:(Protocol *)ptl{
    return [self getObservers:ptl forKey:nil];
}

- (PLObservers *)getObservers:(Protocol *)ptl forKey:(NSString *)key{
    NSString *aKey = [NSString stringWithFormat:@"[%@-%@]", NSStringFromProtocol(ptl), key];
    PLObservers *observers = [self.m_dicObservers objectForKey:aKey];
    if (nil == observers) {
        observers = [[PLObservers alloc] initWithObserverProtocol:ptl];
        [self.m_dicObservers setObject:observers forKey:aKey];
    }
    return observers;
}
@end
