//
// YSKIdentificationRequest.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKUniProxySession;
@class YSKIdentificationRequestSettings;
@protocol YSKAudioSource;
@protocol YSKIdentificationRequestDelegate;

/**
 * @abstract Класс для запроса биометрической идентификации пользователя.
 */
@interface YSKIdentificationRequest : NSObject

/**
 * @property delegate
 * @abstract Делегат, который получает уведомления от `YSKIdentificationRequest`.
 */
@property (nonatomic, weak, nullable) id<YSKIdentificationRequestDelegate> delegate;

/**
 * @property settings
 * @abstract Настройки `YSKIdentificationRequest`.
 */
@property (nonatomic, copy, readonly) YSKIdentificationRequestSettings *settings;

/**
 * @property audioSource
 * @abstract Источник, который передает звук для распознавания.
 * @discussion Если аудиоисточник использует стандарный вход устройства, необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно.
 */
@property (nonatomic, strong, readonly) id<YSKAudioSource> audioSource;

/**
 * @abstract Инициализирует объект класса `YSKIdentificationRequest` с указанными настройками.
 * @discussion В качестве источника звука будет использоваться `YSKAutoAudioSource`. Для его работы необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно. Также внутри будет автоматически создана сессия `YSKUniProxySession` для работы с сетью.
 * @param settings Настройки объекта класса `YSKIdentificationRequest`.
 * @return Объект класса `YSKIdentificationRequest`.
 */
- (instancetype)initWithSettings:(YSKIdentificationRequestSettings *)settings;

/**
 * @abstract Инициализирует экземпляр класса `YSKIdentificationRequest` с указанными настройками и объектом класса `YSKUniProxySession`.
 * @discussion В качестве источника звука будет использоваться `YSKAutoAudioSource`. Для его работы необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно.
  * @warning Используйте данный метод, если требуется явно указать сессию, с которой будет работать online-распознавание. Это необходимо, если вы хотите использовать одно сетевое соединение для нескольких компонентов.
 * @param settings Настройки объекта класса `YSKIdentificationRequest`.
 * @param session Объект класса `YSKUniProxySession`, который будет использоваться для сетевого соединения.
 * @return Объект класса `YSKIdentificationRequest`.
 */
- (instancetype)initWithSettings:(YSKIdentificationRequestSettings *)settings session:(YSKUniProxySession *)session;

/**
 * @abstract Инициализирует объект класса `YSKIdentificationRequest` с указанными настройками, аудиоисточником и объектом класса `YSKUniProxySession`.
 * @discussion Если аудиоисточник использует стандартный вход устройства, необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно. Параметр `session` позволит использовать несколько компонентов в рамках одного сетевого соединения.
 * Этот метод является `designated initializer` для класса `YSKIdentificationRequest`.
 * @param settings Настройки объекта класса `YSKIdentificationRequest`.
 * @param audioSource Источник, который передает объекту класса `YSKOnlineRecognizer` звук для распознавания.
 * @param session Объект класса `YSKUniProxySession`, который будет использоваться для сетевого соединения.
 * @return Объект класса `YSKIdentificationRequest`.
 */
- (instancetype)initWithSettings:(YSKIdentificationRequestSettings *)settings audioSource:(id<YSKAudioSource>)audioSource session:(YSKUniProxySession *)session NS_DESIGNATED_INITIALIZER;

+ (instancetype) new __attribute__((unavailable("Use designated initializer -initWithSettings:audioSource:session: instead.")));
- (instancetype) init __attribute__((unavailable("Use designated initializer -initWithSettings:audioSource:session: instead.")));

/**
 * @abstract Начинает запрос.
 */
- (void)start;

/**
 * @abstract Прерывает запись звука для запроса.
 */
- (void)stopRecording;

/**
 * @abstract Отменяет запрос.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
