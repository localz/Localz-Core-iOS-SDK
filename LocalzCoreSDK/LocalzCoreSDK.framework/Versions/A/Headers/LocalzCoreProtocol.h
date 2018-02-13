//
//  CoreProtocol.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 14/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#ifndef LocalzCoreProtocol_h
#define LocalzCoreProtocol_h

@protocol LocalzCoreSDKDelegate <NSObject>

/**
 * Called when SDK has been initialised.
 * @param deviceId deviceId if the initialisation was successful.
 * @param error error object if there were issues with the initialisation. Nil if successful.
 */
- (void) localzCoreSDKInitDelegate:(NSString * _Nullable)deviceId error:(NSError * _Nullable)error;

@end
#endif /* LocalzCoreProtocol_h */
