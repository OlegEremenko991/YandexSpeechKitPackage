//
// YSKAudioSessionHandler.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YSKAudioSessionSettings;

__attribute__((objc_subclassing_restricted))

/**
* @abstract Настраивает аудиосессию приложения для записи и проигрывания звука.
 * @discussion Аудиосессия — это объект-синглтон. Аудиосессия настраивает аудиоконтекст приложения и позволяет ему взаимодействовать с другими приложениями, которые используют аудио. В приложении используется один объект аудиосессии, поэтому настройка и активация аудиосессии вынесена за пределы компонентов библиотеки `SpeechKit`. Объект аудиосессии можно получить с помощью метода -[YSKAudioSessionHandler sharedInstance]. Класс `YSKAudioSessionHandler` упрощает настройку аудиосессии:
 * - если ваше приложение использует аудиосессию только при работе с библиотекой `SpeechKit`, рекомендуется использовать этот класс для настройки аудиосессии;
 * - если ваше приложение использует аудиосессию вне библиотеки (проигрывание аудио или видео, запись звука и т. д.), вы также можете использовать этот класс или настроить аудиосессию самостоятельно.
 
* Чтобы установить необходимые настройки и активировать аудиосессию, надо вызвать метод -[YSKAudioSessionHandler activateAudioSession:] или -[YSKAudioSessionHandler activateAudioSessionWithSettings:error:] перед началом работы со звуком (то есть перед созданием аудиоисточника, если он использует стандартный вход устройства, или перед любой другой работой с аудио, которая будет выполняться в вашем приложении). Этот метод установит настройки и вызовет метод системного класса -[AVAudioSession setActive:error:]. Активация аудиосессии занимает достаточно продолжительное время и выполняется синхронно. Если в процессе настройки и активации произойдет ошибка, она будет возвращена в параметре `error`. По окончании работы со звуком аудиосессию нужно отключить с помощью метода -[YSKAudioSessionHandler deactivateAudioSession:].

 * @warning Если вы настраиваете аудиосессию самостоятельно, то для работы библиотеки `SpeechKit` установите в методе системного класса -[AVAudioSession setCategory:withOptions:error:] одну из следующих категорий: `AVAudioSessionCategoryPlayAndRecord`, `AVAudioSessionCategoryRecord` или `AVAudioSessionCategoryMultiRoute`.
 */
@interface YSKAudioSessionHandler : NSObject

/**
 * @property settings
 * @abstract Внешние настройки для аудиосессии.
 */
@property (nonatomic, copy, readonly, nullable) YSKAudioSessionSettings *settings;

/**
 * @abstract Возвращает общий объект класса `YSKAudioSessionHandler`.
 * @return Общий объект класса `YSKAudioSessionHandler`.
 */
+ (instancetype)sharedInstance;

+ (instancetype) new __attribute__((unavailable("Use +sharedInstance method instead.")));
- (instancetype) init __attribute__((unavailable("Use +sharedInstance method instead.")));

/**
 * @abstract Настраивает и активирует аудиосессию.
 * @discussion Этот метод необходимо вызывать перед началом работы с аудио (распознавание, голосовая активация, воспроизведение синтезированного звука). Он выполняется синхронно и может занимать достаточно продолжительное время.
 * @param error Ошибка, возникшая в процессе настройки и активации аудиосессии.
 * @return `YES`, если настройка и активация аудиосессии прошли успешно, `NO` — в остальных случаях.
 */
- (BOOL)activateAudioSession:(NSError * _Nullable *)error;

/**
 * @abstract Устанавливает переданные параметры, настраивает и активирует аудиосессию.
 * @discussion Этот метод необходимо вызывать перед началом работы с аудио (распознавание, голосовая активация, воспроизведение синтезированного звука). Он выполняется синхронно и может занимать достаточно продолжительное время.
 * @param settings Внешние параметры для аудиосессии.
 * @param error Ошибка, возникшая в процессе настройки и активации аудиосессии.
 * @return `YES`, если настройка и активация аудиосессии прошли успешно, `NO` — в остальных случаях.
 */
- (BOOL)activateAudioSessionWithSettings:(YSKAudioSessionSettings *)settings error:(NSError * _Nullable *)error;

/**
 * @abstract Останавливает работу аудиосессии.
 * @param error Ошибка, возникшая в процессе деактивации аудиосессии.
 * @return `YES`, если деактивация аудиосессии завершилась успешно, `NO` в остальных случаях.
 */
- (BOOL)deactivateAudioSession:(NSError * _Nullable *)error;

@end

NS_ASSUME_NONNULL_END
