  void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(5, OUTPUT);        //Sets digital pin 5 as output pin
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

char c;
String voice;

void loop()
{
  if(Serial.available() > 0)  
  { voice="";
  delay(2);
    voice=Serial.readString();
    delay(2);
    Serial.println(voice);
  }
  if(voice=="turn off light")
    { digitalWrite(6,HIGH);
    }
  else if (voice=="turn on light")
    {digitalWrite(6,LOW);
    }

  else if(voice=="turn off fan")
    { digitalWrite(7,HIGH);
    }
  else if (voice=="turn on fan")
    {digitalWrite(7,LOW);
    }

  else if(voice=="turn off AC")
    { digitalWrite(5,HIGH);
    }
  else if (voice=="turn on AC")
    {digitalWrite(5,LOW);
    }

  else if(voice=="turn off TV")
    { digitalWrite(8,HIGH);
    }
  else if (voice=="turn on TV")
    {digitalWrite(8,LOW);
    }
}
    
