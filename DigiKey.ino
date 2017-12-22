/*
   Copyright (c) 2017 Edward-P
   Email: micro.fedora@gmail.com
   Website: https://edward-p.ml

   This file is part of DigiKey.

   DigiKey is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "DigiKeyboard.h"
#include "OneButton.h"

#define BUTTON_PIN 0 //pin to trigger button actions
#define LED_PIN 1

//to set voltage level to HIGH when button pushed down(just uncomment the below)
//#define ACTIVE_HIGH

//set up buttons
#ifdef ACTIVE_HIGH
OneButton button(BUTTON_PIN, 0);
#else
OneButton button(BUTTON_PIN, 1);
#endif

//define passwords to be send by button behaviors
enum {CLICK, DOUBLE_CLICK, LONG_PRESS};
const String passwords[3] {
  "password1",
  "password2",
  "password3"
};

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // link the onClick function to be called on a click event.
  button.attachClick(onClick);
  // link the onDoubleclick function to be called on a doubleclick event.
  button.attachDoubleClick(onDoubleClick);
  // link the onLongPressStart function to be called when detected longpress event.
  button.attachLongPressStart(onLongPressStart);

  // set 80 msec. debouncing time. Default is 50 msec.
  button.setDebounceTicks(80);
}
// the loop routine runs over and over again forever:
void loop() {
  DigiKeyboard.update();
  // keep watching the push button:
  button.tick();
}


void blink3times() {
  int i;
  for (i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}
void onClick() {
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println(passwords[CLICK]);
  blink3times();

}
void onDoubleClick() {
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println(passwords[DOUBLE_CLICK]);
  blink3times();
}
void onLongPressStart() {
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println(passwords[LONG_PRESS]);
  blink3times();
}
