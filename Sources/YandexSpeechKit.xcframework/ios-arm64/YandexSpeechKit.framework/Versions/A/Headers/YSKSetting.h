//
// YSKSetting.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Абстрактный класс настроек компонентов библиотеки.
 * @discussion Наследники класса используются для хранения различных настроек. В библиотеке этот класс не используется явно, но его можно создавать для своих целей.
 */
@interface YSKSetting : NSObject<NSCopying>

/**
 * @property value
 * @abstract Строковое значение настройки.
 */
@property (nonatomic, copy, readonly) NSString *value;

/**
 * @abstract Инициализирует объект класса `YSKSetting`.
 * @discussion Этот метод является `designated initializer` для класса `YSKSetting`.
 * @param value Строковое значение настройки.
 * @return Объект класса `YSKSetting`.
 */
- (instancetype)initWithValue:(NSString *)value NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithValue: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithValue: instead.")));

/**
 * @abstract Проверяет на равенство два объекта класса `YSKSetting`.
 * @param object Объект класса `YSKSetting`.
 * @return Значение `YES`, если текущий и переданный объект равны, `NO` — в другом случае.
 */
- (BOOL)isEqualToSetting:(YSKSetting *)object;

@end

NS_ASSUME_NONNULL_END
