//
// YSKBaseAudioSource.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKAudioSource.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKAudioSourceSettings;

/**
 * @abstract Абстрактный класс аудиоисточника, который записывает звук, используя стандартный вход устройства.
 * @discussion Класс не является потокобезопасным, в библиотеке используются его потокобезопасные наследники `YSKAutoAudioSource` и `YSKManualAudioSource`. Перед стартом он запрашивает доступ к чтению данных со входа устройства. Если пользователь разрешает доступ, аудиоисточник стартует и начинает отдавать данные слушателям, если пользователь запрещает доступ, аудиоисточник отправляет слушателям ошибку `YSKErrorRecordingPermissions` в методе -[YSKAudioSourceListener audioSource:didFailWithError:]. Коды возможных ошибок перечислены в YSKErrorCode.

 * @warning Этот аудиоисточник и все его наследники используют стандартный вход устройства, поэтому необходимо правильно настроить аудиосессию приложения. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * - если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно.
* Если вы решите настраивать аудиосессию самостоятельно, обратите внимание на настройки, которые могут повлиять на работу аудиоисточника. Они описаны в классе `YSKAudioSessionHandler`. Без соответствующих настроек класс вернет ошибку с кодом `YSKErrorAudioRecording` в методе -[YSKAudioSourceListener audioSource:didFailWithError:].
 */
@interface YSKBaseAudioSource : NSObject<YSKAudioSource>

/**
 * @property settings
 * @abstract Настройки аудиоисточника.
 */
@property (nonatomic, copy, readonly) YSKAudioSourceSettings *settings;

/**
 * @abstract Инициализирует объект класса `YSKBaseAudioSource`.
 * @discussion Этот метод является `designated initializer` для класса `YSKBaseAudioSource`.
 * @param settings Настройки аудиоисточника.
 * @return Объект класса `YSKBaseAudioSource`.
 */
- (instancetype)initWithSettings:(YSKAudioSourceSettings *)settings NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
