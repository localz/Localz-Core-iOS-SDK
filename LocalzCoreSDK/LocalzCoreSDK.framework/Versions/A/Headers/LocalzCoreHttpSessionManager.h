//
//  LocalzCoreHttpSessionManager.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 17/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

typedef enum {
    LocalzCoreHttpSessionAuthNone = 1,
    LocalzCoreHttpSessionAuthBasic,
    LocalzCoreHttpSessionAuthOAuth2
} LocalzCoreHttpSessionAuthType;


@protocol LocalzCoreHttpSessionManagerDelegate <NSObject>
- (void) networkConnectionChanged:(BOOL) isConnected;
@optional
- (NSDictionary *) additionalHeader;
- (NSDictionary *) additionalSecureHeader;
@end

@interface LocalzCoreHttpSessionManager : NSObject <NSURLSessionDelegate>
@property (nonatomic,assign) id<LocalzCoreHttpSessionManagerDelegate> delegate;
@property (nonatomic) BOOL isConnected;

+ (LocalzCoreHttpSessionManager *) instanceWithBaseURL:(NSURL *)baseURL projectId:(NSString *)projectId projectKey:(NSString *)projectKey;
- (LocalzCoreHttpSessionManager *) initWithBaseURL:(NSURL *)url projectId:(NSString *)projectId projectKey:(NSString *)projectKey;

- (void) setTimeoutInterval:(NSTimeInterval) timeInterval;

- (NSURLSessionDataTask *)secureApiPOST:(NSString *)URLString deviceId:(NSString *)deviceId auth:(LocalzCoreHttpSessionAuthType)authType parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)apiPOST:(NSString *)URLString parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)secureApiPUT:(NSString *)URLString deviceId:(NSString *)deviceId auth:(LocalzCoreHttpSessionAuthType)authType parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)apiPUT:(NSString *)URLString parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)secureApiGET:(NSString *)URLString deviceId:(NSString *)deviceId auth:(LocalzCoreHttpSessionAuthType)authType parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)apiGET:(NSString *)URLString parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)secureApiDELETE:(NSString *)URLString deviceId:(NSString *)deviceId auth:(LocalzCoreHttpSessionAuthType)authType parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
- (NSURLSessionDataTask *)apiDELETE:(NSString *)URLString parameters:(id)parameters success:(void (^)(NSURLSessionDataTask *task, id responseObject))success failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

@end
