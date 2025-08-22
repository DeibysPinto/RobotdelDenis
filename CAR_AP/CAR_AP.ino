#include "camara.h"
#include "motores.h"
#include "wifi_ap.h"
#include "web.h"

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

const char* ssid = "ESP32CAM";
const char* password = "12345678";

const int ServoPin = 2;

void initServo() {
  ledcSetup(8, 50, 16); // 50 Hz PWM, 16-bit resolution
  ledcAttachPin(ServoPin, 8);
}

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); // evitar brownouts

  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  configurarCamara();     // módulo camara.cpp
  initMotors();           // módulo motores.cpp
  initServo();            // función local

  ledcSetup(7, 5000, 8);  // canal para LED
  ledcAttachPin(4, 7);    // pin 4 como LED

  WiFi.softAP(ssid, password);
  IPAddress miIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(miIP);

  startCameraServer();    // módulo web.cpp

  for (int i = 0; i < 5; i++) {
    ledcWrite(7, 10); // parpadeo LED
    delay(50);
    ledcWrite(7, 0);
    delay(50);
  }
}

void loop() {
  delay(1000);
  Serial.printf("RSSi: %ld dBm\n", WiFi.RSSI());
}
