//
// YSKDefaultEarconsBundle.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKSoundBuffer;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Класс для получения звуков, проигрываемых по умолчанию в ходе работы компонент библиотеки.
 */
@interface YSKDefaultEarconsBundle : NSObject

/**
 * @property emptyEarcon
 * @abstract "Пустой" звук.
 */
@property (class, nonatomic, copy, readonly) YSKSoundBuffer *emptyEarcon;
/**
 * @property startEarcon
 * @abstract Звук начала распознавания.
 */
@property (class, nonatomic, copy, readonly) YSKSoundBuffer *startEarcon;
/**
 * @property finishEarcon
 * @abstract Звук успешного окончания распознавания.
 */
@property (class, nonatomic, copy, readonly) YSKSoundBuffer *finishEarcon;
/**
 * @property cancelEarcon
 * @abstract Звук закрытия диалога пользователем.
 */
@property (class, nonatomic, copy, readonly) YSKSoundBuffer *cancelEarcon;
/**
 * @property waitEarcon
 * @abstract Звук ошибки распознавания или получения множественного списка гипотез.
 */
@property (class, nonatomic, copy, readonly) YSKSoundBuffer *waitEarcon;

@end

NS_ASSUME_NONNULL_END
