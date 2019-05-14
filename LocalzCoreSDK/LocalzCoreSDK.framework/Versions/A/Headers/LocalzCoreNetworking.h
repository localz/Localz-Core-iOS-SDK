//
//  LocalzCoreNetworking.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 15/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString * _Nonnull const CORE_UPDATE_HEADER = @"x-localz-spotzupd";
static NSString * _Nonnull const CORE_DEVICE_ID_HEADER = @"x-localz-deviceid";
static NSString * _Nonnull const CORE_CUSTOM_ID_HEADER = @"x-consumer-custom-id";

static double const CORE_HTTP_CONN_TIMEOUT = 15;

@interface LocalzCoreNetworking : NSObject

@property (nonatomic,readonly) BOOL connectionOK;

+ (LocalzCoreNetworking *_Nonnull) shared;

/**
 *  Recreate the networking instance and set it up with a project id and key
 */
- (LocalzCoreNetworking *_Nonnull) initWithProjectId:(NSString *_Nonnull)projectId projectKey:(NSString *_Nonnull)projectKey;

/**
 *  Restart networking with newly set project id and key
 */
- (void) reinitNetworking;

/**
 *  Download an SSL certificate and save it for pinning
 */
- (void) setupSSLCertificatePinning:(void (^_Nullable)(NSError * _Nullable))completion;

#pragma mark - device registration calls
- (void) registerDeviceWithCompletion:(void(^_Nullable)(NSError *_Nullable error))completion;

/**
 *  Map an identity ID and other information to the device. This information may be used by the Spotz's extensions.
 *
 *  @param identityId identity ID (e.g. email, customerId, token)
 *  @param completion A block that is called upon completion which takes one argument: The error object which is set if unsuccesful, nil if no errors.
 */
- (void) identity:(NSString *_Nonnull)identityId completion:(void(^_Nullable)(NSError *_Nullable error))completion;

/**
 *  Remove identity link from the device
 *
 *  @param completion A block that is called upon completion which takes one ragument: The error object which is set if unsuccessful, nil if no errors.
 */
- (void) removeIdentityWithCompletion:(void(^_Nullable)(NSError *_Nullable error))completion;


- (NSError *_Nonnull) handleError:(NSError *_Nonnull)error statusCode:(NSInteger)statusCode shouldValidateAuth:(BOOL)shouldValidateAuth;

/**
 *  Used to check the status of the user api and internet connection
 */
- (void) healthCheckWithCompletion:(void(^_Nullable)(NSError *_Nullable error))completion;

@end
