// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// @dart=2.9

part of 'firebase_ml_vision.dart';

void textRecognizerTests() {
  FirebaseVisionImage visionImage;

  setUp(() async {
    final tmpFilename = await _loadImage('assets/test_text.png');
    visionImage = FirebaseVisionImage.fromFilePath(tmpFilename);
  });

  group('$TextRecognizer', () {
    final recognizer = FirebaseVision.instance.textRecognizer();

    test('processImage', () async {
      final text = await recognizer.processImage(visionImage);

      expect(text.text, 'TEXT');
    });

    test('close', () {
      expect(recognizer.close(), completes);
    });
  });
}
