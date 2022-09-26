float midvolt = 2500.0;
float voltage;
float currentSensitivity = 22.0;  //11.0 for WCS1500, 22.0 for WCS1600, 33.0 for WCS1700, 66.0 for WCS1800
int sensor = A0;
float current;
unsigned long rms_curr;
float rms;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  rms_curr = 0;
  for (int i = 0; i <= 1999; i++) //2000 samples averaging
  {
    voltage = analogRead(sensor) * (5000 / 1023.0);
    current = ((voltage) - midvolt) / (22) ; //for wcs1600  100a module, adjust for offset it should be 2500
    rms_curr = rms_curr + (current * current);
  }
  rms = rms_curr / 2000;
  rms = sqrt(rms);
  Serial.println(rms);
  delay(1000);
}
