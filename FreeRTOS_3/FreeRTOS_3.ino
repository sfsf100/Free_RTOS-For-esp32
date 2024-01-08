#define LED1 18
#define LED2 19

TaskHandle_t handleA;
uint16_t stacksize = 1000;

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
  Serial.begin(115200);
  Serial.printf("stack size: %u bytes\n",ESP.getHeapSize());
  Serial.printf("Before build mission the stack size: %u bytes\n",ESP.getFreeHeap ());

  xTaskCreate(taskA,"my taskA",stacksize ,NULL,1,&handleA);
  xTaskCreate(taskB,"my taskB",stacksize ,NULL,1,NULL);
  
  Serial.printf("AFTER build mission the stack size: %u bytes\n",
  ESP.getFreeHeap ());
}

void loop() {
  UBaseType_t m = stacksize - uxTaskGetStackHighWaterMark(handleA);
  Serial.printf("mission use size: %u bytes\n",m);
  vTaskDelay(1000); //delay 500ms
}
