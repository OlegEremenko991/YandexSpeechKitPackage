//
// YSKAudioProcessingMode.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Alexander Panin <agpanin@yandex-team.ru>
//

#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Режим обработки поступающего на распознавание звука.
 * @discussion Существует три режима обработки звука:
 * - звук проходит без изменений (`pass`);
 * - распознавание звука на какое-то время приостанавливается с последующем запуском (`mute`);
 * - к звуку применяется алгоритм "acoustic echo cancellation" (`echoCancel`).
 */
@interface YSKAudioProcessingMode : YSKSetting

/**
 * @abstract Создает объект класса `YSKAudioProcessingMode`, который соответствует режиму обработки звука `pass` (записанный с микрофона звук не обрабатывается).
 * @return Объект класса `YSKAudioProcessingMode`, который соответствует выбранному режиму.
 */
+ (instancetype)pass;

/**
 * @abstract Создает объект класса `YSKAudioProcessingMode`, который соответствует режиму обработки звука `mute` (записанный с микрофона звук можно на время приостановить, а потом опять запустить).
 * @return Объект класса `YSKAudioProcessingMode`, который соответствует выбранному режиму.
 */
+ (instancetype)mute;

/**
 * @abstract Создает объект класса `YSKAudioProcessingMode`, который соответствует режиму обработки звука `echoCancel` (записанный с микрофона звук обрабатывается алгоритмом подавления эха, поэтому записанная речь не содержит так называемый farend-сигнал, но немного искажается алгоритмом).
 * @return Объект класса `YSKAudioProcessingMode`, который соответствует выбранному режиму.
 */
+ (instancetype)echoCancel;

@end

NS_ASSUME_NONNULL_END
