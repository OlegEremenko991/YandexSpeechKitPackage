//
// YSKTrack.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKArtist;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Результат распознавания музыки.
 */
@interface YSKTrack : NSObject<NSCopying>
/**
 * @property title
 * @abstract Название музыкального произведения.
 */
@property (nonatomic, copy, readonly) NSString *title;
/**
 * @property identifire
 * @abstract Идентификатор музыкального произведения на сайте music.yandex.ru.
 */
@property (nonatomic, copy, readonly, nullable) NSString *identifire;
/**
 * @property url
 * @abstract Ссылка на музыкальное произведение на сайте music.yandex.ru.
 */
@property (nonatomic, copy, readonly, nullable) NSURL *url;
/**
 * @property artists
 * @abstract Список исполнителей музыкального произведения.
 */
@property (nonatomic, copy, readonly) NSArray<YSKArtist *>* artists;
/**
 * @property jsonPayload
 * @abstract Результат распознавания музыки в формате json.
 */
@property (nonatomic, copy, readonly, nullable) NSString *jsonPayload;

@end


__attribute__((objc_subclassing_restricted))
/**
 * @abstract Исполнитель музыкального произведения.
 */
@interface YSKArtist : NSObject<NSCopying>
/**
 * @property identifire
 * @abstract Идентификатор исполнителя.
 */
@property (nonatomic, copy, readonly) NSString *identifire;
/**
 * @property name
 * @abstract Имя исполнителя.
 */
@property (nonatomic, copy, readonly) NSString *name;

@end

NS_ASSUME_NONNULL_END
