void ledOn()
{
    digitalWrite(LED_BUILTIN, HIGH);
}

void ledOff()
{
    digitalWrite(LED_BUILTIN, LOW);
}
void ledProcess()
{
    ledOn();
    delay(1000);
    ledOff();
    delay(600);
    ledOn();
    delay(1000);
    ledOff();
    delay(250);
}

void ledFail()
{
    ledOn();
    delay(250);
    ledOff();
    delay(250);
    ledOn();
    delay(250);
    ledOff();
    delay(250);
}
