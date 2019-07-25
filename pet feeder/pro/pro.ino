/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi

 */

#include <SPI.h>
#include<Servo.h>
#include<NewPing.h>
#include <Ethernet.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 7
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo, mservo;

int pos=0;
int k=0;;
int q=0;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 137, 2);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  myservo.attach(9);
  mservo.attach(3);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    char d;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if(c!='\n')
        d=c;
      }
    }
        /*char a[100];
        int p=0;
        for(int i=0;i<100;i++)
        {  a[i]=c;
        }
        int b=strlen(a);
        for(int i=0;i<b;i++)
        { if(a[i]=='\n')
         {p=a[i-1];
        
         }
        }
        */
        Serial.print("option selected : ");
        Serial.println(d);
        if(d=='1')
        {analogWrite(5,130);
        analogWrite(6,0);
        int b=sonar.ping_cm();
        delay(50);
        Serial.println("ping:");
        Serial.println(b);
        Serial.println("cm");
        if(b<60)
        {client.println("DOG IS HERE");
        }
        while(k<1)
        {for(pos=0;pos<=180;pos++)
        {myservo.write(pos);
        delay(15);
        }
        delay(2000);
         for(pos=180;pos>=0;pos--)
        {myservo.write(pos);
        delay(15);
        }
        k=k+1;
        }
        client.println("food given to dog");
       while(q<1)
        {for(pos=0;pos<=180;pos++)
        {myservo.write(pos);
        delay(15);
        }
        delay(2000);
         for(pos=180;pos>=0;pos--)
        {myservo.write(pos);
        delay(15);
        }
        q=q+1;
        }
        client.println("water given to dog");
        }
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
      /*  if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          client.println("</html>");
          break;*/
       // }
       /* if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }*/
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
