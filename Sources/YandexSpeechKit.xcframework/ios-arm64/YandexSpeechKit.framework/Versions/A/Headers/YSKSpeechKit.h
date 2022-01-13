//
// SpeechKit.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YSKLocationProvider;
@protocol YSKEventLogger;
@class YSKOnlineModel;

/**
 * @defgroup ysk_log_level_global_enums Уровень детализации логов YSKLogLevel
 * @ingroup global_enums
 * @abstract Содержит варианты детализации логов.
 */
//@{
typedef NS_ENUM(NSInteger, YSKLogLevel) {
    
/**
 * @abstract В лог записываются только ошибки, которые возникают в ходе работы библиотеки.
 */
    YSKLogLevelError = 0,
    
/**
 * @abstract В лог записываются ошибки и предупреждения, которые возникают в ходе работы библиотеки.
 */
    YSKLogLevelWarn = 1,
    
/**
 * @abstract В лог записываются ошибки, предупреждения и информационные сообщения, которые возникают в ходе работы библиотеки.
 */
    YSKLogLevelInfo = 2,
    
/**
 * @abstract В лог записывается вся информация о работе библиотеки.
 */
    YSKLogLevelDebug = 3
};
//@}

/**
 * @abstract Класс-синглтон для настройки и управления работой библиотеки.
 * @discussion Объекты класса `YSKSpeechKit` не нужно создавать или уничтожать явным образом. Для доступа к объекту необходимо использовать метод -[YSKSpeechKit sharedInstance], который создает объект класса `YSKSpeechKit` при первом своем вызове. Этот объект уничтожится при завершении работы приложения.
 */
@interface YSKSpeechKit : NSObject

/**
 * @property speechkitVersion
 * @abstract Версия библиотеки.
 */
@property (class, nonatomic, copy, readonly) NSString *speechkitVersion;

/**
 * @property apiKey
 * @abstract API-ключ разработчика, предоставляемый Яндексом.
 * @discussion Задайте значение свойства перед началом использования любой функциональности библиотеки (например, перед созданием объекта класса `YSKPhraseSpotter`). API-ключ проверяется во время работы с сервером, проверка может завершиться ошибкой с кодом `YSKErrorInvalidApiKey`. Коды возможных ошибок перечислены в YSKErrorCode.
 */
@property (nonatomic, copy) NSString *apiKey;

/**
 * @property locationProvider
 * @abstract Объект, который предоставляет библиотеке доступ к геолокации.
 * @discussion Информация о текущем положении пользователя может быть использована для определения наиболее вероятных гипотез, например, при использовании языковой модели -[YSKOnlineModel maps]. 
 * @note Отключить геолокацию можно одним из способов:
 * - не передавайте значение свойства;
 * - задайте пустое значение свойства.
 */
@property (nonatomic, strong, nullable) id<YSKLocationProvider> locationProvider;

/**
 * @property uuid
 * @abstract Идентификатор, который будет использоваться в запросе на распознавание.
 * @discussion Уникальный идентификатор пользователя приложения или сервиса. Значение этого поля передается в каждом запросе к `SpeechKit`. Используется для отслеживания сессий отдельных пользователей и приложений. Значение необходимо генерировать при первом запуске приложения на устройстве и запоминать в постоянном хранилище. Последующие запуски приложения должны использовать сохраненное значение.
 */
@property (nonatomic, copy) NSString *uuid;

/**
 * @property deviceId
 * @abstract Идентификатор устройства, который будет использоваться в запросе на распознавание.
 * @discussion Идентификатор должен быть одним и тем же для всех запросов, отправленных конкретным приложением на конкретном устройстве.
*/

@property (nonatomic, copy) NSString *deviceId;

/**
 * @property logLevel
 * @abstract Уровень детализации логов.
 */
@property (nonatomic) YSKLogLevel logLevel;

/**
 * @property eventLogger
 * @abstract Внешний обработчик для журнала событий.
 */
@property (nonatomic, strong, nullable) id<YSKEventLogger> eventLogger;

/**
 * @property dumpPath
 * @abstract Путь для файлов дампа при отладке.
 */
@property (nonatomic, copy) NSString *dumpPath;

/**
 * @abstract Возвращает общий объект класса `YSKSpeechKit`.
 * @return Общий объект класса `YSKSpeechKit`.
 */
+ (instancetype)sharedInstance;

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance method instead.")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance method instead.")));

@end

NS_ASSUME_NONNULL_END
