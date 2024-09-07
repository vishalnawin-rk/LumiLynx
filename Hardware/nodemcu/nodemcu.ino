#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

const char* ssid = "Redmi Note 9 Pro";
const char* password = "MIHAWK123";

const char* serverAddress = "http://192.168.254.20:8080/api/data/update";

#define value A0
const int ldrPin1 = D0;
const int ldrPin2 = D5;
const int ldrPin3 = D6;
const int ldrPin4 = D4;

int sendToDb[4];

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(value, INPUT);
  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
  pinMode(ldrPin4, INPUT);

  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void loop() {

  int ldrStatus1 = digitalRead(ldrPin1);
  int ldrStatus2 = digitalRead(ldrPin2);
  int ldrStatus3 = digitalRead(ldrPin3);
  int ldrStatus4 = digitalRead(ldrPin4);

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient wifiClient;
    HTTPClient http;
    http.begin(wifiClient, serverAddress);
    Serial.println("WiFi Connected...");
    float voltage = analogRead(A0) * (3.3 / 25.0);
    lcd.setCursor(0, 0);
    lcd.print("Current :");
    lcd.setCursor(10, 0);
    lcd.print(voltage / 10.0);
    lcd.setCursor(15, 0
    );
    lcd.print("A");

    memset(sendToDb, 0, sizeof(sendToDb));

    if (ldrStatus1 == 1) sendToDb[0] = 1;
    if (ldrStatus2 == 1) sendToDb[1] = 2;
    if (ldrStatus3 == 1) sendToDb[2] = 3;
    if (ldrStatus4 == 1) sendToDb[3] = 4;

    String jsonData = "{\"ldrStatus1\": " + String(sendToDb[0]) +
                      ", \"ldrStatus2\": " + String(sendToDb[1]) +
                      ", \"ldrStatus3\": " + String(sendToDb[2]) +
                      ", \"ldrStatus4\": " + String(sendToDb[3]) + "}";

    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.PATCH(jsonData);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String response = http.getString();
      Serial.println(response);
    } 

    http.end();
  }
  delay(5000);
  lcd.clear();
}

