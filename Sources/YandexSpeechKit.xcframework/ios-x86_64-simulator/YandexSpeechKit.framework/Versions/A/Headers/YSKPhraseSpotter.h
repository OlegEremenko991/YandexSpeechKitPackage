//
// YSKPhraseSpotter.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Alexander Panin <agpanin@yandex-team.ru>
// Author: Yuriy Shirokov <yashrk@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YSKPhraseSpotterDelegate;
@protocol YSKAudioSource;
@class YSKPhraseSpotterSettings;

/**
 * @abstract Класс для голосовой активации.
 * @discussion Технология голосовой активации позволяет находить в аудиопотоке заданные фразы. Список фраз содержится в модели для голосовой активации (пример модели можно посмотреть по [ссылке](https://github.com/yandexmobile/yandex-speechkit-samples-ios/tree/master/PhraseSpotterSample/PhraseSpotterSample/phrase_spotter_model)). Поиск фраз может выполняться непрерывно. При этом не требуется подключение к интернету, все вычисления производятся на устройстве.
 * @warning При запуске объекта класса `YSKPhraseSpotter` с аудиоисточником по умолчанию или любым другим источником, который использует стандартный вход устройства, необходимо правильно настроить аудиосессию приложения. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * - если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно.
 * Если вы решите настроить аудиосессию самостоятельно, обратите внимание на настройки, которые могут повлиять на работу объекта класса `YSKPhraseSpotter` (настройки аудиосессии описаны в классе `YSKAudioSessionHandler`). Без соответствующих настроек объект класса `YSKPhraseSpotter` вернет ошибку с кодом `YSKErrorAudioRecording` в методе -[YSKPhraseSpotterDelegate phraseSpotter:didFailWithError:]. Коды возможных ошибок перечислены в YSKErrorCode.
 */
@interface YSKPhraseSpotter : NSObject

/**
 * @property delegate
 * @abstract Делегат, который получает уведомления от объекта класса `YSKPhraseSpotter`.
 */
@property (nonatomic, weak, nullable) id<YSKPhraseSpotterDelegate> delegate;

/**
 * @property settings
 * @abstract Настройки объекта класса `YSKPhraseSpotter`.
 * @discussion В настройках можно задать путь к модели для голосовой активации.
 */
@property (nonatomic, copy, readonly) YSKPhraseSpotterSettings *settings;

/**
 * @property audioSource
 * @abstract Аудиоисточник, который передает объекту класса `YSKPhraseSpotter` звук для распознавания.
 * @discussion Если аудиоисточник использует стандарный вход устройства, необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно.
 */
@property (nonatomic, strong, readonly) id<YSKAudioSource> audioSource;

/**
 * @abstract Инициализирует объект класса `YSKPhraseSpotter` с указанными настройками.
 * @discussion В качестве источника звука будет использоваться `YSKAutoAudioSource`. Для его работы необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно.
 * @param settings Настройки объекта класса `YSKPhraseSpotter`.
 * @return Объект класса `YSKPhraseSpotter`.
 */
- (instancetype)initWithSettings:(YSKPhraseSpotterSettings *)settings;

/**
 * @abstract Инициализирует объект класса `YSKPhraseSpotter` с указанными настройками и аудиоисточником.
 * @discussion Если аудиоисточник использует стандарный вход устройства, необходимо правильно настроить аудиосессию приложения с помощью класса `YSKAudioSessionHandler` или самостоятельно. Этот метод является `designated initializer` для класса `YSKPhraseSpotter`.
 @param settings Настройки объекта класса `YSKPhraseSpotter`.
 @param audioSource Аудиоисточник, который передает объекту класса `YSKPhraseSpotter` звук для распознавания.
 @return Объект класса `YSKPhraseSpotter`.
 */
- (instancetype)initWithSettings:(YSKPhraseSpotterSettings *)settings audioSource:(id<YSKAudioSource>)audioSource NS_DESIGNATED_INITIALIZER;

+ (instancetype) new __attribute__((unavailable("Use designated initializer -initWithSettings:audioSource: instead.")));
- (instancetype) init __attribute__((unavailable("Use designated initializer -initWithSettings:audioSource: instead.")));

/**
 * @abstract Подготавливает объект класса `YSKPhraseSpotter` к распознаванию фраз из модели для голосовой активации.
 * @discussion Заранее выполняет подготовку к распознаванию речи. Если метод не вызван явно, он автоматически вызывается в методе -[YSKPhraseSpotter start]. Метод выполняется асинхронно.
 * @discussion Рекомендуется вызывать данный метод до запуска объекта класса `YSKPhraseSpotter`.
 */
- (void)prepare;

/**
 * @abstract Запускает объект класса `YSKPhraseSpotter`.
 * @discussion Метод выполняется асинхронно, в момент начала записи вызывается callback-метод -[YSKPhraseSpotterDelegate phraseSpotterDidStarted:].
 */
- (void)start;

/**
 * @abstract Останавливает объект класса `YSKPhraseSpotter`.
 * @discussion Метод выполняется синхронно.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
