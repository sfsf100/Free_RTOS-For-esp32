#define LED1 18
#define LED2 19

void taskA(void *pvParam)
{
   pinMode(LED1, OUTPUT);   // 將接腳設定為輸出模式
   while(1){
    digitalWrite(LED1,!digitalRead(LED1));//切換腳位
    vTaskDelay(pdMS_TO_TICKS(250)); //delay 250ms
   }  
}

void taskB(void *pvParam)
{
   pinMode(LED2, OUTPUT);   // 將接腳設定為輸出模式
   while(1){
    digitalWrite(LED2,!digitalRead(LED2));//切換腳位
    vTaskDelay(500/portTICK_PERIOD_MS); //delay 500ms
   }  
}


void setup() {
  // put your setup code here, to run once:
  xTaskCreate(taskA,"taskA",1000,NULL,1,NULL);
  xTaskCreate(taskB,"taskB",1000,NULL,1,NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}
