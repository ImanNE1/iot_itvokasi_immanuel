#include <WiFi.h>


void setup() {
  Serial.begin(115200);


  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);


  Serial.println("Pemindaian Jaringan Wi-Fi Dimulai...");
}


void loop() {
  int n = WiFi.scanNetworks();
  Serial.println("Pemindaian Selesai");
  if (n == 0) {
    Serial.println("Tidak ada jaringan Wi-Fi yang ditemukan.");
  } else {
    Serial.print(n);
    Serial.println(" jaringan Wi-Fi ditemukan:");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print("dBm)");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");


  delay(5000); // Lakukan pemindaian setiap 5 detik
}
