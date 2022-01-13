//
// YSKRecognitionWord.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Kirichenko Vladimir <vvkiri@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Слово или словосочетание, которое является элементом гипотезы `YSKRecognitionHypothesis`.
 * @discussion Минимальный объект, для которого указывается оценка достоверности. На основе этой оценки можно определить плохо распознанные фрагменты.
 */
@interface YSKRecognitionWord: NSObject<NSCopying>

/**
 * @property text
 * @abstract Слово или словосочетание.
 */
@property (nonatomic, copy, readonly) NSString *text;

/**
 * @property confidence
 * @abstract Оценка достоверности распознавания.
 * @discussion Оценка достоверности — это дробное число в диапазоне от 0 до 1, которое определеяет меру достоверности результата распознавания (1 — наибольшая степень уверенности).
 */
@property (nonatomic, assign, readonly) CGFloat confidence;

/**
 * @abstract Инициализирует объект класса `YSKRecognitionWord`.
 * @discussion Этот метод является `designated initializer` для класса `YSKRecognitionWord`.
 * @param text Слово или словосочетание.
 * @param confidence Оценка достоверности распознавания.
 * @return Объект класса `YSKRecognitionWord`.
 */
- (instancetype)initWithText:(NSString *)text confidence:(CGFloat)confidence NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithText:confidence: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithText:confidence: instead.")));

@end

NS_ASSUME_NONNULL_END

