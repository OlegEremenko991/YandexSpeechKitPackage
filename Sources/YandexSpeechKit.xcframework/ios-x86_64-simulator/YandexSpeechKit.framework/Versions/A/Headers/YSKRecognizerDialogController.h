//
// YSKRecognizerDialogController.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YSKRecognizing;
@protocol YSKDialogSkin;
@protocol YSKRecognizerDialogControllerDelegate;
@class YSKOnlineRecognizerSettings;
@class YSKPhraseSpotterSettings;
@class YSKBiometry;
@class YSKAudioProcessingMode;
@class YSKPhraseSpotter;
@class YSKRecognizerDialogEarcons;

/**
 * @abstract UI-диалог для распознавания речи.
 * @discussion Упрощает встраивание распознавания речи в приложение. `YSKRecognizerDialogController` управляет всем процессом распознавания:
 * - пользовательский интерфейс распознавания;
 * - управление жизненным циклом используемых объектов `YSKOnlineRecognizer` и `YSKPhraseSpotter`.

 * `YSKRecognizerDialogController` использует `YSKRecognizerDialogControllerDelegate` для оповещения об основных событиях в процессе распознавания. `YSKRecognizerDialogController` начинает распознавание сразу после открытия. Диалог закрывается автоматически, если:
 * - получен результат распознавания;
 * - произошла ошибка;
 * - пользователь закрыл или свернул приложение.

 * `YSKRecognizerDialogController` самостоятельно обрабатывает повороты экрана, сворачивание приложения и любые другие события, которые могут повлиять на внешний вид диалога или поведение объекта класса `YSKOnlineRecognizer`. Объект класса `YSKRecognizerDialogController` можно переиспользовать. При открытии диалога захватываются все необходимое ресурсы, а при закрытии они освобождаются.

 * Перед началом работы с объектом класса `YSKRecognizerDialogController` необходимо задать API-ключ разработчика с помощью свойства -[YSKSpeechKit apiKey].
 */
@interface YSKRecognizerDialogController : UIViewController

/**
 * @property skin
 * @abstract Внешний вид диалога.
 * @discussion Значение по умолчанию: `YSKLightDialogSkin`. При изменении этого свойства диалог сразу изменяет свой внешний вид.
 */
@property (nonatomic, strong) id<YSKDialogSkin> skin;

/**
 * @property delegate
 * @abstract Делегат, который будет получать уведомления о получении результата распознавания, возникновении ошибки и закрытии диалога.
 */
@property (nonatomic, weak, nullable) id<YSKRecognizerDialogControllerDelegate> delegate;

/**
 * @property shouldDisplayPartialResults
 * @abstract Показ частичных результатов распознавания. Допустимые значения: `YES` —  результат будет показан, `NO` — результат не будет показан.
 */
@property (nonatomic, assign) BOOL shouldDisplayPartialResults;

/**
 * @property shouldDisplayHypothesesList
 * @abstract Показ экрана со списком всех гипотез в случае нескольких вариантов распознавания. Допустимые значения: `YES` —  список будет показан, `NO` — список не будет показан.
 */
@property (nonatomic, assign) BOOL shouldDisplayHypothesesList;

/**
 * @property biometry
 * @abstract Оценочные биометрические характеристики пользователя, такие как возраст, пол, принадлежность к той или иной возрастной группе.
 * @discussion Объект `YSKBiometry` возвращается не равным `nil` в методе -[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:] если выполнены следующие условия:
 * - значение параметра `endOfUtterance` = `YES` (метод -[YSKRecognizerDelegate recognizer:didReceivePartialResults:withEndOfUtterance:]);
 * - значение свойства `requestBiometry` = `YES` (класс `YSKOnlineRecognizerSettings`).
 */
@property (nonatomic, copy, readonly, nullable) YSKBiometry *biometry;

/**
 * @property audioProcessingMode
 * @abstract Режим обработки поступающего звука. Режимы описаны в классе `YSKAudioProcessingMode`.
 * @discussion Значение по умолчанию: `mute`.
 */
@property (nonatomic, copy, readonly) YSKAudioProcessingMode *audioProcessingMode;

/**
 * @property requestId
 * @abstract Идентификатор запроса.
 */
@property (nonatomic, copy, readonly, nullable) NSString *requestId;

/**
 * @property earcons
 * @abstract Список звуков, проигрываемых в ходе работы `YSKRecognizerDialogController`.
 */
@property (nonatomic, copy) YSKRecognizerDialogEarcons *earcons;

/**
 * @abstract Инициализирует объект класса `YSKRecognizerDialogController`.
 * @discussion При использовании данного метода голосовая активация на экране ошибки и дополнительная обработка поступающего звука не используются.
 * @param recognizerSetting Настройки объекта класса `YSKOnlineRecognizer`, который используется для распознавания речи.
 * @return Объект класса `YSKRecognizerDialogController`.
 */
- (instancetype)initWithRecognizerSettings:(YSKOnlineRecognizerSettings *)recognizerSetting;

/**
 * @abstract Инициализирует объект класса `YSKRecognizerDialogController` с режимом дополнительной обработки звука.
 * @discussion При использовании данного метода голосовая активация на экране ошибки не используется. Вы можете задать дополнительную обрабоку звука с помощью параметра `mode`:
 * - не записывать, пока проигрывается звук (режим `mute`);
 * - применять к звуку алгоритм acoustic echo cancellation (режим `echoCancel`).
 *  Этот метод является `designated initializer` для класса `YSKRecognizerDialogController`.
 * @param recognizerSetting Настройки объекта класса `YSKOnlineRecognizer`, который используется для распознавания речи.
 * @param mode Режим дополнительной обработки звука. Режимы описаны в классе `YSKAudioProcessingMode`.
 * @return Объект класса `YSKRecognizerDialogController`.
 */
- (instancetype)initWithRecognizerSettings:(YSKOnlineRecognizerSettings *)recognizerSetting audioProcessingMode:(nullable YSKAudioProcessingMode *)mode NS_DESIGNATED_INITIALIZER;

/**
 * @abstract Инициализирует объект класса `YSKRecognizerDialogController` с настройками для голосовой активации на экране ошибки и режимом дополнительной обработки звука.
 * @discussion Задает настройки объекта класса `YSKPhraseSpotter`, который будет использоваться для  голосовой активации на экране ошибки, и дополнительную обрабоку звука.
 * @param recognizerSettings Настройки объекта класса `YSKOnlineRecognizer`, который используется для распознавания речи.
 * @param phraseSpotterSettings Настройки объекта класса `YSKPhraseSpotter` для голосовой активации на экране ошибки.
 * @param mode Режим дополнительной обработки звука. Режимы описаны в классе `YSKAudioProcessingMode`.
 * @return Объект класса `YSKRecognizerDialogController`.
 */
- (instancetype)initWithRecognizerSettings:(YSKOnlineRecognizerSettings *)recognizerSettings phraseSpotterSettings:(YSKPhraseSpotterSettings *)phraseSpotterSettings audioProcessingMode:(nullable YSKAudioProcessingMode *)mode ;

/**
 * @abstract Инициализирует объект класса `YSKRecognizerDialogController` без заданных настроек.
 * @discussion При использовании данного метода объект класса `YSKPhraseSpotter` равен nil, и голосовая активация на экране ошибки не используется. Этот метод является `designated initializer` для класса `YSKRecognizerDialogController`.
 * @warning Метод устарел и не позволяет задать режим для подавления звука начала записи речи. Используйте метод -[YSKRecognizerDialogController initWithRecognizerSettings:audioProcessingMode:] для создания объекта класса `YSKRecognizerDialogController`.
 * @param recognizer Объект класса, реализующий протокол `YSKRecognizing`, который используется для распознавания речи.
 * @return Объект класса `YSKRecognizerDialogController`.
 */
- (instancetype)initWithRecognizer:(id<YSKRecognizing>)recognizer NS_DESIGNATED_INITIALIZER DEPRECATED_MSG_ATTRIBUTE("Use -initWithRecognizerSettings: instead.");

/**
 * @abstract Инициализирует объект класса `YSKRecognizerDialogController` с заданными настройками.
 * @discussion Метод задает объект класса `YSKPhraseSpotter`, который будет использоваться для голосовой активации на экране ошибки.
 * @warning Метод устарел и не позволяет задать режим для подавления звука начала записи речи. Используйте метод -[YSKRecognizerDialogController initWithRecognizerSettings:phraseSpotterSettings:audioProcessingMode:] для создания класса `YSKRecognizerDialogController`.
 * @param recognizer Обект класса, реализующий протокол `YSKRecognizing`, который используется для распознавания речи.
 * @param phraseSpotter Объект класса `YSKPhraseSpotter` для голосовой активации.
 * @return Объект класса `YSKRecognizerDialogController`.
 */
- (instancetype)initWithRecognizer:(id<YSKRecognizing>)recognizer phraseSpotter:(YSKPhraseSpotter *)phraseSpotter DEPRECATED_MSG_ATTRIBUTE("Use -initWithRecognizerSettings:phraseSpotterSettings: instead.");

+ (instancetype)new __attribute__((unavailable("Use designated initializer -initWithRecognizer:phraseSpotter: instead.")));
- (instancetype)init __attribute__((unavailable("Use designated initializer -initWithRecognizer:phraseSpotter: instead.")));
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil __attribute__((unavailable("Use designated initializer -initWithRecognizer:phraseSpotter: instead.")));
- (instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((unavailable("Use designated initializer -initWithRecognizer:phraseSpotter: instead.")));

/**
 * @abstract Открывает диалог и начинает распознавание.
 * @discussion Для показа диалога следует использовать только этот метод, потому что он вызывает необходимые для работы распознавания настройки.
 * @warning Использование стандартных методов для открытия `UIViewController` может привести к некорректной работе диалога.
 * @param presentingController Контроллер, поверх которого будет открыт диалог.
 * @param animated Диалог будет закрываться с анимацией или без. Допустимые значения: `YES` — диалог закрывается с анимацией, `NO` — диалог закрывается без анимации.
 * @param completion Блок, который будет вызван по окончании анимации закрытия диалога.
 */
- (void)presentRecognizerDialogOverPresentingController:(UIViewController *)presentingController animated:(BOOL)animated completion:(nullable void (^)(void))completion;

/**
 * @abstract Принудительно закрывает диалог.
 * @discussion Вызывать этот метод явно необходимо только в случае, если вы хотите завершить работу с диалогом немедленно. В остальных случаях он будет вызван автоматически по окончании распознавания, при закрытии диалога пользователем или сворачивании приложения.
 * @param animated Диалог будет закрываться с анимацией или без. Допустимые значения: `YES` — диалог закрывается с анимацией, `NO` — диалог закрывается без анимации.
 */
- (void)dismissRecognizerDialogAnimated:(BOOL)animated;

@end

/**
 * @abstract Протокол определяет callback-методы делегата, который вызывается диалогом `YSKRecognizerDialogController`.
 * @discussion Эти методы вызываются в ходе жизненного цикла распознавания. Делегат уведомляется о получении результата распознавания, возникновении ошибки и закрытии диалога.
 */
@protocol YSKRecognizerDialogControllerDelegate <NSObject>

/**
 * @abstract Вызывается при успешном завершении процесса распознавания.
 * @details Метод вызывается, если речь успешно распознана. В противном случае будет показан экран ошибки, если проблема может быть исправлена пользователем (например, "Вас не слышно")  или вызван метод -[YSKRecognizerDialogControllerDelegate recognizerDialogController:didFailWithError:]. Метод вызывается до окончания анимаци закрытия диалога.
 * @param controller Объект класса `YSKRecognizerDialogController`, вызвавший метод.
 * @param result Строка, которая содержит результат распознавания.
 */
- (void)recognizerDialogController:(YSKRecognizerDialogController *)controller didFinishWithResult:(NSString *)result;

/**
 * @abstract Вызывается, если процесс распознавания завершился с ошибкой и проблема не может быть исправлена самим пользователем.
 * @details Метод вызывается до окончания анимаци закрытия диалога.
 * @param controller Объект класса `YSKRecognizerDialogController`, вызвавший метод.
 * @param error Ошибка, которая произошла во время распознавания.
 */
- (void)recognizerDialogController:(YSKRecognizerDialogController *)controller didFailWithError:(NSError *)error;

/**
 * @abstract Вызывается при закрытии диалога.
 * @discussion Метод вызывается по окончании анимации закрытия диалога. Диалог автоматически закрывается при получении результатов распознавания или ошибки. Пользователь может закрыть диалог, не дожидаясь результатов распознавания, нажатием на затемненную область экрана или смахиванием диалога вниз.
 * @param controller Объект класса `YSKRecognizerDialogController`, вызвавший метод.
 * @param automatically Вариант закрытия диалога (автоматически или пользователем). Допустимые значения: `YES` — диалог был закрыт автоматически, при получении результатов распознавания, `NO` — диалог был закрыт пользователем.
 */
- (void)recognizerDialogControllerDidClose:(YSKRecognizerDialogController *)controller automatically:(BOOL)automatically;

@optional
/**
 * @abstract Вызывается, когда диалог закончил работу с аудио.
 * @discussion Диалог использует аудиовходы и выходы устройства для записи звука через объект класса `YSKOnlineRecognizer` и для проигрывания звуков начала записи, ошибки, закрытия диалога. Аудио может закончить играть немного позже закрытия самого диалога. В этом методе можно менять настройки аудиосессии. Метод может вызываться как до, так и после вызова метода -[YSKRecognizerDialogControllerDelegate recognizerDialogControllerDidClose:automatically:].
 * @param controller Объект класса `YSKRecognizerDialogController`, вызвавший метод.
 */
- (void)recognizerDialogControllerDidFinishAudioProcessing:(YSKRecognizerDialogController *)controller;

@end

NS_ASSUME_NONNULL_END
