//
// YSKEventLogger.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Aleksey Sikorsky <alsikorskii@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @defgroup ysk_event_logger_global_const Глобальные константы YSKEventLogger
 * @ingroup global_const
 * @abstract Список событий, которые возникают при работе с объектом класса `YSKRecognizerDialogController`.
 */

//@{
/**
 * @abstract Событие, возникающее при открытии экрана диалога `YSKRecognizerDialogController`.
 */
extern NSString *const YSKEventScreenShown;
/**
 * @abstract `YSKRecognizerDialogController` готов записывать речь для распознавания.
 */
extern NSString *const YSKScreenNameSpeak;
/**
 * @abstract `YSKRecognizerDialogController` закончил запись речи и ожидает результата распознавания.
 */
extern NSString *const YSKScreenNameAnalysing;
/**
 * @abstract Открытие экрана гипотез.
 */
extern NSString *const YSKScreenNameHypotheses;
/**
 * @abstract Открытие экрана ошибки при возникновении сетевой проблемы.
 */
extern NSString *const YSKScreenNameConnectionError;
/**
 * @abstract Открытие экрана ошибки при отсутствии речи.
 */
extern NSString *const YSKScreenNameNoVoiceDetected;
/**
 * @abstract Нажатие на кнопку "Повторите".
 */
extern NSString *const YSKEventButtonRepeatPressed;
/**
 * @abstract Закрытие диалога пользователем при нажатии на затемненную область экрана или смахивании диалога вниз.
 */
extern NSString *const YSKEventButtonCancelPressed;
/**
 * @abstract Закрытие диалога пользователем или автоматически.
 */
extern NSString *const YSKEventButtonBackPressed;
/**
 * @abstract Остановка работы объекта класса `YSKOnlineRecognizer` при нажатии на затемненную область экрана.
 */
extern NSString *const YSKEventButtonReadyPressed;
/**
 * @abstract Выбор гипотезы из списка распознанных гипотез.
 */
extern NSString *const YSKEventHypothesisSelected;
/**
 * @abstract Ключ для названия экрана.
 * @discussion Это значение является ключом в словаре аргументов, которые логгер получает в методе -[YSKEventLogger reportEvent:withEventArgs:].
 */
extern NSString *const YSKParamScreenName;
/**
 * @abstract Ключ для индекса выбранной гипотезы.
 * @discussion Это значение является ключом в словаре аргументов, которые логгер получает в методе -[YSKEventLogger reportEvent:withEventArgs:].
 */
extern NSString *const YSKParamHypothesisSelectedIndex;
/**
 * @abstract Ключ для текста выбранной гипотезы.
 * @discussion Это значение является ключом в словаре аргументов, которые логгер получает в методе -[YSKEventLogger reportEvent:withEventArgs:].
 */
extern NSString *const YSKParamHypothesisSelectedText;
/**
 * @abstract Ключ для списка распознанных гипотез.
 * @discussion Это значение является ключом в словаре аргументов, которые логгер получает в методе -[YSKEventLogger reportEvent:withEventArgs:].
 */
extern NSString *const YSKParamHypothesesList;
/**
 * @abstract В процессе записи звука часть семплов была потеряна.
 */
extern NSString *const YSKEventAudioSamplesLost;
/**
 * @abstract Количество потеряных семплов.
 */
extern NSString *const YSKEventLostAudioSamplesCount;

//@}

/**
 * @abstract Протокол для логирования событий, которые происходят в диалоге `YSKRecognizerDialogController`.
 */
@protocol YSKEventLogger <NSObject>

/**
 * @abstract Обработка события с именем `eventName`.
 * @param eventName Имя события.
 */
- (void)reportEvent:(NSString *)eventName;

/**
 * @abstract Обработка события с именем `eventName` и аргументами.
 * @param eventName Имя события.
 * @param eventArgs Словарь, который содержит дополнительные аргументы.
 */
- (void)reportEvent:(NSString *)eventName withEventArgs:(nullable NSDictionary<NSString *, NSString *> *)eventArgs;
@end

NS_ASSUME_NONNULL_END
