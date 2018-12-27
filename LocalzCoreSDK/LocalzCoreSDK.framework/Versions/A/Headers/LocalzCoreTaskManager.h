//
//  LocalzCoreTaskManager.h
//  LocalzCoreSDK
//
//  Created by Melvin Artemas on 19/12/2017.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzCoreTaskManager : NSObject
@property (nonatomic,strong) NSString *name;

- (instancetype) initWithName:(NSString *)taskName;

- (void) runIfInBackground;
- (BOOL) isRunning;

- (void) stopBackgroundTask;
+ (void) runSafeOnMainThread:(void (^)(void))block;
@end
