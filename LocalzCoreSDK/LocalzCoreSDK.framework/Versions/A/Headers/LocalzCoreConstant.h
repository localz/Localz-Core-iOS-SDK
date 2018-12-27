//
//  CoreConstant.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 14/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Notification when Core has been initialised. Error object, if any, is available in userInfo["error"].
 */
extern NSString * const CoreInitNotification;

/**
 *  Notification when network reachability services changes status.
 *  The new status is available in userInfo["enabled"] with value 1 or 0
 */
extern NSString * const CoreNetworkReachabilityStateChangeNotification;

/**
 *  Notification once logs are uploaded to Papertrail
 *  The error, if any is available in userInfo["error"]
 */
extern NSString * const DebugLogsNotification;

/**
 *  Notification of when the SDK receives a 401 error likely due to tokens expiring.
 */
extern NSString * const SpotzUnexpectedLogoutNotification;
