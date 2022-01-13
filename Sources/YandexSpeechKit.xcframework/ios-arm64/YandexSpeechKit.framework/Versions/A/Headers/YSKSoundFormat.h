//
// YSKSoundFormat.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Форматы синтезируемого звука.
 * @discussion Текущая версия библиотеки поддерживает несжатый PCM и Opus.
 */
@interface YSKSoundFormat : YSKSetting

/**
 * @abstract Устанавливает формат PCM.
 * @return Объект класса `YSKSoundFormat`, который соответствует выбранному формату звука.
 */
+ (instancetype)pcm;

/**
 * @abstract Устанавливает формат Opus.
 * @return Объект класса `YSKSoundFormat`, который соответствует выбранному формату звука.
 */
+ (instancetype)opus;

@end

NS_ASSUME_NONNULL_END
