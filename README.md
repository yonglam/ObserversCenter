# ObserversCenter
Base on [PLObservers](https://github.com/Polidea/PLObservers), create an observers center for multi-observer pattern in obj-c. 

### Advantages beyond PLObservers

1. Decoupling the observed and the observers; 
2. New feature of subscribing on a specify key;
3. Easier usage.

### Usage

```
1. without key
ADD_OBSERVER(protocol, observer)
REMOVE_OBSERVER(protocol, observer)
NOTIFY_OBSERVERS(protocol, func)

2. with a key
ADD_OBSERVER_WITH_KEY(protocol, key, observer)
REMOVE_OBSERVER_WITH_KEY(protocol, key, observer)
NOTIFY_OBSERVERS_WITH_KEY(protocol, key, func)
```
### Example

```
/////////////  ViewController.m   /////////////

@interface ViewController () <IClockMgrExt>

@implementation ViewController

- (void)dealloc
{
    // 3. remove observer 
    REMOVE_OBSERVER(IClockMgrExt, self);
}

- (void)viewDidLoad
{
    // 1. add observer
    ADD_OBSERVER(IClockMgrExt, self);
}

- (void)now:(NSString *)nowStr{
    self.timeLabel.text = nowStr;
}

@end
```
```

/////////////   ClockMgr.h   /////////////

@protocol IClockMgrExt <NSObject>

- (void) now:(NSString *)nowStr;

@end

@interface ClockMgr : NSObject
@end
```
```
/////////////    ClockMgr.m    /////////////

@implementation ClockMgr

- (void)run{
    [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(report) userInfo:nil repeats:YES];
}

- (void)report{
    // 2. notify observers
    NOTIFY_OBSERVERS(IClockMgrExt, now:[[NSDate date] description]);
}

@end

```

### Author
Yonglam, ngulinyong@qq.com

Thanks to Antoni Kedracki and Polidea.


### License
Under the MIT license.