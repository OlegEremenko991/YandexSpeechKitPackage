//
// YSKPhraseSpotterDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Alexander Panin <agpanin@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKDispatchableDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKPhraseSpotter;

/**
 * @abstract Протокол определяет callback-методы делегата, который отслеживает процесс голосовой активации.
 */
@protocol YSKPhraseSpotterDelegate<YSKDispatchableDelegate>

@optional

/**
 * @abstract Вызывается в момент начала записи звука.
 * @param phraseSpotter Ссылка на объект класса `YSKPhraseSpotter`, вызвавший метод.
 */
- (void)phraseSpotterDidStarted:(YSKPhraseSpotter *)phraseSpotter;

/**
 * @abstract Вызывается при обнаружении в аудиопотоке фразы, которая содержится в подключенной модели голосовой активации (активационной команды).
 * @param phraseSpotter Ссылка на объект класса `YSKPhraseSpotter`, вызвавший метод.
 * @param phrase Распознанная фраза.
 * @param phraseIndex Индекс (номер) активационной команды.
 */
- (void)phraseSpotter:(YSKPhraseSpotter *)phraseSpotter didSpotPhrase:(NSString *)phrase withIndex:(NSInteger)phraseIndex;

/**
 * @abstract Вызывается при возникновении ошибки во время процесса голосовой активации.
 * @param phraseSpotter Ссылка на объект класса `YSKPhraseSpotter`, вызвавший метод.
 * @param error Ошибка, возникшая в процессе работы.
 */
- (void)phraseSpotter:(YSKPhraseSpotter *)phraseSpotter didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
