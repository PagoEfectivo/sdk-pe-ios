//
//  CipRequest.h
//  PagoEfectivoSDK
//
//  Created by gerardo on 20/09/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Globals.h"

/** `CipRequest` es el modelo necesario para facilitar la generación de cip*/
@interface CipRequest: NSObject
#pragma mark - Properties
/*En este modelo se divide en 2 tipos de propiedades, las requeridad y opcionales ya que 
 el servicio solicita ciertos campos requeridos*/

#pragma mark - Required fields
/*Los campos requeridos que solicita el servicio*/

/** `currency` es la propiedad requerida de tipo `currency`*/
@property (nonatomic, assign)currency currency; // requerido

/** `amount` es la propiedad requerida de tipo `double`*/
@property (assign) double amount; // requerido

/** `transactionCode` es la propiedad requerida de tipo `NSString`*/
@property (nonatomic,strong)NSString* transactionCode; // requerido

/** `userEmail` es una propiedad requerida de tipo `NSString`
 donde se debe ingresar el email del usuario
 */
@property (nonatomic,strong)NSString* userEmail; // requerido

#pragma mark - Optional fields
/*Los campos opcionales a usar para tratar con el servicio*/

/** `adminEmail` es una propiedad opcional de tipo `NSString`*/
@property (nonatomic,strong)NSString* adminEmail;

/** `dateExpiry` es una propiedad opcional de tipo `NSString`
 NOTA: El servicio validará el formato ingresado de fecha.
*/
@property (nonatomic,strong)NSDate* dateExpiry;

/** `paymentConcept` es una propiedad opcional de tipo `NSString`
     donde se debe indicar el concepto de pago
*/
@property (nonatomic,strong)NSString* paymentConcept;

/** `additionalData` es una propiedad opcional de tipo `NSString`
     donde se debe ingresar alguna información extra.
*/
@property (nonatomic,strong)NSString* additionalData;

/** `userName` es una propiedad opcional de tipo `NSString`
 donde se debe ingresar el nombre del usuario
*/
@property (nonatomic,strong)NSString* userName;

/** `userLastName` es una propiedad opcional de tipo `NSString`
 donde se debe ingresar el apellido del usuario
 */
@property (nonatomic,strong)NSString* userLastName;

/** `userUbigeo` es una propiedad opcional de tipo `NSString`
 donde se debe ingresar el ubigeo
 */
@property (nonatomic,strong)NSString* userUbigeo;

/** `userCountry` es una propiedad opcional de tipo `NSString`
 donde se debe ingresar el país del usuario
 */
@property (nonatomic,strong)NSString* userCountry;

/** `userDocumentType` es una propiedad opcional de tipo `documentType`
 donde se debe ingresar el tipo de documento
 */
@property (nonatomic, assign)documentType userDocumentType; // de tipo

/** `userDocumentNumber` es una propiedad opcional de tipo `NSString`
 donde se debe ingresar el nro de documento
 
 NOTA: El servicio validará el formato ingresado debe ser acorde al tipo de documento.
 */
@property (nonatomic,strong)NSString* userDocumentNumber;

/** `userPhone` es una propiedad opcional de tipo `NSString`
 donde se debe ingresar el número telefónico
 */
@property (nonatomic,strong)NSString* userPhone;

/**
 userCodeCountry es una propiedad opcional
 */
@property (nonatomic,strong)NSString* userCodeCountry;

/**
 serviceId es una propiedad opcional de tipo `int`
 */
@property (assign) int serviceId;
@end
