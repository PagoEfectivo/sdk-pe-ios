//
//  CipHelper.h
//  PagoEfectivoSDK
//
//  Created by gerardo on 20/09/17.
//  Copyright © 2017 Orbis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Globals.h"

/** `CipHelper` es la clase helper donde se aloja funcionalidades genéricas*/
@interface CipHelper: NSObject
#pragma mark - Validations
/**
 `validateCurrency` es el método que válida si un valor ingresado es realmente de tipo `currency`
 @param currency el valor ingresado
 @return retorna un valor de tipo `BOOL` si es válido es TRUE en caso contrario FALSE
*/
+(BOOL)validateCurrency:(currency) currency;

/**
 `validateAmount` es el método que válida si un valor ingresado es realmente de tipo `amount`
 @param amount el valor ingresado debe ser de tipo `double`
 @return retorna un valor de tipo `BOOL` si es válido es TRUE en caso contrario FALSE
 */
+(BOOL)validateAmount:(double)amount;

/**
 `validateTransactionCode` es el método que válida si un valor ingresado es realmente de tipo `NSString` y contiene al menos un caractér
 @param transactionCode el valor ingresado debe ser de tipo `NSString`
 @return retorna un valor de tipo `BOOL` si es válido es TRUE en caso contrario FALSE
 */
+(BOOL)validateTransactionCode:(NSString*)transactionCode;


/**
 `validateTransactionCode` es el método que válida si un valor ingresado es realmente de tipo `NSString` y contiene al menos un caractér
 @param userEmail el valor ingresado debe ser de tipo `NSString`
 @return retorna un valor de tipo `BOOL` si es válido es TRUE en caso contrario FALSE
 */
+(BOOL)validateUserEmail:(NSString*)userEmail;

/**
 `validateArrayCip` es el método que válida una colleción de valores de tipo NSArray
 @param cips la colleción de tipo NSArray
 @return retorna un valor de tipo `BOOL` si es válido es TRUE en caso contrario FALSE
 */
+(BOOL)validateArrayCip:(NSArray*)cips;
@end
