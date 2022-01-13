//
// YSKOtherAudioPolicy.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Класс указывает поведение компоненты, если аудиопоток занят другим приложением.
 * @discussion Эта настройка задается с помощью метода -[YSKAudioSessionSettings otherAudioPolicy] класса `YSKAudioSessionSettings`, который используется `YSKAudioSessionHandler` для настройки аудиосессии.
 * @warning Если вы настраиваете аудиосессию самостоятельно, то для этой настройки необходимо использовать метод системного класса -[AVAudioSession setCategory:withOptions:].
 */

__attribute__((objc_subclassing_restricted))

@interface YSKOtherAudioPolicy : YSKSetting

/**
 * @abstract Прерывает аудиопоток другого приложения.
 * @return Объект класса `YSKOtherAudioPolicy`, который соответствует выбранной настройке.
*/
+ (instancetype)interruptOther;

/**
 * @abstract Игнорирует работу другого приложения и смешивает аудиопотоки.
 * @discussion Соответствует категории `AVAudioSessionCategoryOptionMixWithOthers`.
 * @return Объект класса `YSKOtherAudioPolicy`, который соответствует выбранной настройке.
 */
+ (instancetype)ignoreOther;

@end

NS_ASSUME_NONNULL_END
