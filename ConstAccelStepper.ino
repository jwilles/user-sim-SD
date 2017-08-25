

int n;
int m;
double distance;
double alpha; 
int steps;
double c;
double c0;
double diameter;
double acceleration;
const float pi = 3.14159;
const int f = 16000000;
int dt;



void setup()
{
pinMode(7,OUTPUT); // Step
pinMode(8,OUTPUT); // Dir
Serial.begin(115200);

diameter = 0.0224; // stepper motor diameter (m)
distance = 0.01; //total travel distance (m)
acceleration = 30; // movement accleration (m/s^2)

alpha = 2*acceleration/diameter; // convert linear acceleration to rotational (rad/s^2)
steps = (200*distance/(pi*diameter)); // calculate the total number of steps 

//digitalWrite(8, LOW);

}

void loop()
{

  if (Serial.available()) {
    // read the most recent byte and print
    int  newvel = Serial.parseInt();
    Serial.println(newvel);
   
      if (newvel==1)
      {
        
        digitalWrite(8,HIGH);
        
        c=f*sqrt(2*1.8/alpha); // calculate the initial coefficent
        dt=(1000000*c)/(2*f);
  

        for(n = 0; n < steps/2; n++) //  Positive Acceleration
          {
            digitalWrite(7,HIGH); // Output high
            delayMicroseconds(dt);
            digitalWrite(7,LOW); // Output low
            delayMicroseconds(dt); 
                    
                    
            c0=c; // stores cn-1
            c=c0-((2*c0-1)/(4*n+1)); // calculates cn
            dt=-(c*1000000)/(2*f); // calculates the new delay
            Serial.println(dt);
          }  
            
          
        for(m = n; m < steps; m++) // Negative Acceleration
         {
                  
            digitalWrite(7,HIGH); // Output high
            delayMicroseconds(dt); 
            digitalWrite(7,LOW); // Output low
            delayMicroseconds(dt); 
                   
            c0=c; // stores cn-1
            c=c0-((2*c0-1)/(4*(m-steps)+1)); // calculates cn
            dt=-(c*1000000)/(2*f); // calculates the new delay
            Serial.println(dt);
          }  
             
        delay(1000);
      }
      
      else if (newvel==0)
     {
       digitalWrite(8,LOW);
       
       c=f*sqrt(2*1.8/alpha); // calculate the initial coefficent
       dt=(1000000*c)/(2*f);
        
       for(n = 0; n < steps/2; n++) //  Positive Acceleration
        {
          digitalWrite(7,HIGH); // Output high
          delayMicroseconds(dt);
          digitalWrite(7,LOW); // Output low
          delayMicroseconds(dt); 
                      
          c0=c; // stores cn-1
          c=c0-((2*c0-1)/(4*n+1)); // calculates cn
          dt=-(c*1000000)/(2*f); // calculates the new delay
          Serial.println(dt);
        }  
    
  
       for(m = n; m < steps; m++) // Negative Acceleration
         {
                  
            digitalWrite(7,HIGH); // Output high
            delayMicroseconds(dt); 
            digitalWrite(7,LOW); // Output low
            delayMicroseconds(dt); 
                   
            c0=c; // stores cn-1
            c=c0-((2*c0-1)/(4*(m-steps)+1)); // calculates cn
            dt=-(c*1000000)/(2*f); // calculates the new delay
            Serial.println(dt);
          }  
             
       delay(1000);
       
     }
  }
}
  
  

