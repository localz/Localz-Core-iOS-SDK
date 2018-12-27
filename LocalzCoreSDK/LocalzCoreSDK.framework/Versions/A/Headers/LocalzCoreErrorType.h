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
    ECoreInvalidParameter  = 1, /* Invalid parameter */
    ECoreInvalidResponseFromServer, /* Response received from server is invalid */
    ECoreUnknownError, /* Unknown error */
    ECoreNotFound, /* 404 error */
    ECoreNotAuthorised, /* Not authorised error */
    ECoreUserCancelled, /* User cancelled action */
    ECoreFacebookError, /* Facebook related errors */
    ECoreBeaconError, /* Beacon related errors */
    ECoreBluetoothNotEnabled, /* Bluetooth not enabled */
    ECoreLocationNotAuthorized, /* Location services not authorized */
    ECoreLocationDenied, /* Location services denied */
    ECoreLocationNotEnabled, /* Location services not authorized */
    ECoreNoProjectsAvailable, /* No projects available */
    ECoreNoSitesAvailable, /* No sites available */
    ECoreNoConnection, /* No connection */
    ECoreLocationFailed, /* Failed obtaining location */
} LocalzCoreErrorType;

#endif /* CoreErrorType_h */
