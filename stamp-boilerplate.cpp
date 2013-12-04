/*
  Boilerplate Code for:
    Stamp: a 2D Sprite Library for Adafruit ST7735 for Arduino
  
  Ross Anderson & Andrew Bradshaw

*/
#include "Stamp.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    Serial.begin(9600);
    tft.initR(INITR_BLACKTAB);

    /*
      Setup SD Card
    */
    Serial.print("init'ing SD card..");
    if (!SD.begin(SD_CS)) {
        Serial.println("failed");
        return;
    }
    Serial.println("OK!");

    /*
      Hello World
    */
    // Create a layer
    abLayer layer5 = abLayer("bgyellow.lcd");
    
    // Add some sprites
    abSprite* h = layer5.addSprite("h.lcd", 0, 0);
    abSprite* e = layer5.addSprite("e.lcd", 15, 0);
    abSprite* l_1 = layer5.addSprite("l.lcd", 30, 0);
    abSprite* l_2 = layer5.addSprite("l.lcd", 45, 0);
    abSprite* o = layer5.addSprite("o.lcd", 60, 0);

    layer5.draw(&tft);
    while (true) {
      h->moveDown(12);
      e->moveDown(9);
      l_1->moveDown(6);
      l_2->moveDown(3);
      o->moveDown(0);
      layer5.draw(&tft);

      h->moveUp(12);
      e->moveUp(9);
      l_1->moveUp(6);
      l_2->moveUp(3);
      o->moveUp(0);
      layer5.draw(&tft);
    }

}

void loop() {}
