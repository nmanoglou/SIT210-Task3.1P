// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

//Constants
#define DHTPIN 6     // what pin we're connected to
#define DHTTYPE DHT22    

 

DHT dht(DHTPIN, DHTTYPE);


//Variables
int led = D7;
float temp_float;

void setup()
{
    pinMode(led, OUTPUT);
    dht.begin();
}

void loop()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    temp_float= dht.getTempCelcius();
    //Print temp and humidity values to serial monitor
    String temp_string = String(temp_float);
    Particle.publish("temp", temp_string, PRIVATE);
    delay(30000); 
}