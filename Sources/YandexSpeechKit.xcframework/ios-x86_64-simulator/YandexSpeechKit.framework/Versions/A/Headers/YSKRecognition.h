//
// YSKRecognition.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKRecognitionHypothesis;
@class YSKBiometry;

/**
 * @abstract Результат распознавания, возвращаемый при распознавании речи.
 * @discussion Результат распознавания содержит список лучших гипотез распознавания с оценками их достоверности (так называемый n-best список). Список гипотез отсортирован по убыванию, наиболее вероятный результат распознавания идет первым. Чтобы получить список гипотез, используйте свойство -[YSKRecognition hypotheses].
 */
@interface YSKRecognition : NSObject

/**
 * @property hypotheses
 * @abstract Список гипотез, отсортированный по убыванию оценки достоверности.
 */
@property (nonatomic, copy, readonly) NSArray<YSKRecognitionHypothesis *> *hypotheses;

/**
 * @property bestResultText
 * @abstract Текст лучшей гипотезы.
 */
@property (nonatomic, copy, readonly) NSString *bestResultText;

/**
 * @property biometry
 * @abstract Оценочные биометрические характеристики пользователя, такие как возраст, пол, принадлежность к той или иной возрастной группе.
 * @discussion Объект `YSKBiometry` возвращается не равным `nil` в методе -[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:] если выполнены следующие условия:
 * - значение параметра `endOfUtterance` = `YES` (метод -[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:]);
 * - значение свойства `requestBiometry` = `YES` (класс `YSKOnlineRecognizerSettings`).
 */
@property (nonatomic, copy, readonly, nullable) YSKBiometry *biometry;

/**
 * @property requestId
 * @abstract Идентификатор запроса.
 */
@property (nonatomic, copy, readonly, nullable) NSString *requestId;

/**
 * @abstract Инициализирует объект класса `YSKRecognition` с заданным списком гипотез.
 * @discussion Этот метод является `designated initializer` для класса `YSKRecognition`.
 * @param hypotheses Список гипотез, отсортированный по убыванию оценки достоверности.
 * @return Объект класса `YSKRecognition`.
 */
- (instancetype)initWithHypotheses:(NSArray<YSKRecognitionHypothesis *> *)hypotheses NS_DESIGNATED_INITIALIZER;

/**
 * @abstract Инициализирует объект класса `YSKRecognition` с заданным списком гипотез и оценочными биометрическими характеристиками.
 * @param hypotheses Список гипотез, отсортированный по убыванию оценки достоверности.
 * @param biometry Оценочные биометрические характеристики пользователя.
 * @return Объект класса `YSKRecognition`.
 */
- (instancetype)initWithHypotheses:(NSArray<YSKRecognitionHypothesis *> *)hypotheses biometry:(nullable YSKBiometry *)biometry;

/**
 * @abstract Инициализирует объект класса `YSKRecognition` с заданным списком гипотез, оценочными биометрическими характеристиками и идентификатором запроса.
 * @param hypotheses Список гипотез, отсортированный по убыванию оценки достоверности.
 * @param requestId Идентификатор запроса.
 * @param biometry Биометрические характеристики пользователя.
 * @return Объект класса `YSKRecognition`.
 */
- (instancetype)initWithHypotheses:(NSArray<YSKRecognitionHypothesis *> *)hypotheses requestId:(NSString *)requestId biometry:(nullable YSKBiometry *)biometry;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithHypotheses: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithHypotheses: instead.")));

@end

NS_ASSUME_NONNULL_END
