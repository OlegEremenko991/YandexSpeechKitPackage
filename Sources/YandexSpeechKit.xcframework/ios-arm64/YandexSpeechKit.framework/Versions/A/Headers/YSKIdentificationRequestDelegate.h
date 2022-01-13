//
// YSKIdentificationRequestDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKDispatchableDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKIdentificationRequest;

/**
 * @abstract Протокол определяет callback-методы делегата, которые вызываются объектом класса `YSKIdentificationRequest`.
 */
@protocol YSKIdentificationRequestDelegate <YSKDispatchableDelegate>
/**
 * @abstract Вызывается в момент начала записи звука.
 * @param identificationRequest Объект класса `YSKIdentificationRequest`.
 */
- (void)identificationRequestDidStartRecording:(YSKIdentificationRequest *)identificationRequest;

/**
 * @abstract Вызывается в момент завершения записи звука.
 * @param identificationRequest Объект класса `YSKIdentificationRequest`.
 */
- (void)identificationRequestDidFinishRecording:(YSKIdentificationRequest *)identificationRequest;

/**
 * @abstract Вызывается в момент завершения идентификации.
 * @param identificationRequest Объект класса `YSKIdentificationRequest`.
 * @param uuid Найденный `uuid`.
 */
- (void)identificationRequest:(YSKIdentificationRequest *)identificationRequest didFinishWithUUID:(NSString *)uuid;

/**
 * @abstract Вызывается, если в процессе идентификации произошла ошибка.
 * @param identificationRequest Объект класса `YSKIdentificationRequest`.
 * @param error Ошибка, которая произошла в процессе идентификации.
 */
- (void)identificationRequest:(YSKIdentificationRequest *)identificationRequest didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
