
#include <M5StickCPlus.h>
#define delayTime 20   


const int servo_pin = 26;
int freq           = 50;
int ledChannel     = 0;
int resolution     = 10;
extern const unsigned char m5stack_startup_music[];


void setup() {
            // setup code 
  M5.begin ();
   M5.Lcd.setRotation(0);
  M5.Lcd.setCursor(25, 80, 4);
  M5.Lcd.println("speaker");
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(servo_pin, ledChannel);
  ledcWrite(ledChannel, 256); 
}

void playMusic(const uint8_t* music_data, uint16_t sample_rate) {
  uint32_t length      = strlen((char*)music_data);
  uint32_t delay_interval = ((uint32_t)1000000 /sample_rate);
  for (int i = 0; i < length; i++) {
    ledcWriteTone(ledChannel, music_data[i] * 50);
    delayMicroseconds(delay_interval);
  }
}

void loop() {
   ledcWriteTone(ledChannel, 0);
   M5.update();
   if (M5.BtnA 
               .wasReleased()) {
          underPressure();
      }
      
}

void underPressure(){
  for(int i = 0; i < 3; i++){
    ledcWriteTone(ledChannel, 587);
    delay(258);
    ledcWriteTone(ledChannel, 0);
    delay(delayTime);
  }
   for(int i = 0; i < 2; i++){
    ledcWriteTone(ledChannel, 587);
    delay(129);
    ledcWriteTone(ledChannel, 0);
    delay(delayTime);
   }
   ledcWriteTone(ledChannel, 587);
    delay(258);
    ledcWriteTone(ledChannel, 0);
    delay(delayTime);
    ledcWriteTone(ledChannel, 220);
    delay(258);
    ledcWriteTone(ledChannel, 0);
    delay(delayTime);
    ledcWriteTone(ledChannel, 0);
    delay(1000);
   
}
