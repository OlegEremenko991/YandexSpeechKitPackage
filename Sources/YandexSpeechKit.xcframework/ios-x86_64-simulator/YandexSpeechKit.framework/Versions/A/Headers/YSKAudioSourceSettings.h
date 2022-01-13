//
// YSKAudioSourceSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Задает настройки класса `YSKBaseAudioSource` или его наследников.
 */
@interface YSKAudioSourceSettings : NSObject<NSCopying>

/**
 * @property sampleRate
 * @abstract Частота дискретизации звука.
 * @discussion Значение по умолчанию: 16000 Гц.
 */
@property (nonatomic, assign) UInt32 sampleRate;
@end
