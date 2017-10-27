//
//  CIP.h
//  PagoEfectivoSDK
//
//  Created by Andres on 9/15/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Globals.h"
#import "Helper.h"
#import "CipRequest.h"
#import "Credential.h"
#import "CipHelper.h"

#pragma mark - TypeAliases
/** `serviceCallbackCipSearch` es el typealias para el manejo de respuestas del parte del servicio.*/
typedef void (^serviceCallbackCipSearch)(long status, NSMutableArray *cipSearchArray, NSError *error);

/** `Cip` es la clase que maneja la parte de generación y consulta de Cips*/
@interface Cip : NSObject
#pragma mark - Properties
/** `credentialInstance` es una propiedad de tipo `Credential`*/
@property Credential *credentialInstance;

#pragma mark - Methods
/** `shared` es el método de tipo `instancetype` que permite retornar una instancia Cip*/
/** @param credentialInstance debe ser un modelo válido de tipo `Credential`*/
+(instancetype) shared: (Credential *)credentialInstance;

#pragma mark - Generación de Cip
/** `generate` es el método que me permite generar un nuevo Cip*/
/** @param requestObject debe ser un módelo de tipo `CipRequest`*/
/** @param callback es un parámetro que se ingresa como función para manejar la información que retorna el servicio*/
-(void) generate:(CipRequest *)requestObject responseHandler:(serviceCallback)callback;

/** `generate` es el método que me permite generar un nuevo Cip, esta es una versión con más opciones*/
/** @param language es un tipo de dato `language`*/
/** @param requestObject es un tipo de dato `CipRequest`*/
/** @param callback es un parámetro que se ingresa como función para manejar la información que retorna el servicio*/
-(void) generate:(language)language requestObject:(CipRequest *)requestObject responseHandler:(serviceCallback)callback;

#pragma mark - Búsqueda de Cips
/** `search` es el método que me permite generar un nuevo Cip*/
/** @param params debe ser un arreglo de numeros*/
/** @param callback es un parámetro que se ingresa como función para manejar la información que retorna el servicio*/
-(void) search:(NSArray *)params responseHandler:(serviceCallback)callback;

/** `search` es el método que me permite generar un nuevo Cip, esta es una versión con más opciones*/
/** @param language es un tipo de dato `language`*/
/** @param params debe ser un arreglo de numeros*/
/** @param callback es un parámetro que se ingresa como función para manejar la información que retorna el servicio*/
-(void) search:(language)language params:(NSArray *)params responseHandler:(serviceCallback)callback;
@end
