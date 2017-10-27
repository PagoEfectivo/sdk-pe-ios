//
//  Auth.h
//  PagoEfectivoSDK
//
//  Created by Andres on 9/19/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Globals.h"
#import "Helper.h"
#import "Credential.h"

/** `Auth` es la clase dedicada a la seguridad para con el servicio*/
@interface Auth : NSObject
/**
 `requestToken` es el método que solicita al servidor una llave de autenticación
  para el consumo de los servicios
 @param language Parámetro de tipo language
 @param credentialInstance Parámetro de tipo credentialInstance
 @param responseHandler es un tipo de dato callback para manejar la información que retorna el servicio
 */
+(void)requestToken: (language)language credentialInstance:(Credential*)credentialInstance responseHandler:(serviceCallback)responseHandler;
@end
