//
// YSKOnlineRecognizer.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKRecognizing.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKOnlineRecognizerSettings;
@class YSKUniProxySession;
@protocol YSKAudioSource;

/**
 * @abstract Класс для online-распознавания речи. Реализует протокол `YSKRecognizing`.
 * @discussion Объект управляет всеми процессами распознавания, обнаружения голосовой активности, коммуникацией с сервером и т. д. `YSKOnlineRecognizer` использует `YSKRecognizerDelegate` для оповещения об основных событиях, которые возникают в процессе распознавания.
 
 * Перед началом работы с объектом класса `YSKOnlineRecognizer` необходимо задать API-ключ разработчика с помощью свойства -[YSKSpeechKit apiKey].
 
 * @warning При запуске объекта класса `YSKOnlineRecognizer` с аудиоисточником по умолчанию или любым другим источником, который использует стандартный вход устройства, необходимо правильно настроить аудиосессию приложения. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * - если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно.
 * Если вы решите настроить аудиосессию самостоятельно, обратите внимание на настройки, которые могут повлиять на работу объекта класса `YSKOnlineRecognizer` (настройки аудиосессии описаны в классе `YSKAudioSessionHandler`). Без соответствующих настроек объект класса `YSKOnlineRecognizer` вернет ошибку с кодом `YSKErrorAudioRecording` в методе -[YSKRecognizerDelegate recognizer:didFailWithError:]. Коды возможных ошибок перечислены в YSKErrorCode.
 */
@interface YSKOnlineRecognizer : NSObject<YSKRecognizing>

/**
 * @property settings
 * @abstract Настройки объекта класса `YSKOnlineRecognizer`.
 */
@property (nonatomic, copy, readonly) YSKOnlineRecognizerSettings *settings;

/**
 * @abstract Инициализирует объект класса `YSKOnlineRecognizer` с указанными настройками.
 * @discussion В качестве источника звука будет использоваться `YSKAutoAudioSource`. Для его работы необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно. Также внутри будет автоматически создана сессия `YSKUniProxySession` для работы с сетью.
 * @param settings Настройки объекта класса `YSKOnlineRecognizer`.
 * @return Объект класса `YSKOnlineRecognizer`.
 */
- (instancetype)initWithSettings:(YSKOnlineRecognizerSettings *)settings;

/**
 * @abstract Инициализирует объект класса `YSKOnlineRecognizer` с указанными настройками и объектом класса `YSKUniProxySession`.
 * @discussion В качестве источника звука будет использоваться `YSKAutoAudioSource`. Для его работы необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно.
 * @warning Используйте данный метод, если требуется явно указать сессию, с которой будет работать online-распознавание. Это необходимо, если вы хотите использовать одно сетевое соединение для нескольких компонентов.
 * @param settings Настройки объекта класса `YSKOnlineRecognizer`.
 * @param session Объект класса `YSKUniProxySession`, который будет использоваться для сетевого соединения.
 * @return Объект класса `YSKOnlineRecognizer`.
 */
- (instancetype)initWithSettings:(YSKOnlineRecognizerSettings *)settings session:(YSKUniProxySession *)session;

/**
 * @abstract Инициализирует объект класса `YSKOnlineRecognizer` с указанными настройками, аудиоисточником и объектом класса `YSKUniProxySession`.
 * @discussion Если аудиоисточник использует стандартный вход устройства, необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно. Параметр `session` позволит использовать несколько компонентов в рамках одного сетевого соединения.
 * Этот метод является `designated initializer` для класса `YSKOnlineRecognizer`.
 * @param settings Настройки объекта класса `YSKOnlineRecognizer`.
 * @param audioSource Источник, который передает объекту класса `YSKOnlineRecognizer` звук для распознавания.
 * @param session Объект класса `YSKUniProxySession`, который будет использоваться для сетевого соединения.
 * @return Объект класса `YSKOnlineRecognizer`.
 */
- (instancetype)initWithSettings:(YSKOnlineRecognizerSettings *)settings audioSource:(id<YSKAudioSource>)audioSource session:(YSKUniProxySession *)session NS_DESIGNATED_INITIALIZER;

+ (instancetype) new __attribute__((unavailable("Use designated initializer -initWithSettings:audioSource: instead.")));
- (instancetype) init __attribute__((unavailable("Use designated initializer -initWithSettings:audioSource: instead.")));

@end

NS_ASSUME_NONNULL_END
