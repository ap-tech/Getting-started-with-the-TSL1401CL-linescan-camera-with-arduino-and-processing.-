




int PixelArray[128] ;            // Pixel array.

int CLK = 12;                    // Set pin as CLK.

int SI  = 13;                    // Set pin as SI.

int i   =  0;                    // For pixel count.

int sensorValue = 0;             // sensor for saturation time.




void setup() {
  
  
  pinMode(CLK, OUTPUT);          // Set CLK as output.
  
  pinMode(SI, OUTPUT);           // Set SI as  output.
  
  Serial.begin(9600);
  
  
//8888888888888888888888888888888888888888888  
                                          //8
 digitalWrite(SI, HIGH);     //           //8
                             //           //8
 digitalWrite(CLK, HIGH);    //           //8
                             // Start.    //8
 digitalWrite(SI, LOW);      //           //8
                             //           //8
 digitalWrite(CLK, LOW);     //           //8
                                          //8
                                          //8   This clocks out indeterminate                      
                                          //8   pixel data from power up.
 for(i = 0; i < 128; i ++){               //8    
                                          //8
                                          //8
 digitalWrite(CLK, HIGH);                 //8
                                          //8                                        
 digitalWrite(CLK, LOW);                  //8
                                          //8
 }                                        //8
                                          //8
//8888888888888888888888888888888888888888888 
  
  
}


void loop() {
  
  
  
 sensorValue = analogRead(A1);   // Get value for saturation time.
  
  
  
//11111111111111111111111111111111
                               //1
 digitalWrite(SI, HIGH);       //1
                               //1
 digitalWrite(CLK, HIGH);      //1
                               //1  Starts pixel count.
 digitalWrite(SI, LOW);        //1
                               //1
 digitalWrite(CLK, LOW);       //1
                               //1
//11111111111111111111111111111111  
  
  
//222222222222222222222222222222222222222222222222222222222222222222
                                                                 //2
  for(i = 0; i < 128; i ++){                                     //2
                                                                 //2
  delayMicroseconds(sensorValue);  //  saturation time.          //2
                                                                 //2
                                                                 //2
  PixelArray[i] = analogRead(A0) ;                               //2
                                                                 //2
                                                                 //2                                                            
  digitalWrite(CLK, HIGH);                                       //2    Pixel count
                                                                 //2    and read.
  digitalWrite(CLK, LOW);                                        //2
                                                                 //2
                                                                 //2
  }                                                              //2
                                                                 //2
//222222222222222222222222222222222222222222222222222222222222222222
  
  
//333333333333333333333333333333333333333  
                                      //3
  for(i = 0; i < 128; i ++){          //3
                                      //3
                                      //3
  Serial.print(PixelArray[i]);        //3
                                      //3      Sand data to computer and
  Serial.print(",");                  //3      processing.
                                      //3
   }                                  //3
                                      //3
  Serial.println(",");                //3
                                      //3
//333333333333333333333333333333333333333  
  
  
}         // END





