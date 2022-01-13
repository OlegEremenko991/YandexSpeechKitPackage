//
// YSKRegistrationRequestDelegate.h
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

@class YSKRegistrationRequest;
/**
 * @abstract Протокол определяет callback-методы делегата, которые вызываются `YSKRegistrationRequest`.
 */
@protocol YSKRegistrationRequestDelegate <YSKDispatchableDelegate>

/**
 * @abstract Вызывается в момент начала записи звука.
 * @param identificationRequest Объект класса `YSKRegistrationRequest`.
 */
- (void)registrationRequestDidStartRecording:(YSKRegistrationRequest *)identificationRequest;

/**
 * @abstract Вызывается в момент завершения записи звука.
 * @param identificationRequest Объект класса `YSKRegistrationRequest`.
 */
- (void)registrationRequestDidFinishRecording:(YSKRegistrationRequest *)identificationRequest;

/**
 * @abstract Вызывается в момент завершения регистрации.
 * @param identificationRequest Объект класса `YSKRegistrationRequest`.
 */
- (void)registrationRequestDidFinishRegistration:(YSKRegistrationRequest *)identificationRequest;

/**
 * @abstract Вызывается, если в процессе регистрации произошла ошибка.
 * @param identificationRequest Объект класса `YSKRegistrationRequest`.
 * @param error Ошибка, которая произошла в процессе регистрации.
 */
- (void)registrationRequest:(YSKRegistrationRequest *)identificationRequest didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
