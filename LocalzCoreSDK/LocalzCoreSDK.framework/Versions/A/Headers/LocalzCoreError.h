//
//  CoreError.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 16/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzCoreErrorType.h"

#define LocalzCoreErrorDomain @"LocalzCoreSDKDomain"

@interface LocalzCoreError : NSError
+ (NSError *)errorWithCode:(LocalzCoreErrorType)code userInfo:(NSDictionary *)userInfo;
+ (NSError *)errorWithResponse:(NSURLResponse *)response data:(NSDictionary *)data;
+ (NSError *)invalidResponseFromServer;
+ (NSError *)notFound;
+ (NSString *)descriptionForCode:(int)code;

@end
