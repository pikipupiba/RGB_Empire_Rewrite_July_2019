//#include "Display_Test.h"
//
//SSD_13XX* tft_test;
//
//void display_test(SSD_13XX& new_tft)
//{
//	tft_test = &new_tft;
//
//	for (uint8_t rotation = 0; rotation < 4; rotation++) {
//		tft_test->setRotation(rotation);
//		Serial.println(F("Benchmark                Time (microseconds)"));
//
//		Serial.print(F("Screen fill              "));
//		Serial.println(testFillScreen());
//		delay(200);
//
//		Serial.print(F("Text                     "));
//		Serial.println(testText());
//		delay(600);
//
//		Serial.print(F("Lines                    "));
//		Serial.println(testLines(CYAN));
//		delay(200);
//
//		Serial.print(F("Horiz/Vert Lines         "));
//		Serial.println(testFastLines(RED, BLUE));
//		delay(200);
//
//		Serial.print(F("Rectangles (outline)     "));
//		Serial.println(testRects(GREEN));
//		delay(200);
//
//		Serial.print(F("Rectangles (filled)      "));
//		Serial.println(testFilledRects(YELLOW, MAGENTA));
//		delay(200);
//
//		Serial.print(F("Circles (filled)         "));
//		Serial.println(testFilledCircles(10, MAGENTA));
//
//		Serial.print(F("Circles (outline)        "));
//		Serial.println(testCircles(10, WHITE));
//		delay(200);
//
//		Serial.print(F("Triangles (outline)      "));
//		Serial.println(testTriangles());
//		delay(200);
//
//		Serial.print(F("Triangles (filled)       "));
//		Serial.println(testFilledTriangles());
//		delay(200);
//
//		Serial.print(F("Rounded rects (outline)  "));
//		Serial.println(testRoundRects());
//		delay(200);
//
//		Serial.print(F("Rounded rects (filled)   "));
//		Serial.println(testFilledRoundRects());
//		delay(200);
//
//		Serial.println(F("Done!"));
//		delay(1000);
//	}
//}
//
//unsigned long testFillScreen() {
//	unsigned long start = micros();
//	tft_test->fillScreen(BLACK);
//	tft_test->fillScreen(RED);
//	tft_test->fillScreen(GREEN);
//	tft_test->fillScreen(BLUE);
//	tft_test->fillScreen(BLACK);
//	return micros() - start;
//}
//
//unsigned long testText() {
//	tft_test->clearScreen();
//	unsigned long start = micros();
//	tft_test->setCursor(0, 0);
//	tft_test->setTextColor(WHITE);  tft_test->setTextScale(1);
//	tft_test->println("Hello World!");
//	tft_test->setTextColor(YELLOW); tft_test->setTextScale(2);
//	tft_test->println(1234.56);
//	tft_test->setTextColor(RED);    tft_test->setTextScale(3);
//	tft_test->println(0xDEADBEEF, HEX);
//	tft_test->println();
//	tft_test->setTextColor(GREEN);
//	tft_test->setTextScale(5);
//	tft_test->println("Groop");
//	tft_test->setTextScale(2);
//	tft_test->println("I implore thee,");
//	tft_test->setTextScale(1);
//	tft_test->println("my foonting turlingdromes.");
//	tft_test->println("And hooptiously drangle me");
//	tft_test->println("with crinkly bindlewurdles,");
//	tft_test->println("Or I will rend thee");
//	tft_test->println("in the gobberwarts");
//	tft_test->println("with my blurglecruncheon,");
//	tft_test->println("see if I don't!");
//	return micros() - start;
//}
//
//unsigned long testLines(uint16_t color) {
//	unsigned long start, t;
//	int           x1, y1, x2, y2,
//		w = tft_test->width(),
//		h = tft_test->height();
//
//	tft_test->clearScreen();
//
//	x1 = y1 = 0;
//	y2 = h - 1;
//	start = micros();
//	for (x2 = 0; x2 < w; x2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	x2 = w - 1;
//	for (y2 = 0; y2 < h; y2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	t = micros() - start; // fillScreen doesn't count against timing
//
//	tft_test->clearScreen();
//
//	x1 = w - 1;
//	y1 = 0;
//	y2 = h - 1;
//	start = micros();
//	for (x2 = 0; x2 < w; x2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	x2 = 0;
//	for (y2 = 0; y2 < h; y2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	t += micros() - start;
//
//	tft_test->clearScreen();
//
//	x1 = 0;
//	y1 = h - 1;
//	y2 = 0;
//	start = micros();
//	for (x2 = 0; x2 < w; x2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	x2 = w - 1;
//	for (y2 = 0; y2 < h; y2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	t += micros() - start;
//
//	tft_test->clearScreen();
//
//	x1 = w - 1;
//	y1 = h - 1;
//	y2 = 0;
//	start = micros();
//	for (x2 = 0; x2 < w; x2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//	x2 = 0;
//	for (y2 = 0; y2 < h; y2 += 6) tft_test->drawLine(x1, y1, x2, y2, color);
//
//	return micros() - start;
//}
//
//unsigned long testFastLines(uint16_t color1, uint16_t color2) {
//	unsigned long start;
//	int           x, y, w = tft_test->width(), h = tft_test->height();
//
//	tft_test->clearScreen();
//	start = micros();
//	for (y = 0; y < h; y += 5) tft_test->drawFastHLine(0, y, w, color1);
//	for (x = 0; x < w; x += 5) tft_test->drawFastVLine(x, 0, h, color2);
//
//	return micros() - start;
//}
//
//unsigned long testRects(uint16_t color) {
//	unsigned long start;
//	int           n, i, i2,
//		cx = tft_test->width() / 2,
//		cy = tft_test->height() / 2;
//
//	tft_test->clearScreen();
//	n = min(tft_test->width(), tft_test->height());
//	start = micros();
//	for (i = 2; i < n; i += 6) {
//		i2 = i / 2;
//		tft_test->drawRect(cx - i2, cy - i2, i, i, color);
//	}
//
//	return micros() - start;
//}
//
//unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
//	unsigned long start, t = 0;
//	int           n, i, i2,
//		cx = tft_test->width() / 2 - 1,
//		cy = tft_test->height() / 2 - 1;
//
//	tft_test->clearScreen();
//	n = min(tft_test->width(), tft_test->height());
//	for (i = n; i > 0; i -= 6) {
//		i2 = i / 2;
//		start = micros();
//		tft_test->fillRect(cx - i2, cy - i2, i, i, color1);
//		t += micros() - start;
//		// Outlines are not included in timing results
//		tft_test->drawRect(cx - i2, cy - i2, i, i, color2);
//	}
//
//	return t;
//}
//
//unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
//	unsigned long start;
//	int x, y, w = tft_test->width(), h = tft_test->height(), r2 = radius * 2;
//
//	tft_test->clearScreen();
//	start = micros();
//	for (x = radius; x < w; x += r2) {
//		for (y = radius; y < h; y += r2) {
//			tft_test->fillCircle(x, y, radius, color);
//		}
//	}
//
//	return micros() - start;
//}
//
//unsigned long testCircles(uint8_t radius, uint16_t color) {
//	unsigned long start;
//	int           x, y, r2 = radius * 2,
//		w = tft_test->width() + radius,
//		h = tft_test->height() + radius;
//
//	// Screen is not cleared for this one -- this is
//	// intentional and does not affect the reported time.
//	start = micros();
//	for (x = 0; x < w; x += r2) {
//		for (y = 0; y < h; y += r2) {
//			tft_test->drawCircle(x, y, radius, color);
//		}
//	}
//
//	return micros() - start;
//}
//
//unsigned long testTriangles() {
//	unsigned long start;
//	int           n, i, cx = tft_test->width() / 2 - 1,
//		cy = tft_test->height() / 2 - 1;
//
//	tft_test->clearScreen();
//	n = min(cx, cy);
//	start = micros();
//	for (i = 0; i < n; i += 5) {
//		tft_test->drawTriangle(
//			cx, cy - i, // peak
//			cx - i, cy + i, // bottom left
//			cx + i, cy + i, // bottom right
//			tft_test->Color565(0, 0, i));
//	}
//
//	return micros() - start;
//}
//
//unsigned long testFilledTriangles() {
//	unsigned long start, t = 0;
//	int           i, cx = tft_test->width() / 2 - 1,
//		cy = tft_test->height() / 2 - 1;
//
//	tft_test->clearScreen();
//	start = micros();
//	for (i = min(cx, cy); i > 10; i -= 5) {
//		start = micros();
//		tft_test->fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
//			tft_test->Color565(0, i, i));
//		t += micros() - start;
//		tft_test->drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
//			tft_test->Color565(i, i, 0));
//	}
//
//	return t;
//}
//
//unsigned long testRoundRects() {
//	unsigned long start;
//	int           w, i, i2,
//		cx = tft_test->width() / 2 - 1,
//		cy = tft_test->height() / 2 - 1;
//
//	tft_test->clearScreen();
//	w = min(tft_test->width(), tft_test->height());
//	start = micros();
//	for (i = 0; i < w; i += 6) {
//		i2 = i / 2;
//		tft_test->drawRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_test->Color565(i, 0, 0));
//	}
//
//	return micros() - start;
//}
//
//unsigned long testFilledRoundRects() {
//	unsigned long start;
//	int           i, i2,
//		cx = tft_test->width() / 2 - 1,
//		cy = tft_test->height() / 2 - 1;
//
//	tft_test->clearScreen();
//	start = micros();
//	for (i = min(tft_test->width(), tft_test->height()); i > 20; i -= 6) {
//		i2 = i / 2;
//		tft_test->fillRoundRect(cx - i2, cy - i2, i, i, i / 8, tft_test->Color565(0, i, 0));
//	}
//
//	return micros() - start;
//}