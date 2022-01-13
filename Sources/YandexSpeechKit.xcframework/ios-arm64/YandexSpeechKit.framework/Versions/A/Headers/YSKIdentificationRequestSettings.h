//
// YSKIdentificationRequestSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Задает настройки для объекта класса `YSKIdentificationRequest`.
 */
@interface YSKIdentificationRequestSettings : NSObject<NSCopying>

/**
 * @property biometryGroupId
 * @abstract Идентификатор `biometry group`.
 */
@property (nonatomic, copy) NSString *biometryGroupId;

@end
