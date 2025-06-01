#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h> 

const char* ssid = "NAMA_WIFI";
const char* password = "PASSWORD_WIFI";

// Ganti dengan URL dari Google Apps Script kamu
const String url = "URL_GOOGLE_APP_SCRIPT";

void setup() {
  Serial.begin(115200);
  Serial.println("Starting setup");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure();

    HTTPClient http;

    int suhu = random(20, 40);
    int kelembapan = random(40, 70);

    String fullUrl = url + "?suhu=" + suhu + "&kelembapan=" + kelembapan;
    
    http.begin(client, fullUrl);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.println("Data terkirim: " + String(suhu) + " - " + String(kelembapan));
    } else {
      Serial.println("Gagal kirim data");
    }

    http.end();
  }

  delay(5000); // Kirim data tiap 5 detik
}
