// 🔹 Pins
#define MQ6_PIN 34
#define BUZZER 25
#define LED 26

// 🔹 Settings
int threshold = 500;        // 🔥 thoda low rakha fast detection ke liye
int hysteresis = 30;        // noise control

bool gasDetected = false;

unsigned long buzzerStartTime = 0;
bool buzzerActive = false;

// 🔹 Smooth reading (noise reduce)
int readGas() {
  int total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(MQ6_PIN);
    delay(3);
  }
  return total / 10;
}

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, LOW);

  Serial.println("🔥 GAS DETECTION SYSTEM STARTED");

  // 🔥 Sensor warmup (IMPORTANT)
  Serial.println("Warming up sensor...");
  delay(20000);
  Serial.println("✅ Ready!");
}

void loop() {

  int gasValue = readGas();

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // 🚨 GAS DETECTED (with hysteresis)
  if (gasValue > threshold && !gasDetected) {
    gasDetected = true;

    Serial.println("⚠️ GAS DETECTED!");

    digitalWrite(LED, HIGH);

    // 🔊 buzzer ON (pulse mode)
    digitalWrite(BUZZER, HIGH);
    buzzerStartTime = millis();
    buzzerActive = true;
  }

  // ⏱️ buzzer OFF after 5 sec
  if (buzzerActive && millis() - buzzerStartTime > 5000) {
    digitalWrite(BUZZER, LOW);
    buzzerActive = false;
  }

  // ✅ SAFE (with hysteresis to avoid fluctuation)
  if (gasValue < (threshold - hysteresis) && gasDetected) {
    gasDetected = false;

    Serial.println("✅ SAFE");

    digitalWrite(LED, LOW);
  }

  delay(300);
}
