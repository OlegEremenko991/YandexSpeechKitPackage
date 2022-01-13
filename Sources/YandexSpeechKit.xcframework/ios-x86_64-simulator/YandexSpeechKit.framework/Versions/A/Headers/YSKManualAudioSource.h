//
// YSKManualAudioSource.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKBaseAudioSource.h"

/**
 * @abstract Аудиоисточник, который позволяет управлять началом и окончанием записи звука, используя стандартный вход устройства.
 * @discussion Класс `YSKManualAudioSource` потокобезопасный, к нему можно обращаться из разных потоков. Объект `YSKManualAudioSource` многоразовый, он может начинать и заканчивать процесс записи звука неограниченное количество раз. Для этого достаточно снова вызвать метод -[YSKManualAudioSource start]. Перед стартом он запрашивает доступ к чтению данных со входа устройства. Если пользователь разрешает доступ, аудиоисточник стартует и начинает отдавать данные слушателям, если пользователь запрещает доступ, аудиоисточник отправляет слушателям ошибку с кодом `YSKErrorRecordingPermissions` в методе -[YSKAudioSourceListener audioSource:didFailWithError:]. Коды возможных ошибок перечислены в YSKErrorCode.
 * @warning Этот аудиоисточник использует стандартный вход устройства, для его работы необходимо правильно настроить аудиосессию приложения. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * - если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно.
* Если вы решите настраивать аудиосессию самостоятельно, обратите внимание на настройки, которые могут повлиять на работу аудиоисточника. Они описаны в классе `YSKAudioSessionHandler`. Без соответствующих настроек `YSKManualAudioSource` вернет ошибку с кодом `YSKErrorAudioRecording` в методе -[YSKAudioSourceListener audioSource:didFailWithError:].
 */
@interface YSKManualAudioSource : YSKBaseAudioSource

/**
 * @abstract Начинает запись звука, используя стандартный вход устройства.
 * @discussion Метод выполняется ассинхронно, когда аудиоисточник готов отдавать звук, у слушателей вызвывается метод -[YSKAudioSourceListener audioSourceDidStart:].
 */
- (void)start;

/**
 * @abstract Завершает запись звука.
 * @discussion Метод выполняется ассинхронно, когда аудиоисточник завершит работу со звуком, у слушателей будет вызван метод -[YSKAudioSourceListener audioSourceDidStop:].
 */
- (void)stop;

@end
