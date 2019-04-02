//
//  LocalzCoreConfiguration.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 15/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#define CORE_BEACONS_MAX_THRESHOLD 16

typedef enum {
    CoreDCRegionAU = 6000,
    CoreDCRegionEU = 3000,
    CoreDCRegionUS = 9000
} LocalzCoreDCRegion;

extern NSString * const CORE_SDK_VERSION;
extern NSString * const CORE_APPID_AU_REGION;
extern NSString * const CORE_APPID_EU_REGION;
extern NSString * const CORE_API_AU_REGION_KEY;
extern NSString * const CORE_API_EU_REGION_KEY;
extern NSString * const CORE_API_HOST_SUFFIX;
extern NSString * const CORE_PROJECT_ID;
extern NSString * const CORE_PROJECT_KEY;
extern NSString * const CORE_DEVICE_ID;
extern NSString * const CORE_TYPES;
extern NSString * const CORE_ENV_ID;
extern NSString * const CORE_ENV_URL;
extern NSString * const CORE_ENV;
extern NSString * const CORE_SDK_CURRENT_VERSION_KEY;
extern NSString * const CORE_SSL_DOMAIN_SPKI_KEY;
extern NSString * const CORE_SSL_PIN_ENABLE_KEY;
extern NSString * const CORE_SSL_PIN_SUFFIX;
extern NSString * const CORE_DEVICE_JWT_KEY;
extern NSString * const CORE_DEVICE_JWT_REFRESH_KEY;
extern NSString * const CORE_DEBUG_LOG;
extern NSString * const CORE_DEBUG_URL;
extern NSString * const CORE_DEBUG_PROJECT_KEY;
extern NSString * const CORE_DEBUG_JWT_KEY;

@interface LocalzCoreConfiguration : NSObject

// True if SDK is running in dev mode
@property (nonatomic) BOOL isDebug;
@property (nonatomic, strong) NSString *regionCode;
@property (nonatomic, strong) NSString *currentVersion;
@property (nonatomic, strong) NSArray *sslDomainAndSPKIKeys;
@property (nonatomic) BOOL isSSLPinEnabled;
@property (nonatomic, strong) NSString *jwtToken;
@property (nonatomic, strong) NSString *jwtRefreshToken;
@property (nonatomic, strong) NSString *debugJWT;

/**
 *  Returns an instance of this class
 *
 *  @return instance of the class
 */
+ (LocalzCoreConfiguration *) shared;

- (void) configureWithParams:(NSDictionary *)config;

/**
 *  Initialise shared instance for the given environment. If called after initial call, it will update values to the given environment.
 *
 * @param env Environment to use [Production,Development]
 */
- (void) configureForEnv:(NSString *)env;

/**
 *  Check if SDK is set correctly - i.e project Id and key are present and set
 */
- (BOOL) isSDKOk;

/**
 *  Returns the value stored in the configuration file based on SpotzEnvironments.plist
 *  If there is an override value for the key given, it will return the override value
 *  If the value exists for the target build, it will return the target build value
 *  Otherwise it will return the default value set. If not found it will return null
 *
 *  @param key the key name to retrieve
 *
 *  @return returns the value for the given key
 */
- (id) getValue:(NSString *)key;

/**
 *  Override value of the SDK config
 *
 *  @param key    the key name to override
 *  @param object the object to override with
 */
- (void) overrideKey:(NSString *)key withObject:(id)object;

/**
 *  Retrieve SDK Version
 *
 *  @return sdk version
 */
- (NSString *) sdkVersion;

/**
 *  Set application Id and client Key
 *
 *  @param projectId projectID
 *  @param projectKey projectKey
 */
- (void) setProjectId:(NSString *)projectId projectKey:(NSString *)projectKey;

/**
 *  Set application Id and client Key
 *
 *  @param projectId projectID
 */
- (void) setDebugProjectId:(NSString *)projectId debugJwt:(NSString *)jwt;

/**
 *  Returns projectId
 */
- (NSString *) projectId;

/**
 *  Returns projectKey
 */
- (NSString *) projectKey;

/**
 *  Retrieve device ID from user defaults
 */
- (NSString *) deviceId;

/**
 *  Set Device ID
 *
 *  @param deviceId device ID
 */
- (void) setDeviceId:(NSString *)deviceId;

/**
 * Retrieve Host server
 *
 *  @return host server
 */
- (NSString *) host;

/**
 * Retrieve the URL of the SSL pinning certificate
 *
 *  @return ssl pin url
 */
- (NSString *) sslPinUrl;

/**
 *  Delete all Localz config to factory setting (i.e. none set)
 */
- (void) reset;

- (BOOL) pLog;

- (void) setDebugMode:(BOOL)debug;

- (LocalzCoreDCRegion) dcRegion;

@end
