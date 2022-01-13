//
// YSKRecognizerDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKDispatchableDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YSKRecognizing;
@class YSKRecognition;
@class YSKTrack;

/**
 * @abstract Протокол определяет callback-методы делегата, который отслеживает процесс распознавания.
 * @discussion Методы вызываются в ходе жизненного цикла распознавания. Делегат уведомляется о начале записи, новом фрагменте звука, завершении процесса распознавания (успешно или с ошибкой) и других событиях.
 */
@protocol YSKRecognizerDelegate <YSKDispatchableDelegate>

@optional

/**
 * @abstract Вызывается в момент начала записи звука.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 */
- (void)recognizerDidStartRecording:(id<YSKRecognizing>)recognizer;

/**
 * @abstract Вызывается в момент обнаружения речи (пользовать начал говорить).
 * @discussion Метод вызывается, если включен детектор голосовой активности (VAD — Voice Activity Detection). По умолчанию детектор включен. С помощью свойства -[YSKOnlineRecognizerSettings enableVAD] можно включить или выключить VAD.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 */
- (void)recognizerDidDetectSpeech:(id<YSKRecognizing>)recognizer;

/**
 * @abstract Вызывается, когда пользователь закончил говорить.
 * @discussion Метод вызывается, если включен детектор голосовой активности (VAD — Voice Activity Detection). По умолчанию детектор включен. С помощью свойства -[YSKOnlineRecognizerSettings enableVAD] можно включить или выключить VAD.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 */
- (void)recognizerDidDetectSpeechEnd:(id<YSKRecognizing>)recognizer;

/**
 * @abstract Вызывается в момент окончания записи звука.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 */
- (void)recognizerDidFinishRecording:(id<YSKRecognizing>)recognizer;

/**
 * @abstract Вызывается каждый раз после записи очередного фрагмента звука и используется для обновления индикатора уровня речевого сигнала в пользовательском интерфейсе.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 * @param power Дробное число в диапазоне от 0 до 1, которое обозначает уровень речевого сигнала (0 — нет сигнала, 1 — максимум).
 */
- (void)recognizer:(id<YSKRecognizing>)recognizer didUpdatePower:(float)power;

/**
 * @abstract Вызывается, когда получен промежуточный результат распознавания.
 * @discussion Метод может вызываться несколько раз после начала распознавания. В метод передается часть результата распознавания и признак окончания высказывания. Если значение параметра `endOfUtterance` = `YES`, параметр `results` содержит итоговый результат распознавания.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 * @param results Частичный результат распознавания.
 * @param endOfUtterance Признак окончания высказывания. Допустимые значения: `YES` - обнаружен конец высказывания; `NO` — высказывание еще не закончено.
 */
- (void)recognizer:(id<YSKRecognizing>)recognizer didReceivePartialResults:(YSKRecognition *)results withEndOfUtterance:(BOOL)endOfUtterance;

/**
 * @abstract Вызывается, если процесс распознавания завершился успешно.
 * @discussion Метод вызывается, если речь успешно распознана. В противном случае вызывается -[YSKRecognizerDelegate recognizer:didFailWithError:].
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 */
- (void)recognizerDidFinishRecognition:(id<YSKRecognizing>)recognizer;

/**
 * @abstract Вызывается, когда процесс распознавания завершился с ошибкой.
 * @discussion Ошибки могут произойти по разным причинам:
 * - ошибка открытия аудиоустройства;
 * - ошибка коммуникации с сервером;
 * - передано неверное значение параметра при инициализации (например, код языка или данные аутентификации);
 * - пользователь прервал выполнение запроса и т.п.
 * @discussion Коды возможных ошибок перечислены в YSKErrorCode.
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 * @param error Ошибка, которая произошла во время распознавания.
 */
- (void)recognizer:(id<YSKRecognizing>)recognizer didFailWithError:(NSError *)error;

/**
 * @abstract Вызывается, когда получен результат распознавания музыки.
 * @discussion Этот метод вызывается, если задано свойство -[YSKOnlineRecognizerSettings enableMusicRecognition].
 * @param recognizer Ссылка на объект класса, реализующий протокол `YSKRecognizing`, который вызвал метод.
 * @param track Результат распознавания музыки.
 */
- (void)recognizer:(id<YSKRecognizing>)recognizer didReceiveMusicResult:(YSKTrack *)track;

@end

NS_ASSUME_NONNULL_END
