//
//  Credential.h
//  PagoEfectivoSDK
//
//  Created by Andres on 9/21/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Credential : NSObject

//Properties
@property int serviceId;
@property NSString* accessKey;
@property NSString* secretKey;

@end
