//
// YSKEchoCancellingAudioSource.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKAudioSource.h"

@class YSKSoundBuffer;

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Реализация протокола `YSKAudioSource`, которая применяет к поступающему звуку алгоритм "acoustic echo cancellation" (далее — aec).
 * @discussion Для применения алгоритма нужно задать farend-буфер: данные, которые будут вычтены из поступающего через аудиоисточник звука.  Данная реализация может быть использована в любом классе, который работает с протоколом `YSKAudioSource`. Класс не записывает звук, а лишь применяет к нему дополнительную обработку, поэтому должен использоваться только совместно с другим аудиоисточником.
 */
@interface YSKEchoCancellingAudioSource : NSObject<YSKAudioSource>

/**
 * @property outputLatency
 * @abstract Величина задержки между началом проигрывания звука и его реальным попаданием в динамик устройства.
 * @discussion Эта величина зависит от устройства и сильно влияет на качество aec. В iOS это значение можно получить из свойства системного класса - [AVAudioSession outputLatency] или задать самостоятельно.
 */
@property (nonatomic, assign) NSTimeInterval outputLatency;

/**
 * @abstract Инициализирует объект класса `YSKEchoCancellingAudioSource`.
 * @discussion Объект класса `YSKEchoCancellingAudioSource` самостоятельно не пишет звук с динамика устройства, файла или какого-то другого источника, он лишь применяет алгоритм aec к поступающему звуку. Поэтому для его работы необходимо задать аудиоисточник, который запишет звук и передаст его объекту класса `YSKEchoCancellingAudioSource`. Параметр `outputLatency` можно получить из свойства системного класса -[AVAudioSession outputLatency] или задать самостоятельно.
 * @param audioSource Аудиоисточник, из которого звук поступает на обработку.
 * @param outputLatency Величина задержки между началом проигрывания звука и его реальным попаданием в динамик устройства.
 * @return Объект класса `YSKEchoCancellingAudioSource`.
 */
- (instancetype)initWithAudioSource:(id<YSKAudioSource>)audioSource outputLatency:(NSTimeInterval)outputLatency;

/**
 * @abstract Останавливает алгоритм aec.
 * @discussion Если этот метод не будет вызван, то алгоритм будет применяться даже при пустом farend-буфере. Это может сказаться на времени обработки звука.
 */
- (void)finishEchoCancelling;

/**
 * @abstract Устанавливает farend-буфер для aec.
 * @discussion Установка farend-буфера требуется для удаления из результата распознавания некоторого звука.
 * @param soundBuffer Farend-буфер, который будет использоваться в алгоритме aec.
 */
- (void)appendCancellationBuffer:(YSKSoundBuffer *)soundBuffer;

@end

NS_ASSUME_NONNULL_END
