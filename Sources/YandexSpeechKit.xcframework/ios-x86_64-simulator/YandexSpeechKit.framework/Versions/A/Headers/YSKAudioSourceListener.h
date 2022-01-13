//
// YSKAudioSourceListener.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKSoundBuffer;
@protocol YSKAudioSource;

/**
 * @abstract Протокол слушателя аудиоисточника.
 * @discussion Этот протокол должен быть реализован классом, который хочет получать данные от аудиоисточника. Чтобы подключить слушателя к аудиоисточнику, используйте метод -[YSKAudioSource subscribeListener:], чтобы отключить слушателя — метод -[YSKAudioSource unsubscribeListener:].
 */
@protocol YSKAudioSourceListener <NSObject>

/**
 * @abstract Вызывается, когда аудиоисточник готов передавать данные.
 * @param audioSource Ссылка на объект класса `YSKAudioSource`, вызвавший метод.
 */
- (void)audioSourceDidStart:(id<YSKAudioSource>)audioSource;

/**
 * @abstract Вызывается, когда аудиоисточник закончил передавать данные.
 * @param audioSource Ссылка на объект класса `YSKAudioSource`, вызвавший метод.
 */
- (void)audioSourceDidStop:(id<YSKAudioSource>)audioSource;

/**
 * @abstract Вызывается при передаче данных.
 * @discussion Этот метод может вызываться несколько раз в зависимости от объема данных, которые передает аудиоисточник, с интервалами, равными величине -[YSKAudioSource bufferCaptureTimeout].
 * @param audioSource Ссылка на объект класса `YSKAudioSource`, вызвавший метод.
 * @param soundBuffer Буфер с данными.
 */
- (void)audioSource:(id<YSKAudioSource>)audioSource didReceiveData:(YSKSoundBuffer *)soundBuffer;

/**
 * @abstract Вызывается, если в процессе работы аудиоисточника возникли ошибки.
 * @discussion Коды возможных ошибок перечислены в YSKErrorCode.
 * @param audioSource Ссылка на объект класса `YSKAudioSource`, вызвавший метод.
 * @param error Ошибка, которая возникла в процессе работы аудиоисточника.
 */
- (void)audioSource:(id<YSKAudioSource>)audioSource didFailWithError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
