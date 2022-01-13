//
// YSKRecognitionHypothesis.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKRecognitionWord;

/**
 * @abstract Объект, представляющий одну гипотезу распознавания.
 * @discussion Каждая гипотеза имеет оценку достоверности — это дробное число в диапазоне от 0 до 1, которое определеяет меру достоверности результата распознавания (1 — наибольшая степень уверенности).
 
 * Гипотеза имеет два представления:
 * - Строка, которая содержит текст гипотезы. Это представление можно считать основным. Числа в таком тексте записаны цифрами, присутствуют знаки препинания, аббревиатуры.
 * - Массив слов или словосочетаний, для каждого из которых указана оценка его достоверности. На основе этой оценки можно определить плохо распознанные фрагменты.
 
 * @warning Оценка достоверности предоставляется только для информации. Со временем формула ее расчета может корректироваться.
 */
@interface YSKRecognitionHypothesis : NSObject<NSCopying>

/**
 * @property confidence
 * @abstract Оценка достоверности гипотезы распознавания.
 * @discussion Оценка достоверности — это дробное число в диапазоне от 0 до 1, которое определеяет меру достоверности результата распознавания (1 — наибольшая степень уверенности).
 */
@property (nonatomic, assign, readonly) CGFloat confidence;

/**
 * @property normalized
 * @abstract Строка, которая содержит текст гипотезы.
 * @discussion Это представление можно считать основным. Числа в таком тексте записаны цифрами, присутствуют знаки препинания, аббревиатуры.
 */
@property (nonatomic, copy, readonly) NSString *normalized;

/**
 * @property words
 * @abstract Массив слов или словосочетаний, для каждого из которых указана оценка его достоверности.
 * @discussion На основе этой оценки можно определить плохо распознанные фрагменты.
 */
@property (nonatomic, copy, readonly) NSArray<YSKRecognitionWord *> *words;

/**
 * @abstract Инициализирует объект класса `YSKRecognitionHypothesis`.
 * @discussion Этот метод является `designated initializer` для класса `YSKRecognitionHypothesis`.
 * @param words Массив слов или словосочетаний, для каждого из которых указана оценка его достоверности.
 * @param normalized Строка, которая содержит текст гипотезы.
 * @param confidence Оценка достоверности гипотезы распознавания.
 * @return Объект класса `YSKRecognitionHypothesis`.
 */
- (instancetype)initWithWords:(NSArray<YSKRecognitionWord *> *)words normalizedText:(NSString *)normalized confidence:(CGFloat)confidence NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithWords:normalizedText:confidence: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithWords:normalizedText:confidence: instead.")));

@end

NS_ASSUME_NONNULL_END
