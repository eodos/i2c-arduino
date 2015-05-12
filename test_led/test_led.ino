const int led[] = {22, 23, 24, 25, 26};

void setup()
{
  for (int i=0; i<=4; i++)
  {
    pinMode(led[i], OUTPUT);
  };
};
  
void loop()
{
    for (int i=0; i<=4; i++)
    {
      digitalWrite(led[i],HIGH);
      delay(100);
      digitalWrite(led[i],LOW);
    };
    for (int i=4; i>=0; i--)
    {
      digitalWrite(led[i],HIGH);
      delay(100);
      digitalWrite(led[i],LOW);
    };
};
