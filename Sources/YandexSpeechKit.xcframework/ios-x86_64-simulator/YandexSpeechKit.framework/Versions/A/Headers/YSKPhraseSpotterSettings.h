//
// YSKPhraseSpotterSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKOtherAudioPolicy;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Класс задает настройки для объекта класса `YSKPhraseSpotter`.
 * @discussion Обязательной настройкой объекта класса `YSKPhraseSpotter` является путь к модели.
 */
@interface YSKPhraseSpotterSettings : NSObject<NSCopying>

/**
 * @property modelPath
 * @abstract Путь к модели для объекта класса `YSKPhraseSpotter`.
 */
@property (nonatomic, copy, readonly) NSString *modelPath;

/**
 * @property enableLogging
 * @abstract Логирование звука.
 * @discussion Допустимые значения: `YES` — включить логирование звука, `NO` — выключить логирование звука.
 * Значение по умолчанию: `NO`.
 */
@property (nonatomic, assign) BOOL enableLogging;

/**
 * @abstract Инициализирует объект класса `YSKPhraseSpotterSettings`.
 * @discussion Этот метод является `designated initializer` для класса `YSKPhraseSpotterSettings`.
 * @param modelPath Путь к модели для объекта класса `YSKPhraseSpotter`.
 * @return Объект класса `YSKPhraseSpotterSettings`.
 */
- (instancetype)initWithModelPath:(NSString *)modelPath NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithModelPath: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithModelPath: instead.")));

@end

NS_ASSUME_NONNULL_END
