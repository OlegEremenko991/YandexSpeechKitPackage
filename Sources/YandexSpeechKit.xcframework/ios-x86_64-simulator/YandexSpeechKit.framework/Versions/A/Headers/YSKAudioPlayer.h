//
//  YSKAudioPlayer.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import <Foundation/Foundation.h>
#import "YSKDispatchableDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YSKSoundBuffer;
@protocol YSKAudioPlayerDelegate;

__attribute__((objc_subclassing_restricted))

/**
 * @abstract Плеер для проигрывания фрагсентов звука.
 * @discussion Плеер выполняет настройку своих компонентов как только он получит первый фрагмент звука. Компоненты настраиваются согласно `soundInfo`, это означает, что один экземпляр плеера может проигрывать аудиофайл, фрагменты которого имеют одинаковый формат (`soundInfo`).
 */
@interface YSKAudioPlayer : NSObject

/**
 * @property delegate
 * @abstract Делегат, который будет получать уведомления об изменении состояния плеера.
 */
@property (nonatomic, weak, nullable) id<YSKAudioPlayerDelegate> delegate;

/**
 * @abstract Признак того, что плеер находится в состоянии проигрывания звуков.
 */
@property (nonatomic, assign, readonly) BOOL playing;

/**
 * @abstract Проигрывает буфер целиком.
 * @discussion По окончании проигрывания переданного буфера плеер завершит свою работу. Вызов метода `finish` не требуется.
 @param buffer Аудио буфер.
 */
- (void)play:(YSKSoundBuffer *)buffer;

/**
 * @abstract Проигрывает фрагмент звука.
 * @discussion По окончании проигрывания переданного буфера плеер перейдет к проигрыванию следующего фрагмента звука. Как только все данные будут отправлены в очередь плеера, необходимо вызвать метод -[YSKAudioPlayer finish].
 * @param buffer Аудиобуфер.
 */
- (void)playChunk:(YSKSoundBuffer *)buffer;

/**
 * @abstract Метод сообщает плееру о том, что данные закончились, и как только все полученные ранее данные будут проиграны, можно завершать работу.
 * @warning Этот метод обязательно должен быть вызван, если данные для проигрывания закончились. Иначе плеер будет бесконечно отправлять на проигрывание пустой буфер (тишину).
 */
- (void)finish;

/**
 * @abstract Принудительно завершает проигрывание.
 */
- (void)cancel;

@end

@protocol YSKAudioPlayerDelegate <YSKDispatchableDelegate>
- (void)audioPlayerDidStartPlaying:(YSKAudioPlayer *)player;
- (void)audioPlayerDidFinishPlaying:(YSKAudioPlayer *)player;
- (void)audioPlayer:(YSKAudioPlayer *)player didFailWithError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
