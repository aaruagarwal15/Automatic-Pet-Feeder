#include <Servo.h>
#include <NewPing.h>

Servo myservo,mservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int pos = 0;    // variable to store the servo position
int i = 0;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  mservo.attach(10);
  
}

void loop() 
{   Serial.println(" ");
    int b=sonar.ping_cm();
    delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.println("Ping: ");
  Serial.println(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  while(i<1){
  for (pos =180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  for (pos =0; pos <=180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  i = i+1;
  }
  while(i<1){
  for (pos =180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    mservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  for (pos =0; pos <=180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    mservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  i = i+1;
  }
}

