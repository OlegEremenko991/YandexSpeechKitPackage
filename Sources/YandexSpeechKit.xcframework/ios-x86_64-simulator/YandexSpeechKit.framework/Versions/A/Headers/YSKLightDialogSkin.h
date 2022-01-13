//
// YSKLightDialogSkin.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import "YSKDialogSkin.h"

/**
 * @abstract Реализация протокола `YSKDialogSkin`, которая задает светлую тему диалога `YSKRecognizerDialogController`.
 * @discussion Наследование от данного класса запрещено. Если необходимо изменить какие-либо настройки схемы, создайте свой объект, который реализует протокол `YSKDialogSkin`.
 */

__attribute__((objc_subclassing_restricted))

@interface YSKLightDialogSkin : NSObject<YSKDialogSkin>

@end
