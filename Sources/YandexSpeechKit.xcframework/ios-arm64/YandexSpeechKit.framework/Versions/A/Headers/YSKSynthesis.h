//
// YSKSynthesis.h
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

/**
 * @abstract Класс содержит результат синтеза речи.
 */
@interface YSKSynthesis : NSObject

/**
 * @property soundBuffer
 * @abstract Буфер, который содержит синтезированную речь.
 */
@property (nonatomic, strong, readonly) YSKSoundBuffer *soundBuffer;

/**
 * @abstract Инициализирует объект класса `YSKSynthesis`.
 * @discussion  Этот метод является `designated initializer` для класса `YSKSynthesis`.
 * @param soundBuffer Буфер, который содержит синтезированную речь.
 * @return Объект класса `YSKSynthesis`.
 */
- (instancetype)initWithSoundBuffer:(YSKSoundBuffer *)soundBuffer NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithSoundBuffer: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithSoundBuffer: instead.")));

@end

NS_ASSUME_NONNULL_END
