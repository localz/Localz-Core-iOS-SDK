//
//  LocalzCoreErrorType.h
//  LocalzCoreSDK
//
//  Created by Rashmi Sivaramareddy on 14/11/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#ifndef LocalzCoreErrorType_h
#define LocalzCoreErrorType_h

typedef enum {
    EInvalidParameter  = 1, /* Invalid parameter */
    EInvalidResponseFromServer, /* Response received from server is invalid */
    EUnknownError, /* Unknown error */
    ENotFound, /* 404 error */
    ENotAuthorised, /* Not authorised error */
    EUserCancelled, /* User cancelled action */
    ENoProjectsAvailable, /* No projects available */
    ENoConnection, /* No connection */
} LocalzCoreErrorType;

#endif /* CoreErrorType_h */
