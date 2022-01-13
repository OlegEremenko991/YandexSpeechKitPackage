//
// YSKUniProxySession.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @abstract Объект сессии хранит в себе подключение к серверу и предоставляет его для созданных запросов.
 * @discussion Класс `YSKUniProxySession` дает возможность использовать одно сетевое соединение для нескольких компонентов библиотеки. Это позволяет не тратить время на повторную установку соединения и выполнять все запросы в рамках одной сессии. Для этого необходимо создать один объект класса `YSKUniProxySession` и передавать его в конструкторы тех компонентов, которые вы хотите объединить в одну сессию. Если вы работаете только с одной компонентой, то вы можете использовать конструктор с сессией по умолчанию, тогда она будет создана автоматически внутри компоненты с необходимыми параметрами.
 */
@interface YSKUniProxySession : NSObject

/**
 * @property url
 * @abstract Адрес сервера.
 */
@property (nonatomic, copy, readonly) NSURL *url;

/**
 * @abstract Инициализирует объект класса `YSKUniProxySession` с адресом по умолчанию.
 * @return Объект класса `YSKUniProxySession`.
 */
- (instancetype)init;

/**
 * @abstract Инициализирует объект класса `YSKUniProxySession` с заданным адресом сервера.
 * @param url Адрес сервера.
 * @return Объект класса `YSKUniProxySession`.
 */
- (instancetype)initWithURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
