
#include<AdafruitIO_WiFi.h>

#define IO_USERNAME   "praptidhote"
#define IO_KEY    "aio_VVTW25uRoexhBpWPr4806CHChXlT"

#define WIFI_SSID     "$dvd$"
#define WIFI_PASSWORD "dvd12345"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASSWORD);

AdafruitIO_Feed *tempFeed = io.feed("lm35");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Connecting to AdaFruit");
  io.connect();

  
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

   delay(5000);

}






