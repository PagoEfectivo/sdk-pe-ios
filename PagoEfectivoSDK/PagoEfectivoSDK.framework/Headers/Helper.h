//
//  Helper.h
//  PagoEfectivoSDK
//
//  Created by Andres on 9/18/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Globals.h"
/** `Helper` es la clase que se dedica a dar funcionalidades genéricas para la interacción con el API*/
@interface Helper : NSObject

#pragma mark - Methods
/** `callService` es el método de tipo `void` que me permite realizar una petición a un servicio*/
/** @param url Es la dirección URL del servicio a consultar*/
/** @param headers Son las cabeceras que se enviarán en la petición a realizar*/
/** @param params Son los parámetros que se enviarán en la petición a realizar*/
/** @param callback Es la función de typo `serviceCallback` que nos permitirá manejar la respuesta del servicio*/
+(void) callService:(NSString*)url headers:(NSDictionary*)headers params:(id)params responseHandler:(serviceCallback)callback;

/** `callService` es el método de tipo `void` que me permite realizar una petición a un servicio*/
/** @param url Es la dirección URL del servicio a consultar*/
/** @param params Son los parámetros que se enviarán en la petición a realizar*/
/** @param callback Es la función de typo `serviceCallback` que nos permitirá manejar la respuesta del servicio*/
+(void) callService:(NSString *)url params:(id)params responseHandler:(serviceCallback)callback;

/** `getDateToRequest` es el método que retorna el tiempo en el formato como indica el servicio*/
+(NSString *) getDateToRequest;

/** `generateHashToRequest` es el método que retorna el hash que solicita el servicio*/
/** @param idService En este parámetro debe ingresarse un id válido*/
/** @param accessKey En este parámetro debe ingresarse un accessKey válido*/
/** @param secretKey En este parámetro debe ingresarse un secretKey válido*/
/** @param dateRequest En este parámetro debe ingresarse un dateRequest válido*/
+(NSString *) generateHashToRequest: (int)idService accessKey:(NSString *)accessKey
                          secretKey:(NSString *)secretKey
                        dateRequest:(NSString *)dateRequest;

/** `generateDictionaryFromArray` es el método que retorna un `NSdictionary*` desde un `NSArray*`*/
/** @param nsarray En este parámetro debe ingresarse el array de valores*/
+(NSDictionary*) generateDictionaryFromArray: (NSArray*) nsarray;
@end
