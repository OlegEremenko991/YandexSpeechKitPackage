//
// YSKAudioSessionSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class YSKOtherAudioPolicy;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Задает настройки класса `YSKAudioSessionHandler`.
 */
@interface YSKAudioSessionSettings : NSObject<NSCopying>

/**
 * @property otherAudioPolicy
 * @abstract Настройка указывает поведение компоненты, если аудиопоток занят другим приложением.
 */
@property (nonatomic, copy, nonnull) YSKOtherAudioPolicy *otherAudioPolicy;

@end
