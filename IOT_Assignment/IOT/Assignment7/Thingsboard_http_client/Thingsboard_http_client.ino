
#include<WiFi.h>
#include<HTTPClient.h>

const char *ssid = "$dvd$";
const char *password = "dvd12345";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.flush();

  pinMode(A0, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to a WiFi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("\n WiFi is connected");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

  float value = random(200, 300) / 10.0;
  String body = "{\"temperature\":" + String(value) + "}";

  HTTPClient httpClient;
  WiFiClient wifiClient;
  httpClient.begin(wifiClient, "http://thingsboard.cloud/api/v1/zgswz7sju2JT14Z8d5dy/telemetry");
  httpClient.addHeader("Content-type", "application/JSON");

  int status = httpClient.POST(body);
  Serial.printf("Status : %d\n", status);

  delay(2000);
}



