// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <Flutter/Flutter.h>

#import "Firebase/Firebase.h"

@import MLKitVision;

@interface FLTFirebaseMlVisionPlugin : NSObject <FlutterPlugin>
+ (void)handleError:(NSError *)error result:(FlutterResult)result;
@end

@protocol Detector
@required
- (instancetype)initWithOptions:(NSDictionary *)options;
- (void)handleDetection:(MLKVisionImage *)image result:(FlutterResult)result;
@optional
@end

@interface BarcodeDetector : NSObject <Detector>
@end

@interface FaceDetector : NSObject <Detector>
@end

@interface ImageLabeler : NSObject <Detector>
@end

@interface TextRecognizer : NSObject <Detector>
@end
