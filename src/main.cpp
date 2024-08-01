#include <Arduino.h>
#include <yboard.h>

#include "cyber.h"

void setup()
{
    Serial.begin(115200);
    Yboard.setup();
    cyber_init();
}

void loop()
{
    cyber_loop();
}
