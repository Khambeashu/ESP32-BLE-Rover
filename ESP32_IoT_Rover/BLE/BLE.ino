#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Motor pins (ESP32 DevKit)
#define EN 22
#define M1 27
#define M2 14
#define M3 12
#define M4 13

BLECharacteristic *pCharacteristic;

// BLE UUIDs
#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890ab"
#define CHARACTERISTIC_UUID "abcd1234-1234-1234-1234-abcdef987654"

// ============= Motor Functions =============

void turnFORWARD() {
  Serial.println("FORWARD → M1=HIGH, M2=LOW, M3=HIGH, M4=LOW");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}

void turnBACKWARD() {
  Serial.println("BACKWARD → M1=LOW, M2=HIGH, M3=LOW, M4=HIGH");
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
}

void turnLEFT() {
  Serial.println("LEFT → M1=LOW, M2=HIGH, M3=HIGH, M4=LOW");
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}

void turnRIGHT() {
  Serial.println("RIGHT → M1=HIGH, M2=LOW, M3=LOW, M4=HIGH");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
}

void stopMotor() {
  Serial.println("STOP → All LOW");
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
}

// ============= BLE Callback =============

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String rxValue = pCharacteristic->getValue();   // Arduino String

    if (rxValue.length() > 0) {
      char cmd = rxValue.charAt(0);
      Serial.print("Received: ");
      Serial.println(cmd);

      switch (cmd) {
        case 'F': turnFORWARD(); break;
        case 'B': turnBACKWARD(); break;
        case 'L': turnLEFT(); break;
        case 'R': turnRIGHT(); break;
        case 'S': stopMotor(); break;
        default:  Serial.println("Unknown Command"); break;
      }
    }
  }
};

// ============= Setup =============

void setup() {
  delay(1500);  // avoid Serial blank issue
  Serial.begin(115200);
  Serial.println("Booting...");

  // Motor pin setup
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);

  // BLE setup
  BLEDevice::init("ESP32-Rover");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_WRITE
                    );

  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  BLEDevice::startAdvertising();

  Serial.println("BLE Rover Ready!");
}

// ============= Loop =============
void loop() {
  // Nothing here — BLE callback handles commands
}
