//
// YSKDispatchableDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

/**
 * @abstract Базовый протокол для делегатов, которые отслеживают события основных компонентов библиотеки.
 * @discussion Протокол позволяет задать очередь, в которую будут приходить все callback-методы делегата.
 */
@protocol YSKDispatchableDelegate <NSObject>

@optional
/**
 * @property callbackQueue
 * @abstract Очередь, в которую будут приходить callback-и делегата.
 * @discussion Если это свойство не задано, или его значение равно `nil`, все callback-методы будут приходить в main-очередь.
 */
@property (nonatomic, strong, readonly, nullable) dispatch_queue_t callbackQueue;

@end
