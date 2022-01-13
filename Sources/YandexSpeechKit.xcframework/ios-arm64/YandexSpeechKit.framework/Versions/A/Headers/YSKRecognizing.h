//
// YSKRecognizing.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

@protocol YSKRecognizerDelegate;
@protocol YSKAudioSource;

/**
 * @abstract Протокол описывает интерфейс объекта, который распознает речь.
 */
@protocol YSKRecognizing <NSObject>

/**
 * @property delegate
 * @abstract Делегат для извещения о ходе распознавания.
 */
@property (nonatomic, weak, nullable) id<YSKRecognizerDelegate> delegate;

/**
 * @property audioSource
 * @abstract Источник, который передает объекту класса, реализующему протокол `YSKRecognizing`, звук для распознавания.
 * @discussion Если аудиоисточник берет данные из стандарного входа устройства, то для его работы необходимо настроить аудиосессию.
 */
@property (nonatomic, strong, readonly, nonnull) id<YSKAudioSource> audioSource;

/**
 * @abstract Подготавливает объект класса, реализующий протокол `YSKRecognizing`, к распознаванию речи.
 * @discussion Заранее выполняет подготовку к распознаванию речи. Если метод не вызван явно, он автоматически вызывается в методе -[YSKRecognizing startRecording]. Метод выполняется асинхронно.
 * @note Рекомендуется вызывать данный метод до запуска объекта класса, реализующего протокол `YSKRecognizing`.
 */
- (void)prepare;

/**
 * @abstract Запускает процесс распознавания.
 * @discussion Метод может быть вызван многократно для одного и того же объекта класса. Метод выполняется асинхронно, в момент начала записи вызывается callback-метод -[YSKRecognizerDelegate recognizerDidStartRecording:].
 */
- (void)startRecording;

/**
 * @abstract Принудительно завершает запись звука.
 * @discussion Метод не отменяет распознавание, оно продолжается до получения всех результатов. В большинстве случаев вызывать этот метод не требуется, так как детектор голосовой активности (VAD) автоматически определяет момент окончания речи. Однако, метод может быть полезен в случаях, когда VAD выключен или неверно распознает окончание речи.
 */
- (void)stopRecording;

/**
 * @abstract Отменяет запрос на распознавание.
 * @discussion Метод отменяет запрос на распознавание на любой стадии операции. Запись звука прекращается, а сетевое соединение разрывается, если необходимо. Метод отменяет запрос синхронно, после его вызова методы делегата `YSKRecognizerDelegate` больше не вызываются.
 * @discussion Метод выполняется синхронно.
 */
- (void)cancel;

@end
