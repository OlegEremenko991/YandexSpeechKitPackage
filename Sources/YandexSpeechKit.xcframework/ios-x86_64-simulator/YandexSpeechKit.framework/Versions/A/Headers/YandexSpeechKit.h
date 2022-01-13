//
// YandexSpeechKit.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2018 Yandex, LLC. All rights reserved.
//
// Author: Anastasia Kononova <a-kononova@yandex-team.ru>
//

#import "YSKSpeechKit.h"
#import "YSKError.h"
#import "YSKLocationProvider.h"
#import "YSKPhraseSpotter.h"
#import "YSKPhraseSpotterDelegate.h"
#import "YSKRecognition.h"
#import "YSKRecognitionHypothesis.h"
#import "YSKRecognitionWord.h"
#import "YSKOnlineRecognizer.h"
#import "YSKRecognizerDelegate.h"
#import "YSKOnlineVocalizer.h"
#import "YSKOnlineVocalizerSettings.h"
#import "YSKVocalizerDelegate.h"
#import "YSKDialogSkin.h"
#import "YSKLightDialogSkin.h"
#import "YSKDarkDialogSkin.h"
#import "YSKRecognizerDialogController.h"
#import "YSKSynthesis.h"
#import "YSKSoundBuffer.h"
#import "YSKOnlineRecognizerSettings.h"
#import "YSKPhraseSpotterSettings.h"
#import "YSKSetting.h"
#import "YSKLanguage.h"
#import "YSKEmotion.h"
#import "YSKOnlineModel.h"
#import "YSKOtherAudioPolicy.h"
#import "YSKSoundFormat.h"
#import "YSKVoice.h"
#import "YSKAudioSource.h"
#import "YSKAudioSourceListener.h"
#import "YSKBaseAudioSource.h"
#import "YSKAutoAudioSource.h"
#import "YSKManualAudioSource.h"
#import "YSKAudioSessionHandler.h"
#import "YSKAudioSessionSettings.h"
#import "YSKAudioSourceSettings.h"
#import "YSKSoundQuality.h"
#import "YSKRecognizing.h"
#import "YSKVocalizing.h"
#import "YSKDispatchableDelegate.h"
#import "YSKBiometry.h"
#import "YSKLanguageScore.h"
#import "YSKUniProxySession.h"
#import "YSKAudioProcessingMode.h"
#import "YSKEchoCancellingAudioSource.h"
#import "YSKMutingAudioSource.h"
#import "YSKEventLogger.h"
#import "YSKIdentificationRequest.h"
#import "YSKIdentificationRequestDelegate.h"
#import "YSKIdentificationRequestSettings.h"
#import "YSKRegistrationRequest.h"
#import "YSKRegistrationRequestDelegate.h"
#import "YSKRegistrationRequestSettings.h"
#import "YSKRecognizerDialogEarcons.h"
#import "YSKDefaultEarconsBundle.h"
#import "YSKRecognizerProxy.h"
#import "YSKTrack.h"
#import "YSKNativeRecognizer.h"
#import "YSKNativeRecognizerSettings.h"