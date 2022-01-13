//
// YSKSoundBuffer.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

#import "YSKSoundFormat.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKSoundInfo;

/**
 * @abstract Класс содержит буфер с данными и информацию о звуке.
 */
@interface YSKSoundBuffer : NSObject<NSCopying>

/**
 * @property data
 * @abstract Буфер с данными.
 */
@property (nonatomic, strong, readonly) NSData *data;

/**
 * @property soundInfo
 * @abstract Информация о звуке.
 */
@property (nonatomic, strong, readonly) YSKSoundInfo *soundInfo;

/**
 * @abstract Инициализирует объект класса `YSKSoundBuffer`.
 * @discussion Этот метод является `designated initializer` для класса `YSKSoundBuffer`.
 * @param data Буфер с данными.
 * @param soundInfo Информация о звуке.
 * @return Объект класса `YSKSoundBuffer`.
 */
- (instancetype)initWithData:(NSData *)data soundInfo:(YSKSoundInfo *)soundInfo NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithData:soundInfo: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithData:soundInfo: instead.")));

@end

/**
 * @abstract Информация о звуке.
 * @discussion Эти данные могут понадобиться при работе со звуком, например, для записи в аудиофайл или при воспроизведении звука различными плеерами.
 */
@interface YSKSoundInfo : NSObject<NSCopying>

/**
 * @property soundFormat
 * @abstract Формат звука.
 */
@property (nonatomic, strong, readonly) YSKSoundFormat* soundFormat;

/**
 * @property channelCount
 * @abstract Количество каналов.
 */
@property (nonatomic, assign, readonly) UInt32 channelCount;

/**
 * @property sampleRate
 * @abstract Частота дискретизации звука.
 */
@property (nonatomic, assign, readonly) UInt32 sampleRate;

/**
 * @property sampleSize
 * @abstract Разрядность квантования, 1 или 2 байта.
 */
@property (nonatomic, assign, readonly) UInt32 sampleSize;

/**
 * @abstract Инициализирует объект класса `YSKSoundInfo`.
 * @discussion  Этот метод является `designated initializer` для класса `YSKSoundInfo`.
 * @param soundFormat Формат звука.
 * @param channelCount Количество каналов.
 * @param sampleRate Частота дискретизации звука.
 * @param sampleSize Разрядность квантования, 1 или 2 байта.
 * @return Объект класса `YSKSoundInfo`.
 */
- (instancetype)initWithFormat:(YSKSoundFormat*)soundFormat channelCount:(UInt32)channelCount sampleRate:(UInt32)sampleRate sampleSize:(UInt32)sampleSize NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithFormat:channelCount:sampleRate:sampleSize: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithFormat:channelCount:sampleRate:sampleSize: instead.")));

@end

@interface YSKSoundBuffer(AudioFile)

+ (nullable instancetype)pcmSoundBufferWithWavFile:(NSString *)audioFilePath NS_SWIFT_NAME(wav(path:));
+ (nullable instancetype)pcmSoundBufferWithOpusFile:(NSString *)audioFilePath NS_SWIFT_NAME(opus(path:));

@end

NS_ASSUME_NONNULL_END
