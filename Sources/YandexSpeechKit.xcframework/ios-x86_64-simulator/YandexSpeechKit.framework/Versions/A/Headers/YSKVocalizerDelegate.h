//
// YSKVocalizerDelegate.h
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

@protocol YSKVocalizing;
@class YSKSynthesis;

/**
 * @abstract Протокол определяет callback-методы делегата, который отслеживает события синтеза и проигрывания речи.
 * @discussion Методы вызываются объектом класса, который реализует протокол `YSKVocalizing`, при изменении его состояния: получение результатов синтеза речи, окончание синтеза речи, возникновение ошибок. Если синтезированная речь воспроизводится через встроенный плеер, то методы вызываются при начале и окончании проигрывания.
 */
@protocol YSKVocalizerDelegate <YSKDispatchableDelegate>

@optional

/**
 * @abstract Вызывается, когда сервер завершил синтез части речи и ее можно проиграть.
 * @discussion Метод вызывается каждый раз при получении нового фрагмента звука.
 * @param vocalizer Ссылка на объект класса `YSKVocalizing`, вызвавший метод.
 * @param synthesis Результаты синтеза речи.
 */
- (void)vocalizer:(id<YSKVocalizing>)vocalizer didReceivePartialSynthesis:(YSKSynthesis *)synthesis;

/**
 * @abstract Вызывается, когда сервер завершил синтез речи.
 * @param vocalizer Ссылка на объект класса `YSKVocalizing`, вызвавший метод.
 */
- (void)vocalizerDidSynthesisDone:(id<YSKVocalizing>)vocalizer;

/**
 * @abstract Вызывается, когда встроенный плеер начинает воспроизводить звук.
 * @param vocalizer Ссылка на объект класса `YSKVocalizing`, вызвавший метод.
 */
- (void)vocalizerDidStartPlaying:(id<YSKVocalizing>)vocalizer;

/**
 * @abstract Вызывается, когда встроенный плеер заканчивает воспроизводить звук.
 * @param vocalizer Ссылка на объект класса `YSKVocalizing`, вызвавший метод.
 */
- (void)vocalizerDidFinishPlaying:(id<YSKVocalizing>)vocalizer;

/**
 * @abstract Вызывается, если в процессе синтеза или проигрывания речи возникли ошибки.
 * @discussion Коды возможных ошибок перечислены в YSKErrorCode.
 * @param vocalizer Ссылка на объект класса `YSKVocalizing`, вызвавший метод.
 * @param error Ошибка, которая возникла в процессе синтеза или воспроизведения речи.
 */
- (void)vocalizer:(id<YSKVocalizing>)vocalizer didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
