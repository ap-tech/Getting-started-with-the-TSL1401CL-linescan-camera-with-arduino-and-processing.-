// Processing code for Robot1 moniter
 
 
 import processing.serial.*;
 
 
float  [] PixelArray = new float[128] ;
 
 int i = 0;
 
 Serial myPort;
 
 void setup() {
 size(128, 70);
 
 
 // List all the available serial ports
 println(Serial.list());
 // I know that the first port in the serial list on my mac
 // is always my  Arduino, so I open Serial.list()[0].
 // Open whatever port is the one you're using.
 myPort = new Serial(this,"/dev/tty.usbmodem641",9600);
 // don't generate a serialEvent() unless you get a newline character:
 myPort.bufferUntil('\n');
 }
 
 void draw() {
 // set the background color with the color values:
  
 
 
  for(i = 0; i < 128; i ++){


  stroke(PixelArray[i]);
  line(i, 0, i, 70);
 
 
  }


 }
 
 
 void serialEvent(Serial myPort) { 
 // get the ASCII string:
 String inString = myPort.readStringUntil('\n');
 
 if (inString != null) {
 // trim off any whitespace:
 inString = trim(inString);
 // split the string on the commas and convert the 
 // resulting substrings into an integer array:
 float[] colors = float(split(inString, ","));
 // if the array has at least three elements, you know
 // you got the whole thing.  Put the numbers in the
 // color variables:
 if (colors.length >=128) {
 // map them to the range 0-255:
 
 
 
 
 for(i = 0; i < 128; i ++){

  PixelArray[i] = map(colors[i], 0, 1023, 0, 255);
 
 }
 
 
 
 
 
 
 }
 }
 }


 

 

 
 

 
 
 
 
 
 
 
 
 
 
 
 
 

