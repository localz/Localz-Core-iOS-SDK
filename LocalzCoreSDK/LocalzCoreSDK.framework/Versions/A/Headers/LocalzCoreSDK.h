/*
 * (C) 2018 Localz Pty Ltd
 *
 * [All rights reserved]. This product and related documentation are protected
 * by copyright restricting its use, copying, distribution, and decompilation.
 * No part of this product or related documentation may be reproduced in any
 * form by any means without prior written authorization of Localz.
 * Unless otherwise arranged, third parties may not
 * have access to this product or related documents.
 */

#import <UIKit/UIKit.h>
#import "LocalzCoreErrorType.h"
#import "LocalzCoreProtocol.h"
#import "LocalzCoreConstant.h"
#import "LocalzCoreError.h"

@class LocalzCoreSDK;

/**
 *  CoreSDK is the base class of Localz's Platform
 */
@interface LocalzCoreSDK : NSObject

/**
 *  Returns a singleton instance of LocalzCore
 *
 *  @return Returns a singleton instance of LocalzCoreSDK
 */
+ (nonnull LocalzCoreSDK *) shared;

/**
 *  Initialises the service and registers the device with the given API Key and client Key.
 *
 *  @param projectId projectId provided by Localz
 *  @param projectKey projectKey provided by Localz
 *  @param config options for additional setup
 *  @param delegate the delegate class that adopts LocalzCoreSDKDelegate protocol
 */
+ (void) initWithProjectId:(NSString *_Nonnull)projectId projectKey:(NSString *_Nonnull)projectKey config:(NSDictionary *_Nullable)config withDelegate:(_Nullable id<LocalzCoreSDKDelegate>)delegate;

/**
 *  Returns the device ID assigned to this device
 *
 *  @return The Localz's device ID assigned to this device
 */
- (nullable NSString *)deviceId;

/**
 *  Sets Core SDK with the required JWT token.
 *
 *  @param jwtToken jwtToken provided by Localz
 *  @param refreshToken refreshToken provided by Localz to refresh JWT when expired
 */
- (void) setJWT:(NSString *_Nullable)jwtToken refreshToken:(NSString *_Nullable)refreshToken;

/**
 *  Associates the current device with a custom identity. Note that if the app is reinstalled, deviceId will need to be re-associated with the identity.
 *
 *  @param identityId identity to be assigned to this device e.g. customerId/token/email
 *  @param completion A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the error object describing the error that occurred.
 */
- (void) identity:(nonnull NSString *)identityId completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

/**
 *  Removes identity that is mapped to this device
 *
 *  @param completion A block object to be executed when the task finishes successfully. This block has no return value and takes one argument: the error object describing the error that occurred.
 */
- (void) removeIdentityWithCompletion:(void(^ _Nullable)(NSError * _Nullable error))completion;

/**
 *  Reset all data on the SDK. You will need to initialise the SDK again before use after calling this.
 */
- (void) resetSDK;

/**
 *  Sets the JWT token and refresh token to Null
 */
- (void) logoutDevice;

@end

