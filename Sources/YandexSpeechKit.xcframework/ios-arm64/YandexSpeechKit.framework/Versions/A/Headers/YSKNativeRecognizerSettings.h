//
// YSKNativeRecognizerSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Класс задает настройки для встроенного распознавания речи (объект класса `YSKNativeRecognizer`).
 * @discussion Обязательной настройкой является путь к встроенной модели для распознавания. Остальные настройки можно устанавливать в зависимости от задачи.
 */
@interface YSKNativeRecognizerSettings : NSObject<NSCopying>

/**
 * @property locale
 * @abstract Локаль, которая определяет язык голосового запроса.
 */
@property (nonatomic, copy, readonly) NSLocale *locale;

/**
 * @property enableVAD
 * @abstract Управляет поведением детектора голосовой активности (Voice Activity Detection, VAD).
 * @discussion Если VAD выключен, объект класса `YSKNativeRecognizer` не определяет момент окончания речи автоматически. В этом случае вызовите -[YSKRecognizing stopRecording], чтобы закончить запись и перейти к распознаванию. Значение по умолчанию: `YES`.
 */
@property (nonatomic, assign) BOOL enableVAD;

/**
 * @property inactiveTimeout
 * @abstract Время ожидания речи в секундах после старта объекта класса `YSKNativeRecognizer`.
 * @discussion Если за это время объект класса `YSKNativeRecognizer` не обнаружил речь, то он вернет ошибку с кодом `YSKErrorNoSpeechDetected` в методе -[YSKRecognizerDelegate recognizer:didFailWithError:]. Коды ошибок перечислены в YSKErrorCode.
 * Значение по умолчанию: 5 секунд.
 */
@property (nonatomic, assign) NSTimeInterval inactiveTimeout;

/**
 * @property waitForResultTimeout
 * @abstract Время ожидания ответа от сервера после отправки последнего фрагмента.
 * @discussion Если за это время сервер не вернул ответ с `endOfUtterance` = `YES` (метод -[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:]), то объект класса `YSKNativeRecognizer` вернет последний полученый от сервера результат.
 * Значение по умолчанию: 3 секунды.
 */
@property (nonatomic, assign) NSTimeInterval waitForResultTimeout;

/**
 * @abstract Инициализирует объект класса `YSKNativeRecognizerSettings`.
 * @param locale Язык распознавания.
 * @return Объект класса `YSKNativeRecognizerSettings`.
 */
- (instancetype)initWithLocale:(NSLocale *)locale;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithLocale: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithLocale: instead.")));

@end

NS_ASSUME_NONNULL_END
