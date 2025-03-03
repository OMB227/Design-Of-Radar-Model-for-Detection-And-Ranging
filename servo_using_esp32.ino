#include <Servo.h>

/*
 * Description:
 * Example for setting the minimal and maximal angle.
 * 
 * servo simple project with esp32 for Arduino IDE
 * The interface is similar to arduino/servo but the attach() function is slightly different
 * bool attach(
    int pin,
    int channel = CHANNEL_NOT_ATTACHED,
    int minAngle = MIN_ANGLE,
    int maxAngle = MAX_ANGLE,
    int minPulseWidth = MIN_PULSE_WIDTH,
    int maxPulseWidth = MAX_PULSE_WIDTH
);

 */

static const int servoPin = 4;

Servo servo1;

void setup() {
    Serial.begin(115200);
    servo1.attach(
        servoPin, 
        Servo::CHANNEL_NOT_ATTACHED, 
        45,
        120
    );
}

void loop() {
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(10);
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(10);
    }
}
/*project modified by Eng moussa Bola Oumarou

 */
