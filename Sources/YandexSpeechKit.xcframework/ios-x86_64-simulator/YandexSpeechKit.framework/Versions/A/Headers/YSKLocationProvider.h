//
// YSKLocationProvider.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Alexander Panin <agpanin@yandex-team.ru>
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

/**
 * @abstract Протокол для доступа к геолокации.
 * @discussion Информация о текущем положении пользователя может быть использована для определения наиболее вероятных гипотез, например, при использовании языковой модели -[YSKOnlineModel maps].
 */
@protocol YSKLocationProvider<NSObject>

/**
 * @abstract Возвращает текущие координаты местоположения пользователя.
 * @return Текущие координаты местоположения пользователя.
 */
- (nullable CLLocation*)getLocation;

@end
