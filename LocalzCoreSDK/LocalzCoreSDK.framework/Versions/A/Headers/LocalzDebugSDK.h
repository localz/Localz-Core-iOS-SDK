//
//  LocalzDebugSDK.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 1/10/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    ERROR,
    DDEBUG,
    WARN,
    DATA,
    INFO,
    VERBOSE
} LocalzDebugLevel;


@interface LocalzDebugSDK : NSObject

/**
 *  Returns a singleton instance of LocalzDebug
 *
 *  @return Returns a singleton instance of LocalzDebugSDK
 */
+ (LocalzDebugSDK * _Nonnull) shared;

/**
 * Initialize the LocalzDebugSDK. Must be called at application start prior to using the Localz
 * SDKs. Temporarily sends Localz verbose logs to assist with remote debugging.
 *
 * @param projectId Your Localz projectId, or in its absence a unique identifier for your project
 * @param jwt A valid JWT provided by Localz. Automatically expires after a set period of time.
 */
- (void) initWithProjectId:(NSString * _Nonnull)projectId jwt:(NSString * _Nonnull)jwt config:(NSDictionary * _Nullable)config;

/**
 * Log messages to Papertrail. Logs are uploaded periodically on an interval.
 *
 * @param level The enum value describing what level of log message to output
 * @param message A valid JWT provided by Localz. Automatically expires after a set period of time.
 */
- (void) log:(LocalzDebugLevel)level message:(NSString * _Nullable)message;

@end

NS_ASSUME_NONNULL_END
