//
// YSKOnlineModel.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import "YSKSetting.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Языковые модели для online-распознавания.
 */
@interface YSKOnlineModel : YSKSetting

/**
 * @abstract Создает языковую модель «Заказы» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания фраз, связанных с оформлением заказов в интернет-магазинах (подтверждение и форма доставки).
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)buying;

/**
 * @abstract Создает языковую модель «Даты» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания названий месяцев, порядковых и количественных числительных.
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)dates;

/**
 * @abstract Создает языковую модель «Адреса» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания географических названий, адресов.
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)maps;

/**
 * @abstract Создает языковую модель «Музыка» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания запросов на музыкальную тематику.
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)music;

/**
 * @abstract Создает языковую модель «Имена» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания имен и фамилий (например, в просьбе соединить по телефону).
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)names;

/**
 * @abstract Создает языковую модель «Тексты» (объект класса `YSKOnlineModel`).
 * @discussion Модель для свободной диктовки коротких текстов, например, SMS, заметок, комментариев.
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)notes;

/**
 * @abstract Создает языковую модель «Числа» (объект класса `YSKOnlineModel`).
 * @discussion Модель для количественных числительных от 1 до 999 и разделителей — точка, запятая, тире. Модель подходит для диктовки номеров телефонов, счетов, документов.
 @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)numbers;

/**
 * @abstract Создает языковую модель «Короткие запросы» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания общих поисковых запросов и коротких фраз (3—5 слов) на различную тематику.
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)queries;

/**
 * @abstract Создает языковую модель «Диалог» (объект класса `YSKOnlineModel`).
 * @discussion Модель для распознавания фраз в диалоге.
 * @return Объект класса `YSKOnlineModel`, который соответствует выбранному типу модели.
 */
+ (instancetype)dialog;

@end

NS_ASSUME_NONNULL_END
