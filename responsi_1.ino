#include <NewPing.h>   // library untuk HC-SR04 
// ---------- Ultrasonic HC-SR04 ---------- 
#define TRIG_PIN   5 
#define ECHO_PIN   18 
#define MAX_DIST   200   // jarak maksimum (cm) 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST); 
// ---------- PIR HC-SR501 ---------- 
#define PIR_PIN    19 
// ---------- LDR ---------- 
#define LDR_PIN    34   // pin ADC1 

void setup() { 
  Serial.begin(115200); 
  pinMode(PIR_PIN, INPUT); 
  Serial.println("responsi 1: Ultrasonic, PIR, dan LDR siap."); 
} 

void loop() { 
  // 1. Baca sensor ultrasonic 
  unsigned int jarak = sonar.ping_cm(); 
  if (jarak == 0) jarak = MAX_DIST;   // tidak ada pantulan terdeteksi 
  // 2. Baca sensor PIR 
  int gerakan = digitalRead(PIR_PIN); 
  // 3. Baca sensor LDR (nilai mentah ADC 0-4095) 
  int nilaiLDR = analogRead(LDR_PIN); 
  // 4. Tampilkan seluruh hasil ke Serial Monitor 
  Serial.print("Jarak: "); 
  Serial.print(jarak); 
  Serial.print(" cm | Gerakan: "); 
  Serial.print(gerakan == HIGH ? "TERDETEKSI" : "tidak ada"); 
  Serial.print(" | Cahaya (ADC): "); 
  Serial.println(nilaiLDR); 
  
delay(1000);
}