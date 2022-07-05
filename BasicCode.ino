float midvolt = 2500.0;
float voltage;
float currentSensitivity = 22.0;  //11.0 for WCS1500, 22.0 for WCS1600, 33.0 for WCS1700, 66.0 for WCS1800
int sensor = A0;
float current;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int temp;
  long int average_curr = 0;
  for (int i = 0; i <= 1999; i++) //2000 samples averaging
  {
    temp = analogRead(sensor);
    average_curr = average_curr + temp;
  }
  average_curr = average_curr / 2000;
  voltage = average_curr * (5000 / 1023.0);
  current = ((voltage) - midvolt) / (currentSensitivity);
  Serial.println(current);
  delay(1000);
}
