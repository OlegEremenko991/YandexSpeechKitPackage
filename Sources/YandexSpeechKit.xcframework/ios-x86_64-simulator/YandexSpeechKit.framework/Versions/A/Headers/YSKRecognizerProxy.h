//
// YSKRecognizerProxy.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKRecognizing.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKLanguage;
@class YSKUniProxySession;
@class YSKOnlineRecognizerSettings;

__attribute__((objc_subclassing_restricted))

/**
 @abstract Класс-переключатель между online-распознаванием библиотеки `SpeechKit` и системным фреймворком `Speech`.
 @discussion Класс задает список языков, которые будут распознаваться библиотекой `SpeechKit`. Если переданный язык не входит в этот список, речь будет распознана с помощью системного фреймворка `Speech`. Если переданный язык входит в список, но не поддерживается библиотекой `SpeechKit`, будет возвращена ошибка в методе -[YSKRecognizerDelegate recognizer: didFailWithError:].
 @warning Данная функциональность доступна, начиная с iOS 10.0.
 */
@interface YSKRecognizerProxy : NSObject<YSKRecognizing>

/**
 @abstract Инициализирует объект класса `YSKRecognizerProxy`.
 @discussion В качестве источника звука будет использоваться `YSKAutoAudioSource`. Для его работы необходимо правильно настроить аудиосессию приложения. Для этого используйте класс `YSKAudioSessionHandler` или настройте аудиосессию самостоятельно для корректной записи звука. Также внутри будет автоматически создана сессия `YSKUniProxySession` для работы с сетью.
 @param settings Настройки объекта класса `YSKOnlineRecognizer`.
 @param languages Cписок языков, которые будут распознаваться библиотекой `SpeechKit`.
 @return Объект класса `YSKRecognizerProxy`.
 */
- (instancetype)initWithSettings:(YSKOnlineRecognizerSettings *)settings
              supportedLanguages:(NSArray<YSKLanguage *>*)languages;

/**
 @abstract Инициализирует объект класса `YSKRecognizerProxy`.
 @discussion Этот метод является `designated initializer` для класса `YSKRecognizerProxy`.
 Если переданный аудиоисточник использует стандартный вход устройства, необходимо правильно настроить аудиосессию приложения. Для этого используйте класс `YSKAudioSessionHandler` или настройте аудиосессию самостоятельно для корректной записи звука. Параметр сессия позволит использовать несколько компонентов в рамках одного сетевого соединения.
 @param settings Настройки объекта класса `YSKOnlineRecognizer`.
 @param audioSource Источник, который передает объекту класса `YSKOnlineRecognizer` звук для распознавания.
 @param session Объект класса `YSKUniProxySession`, который будет использоваться для сетевого соединения.
 @param languages Cписок языков, которые будут распознаваться библиотекой `SpeechKit`
 @return Объект класса `YSKRecognizerProxy`.
 */
- (instancetype)initWithSettings:(YSKOnlineRecognizerSettings *)settings
                     audioSource:(id<YSKAudioSource>)audioSource
                         session:(YSKUniProxySession *)session
              supportedLanguages:(NSArray<YSKLanguage *>*)languages NS_DESIGNATED_INITIALIZER;

+ (instancetype) new __attribute__((unavailable("Use designated initializer -initWithSettings:supportedLanguages: instead.")));
- (instancetype) init __attribute__((unavailable("Use designated initializer -initWithSettings:supportedLanguages: instead.")));

@end

NS_ASSUME_NONNULL_END
