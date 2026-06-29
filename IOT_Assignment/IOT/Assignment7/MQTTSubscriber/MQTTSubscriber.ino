#include<WiFi.h>
#include<ArduinoMqttClient.h>

#define LED_PIN   2

const char *ssid = "SUNBEAM";
const char *password = "sunbeam";

const char *host = "172.18.3.2";
const int port = 1883;
const char *topic = "toggle/led";

WiFiClient wifiClient;
MqttClient subscriber(wifiClient);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nConnected to WiFi");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  subscriber.connect(host, port);
  Serial.println("Connected to the broker !!!");

  subscriber.subscribe(topic);

  Serial.printf("%s is subscribed\n", topic);

}

void loop() {
  int size = subscriber.parseMessage();
  if(size != 0)
  {
    char str[size + 1];
    int i;
    for(i = 0 ; i < size ; i++)
      str[i] = (char)subscriber.read();
    str[i] = '\0';

    Serial.printf("Received msg = %s\n", str);  

    if(strcmp(str, "ON") == 0){
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED is turned ON");
    }else if(strcmp(str, "OFF") == 0){
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED is turned OFF");
    }

  }

  delay(5000);

}











