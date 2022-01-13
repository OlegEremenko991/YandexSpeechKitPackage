//
// YSKOnlineVocalizer.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKVocalizing.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKOnlineVocalizerSettings;
@class YSKUniProxySession;

/**
 * @abstract Класс для online-синтеза и озвучивания речи.
 * @discussion Отвечает за отправку текста на сервер и озвучивание синтезированной речи. Реализует протокол `YSKVocalizing`.
 * @warning При проигрывании синтезированной речи через встроенный плеер в объекте класса `YSKOnlineVocalizer`, необходимо правильно настроить аудиосессию приложения. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * - если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно.
 * Если вы решите настраивать аудиосессию самостоятельно, обратите внимание на настройки, которые могут повлиять на работу проигрывателя в объекте класса `YSKOnlineVocalizer` (настройки аудиосессии описаны в классе `YSKAudioSessionHandler`). Без соответствующих настроек объект класса `YSKOnlineVocalizer` вернет ошибку с кодом `YSKErrorAudioPlaying` в методе -[YSKVocalizerDelegate vocalizer:didFailWithError:]. Коды возможных ошибок перечислены в YSKErrorCode.
 */
@interface YSKOnlineVocalizer : NSObject<YSKVocalizing>

/**
 * @property settings
 * @abstract Настройки объекта класса `YSKOnlineVocalizer`.
 */
@property (nonatomic, copy, readonly) YSKOnlineVocalizerSettings *settings;

/**
 * @abstract Инициализирует объект класса `YSKOnlineVocalizer` с указанными настройками.
 * @param settings Настройки объекта класса `YSKOnlineVocalizer`.
 * @return Объект класса `YSKOnlineVocalizer`.
 */
- (instancetype)initWithSettings:(YSKOnlineVocalizerSettings *)settings;

/**
 * @abstract Инициализирует объект класса `YSKOnlineVocalizer` с указанными настройками и сетевым соединением.
 * @discussion Параметр `session` позволяет использовать несколько компонентов в рамках одного сетевого соединения.
 * Этот метод является `designated initializer` для класса `YSKOnlineVocalizer`.
 * @param settings Настройки объекта класса `YSKOnlineVocalizer`.
 * @param session Объект класса `YSKUniProxySession`, который будет использоваться для сетевого соединения.
 * @return Объект класса `YSKOnlineVocalizer`.
 */
- (instancetype)initWithSettings:(YSKOnlineVocalizerSettings *)settings session:(YSKUniProxySession *)session NS_DESIGNATED_INITIALIZER;

+ (instancetype) new __attribute__((unavailable("Use designated initializer -initWithSettings: instead.")));
- (instancetype) init __attribute__((unavailable("Use designated initializer -initWithSettings: instead.")));

@end

NS_ASSUME_NONNULL_END
