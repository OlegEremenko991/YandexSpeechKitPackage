//
// YSKOnlineRecognizerSettings.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKLanguage;
@class YSKOnlineModel;
@class YSKSoundFormat;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Задает настройки для объекта класса `YSKOnlineRecognizer`.
 * @discussion Обязательными настройками являются язык распознавания и модель. Остальные настройки можно устанавливать в зависимости от задачи.
 */
@interface YSKOnlineRecognizerSettings : NSObject<NSCopying>

/**
 * @property language
 * @abstract Язык голосового запроса.
 */
@property (nonatomic, copy, readonly) YSKLanguage *language;

/**
 * @property model
 * @abstract Модель, используемая для распознавания.
 */
@property (nonatomic, copy, readonly) YSKOnlineModel *model;

/**
 * @property enableVAD
 * @abstract Управляет поведением детектора голосовой активности (Voice Activity Detection, VAD).
 * @discussion Если VAD выключен, объект класса `YSKOnlineRecognizer` не определяет момент окончания речи автоматически. В этом случае вызовите метод -[YSKRecognizing stopRecording], чтобы закончить запись и перейти к распознаванию. Значение по умолчанию: `YES`.
 */
@property (nonatomic, assign) BOOL enableVAD;

/**
 * @property soundFormat
 * @abstract Формат звука.
 * @discussion Значение по умолчанию: `opus`. Варианты значений можно посмотреть в классе `YSKSoundFormat`.
 */
@property (nonatomic, copy) YSKSoundFormat *soundFormat;

/**
 * @property disableAntimat
 * @abstract Признак пропуска нецензурных слов.
 * @discussion Допустимые значения: `YES` — ASR-сервер не будет пропускать нецензурные слова, `NO` — ASR-сервер будет пропускать нецензурные слова. Значение по умолчанию: `NO`.
 */
@property (nonatomic, assign) BOOL disableAntimat;

/**
 * @property encodingBitrate
 * @abstract Битрейт выбранного аудиокодека (бит/с).
 * @discussion Битрейт определяет, сколько бит будет занимать одна секунда сжатого звука (примерно). Этот параметр влияет на качество звука, и, следовательно, на качество распознавания. Рекомендуемый диапазон для `opus` — от 12000 до 64000 бит/с, если свойство -[YSKOnlineRecognizerSettings encodingComplexity] равно 10. При выборе формата PCM этот параметр не используется. Значение по умолчанию, при котором достигается оптимальное соотношение размера и качества: 24000.
 */
@property (nonatomic, assign) NSInteger encodingBitrate;

/**
 * @property encodingComplexity
 * @abstract Сложность алгоритма сжатия.
 * @discussion Сложность алгоритма влияет на качество звука, и, следовательно, на качество распознавания. Увеличение сложности при фиксированном битрейте позволяет достичь большего качества звука, но при этом увеличивает нагрузку на процессор и время кодирования. Однако, зависимость нелинейная, и при битрейте 24000 бит/с высокое качество распознавания достигается с любым значением сложности, в то время, как при битрейте 12000 бит/с хорошее качество можно получить только при сложности 10. При выборе формата PCM этот параметр не используется. Значение по умолчанию: 0.
 */
@property (nonatomic, assign) NSInteger encodingComplexity;

/**
 * @property silenceBetweenUtterances
 * @abstract Минимальное время тишины между фразами в секундах.
 * @discussion Если тишина между словами будет превышать указанное значение, это будет интерпретировано системой распознавания как окончание фразы. При отрицательных значениях используется значение сервера по умолчанию. Значение по умолчанию: -1.
 */
@property (nonatomic, assign) NSTimeInterval silenceBetweenUtterances;

/**
 * @property enablePunctuation
 * @abstract Признак расстановки знаков препинания.
 * @discussion Допустимые значения: `YES` — ASR-сервер будет расставлять знаки препинания в тексте, `NO`— ASR-сервер не будет расставлять знаки препинания в тексте. Значение по умолчанию: `YES`.
 */
@property (nonatomic, assign) BOOL enablePunctuation;

/**
 * @property enableManualPunctuation
 * @abstract Признак замены слов пунктуации на знаки.
 * @discussion Допустимые значения: `YES` — ASR-сервер будет заменять слова пунктуации на знаки, `NO`— ASR-сервер не будет заменять слова пунктуации на знаки. Значение по умолчанию: `NO`.
 * Например, фраза "привет запятая как дела воспросительный знак" может быть распознана как "привет, как дела?".
 */
@property (nonatomic, assign) BOOL enableManualPunctuation;

/**
 * @property requestBiometry
 * @abstract Признак запроса оценочных биометрических характеристик пользователя (например, возраст, пол, принадлежность к той или иной возрастной группе).
 * @discussion Допустимые значения: `YES` — запрашивать оценочные биометрические характеристики, `NO` — не запрашивать оценочные характеристики. Значение по умолчанию: `NO`.
 */
@property (nonatomic, assign) BOOL requestBiometry;

/**
 * @property finishAfterFirstUtterance
 * @abstract Признак завершения распознавания после получения параметра `endOfUtterance` = `YES` (-[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:]).
 * @discussion Допустимые значения: 
 * - `YES` — объект класса `YSKOnlineRecognizer` завершит распознавание, когда получит параметр `endOfUtterance` = `YES`;
 * - `NO` — объект класса `YSKOnlineRecognizer` продолжит распознавание даже после получения `endOfUtterance` = `YES`. Также необходимо настроить `recordingTimeout` соответствующим образом (например, выставить значение -1 или очень большое значение).
* Значение по умолчанию: `YES`.
 */
@property (nonatomic, assign) BOOL finishAfterFirstUtterance;

/**
 * @property recordingTimeout
 * @abstract Максимальная длина записи голосового запроса в секундах.
 * @discussion Значение по умолчанию: 20.
 */
@property (nonatomic, assign) NSTimeInterval recordingTimeout;

/**
 * @property inactiveTimeout
 * @abstract Время ожидания речи в секундах после старта объекта класса `YSKOnlineRecognizer`.
 * @discussion Если за это время объект класса `YSKOnlineRecognizer` не обнаружил речь, он вернет ошибку с кодом `YSKErrorNoSpeechDetected` в методе -[YSKRecognizerDelegate recognizer:didFailWithError:]. Коды ошибок перечислены в YSKErrorCode. 
 * Значение по умолчанию: 5 секунд.
 */
@property (nonatomic, assign) NSTimeInterval inactiveTimeout;

/**
 * @property soundCacheLength
 * @abstract Максимальная длина звука в миллисекундах, которая будет переотправлена на сервер при обрыве сетевого соединения.
 * @discussion Если значение отрицательное, длина кэша не ограничена. Значение по умолчанию: -1.
 */
@property (nonatomic, assign) NSInteger soundCacheLength;

/**
 * @property waitForConnection
 * @abstract Признак начала записи звука после установки сетевого соединения.
 * @discussion Допустимые значения: `YES` – объект класса `YSKOnlineRecognizer` начнет запись сразу после установки сетевого соединения, `NO` — объект класса `YSKOnlineRecognizer` начнет запись сразу после старта и будет кэшировать данные до установки сетевого соединения.
 * Значение по умолчанию: `NO`.
 */
@property (nonatomic, assign) BOOL waitForConnection;

/*
 * @property waitForResultTimeout
 * @abstract Время ожидания ответа от сервера после отправки последнего фрагмента.
 * @discussion Если за это время сервер не вернул ответ с `endOfUtterance` = `YES` (метод -[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:]), то объект класса `YSKOnlineRecognizer` вернет ошибку с кодом `YSKErrorServer` в методе -[YSKRecognizerDelegate recognizer:didFailWithError:]. Значение по умолчанию: 10 секунд.
*/
@property (nonatomic, assign) NSTimeInterval waitForResultTimeout;

/**
 * @property enableMusicRecognition
 * @abstract ASR-сервер будет или не будет присылать результаты распознавания музыки.
 * @discussion Допустимые значения: `YES` — ASR-сервер будет или не будет присылать результаты распознавания музыки, `NO` — ASR-сервер не будет присылать результаты распознавания музыки.
 * Значение по умолчанию: `NO`.
 */
@property (nonatomic, assign) BOOL enableMusicRecognition;

/**
 * @property asrUrl
 * @abstract URL ASR-сервера.
 */
@property (nonatomic, copy) NSString *asrUrl;

/**
 * @property energyWeight
 * @abstract Вес каждого нового фрагмента звука при вычислении уровня речевого сигнала.
 * @discussion Уровень речевого сигнала можно получить в методе -[YSKRecognizerDelegate recognizer:didUpdatePower:].
 */
@property (nonatomic, assign) CGFloat energyWeight;

/**
 * @property reachabilityTimeout
 * @abstract Время ожидания сетевого соединения.
 * @discussion Отрицательное значение отключает время ожидания. Значение по умолчанию: 5 секунд.
 */
@property (nonatomic, assign) NSTimeInterval reachabilityTimeout;

/**
 * @abstract Инициализирует объект класса `YSKOnlineRecognizerSettings`.
 * @discussion Этот метод является `designated initializer` для класса `YSKOnlineRecognizerSettings`.
 * @param language Язык распознавания.
 * @param model Модель распознавания.
 * @return Объект класса `YSKOnlineRecognizerSettings`.
 */
- (instancetype)initWithLanguage:(YSKLanguage *)language model:(YSKOnlineModel *)model NS_DESIGNATED_INITIALIZER;

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithLanguage:model: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithLanguage:model: instead.")));

@end

NS_ASSUME_NONNULL_END
