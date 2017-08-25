int x;
int new_delay_velocity;
int delay_velocity;


void setup()
{
pinMode(7,OUTPUT); // Step
pinMode(8,OUTPUT); // Dir
//pinMode(2,OUTPUT); //MS3
//pinMode(3,OUTPUT); //MS2
//pinMode(4,OUTPUT); //MS1

Serial.begin(9600);

// Set Half Step
//digitalWrite(4,HIGH);


// Set delay
delay_velocity=700;

}

void loop()
{

  if (Serial.available()) {
    /* read the most recent byte */
    int  newvel = Serial.parseInt();
    /*ECHO the value that was read, back to the serial port. */
    Serial.println(newvel);
   
      if (newvel==1)
      {
        
        digitalWrite(8,HIGH);
        
        for(x = 0; x < 200; x++) // Constant Velocity
            {
              
              digitalWrite(7,HIGH); // Output high
               delayMicroseconds(delay_velocity); 
               digitalWrite(7,LOW); // Output low
              delayMicroseconds(delay_velocity); 
             }  
             delay(1000);
      }
      
      else if (newvel==0)
     {
       digitalWrite(8,LOW);
       
       for(x = 0; x < 200; x++) // Constant Velocity
            {
              
              digitalWrite(7,HIGH); // Output high
               delayMicroseconds(delay_velocity); 
               digitalWrite(7,LOW); // Output low
              delayMicroseconds(delay_velocity); 
             }  
             delay(1000);
     }
  }
}
        
        

