#include <Servo.h>

static const int servoPin = 4;
const int trigPin = 5 ;
const int echoPin = 18 ;
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
long duration;
float distance;//distance en cm
Servo servo1;

void setup() {
    Serial.begin(115200);// Starts the serial communication
    servo1.attach(
        servoPin, 
        Servo::CHANNEL_NOT_ATTACHED,0,180
    );
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input    
}

void loop() {
  
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo1.write(posDegrees);
        Serial.print("La position en degre: ");
        Serial.println(posDegrees);
        delayMicroseconds(5);
        distance = calculateDistance();
        
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        servo1.write(posDegrees);
        Serial.print("La position en degre: ");
        Serial.println(posDegrees);
        delayMicroseconds(5);
        distance = calculateDistance();
        
    }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
distance= duration*SOUND_SPEED/2;

// Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distance);
 
delayMicroseconds(5);

return distance;
}
