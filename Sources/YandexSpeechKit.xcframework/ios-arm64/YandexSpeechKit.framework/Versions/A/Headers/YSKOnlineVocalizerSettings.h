//
// YSKOnlineVocalizerSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Aleksey Sikorsky <alsikorskii@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKLanguage;
@class YSKSoundFormat;
@class YSKEmotion;
@class YSKVoice;
@class YSKSoundQuality;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Класс задает настройки для online-синтеза и озвучивания речи.
 * @discussion Обязательной настройкой объекта класса `YSKOnlineVocalizer` является язык текста для синтеза. Остальные настройки можно устанавливать в зависимости от задачи.
 */
@interface YSKOnlineVocalizerSettings : NSObject<NSCopying>

/**
 * @property language
 * @abstract Язык синтезируемой речи.
 * @discussion Обязательный параметр настроек объекта класса `YSKOnlineVocalizer`.
 */
@property (nonatomic, copy, readonly) YSKLanguage *language;

/**
 * @property voice
 * @abstract Голос, который используется для синтезируемой речи.
 * @discussion Значение по умолчанию: `jane` (метод -[YSKVoice jane]).
 */
@property (nonatomic, copy) YSKVoice *voice;

/**
 * @property autoPlaying
 * @abstract Признак проигрывания речи (после синтеза) встроенным пллером.
 * @discussion Допустимые значения: `YES` — речь будет проиграна после синтеза, `NO` — речь не будет проиграна. Значение по умолчанию: `YES`.
 */
@property (nonatomic, assign) BOOL autoPlaying;

/**
 * @property emotion
 * @abstract Эмоции синтезируемого голоса.
 * @discussion Значение по умолчанию: `neutral` (метод -[YSKEmotion neutral]).
 */
@property (nonatomic, copy) YSKEmotion *emotion;

/**
 * @property speed
 * @abstract Скорость синтезируемой речи.
 * @discussion Значение по умолчанию: 1.
 */
@property (nonatomic, assign) CGFloat speed;

/**
 * @property soundFormat
 * @abstract Формат синтезируемого звука.
 * @discussion Значение по умолчанию: `opus` (метод -[YSKSoundFormat opus]).
 */
@property (nonatomic, copy) YSKSoundFormat *soundFormat;

/**
 * @property soundQuality
 * @abstract Качество синтезируемого звука.
 * @discussion Значение по умолчанию: `ultrahigh` (метод -[YSKSoundQuality ultrahigh]).
 */
@property (nonatomic, copy) YSKSoundQuality *soundQuality;

/**
 * @property serverRequestVolume
 * @abstract Уровень громкости, который будет использован при синтезе речи (не путайте с громкостью воспроизведения).
 * @discussion Значение по умолчанию: 1 (средняя громкость).
 */
@property (nonatomic, assign) CGFloat serverRequestVolume;

/**
 * @abstract Инициализирует объект класса `YSKOnlineVocalizerSettings`.
 * @discussion Этот метод является `designated initializer` для класса `YSKOnlineVocalizerSettings`.
 * @param language Язык синтеза.
 * @return Объект класса `YSKOnlineVocalizerSettings`.
 */
- (instancetype)initWithLanguage:(nonnull YSKLanguage *)language NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithLanguage: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithLanguage: instead.")));

@end

NS_ASSUME_NONNULL_END
