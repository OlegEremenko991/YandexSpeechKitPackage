//
// YSKRecognizerDialogEarcons.h
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
 @abstract Класс для хранения звуков, проигрываемых в ходе работы `YSKRecognizerDialogController`.
 */
@interface YSKRecognizerDialogEarcons : NSObject

/**
 @abstract Звук, проигрываемый в начале распознавания.
 @discussion Если настройка -[YSKRecognizerDialogController audioProcessingMode] равна `echoCancel`, то данный звук будет вычитаться из записи, которая идет на распознавание, с помощью алгоритма acoustic echo cancellation. Для этого звук `start` должен быть моно (`channelCount` = 1) и несжатым (`soundFormat`= `pcm`). Иначе алгоритм aec применяться не будет, и в лог будет выведено сообщение о возможной ошибке. Значение по умолчанию: звук sounds/start.wav из бандла библиотеки.
 */
@property (nonatomic, strong) YSKSoundBuffer *start;

/**
 @abstract Звук, проигрываемый при получении однозначного результата распознавания.
 @discussion Значение по умолчанию: звук sounds/finish.wav из бандла библиотеки.
 */
@property (nonatomic, strong) YSKSoundBuffer *finish;

/**
 @abstract Звук, проигрываемый по окончании работы с диалогом.
 @discussion Значение по умолчанию: звук sounds/cancel.wav из бандла библиотеки.
 */
@property (nonatomic, strong) YSKSoundBuffer *cancel;

/**
 @abstract Звук, проигрываемый при получении списка гипотез или ошибки во время распознавания.
 @discussion Значение по умолчанию: звук sounds/wait.wav из бандла библиотеки.
 */
@property (nonatomic, strong) YSKSoundBuffer *wait;

@end

NS_ASSUME_NONNULL_END
