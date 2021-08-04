#include <Arduino.h>
#include <CircuitOS.h>
#include <Nibble.h>

Display* display;
Sprite* sprite;

void BTN_LEFT_press() {
  if (PX < 120) {
    PX += 1;
  }
}

void BTN_RIGHT_press() {
  if (PX > 8) {
    PX += -1;
  }
}

void setup() {
  Nibble.begin();
  display = Nibble.getDisplay();
  sprite = display->getBaseSprite();
  Input::getInstance()->setBtnPressCallBack(BTN_LEFT, BTN_LEFT_press);
  Input::getInstance()->setBtnPressCallBack(BTN_RIGHT, BTN_RIGHT_press);

}
void loop() {
  Input::getInstance()->loop(0);
  
  sprite->fillRect(PX, PY, 25, 25, TFT_LIGHTGREY);
  display->commit();
  
}
