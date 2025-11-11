// Pin relay (gunakan pin sesuai NodeMCU)
#define RELAY1 5   // GPIO5
#define RELAY2 4   // GPIO4
// #define RELAY3 14   // GPIO14
// #define RELAY4 12   // GPIO12

// Simpan status masing-masing relay
bool relay1State = LOW;
bool relay2State = LOW;
// bool relay3State = LOW;
// bool relay4State = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  // pinMode(RELAY3, OUTPUT);
  // pinMode(RELAY4, OUTPUT);

  // Matikan semua relay saat awal
  digitalWrite(RELAY1, relay1State);
  digitalWrite(RELAY2, relay2State);
  // digitalWrite(RELAY3, relay3State);
  // digitalWrite(RELAY4, relay4State);

  Serial.println("Kontrol 4 Relay ESP8266 Siap!");
  Serial.println("Ketik: ");
  Serial.println("1 = Relay1 ON, 2 = Relay2 ON, 3 = Relay3 ON, 4 = Relay4 ON");
  Serial.println("5 = Relay1 OFF, 6 = Relay2 OFF, 7 = Relay3 OFF, 8 = Relay4 OFF");
}

void loop() {
  if (Serial.available()) {
    char perintah = Serial.read();

    switch (perintah) {
      case '1':
        relay1State = HIGH;
        digitalWrite(RELAY1, relay1State);
        Serial.println("Relay1 ON");
        break;
      case '2':
        relay2State = HIGH;
        digitalWrite(RELAY2, relay2State);
        Serial.println("Relay2 ON");
        break;
      // case '3':
      //   relay3State = HIGH;
      //   digitalWrite(RELAY3, relay3State);
      //   Serial.println("Relay3 ON");
      //   break;
      // case '4':
      //   relay4State = HIGH;
      //   digitalWrite(RELAY4, relay4State);
      //   Serial.println("Relay4 ON");
      //   break;
      case '3':
        relay1State = LOW;
        digitalWrite(RELAY1, relay1State);
        Serial.println("Relay1 OFF");
        break;
      case '4':
        relay2State = LOW;
        digitalWrite(RELAY2, relay2State);
        Serial.println("Relay2 OFF");
        break;
      // case '7':
      //   relay3State = LOW;
      //   digitalWrite(RELAY3, relay3State);
      //   Serial.println("Relay3 OFF");
      //   break;
      // case '8':
      //   relay4State = LOW;
      //   digitalWrite(RELAY4, relay4State);
      //   Serial.println("Relay4 OFF");
      //   break;
    }
  }
}
