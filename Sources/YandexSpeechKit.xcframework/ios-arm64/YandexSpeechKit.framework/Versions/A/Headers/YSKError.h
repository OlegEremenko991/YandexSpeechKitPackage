//
// SpeechKit.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <UIKit/UIKit.h>

/**
 * @defgroup global_enums Перечисления
 */
/**
 * @defgroup ysk_error_code_global_enums Коды ошибок YSKErrorCode
 * @ingroup global_enums
 * @abstract Содержит описания ошибок, которые могут произойти в процессе работы в различных компонентах библиотеки.
 * @discussion Эти коды используются в ошибках, которые возвращаются методами -[YSKRecognizerDelegate recognizer:didFailWithError:], -[YSKVocalizerDelegate vocalizer:didFailWithError:], -[YSKPhraseSpotterDelegate phraseSpotter:didFailWithError:], -[YSKAudioSourceListener audioSource:didFailWithError:], -[YSKIdentificationRequestDelegate identificationRequest:didFailWithError:], -[YSKRegistrationRequestDelegate registrationRequest:didFailWithError:].
 */
//@{
typedef NS_ENUM(NSInteger, YSKErrorCode) {
    
/**
 * @abstract Ошибка при проверке API-ключа.
 */
    YSKErrorInvalidApiKey = 1,
    
/**
 * @abstract Ошибка записи звука.
 */
    YSKErrorAudioRecording = 2,
    
/**
 * @abstract Ошибка воспроизведения звука.
 */
    YSKErrorAudioPlaying = 3,
    
/**
 * @abstract У приложения нет прав для использования микрофона.
 */
    YSKErrorRecordingPermissions = 4,
    
/**
 * @abstract Работа со звуком была прервана.
 */
    YSKErrorAudioInterrupted = 5,
    
/**
 * @abstract Ошибка кодирования звука.
 */
    YSKErrorAudioEncoding = 6,
    
/**
 * @abstract Ошибка сети.
 */
    YSKErrorNetwork = 7,
    
/**
 * @abstract Ошибка сервера.
 */
    YSKErrorServer = 8,
    
/**
 * @abstract Речь не обнаружена.
 */
    YSKErrorNoSpeechDetected = 9,

/**
 * @abstract Ошибка преобразования текста в речь.
 */
    YSKErrorNoTextToSynthesize = 10,
    
/**
 * @abstract Ошибка при работе с моделью.
 */
    YSKErrorModel = 11,

/**
 * @abstract Биометрический запрос (регистрация, идентификация) завершился ошибкой.
 * @discussion Ошибка может быть вызвана следующими причинами: недостаточно звука, проблемы при работе с базой данных, неправильный формат звука.
 */
    YSKErrorBiometry = 12,
    
/**
 * @abstract Платформенное распознавание `Speech.framework` не поддерживает заданный язык.
 */
    YSKErrorNativeRecognizerUnsupportedLanguage = 42,
};
//@}

/**
 * @defgroup global_const Глобальные константы
 */
/**
 * @defgroup ysk_speechkit_error_domain_global_const Глобальные константы YSKSpeechKit
 * @ingroup global_const
 */

//@{
/**
 * @abstract Общий домен для ошибок библиотеки `SpeechKit`.
 */

UIKIT_EXTERN NSString *const YSKSpeechKitErrorDomain;

//@}
