//
//  LocalzCoreTools.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 13/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzCoreTools : NSObject

+ (LocalzCoreTools *)sharedInstance;

/**
 *  Convert string to date. If date is not in ISO8091 format it will return nil
 *
 *  @param date NSDate object
 */
- (NSDate *) convertStringToISODate:(NSString *)date;

/**
 *  Convert date to string in ISO8091 format.
 *
 *  @param date NSDate object
 */
- (NSString *) convertISODateToString:(NSDate *)date;

- (NSString *) devicePlatform;

- (NSString *) deviceMachine;

- (void) setupDateFormatter;

@end
