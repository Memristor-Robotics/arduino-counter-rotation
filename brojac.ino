volatile boolean nazad;
volatile boolean napred;

#define pinA 2
#define pinB 3
#define interrupt 0 

void isr ()
{
 if (digitalRead (pinA))
   napred = digitalRead (pinB);
 else
   napred = !digitalRead (pinB);
 nazad = true;
}  

void setup ()
{
 digitalWrite (pinA, HIGH);    
 digitalWrite (pinB, HIGH); 
 attachInterrupt (interrupt, isr, CHANGE);   
 Serial.begin (115200);
} 

void loop ()
{
static long brojac = 0;

 if (nazad)
   {
   if (napred)
     brojac++;
   else
     brojac--;
   nazad = false;
       
   Serial.print ("Obrtaji = ");  
   Serial.println (brojac);
   } 

}  
