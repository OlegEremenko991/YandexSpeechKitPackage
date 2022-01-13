//
// YSKBiometry.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Karimova <akarimova@yandex-team.ru>
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKLanguageScore;

/**
 * @abstract Оценочные характериситики пола и возрастной группы.
 */
@interface YSKBiometryGroup : NSObject<NSCopying>

/**
 * @property childScore
 * @abstract Оценка того, что пользователь — ребенок в возрасте до 14 лет.
 */
@property (nonatomic, assign, readonly) CGFloat childScore;

/**
 * @property youngMaleScore
 * @abstract Оценка того, что пользователь — юноша в возрасте 14-20 лет.
 */
@property (nonatomic, assign, readonly) CGFloat youngMaleScore;

/**
 * @property youngFemaleScore
 * @abstract Оценка того, что пользователь — девушка в возрасте 14-20 лет.
 */
@property (nonatomic, assign, readonly) CGFloat youngFemaleScore;

/**
 * @property adultMaleScore
 * @abstract Оценка того, что пользователь — мужчина в возрасте 20-55 лет.
 */
@property (nonatomic, assign, readonly) CGFloat adultMaleScore;

/**
 * @property adultFemaleScore
 * @abstract Оценка того, что пользователь — женщина в возрасте 20-55 лет.
 */
@property (nonatomic, assign, readonly) CGFloat adultFemaleScore;

/**
 * @property seniorMaleScore
 * @abstract Оценка того, что пользователь — мужчина старше 55 лет.
 */
@property (nonatomic, assign, readonly) CGFloat seniorMaleScore;

/**
 * @property seniorFemaleScore
 * @abstract Оценка того, что пользователь — женщина старше 55 лет.
 */
@property (nonatomic, assign, readonly) CGFloat seniorFemaleScore;


@end

/**
 * @abstract Оценочные характеристики того, что пользователь испытывает одну из следующих эмоций: радость, досаду, гнев, спокойствие или удовольствие.
 */
@interface YSKBiometryEmotion : NSObject<NSCopying>

/**
 * @property angerScore
 * @abstract Оценка того, что текущая эмоция — гнев.
 */
@property (nonatomic, assign, readonly) CGFloat angerScore;

/**
 * @property dissappScore
 * @abstract Оценка того, что текущая эмоция — досада.
 */
@property (nonatomic, assign, readonly) CGFloat dissappScore;

/**
 * @property joyScore
 * @abstract Оценка того, что текущая эмоция — радость.
 */
@property (nonatomic, assign, readonly) CGFloat joyScore;

/**
 * @property neutralScore
 * @abstract Оценка того, что текущая эмоция — спокойствие.
 */
@property (nonatomic, assign, readonly) CGFloat neutralScore;

/**
 * @property pleasureScore
 * @abstract Оценка того, что текущая эмоция — удовольствие.
 */
@property (nonatomic, assign, readonly) CGFloat pleasureScore;

@end

/**
 * @abstract Оценочные биометрические характеристики пользователя (возраст, пол, принадлежность к той или иной возрастной группе и другие характеристики), которые возвращает объект класса, реализующий протокол `YSKRecognition`, при распознавании речи.
 */
@interface YSKBiometry : NSObject<NSCopying>

/**
 * @property age
 * @abstract Предполагаемый возраст пользователя.
 */
@property (nonatomic, assign, readonly) CGFloat age;

/**
 * @property maleScore
 * @abstract Оценка того, что пользователь — мужчина.
 */
@property (nonatomic, assign, readonly) CGFloat maleScore;

/**
 * @property femaleScore
 * @abstract Оценка того, что пользователь — женщина.
 */
@property (nonatomic, assign, readonly) CGFloat femaleScore;

/**
 * @property childScore
 * @abstract Оценка того, что пользователь — ребенок.
 */
@property (nonatomic, assign, readonly) CGFloat childScore;

/**
 * @property adultScore
 * @abstract Оценка того, что пользователь — взрослый.
 */
@property (nonatomic, assign, readonly) CGFloat adultScore;

/**
 * @property group
 * @abstract Объект, который содержит оценки пола и возрастной группы.
 */
@property (nonatomic, copy, readonly) YSKBiometryGroup *group;

/**
 * @property emotion
 * @abstract Объект, содержащий оценки того, что пользователь испытывает одну из следующих эмоций: радость, досаду, гнев, спокойствие или печаль.
 */
@property (nonatomic, copy, readonly) YSKBiometryEmotion *emotion;


/**
 * @property languageScores
 * @abstract Массив, каждый элемент которого `YSKLanguageScore` — язык и оценка того, что пользователь говорил именно на этом языке.
 */
@property (nonatomic, copy, readonly) NSArray<YSKLanguageScore *> *languageScores;

+ (instancetype)new __attribute__((unavailable("Readonly class, it could be initialized only inside SpeechKit Framework.")));
- (instancetype)init __attribute__((unavailable("Readonly class, it could be initialized only inside SpeechKit Framework.")));

@end

NS_ASSUME_NONNULL_END
