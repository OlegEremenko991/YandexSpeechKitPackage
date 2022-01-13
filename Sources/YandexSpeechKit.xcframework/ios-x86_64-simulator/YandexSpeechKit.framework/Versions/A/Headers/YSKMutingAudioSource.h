//
// YSKMutingAudioSource.h
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

/**
 * @abstract Реализация интерфейса `YSKAudioSource`, которая приостанавливает звук, поступающий через аудиоисточник.
 * @discussion Используется для дополнительной обработки звука, который поступает через аудиоисточник. Данная реализация может быть использована в любом классе, который работает с протоколом `YSKAudioSource`.
 * Класс не записывает звук, а лишь применяет к нему дополнительную обработку, поэтому должен использоваться только совместно с другим аудиоисточником.
 */
@interface YSKMutingAudioSource : NSObject<YSKAudioSource>

/**
 * @abstract Инициализирует объект класса `YSKMutingAudioSource`.
 * @discussion Объект класса `YSKMutingAudioSource` самостоятельно не пишет звук с динамика устройства, файла или какого-то другого источника, он лишь применяет некоторый алгоритм к поступающему звуку. Поэтому для его работы необходимо задать аудиоисточник, который запишет звук и передаст его объекту класса `YSKMutingAudioSource`.
 @param audioSource Аудиоисточник, из которого звук поступает на обработку.
 @return Объект класса `YSKMutingAudioSource`.
 */
- (instancetype)initWithAudioSource:(id<YSKAudioSource>)audioSource;

/**
 * @abstract Приостанавливает/запускает поток звука на распознавание.
 * @param shouldMute Признак отправки потока звука на распознавание. Допустимые значения: `YES` — звук, поступающий из аудиоисточника, не будет отправлен на распознавание, `NO` — звук, поступающий из аудиоисточника будет отправлен на распознавание.
 */
- (void)muteAudio:(BOOL)shouldMute;

@end

NS_ASSUME_NONNULL_END

