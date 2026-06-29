
#include<AdafruitIO_WiFi.h>

#define IO_USERNAME   "praptidhote"
#define IO_KEY    "aio_VVTW25uRoexhBpWPr4806CHChXlT"

#define WIFI_SSID     "$dvd$"
#define WIFI_PASSWORD "dvd12345"

#define LED_PIN   2

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASSWORD);

AdafruitIO_Feed *ledFeed = io.feed("led");
AdafruitIO_Feed *tempFeed = io.feed("lm35");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  Serial.print("Connecting to AdaFruit");
  io.connect();

  ledFeed->onMessage(handleLED);

  while(io.status() != AIO_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to AdaFruit");
}

void loop() {
  // put your main code here, to run repeatedly:
  // to keep the connection alive and process incoming packets
  io.run();

  float temp = random(200, 350) / 10.0;

  Serial.printf("Sending Temperature = %f\n", temp);

   tempFeed->save(temp);

   delay(10000);

}
void handleLED(AdafruitIO_Data *data)
{
  if(data->toString() == "ON"){
    digitalWrite(LED_PIN, LOW);
  }else if(data->toString() == "OFF"){
    digitalWrite(LED_PIN, HIGH);
  }
}





