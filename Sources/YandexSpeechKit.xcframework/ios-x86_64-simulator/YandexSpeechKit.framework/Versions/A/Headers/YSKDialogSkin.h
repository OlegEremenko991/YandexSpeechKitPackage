//
// YSKDialogSkin.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Протокол определяет методы для настройки внешнего вида диалога `YSKRecognizerDialogController`.
 * @discussion Две основные реализации этого протокола задают цвет темы диалога:
 * - `YSKLightDialogSkin` — светлая тема диалога;
 * - `YSKDarkDialogSkin` — темная тема диалога.
 * @discussion Чтобы задать эту настройку, используйте свойство -[YSKRecognizerDialogController skin].
 */
@protocol YSKDialogSkin <NSObject>

/**
 * @property backgroundColor
 * @abstract Основной цвет подложки диалога.
 */
@property (nonatomic, strong, readonly) UIColor *backgroundColor;

/**
 * @property primaryTextColor
 * @abstract Основной цвет текста, который используется для отображения результатов распознавания.
 */
@property (nonatomic, strong, readonly) UIColor *primaryTextColor;

/**
 * @property secondaryTextColor;
 * @abstract Дополнительный цвет текста, который используется для UI-элементов.
 */
@property (nonatomic, strong, readonly) UIColor *secondaryTextColor;

/**
 * @property errorTextColor
 * @abstract Цвет текста об ошибке.
 */
@property (nonatomic, strong, readonly) UIColor *errorTextColor;

/**
 * @property powerBackgroundColor
 * @abstract Цвет подложки полукруга, который показывает изменение уровня сигнала речи.
 */
@property (nonatomic, strong, readonly) UIColor *powerBackgroundColor;

@end

NS_ASSUME_NONNULL_END
