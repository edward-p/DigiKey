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


OneButton button(0, 0); //(pin,mode),mode:0-active with HIGH;1-active with LOW

void setup() {
  // initialize the digital pin as an output.
  pinMode(0, INPUT); //
  pinMode(1, OUTPUT);

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
    digitalWrite(1, HIGH);
    delay(100);
    digitalWrite(1, LOW);
    delay(100);
  }
}
void onClick() {
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("password1");
  blink3times();

}
void onDoubleClick() {
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("password2");
  blink3times();
}
void onLongPressStart() {
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("password3");
  blink3times();
}
