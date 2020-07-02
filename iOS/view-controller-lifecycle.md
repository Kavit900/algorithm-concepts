## View Controller Lifecycle

- awakeFromNib
- Outlets get set
- viewDidLoad
- When (geometry is determined)
       viewWillLayoutSubviews:  and  viewDidLayoutSubviews:
 -  viewWillAppear:   and viewDidAppear:

Possibly if memory gets low
- didReceiveMemoryWarning

## NSNotification

- Radio station - notifications -
Steps:-
1. Get the default “Notification Center” via [NSNotificationCenter defaultCenter]
2. Then send the following message if you want to listen to a radio station.
```
-(void)addObserver:(id)addObserver                         // (the object to get notified)
          selector:(SEL)methodToInvokeIfSomethingHappens
              name:(NSString *)name                        // name of the station
            object:(id)sender;                             // whose changed you're interested in (nil is anyone's)     
```
You will be notified when there are broadcasts

```
- (void)methodToInvokeIfSomethingHappens:(NSNotification *)notification {
  notification.name    // the name passed above
  notification.object  // the object sending you the notification
  notification.userInfo // notification-specific information about what happened
}
```
