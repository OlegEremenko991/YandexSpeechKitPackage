//
// YSKSoundQuality.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Aleksey Sikorsky <alsikorskii@yandex-team.ru>
//

#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Качество синтезируемого звука.
 * @discussion Качество синтезируемого звука влияет на размер присылаемого буфера данных.
 */

@interface YSKSoundQuality : YSKSetting

/**
 * @abstract Низкое качество синтезируемого звука. По умолчанию для него используется 8 кГц.
 * @return Объект класса `YSKSoundQuality`, который соответствует выбранному качеству звука.
 */
+ (instancetype)low;

/**
 * @abstract Среднее качество синтезируемого звука. По умолчанию для него используется 16 кГц.
 * @return Объект класса `YSKSoundQuality`, который соответствует выбранному качеству звука.
 */
+ (instancetype)high;

/**
 * @abstract Высокое качество синтезируемого звука. По умолчанию для него используется 48 кГц.
 * @return Объект класса `YSKSoundQuality`, который соответствует выбранному качеству звука.
 */
+ (instancetype)ultrahigh;

@end

NS_ASSUME_NONNULL_END
