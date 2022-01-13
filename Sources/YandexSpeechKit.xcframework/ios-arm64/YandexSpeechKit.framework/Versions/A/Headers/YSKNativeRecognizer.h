//
// YSKNativeRecognizer.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKRecognizing.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKNativeRecognizerSettings;

/**
 * @abstract Класс для платформенного распознавания речи.
 * @discussion Данный класс использует распознавание с помощью iOS-фреймворка `Speech.framework`. Рекомендуется использовать этот класс, если вам необходимо распознавание языков, которые пока не поддерживаются бибилиотекой Yandex SpeechKit.
 */

API_AVAILABLE(ios(10.0))
@interface YSKNativeRecognizer : NSObject<YSKRecognizing>

/**
 * @property settings
 * @abstract Настройки платформенного распознавания речи.
 */
@property (nonatomic, copy, readonly) YSKNativeRecognizerSettings *settings;

/**
 * @abstract Инициализирует объект класса `YSKNativeRecognizer`.
 * @param settings Настройки платформенного распознавания речи.
 * @return Объект класса `YSKNativeRecognizer`.
 */
- (instancetype)initWithSettings:(YSKNativeRecognizerSettings *)settings;

+ (instancetype) new __attribute__((unavailable("Use designated initializer -initWithSettings: instead.")));
- (instancetype) init __attribute__((unavailable("Use designated initializer -initWithSettings: instead.")));

@end

NS_ASSUME_NONNULL_END
