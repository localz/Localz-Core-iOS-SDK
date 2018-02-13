//
//  LocalzCoreAppState.h
//  LocalzCoreSDK
//
//  Created by Melvin Artemas on 19/12/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

@import UIKit;
#import <Foundation/Foundation.h>

@interface LocalzCoreAppState : NSObject

+ (void) listen;
+ (UIApplicationState) state;

@end
