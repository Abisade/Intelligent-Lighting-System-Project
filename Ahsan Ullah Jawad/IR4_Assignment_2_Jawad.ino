//This is a program to turn on and off the builtin LED Light by pressing 
//the first and last name of the student. In this case, the name of the 
//student is Jawad. So the the Led will be turned on if "J" is pressed and 
//turned off if "D" is pressed. 

 
byte rb=0;       //Delaration of the variable "rb" 
void setup() {   //Setup function. 
  
pinMode(LED_BUILTIN, OUTPUT);    //Initialization of digital pin "LED_BUILTIN" as an output.
Serial.begin(230400);
}

void loop() {                   // Loop fuction. 
  if(Serial.available()>0){     // Checking of any value coming through the serial port 
    rb=Serial.read();           // Assigning the found value to the variable "rb". 
    if(rb=='D'){                // Checking if the value is J
      
      digitalWrite(LED_BUILTIN, HIGH); //Instruction to output voltage to high
    }    else if(rb=='J'){             // Checking agian if the value is D
      digitalWrite(LED_BUILTIN, LOW);  //Instruction to output voltage to low
      
    }
  }

}
