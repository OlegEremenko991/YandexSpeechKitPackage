//
// YSKVoice.h
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
 * @abstract Класс задает настройки голоса для синтезируемой речи.
 */
@interface YSKVoice : YSKSetting

/**
 * @abstract Создает объект класса `YSKVoice` с мужским голосом Ermil.
 * @return Объект класса `YSKVoice`, который соответствует выбранному голосу.
 */
+ (instancetype)ermil;

/**
 * @abstract Создает объект класса `YSKVoice` с мужским голосом Zahar.
 * @return Объект класса `YSKVoice`, который соответствует выбранному голосу.
 */
+ (instancetype)zahar;

/**
 * @abstract Создает объект класса `YSKVoice` с женским голосом Jane.
 * @return Объект класса `YSKVoice`, который соответствует выбранному голосу.
 */
+ (instancetype)jane;

/**
 * @abstract Создает объект класса `YSKVoice` с женским голосом Alyss.
 * @return Объект класса `YSKVoice`, который соответствует выбранному голосу.
 */
+ (instancetype)alyss;

/**
 * @abstract Создает объект класса `YSKVoice` с женским голосом Omazh.
 * @return Объект класса `YSKVoice`, который соответствует выбранному голосу.
 */
+ (instancetype)omazh;

/**
 * @abstract Создает объект класса `YSKVoice` с женским голосом Oksana.
 * @return Объект класса `YSKVoice`, который соответствует выбранному голосу.
 */
+ (instancetype)oksana;

@end

NS_ASSUME_NONNULL_END
