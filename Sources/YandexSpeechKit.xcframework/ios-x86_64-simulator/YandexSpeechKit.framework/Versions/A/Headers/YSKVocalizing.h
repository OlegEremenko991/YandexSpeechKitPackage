//
// YSKVocalizing.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>

/**
 * @defgroup ysk_text_synthesizing_mode_global_enums Перечисления YSKTextSynthesizingMode
 * @ingroup global_enums
 * Константы определяют поведение объекта класса `YSKOnlineVocalizer` при старте синетеза речи, если запущенный ранее процесс синтеза не был завершен.
 */
//@{
typedef NS_ENUM(NSInteger, YSKTextSynthesizingMode) {
    
    /**
     * @abstract Добавляет новый текст к синтезируемому.
     */
    YSKTextSynthesizingModeAppend,
    
    /**
     * @abstract Прерывает текущий процесс синтеза речи и начинает его заново с новым текстом.
     */
    YSKTextSynthesizingModeInterrupt
};
//@}

@protocol YSKVocalizerDelegate;

/**
 * @abstract Протокол описывает интерфейс объекта, который синтезирует речь из текста и озвучивает ее.
 */
@protocol YSKVocalizing <NSObject>

/**
 * @property delegate
 * @abstract Делегат для отслеживания событий синтеза речи.
 */
@property (nonatomic, weak, nullable) id<YSKVocalizerDelegate> delegate;

/**
 * @abstract Подготавливает объект класса, реализующий протокол `YSKVocalizing`, к синтезу речи.
 * @discussion Заранее выполняет подготовку к синтезу речи. Если метод не вызван явно, он автоматически вызывается в методе -[YSKVocalizing synthesize:mode:]. Метод выполняется асинхронно.
 */
- (void)prepare;

/**
 * @abstract Запускает синтез речи из текста.
 * @discussion Может быть вызван многократно для одного объекта класса, реализующего протокол `YSKVocalizing`. Если синтез речи не был завершен на момент повторного вызова метода, то поведение объекта будет определяться параметром `mode`. Метод выполняется асинхронно.
 * @param text Текст для синтеза.
 * @param mode Поведение объекта класса, реализующего протокол `YSKVocalizing`, если запущенный ранее процесс синтеза не был завершен.
 */
- (void)synthesize:(nonnull NSString *)text mode:(YSKTextSynthesizingMode)mode;

/**
 * @abstract Запускает проигрывание синтезированной речи.
 */
- (void)play;

/**
 * @abstract Прерывает процесс синтеза речи.
 */
- (void)cancel;

@end
