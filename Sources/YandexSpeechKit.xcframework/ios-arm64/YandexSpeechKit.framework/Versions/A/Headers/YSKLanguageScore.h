//
// YSKLanguageScore.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Karimova <akarimova@yandex-team.ru>
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Содержит код языка и оценку того, что пользователь говорил на этом языке.
 * @discussion Для получения массива объектов `YSKLanguageScore` используйте -[YSKBiometry languageScores].
 */
@interface YSKLanguageScore : NSObject<NSCopying>

/**
 * @property language
 * @abstract Код языка.
 */
@property (nonatomic, copy, readonly) NSString *language;

/**
 * @property score
 * @abstract Оценка того, что пользователь говорил на указанном языке.
 */
@property (nonatomic, assign, readonly) CGFloat score;

+ (instancetype)new __attribute__((unavailable("Readonly class, it should be initialized only inside SpeechKit Framework.")));
- (instancetype)init __attribute__((unavailable("Readonly class, it should be initialized only inside SpeechKit Framework.")));

@end

NS_ASSUME_NONNULL_END

