#include "ESP_dht11.h"
ESP_dht11::ESP_dht11(uint8_t pin){
    _pin=pin;
}
void ESP_dht11::sendStart(){
      // low for 20ms
    pinMode(_pin,OUTPUT);
    digitalWrite(_pin,LOW);
    //keep it low for 20 ms
    delay(18);
    pinMode(_pin,INPUT);// switch the bus for reading data. The pull up resistor will make it HIGH

}