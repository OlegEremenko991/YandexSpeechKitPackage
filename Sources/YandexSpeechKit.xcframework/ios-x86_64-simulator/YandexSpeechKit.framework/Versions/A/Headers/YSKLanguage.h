//
// YSKLanguage.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Доступные языки распознавания.
 */
@interface YSKLanguage : YSKSetting

/**
* @abstract Создает объект класса `YSKLanguage`, который соответствует русскому языку.
* @return Объект класса `YSKLanguage`, который соответствует выбранному языку.
*/
+ (instancetype)russian;

/**
 * @abstract Создает объект класса `YSKLanguage`, который соответствует английскому языку.
 * @return Объект класса `YSKLanguage`, который соответствует выбранному языку.
 */
+ (instancetype)english;

/**
 * @abstract Создает объект класса `YSKLanguage`, который соответствует турецкому языку.
 * @return Объект класса `YSKLanguage`, который соответствует выбранному языку.
 */
+ (instancetype)turkish;

/**
 * @abstract Создает объект класса `YSKLanguage`, который соответствует украинскому языку.
 * @return Объект класса `YSKLanguage`, который соответствует выбранному языку.
 */
+ (instancetype)ukrainian;

@end

NS_ASSUME_NONNULL_END

