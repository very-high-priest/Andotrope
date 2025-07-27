#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <string.h>  // For memset
#include "image.h"

// Display 1 Pins
#define TFT_CS1  5
#define TFT_DC1  4
#define TFT_RST1 -1

// Display 2 Pins
#define TFT_CS2  6
#define TFT_DC2  7
#define TFT_RST2 -1
#define FRAMES 28
#define image_width 183
#define image_height 194

#define screen_width 240
#define screen_height 320

Adafruit_ST7789 tft1(TFT_CS1, TFT_DC1, TFT_RST1);
Adafruit_ST7789 tft2(TFT_CS2, TFT_DC2, TFT_RST2);

// Allocate RAM buffer (150KB)
uint16_t ramImage[screen_width * screen_height]; 

void drawFullscreen(Adafruit_ST7789 &tft) {
  tft.startWrite();
  tft.setAddrWindow(0, 0, screen_width, screen_height);
  tft.writePixels(ramImage, screen_width * screen_height);  // Block transfer
  tft.endWrite();
}

void setup() {
  // Configure SPI
  SPI.setSCK(2);
  SPI.setTX(3);
  SPI.begin();

  // Initialize displays
  tft1.init(screen_width, screen_height, SPI_MODE3);
  tft1.setSPISpeed(62500000);  // 62.5MHz (safe max for ST7789)
  tft1.setRotation(2);
  tft1.invertDisplay(false);  

  tft2.init(screen_width, screen_height, SPI_MODE3);
  tft2.setSPISpeed(62500000);
  tft2.setRotation(2);
  tft2.invertDisplay(false); 
  
  // Draw initial background
  tft1.fillScreen(0x0000);
  tft2.fillScreen(0x0000);
}

void loop() {
  static int i = 0;
  static unsigned long nextFrameTime = 0;

  // Initialize timing on first run
  if (nextFrameTime == 0) {
    nextFrameTime = millis();
  }

  // Wait until scheduled frame time
  unsigned long currentTime = millis();
  if (currentTime < nextFrameTime) {
    delay(nextFrameTime - currentTime);
  }

  // Clear buffer to black (0x0000)
  memset(ramImage, 0, sizeof(ramImage));

  // Calculate centering offsets
  int x_offset = (screen_width - image_width) / 2;  // 28px horizontal margin
  int y_offset = (screen_height - image_height) / 2; // 63px vertical margin

  // Copy image to center of buffer
  uint16_t* dest = ramImage + (y_offset * screen_width) + x_offset;
  const uint16_t* src = epd_bitmap_allArray[i];
  
  for (int row = 0; row < image_height; row++) {
    memcpy_P(dest, src, image_width * sizeof(uint16_t));
    dest += screen_width;  // Move to next display row
    src += image_width;    // Move to next image row
  }

  // Render to both displays
  drawFullscreen(tft1);
  drawFullscreen(tft2);

  // Update frame index
  i = (i + 1) % FRAMES;

  // Schedule next frame (alternate between 66/67ms for 15 FPS average)
  nextFrameTime += 66 + (i % 2);
}