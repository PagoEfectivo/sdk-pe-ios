//
//  Globals.h
//  PagoEfectivoSDK
//
//  Created by Andres on 9/15/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>
#pragma mark - Typealias
/**
 `serviceCallback` El alias del manejo del callback del API
*/
typedef void (^serviceCallback)(long status, id receivedData, NSError *error);

#pragma mark - Constants

/*typedef enum {
 PEN = 1,
 USD
 } currency; */
/** `currency`
  Los valores de la estructura representa el tipo de moneda
  - PEN: soles
  - USD: dólares
*/
typedef NS_ENUM(NSInteger, currency){
    /** `PEN` en Soles*/
    PEN = 1,
    /** `USD` en Dólares*/
    USD,
    /** `NONE` en caso se envíe vacío*/
    NONE
};


/*typedef enum {
    DNI,
    PASS,
    LMI,
    PAR,
    NANE
} documentType;*/
/**
 `documentType` la estructura que se orienta al tipo de documento
 - DNI: Documento nacional de identidad
 - PASS: Pasaporte
 - LMI: Libreta Militar
 - PAR: Partida de nacimiento
 - NANE: No tiene uno
 */
typedef NS_ENUM(NSInteger, documentType){
    /** Documento nacional de identidad */
    DNI,
    /** Pasaporte */
    PASS,
    /** Libreta militar */
    LMI,
    /** Partida de nacimiento */
    PAR,
    /** No tiene documentos */
    NANE
};

/*
 typedef enum {
    ES,
    EN
} language;
*/
/** `language` la estructura que se orienta al idioma a trabajar con el API
  Los valores de la estructura representa los lenguajes disponibles
*/
typedef NS_ENUM(NSInteger, language){
    /** `ES` es para indicar al servicio que debe retornar las respuestas en español*/
    ES,
    /** `EN` es para indicar al servicio que debe retornar las respuestas en español*/
    EN
};


/*typedef enum {
    Indica autorización satisfacoria de parte del servicio
    SUCCESS_AUTHORIZATION, // 201
    Indica generación de cip satisfacoria de parte del servicio
    SUCCESS_GENERATE_CIP, // 201
    SUCCESS_SEARCH_CIP,
    BAD_REQUEST, //400
    UNAUTHORIZED, //401
    INTERNAL_ERROR //500
} API_STATUS;*/

/** `API_STATUS` es la estructura que se orienta a las respuestas del API
  Los valores de la estructura representa los estados del servicio
 */
typedef NS_ENUM(NSInteger, API_STATUS) {
    /** Indica autorización satisfacoria de parte del servicio*/
    SUCCESS_AUTHORIZATION, // 201
    /** Indica generación de cip satisfacoria de parte del servicio*/
    SUCCESS_GENERATE_CIP, // 201
    /** Indica búsqueda de cip satisfacoria de parte del servicio*/
    SUCCESS_SEARCH_CIP,
    /** Indica una respuesta no satisfactoria de parte del servicio*/
    BAD_REQUEST, //400
    /** Indica error de autorización al servicio*/
    UNAUTHORIZED, //401
    /** Indica error interno del servicio*/
    INTERNAL_ERROR, //500
    /** Indica cuando servidor está apagado*/
    SERVICE_DOWN //503
};

/**
  `Globals` es la clase que provee propiedades transversales al SDK
*/
@interface Globals : NSObject

#pragma mark - Methods
/**
 Transforma el `Currency` ingresado en la aplicación retornando una cadena
 @param value de tipo `currency` a transformar
*/
+(NSString*)currencyToString: (currency)value;

/**
 Transforma el `documentType` ingresado en la aplicación retornando una cadena
 @param value de tipo `documentType` a transformar
*/
+(NSString*)documentTypeToString: (documentType)value;

/**
 Transforma el `language` ingresado en la aplicación retornando una cadena
 @param value de tipo `language` a transformar
 */
+(NSString*)languageToString: (language)value;

/**
 Retorna la URL base del servicio
*/
+(NSString*)getURLService;

/**
 Retorna la URL de la autorización
 */
+(NSString*)getURLAuth;

/**
 Retorna la URL de la generación de CIP
 */
+(NSString*)getURLGenerateCip;

/**
 Retorna la URL de buscar CIP
 */
+(NSString*)getURLSearchCip;

/**
 Retorna el status numérico en base a un valor de tipo API_STATUS
 */
+(long)getAPIStatus: (API_STATUS)value;
@end
