TaskHandle_t handleB;
long counter = 0;

void taskA(void *pvParam)
{
   while(1){
    printf("任務 A 進行中\n");
    counter++;
    if(counter == 8){
      vTaskPrioritySet(handleB,3); //調高優先權
    }
    yield();//讓出資源 
   }  
}

void taskB(void *pvParam)
{
    while(1){
     printf("終於輪到任務 B 上場了\n");
     if(counter == 16){
        vTaskDelete(handleB); //
     }
    yield();//讓出資源 
   }  
}


void setup() {
  // put your setup code here, to run once:
  xTaskCreate(taskA,"my taskA",1000,NULL,2,NULL);
  xTaskCreate(taskB,"my taskB",1000,NULL,1,&handleB);
}

void loop() {
}
