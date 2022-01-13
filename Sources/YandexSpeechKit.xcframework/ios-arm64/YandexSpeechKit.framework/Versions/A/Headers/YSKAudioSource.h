//
// YSKAudioSource.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKSoundInfo;
@class YSKAudioProcessingMode;
@protocol YSKAudioSourceListener;

/**
 * @abstract Протокол для аудиоисточника.
 * @discussion Используется классами, которые распознают речь: `YSKRecognizing` и `YSKPhraseSpotter`. Аудиоисточник может использовать любой источник звука: стандартный вход устройства, удаленный источник и т.д.
 
 * Работа с любым аудиоисточником происходит по следующей схеме:

 * - Создание и запуск объекта, который отдает звуковые данные. Когда аудиоисточник готов передавать данные слушателям, он должен отправить сообщение каждому подписанному слушателю с помощью метода -[YSKAudioSourceListener audioSourceDidStart:].
 * Если  во время работы аудиоисточника подписывается новый слушатель, он также получает сообщение сразу после подписки (с помощью метода -[YSKAudioSourceListener audioSourceDidStart:]).

 * - Передача слушателям данных, фрагментами с некоторым интервалом. Данные передаются с помощью метода -[YSKAudioSourceListener audioSource:didReceiveData:]. Интервал задается через значение свойства -[YSKAudioSource bufferCaptureTimeout]. Эти значения слушатели могут запросить еще до подписки на аудиоисточник.
 
 * - По окончании работы аудиоисточника необходимо сообщить об этом слушателям с помощью метода -[YSKAudioSourceListener audioSourceDidStop:]. На момент окончания работы аудиоисточника количество слушателей может уменьшиться, потому что они могут отписаться в процессе работы. Например, `YSKOnlineRecognizer` отписывается при обнаружении окончания речи.
 
 * Если аудиоисточник использует стандартный вход устройства, необходимо правильно настроить аудиосессию приложения. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * — если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно. В вашем собственном классе, который реализует протокол `YSKAudioSource`, надо запросить у пользователя доступ к записи звука. Для этого необходимо вызвать метод системного класса -[AVAudioSession requestRecordPermission:].
 
 * Для работы `YSKBaseAudioSource` и его наследников `YSKAutoAudioSource` и `YSKManualAudioSource` необходимо настроить аудиосессию. Без соответствующих настроек они вернут ошибку с кодом `YSKErrorAudioRecording` в методе -[YSKAudioSourceListener audioSource:didFailWithError:]. Коды возможных ошибок перечислены в YSKErrorCode.
 */
@protocol YSKAudioSource <NSObject>

/**
 * @property soundInfo
 * @abstract Информация о звуке, который будет передаваться этим аудиоисточником.
 */
@property (nonatomic, strong, readonly) YSKSoundInfo *soundInfo;

/**
 * @property bufferCaptureTimeout
 * @abstract Интервал между фрагментами звука, которые аудиоисточник отправляет слушателям.
 */
@property (nonatomic, assign, readonly) NSTimeInterval bufferCaptureTimeout;

/**
 * @abstract Метод подписывает слушателя, который реализует протокол `YSKAudioSourceListener`.
 * @param listener Слушатель, который будет получать сообщения о статусе аудиоисточника и звуковые данные.
 */
- (void)subscribeListener:(id<YSKAudioSourceListener>)listener;

/**
 * @abstract Метод отписывает слушателя, который реализует протокол `YSKAudioSourceListener`.
 * @param listener Слушатель, который будет получать сообщения о статусе аудиоисточника и звуковые данные.
 */
- (void)unsubscribeListener:(id<YSKAudioSourceListener>)listener;

@optional
/**
 * @property audioProcessingMode
 * @abstract Информация о том, осуществляет ли аудиоисточник дополнительную обработку аудио.
 * @discussion Если аудиоисточник перобразует поступающий аудиосигнал одним из следующих способов: применяет алгоритм AEC или пропускает часть звуков, то он должен передать соответствующее значение. В остальных случаях свойство можно не задавать.
 * Значение по умолчанию: -[YSKAudioProcessingMode pass].
 */
@property (nonatomic, copy, readonly) YSKAudioProcessingMode *audioProcessingMode;

@end

NS_ASSUME_NONNULL_END
