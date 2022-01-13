//
// YSKEmotion.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Доступные эмоции синтезируемого голоса.
 */
@interface YSKEmotion : YSKSetting

/**
 * @abstract Создает объект класса `YSKEmotion` с позитивной эмоцией.
 * @return Объект класса `YSKEmotion`, который соответствует выбранной эмоции.
 */
+ (instancetype)good;

/**
 * @abstract Создает объект класса `YSKEmotion` с негативной эмоцией.
 * @return Объект класса `YSKEmotion`, который соответствует выбранной эмоции.
 */
+ (instancetype)evil;

/**
 * @abstract Создает объект класса `YSKEmotion` с нейтральной эмоцией.
 * @return Объект класса `YSKEmotion`, который соответствует выбранной эмоции.
 */
+ (instancetype)neutral;

@end

NS_ASSUME_NONNULL_END
