  /*     Sketch pentru senzor de culoare TCS230 compatibil Arduino
   *      
   *  by Doru Mandache, www.robodomit.blogspot.ro
   *  
   */
 
  #define S0 4
  #define S1 5
  #define S2 6
  #define S3 7
  #define sensorOut 8
  int frequency = 0;
  int tmpfrequency; 
  
  void setup() {
     Serial.begin(9600);

     pinMode(S0, OUTPUT);
     pinMode(S1, OUTPUT);
     pinMode(S2, OUTPUT);
     pinMode(S3, OUTPUT);
     pinMode(sensorOut, INPUT);
  
     digitalWrite(S0,HIGH); //
     digitalWrite(S1,LOW);  // Seteaza scalarea frecventei de iesire la 20%
  }
  
 void loop() {
   for (int i = 0; i < 100; i++) {
     digitalWrite(S2,LOW); //
     digitalWrite(S3,LOW); // Seteaza fotodiodele rosii de filtrare pentru a fi citite
     frequency = pulseIn(sensorOut, LOW); // Citeste frecventa de iesire
     frequency = map(frequency, 25,72,255,0); //Remapeaza valorile frecventei la modelul RGB (0 - 255)
     tmpfrequency = tmpfrequency + frequency;  
   }
   frequency = tmpfrequency / 100; tmpfrequency = 0;
   Serial.print("R= ");       //
   Serial.print(frequency);   // Afiseaza culoarea si frecventa la monitorul serial
   Serial.print("  ");        // 
   delay(100);

   for (int i = 0; i < 100; i++) {
     digitalWrite(S2,HIGH); //
     digitalWrite(S3,HIGH); // Seteaza fotodiodele verzi de filtrare pentru a fi citite
     frequency = pulseIn(sensorOut, LOW); // Citeste frecventa de iesire   
     frequency = map(frequency, 30,90,255,0); //Remapeaza valorile frecventei la modelul RGB (0 - 255)
     tmpfrequency = tmpfrequency + frequency;  
   }
   frequency = tmpfrequency / 100; tmpfrequency = 0;
   Serial.print("G= ");        //
   Serial.print(frequency);    // Afiseaza culoarea si frecventa la monitorul serial
   Serial.print("  ");         //
   delay(100);


   for (int i = 0; i < 100; i++) {
     digitalWrite(S2,LOW);  //
     digitalWrite(S3,HIGH); // Seteaza fotodiodele albastre de filtrare pentru a fi citite
     frequency = pulseIn(sensorOut, LOW); // Citeste frecventa de iesire
     frequency = map(frequency, 25,70,255,0); //Remapeaza valorile frecventei la modelul RGB (0 - 255)
     tmpfrequency = tmpfrequency + frequency;  
   }
   frequency = tmpfrequency / 100; tmpfrequency = 0;  
   Serial.print("B= ");       //
   Serial.print(frequency);   // Afiseaza culoarea si frecventa la monitorul serial
   Serial.println("  ");      //
   delay(100);
  }
