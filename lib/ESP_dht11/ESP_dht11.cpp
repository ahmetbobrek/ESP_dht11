#include "ESP_dht11.h"
ESP_dht11::ESP_dht11(uint8_t pin){
    _pin=pin;
}

void ESP_dht11::afterRead(afterRead_CB callback){
    _afterRead=callback;
}
void ESP_dht11::afterRead(afterReadPt_CB callback){
    _afterReadPt=callback;
}
void ESP_dht11::onError(onError_CB error_callback){
    _errorCallback=error_callback;
    
}
/*void ESP_dht11::read() {
	_data[0] = _data[1] = _data[2] = _data[3] = _data[4] = 0;
	_counter = 0;
	_result = 0;
//	noInterrupts(); // turning interrupts off
	sendStart();
	int result = readData();
//	interrupts();
	if (result != DHTLIB_OK) {
		_errorCallback(error);
		return;
	}

	// TEST CHECKSUM
	uint8_t sum = bits[0] + bits[1] + bits[2] + bits[3];
	if (bits[4] != sum)
	{
		DEBUG_FSE_SENSOR("Fail checksum");
		error.errorMsg = "Fail checksum";
		error.errorNum = DHTLIB_ERROR_CHECKSUM;
		if (_errorCallback) {
			_errorCallback(error);
		}

		return;
	}


	// CONVERT AND STORE
	humidity = bits[0] + bits[1] * 0.1;
	temperature = (bits[2] & 0x7F) + bits[3] * 0.1;
	if (bits[2] & 0x80)  // negative temperature
	{
		temperature = -temperature;
	}

	if (_afterRead) {
		_afterRead(getHumidity(), toCelsius());
	}

	if (_afterReadPt) {
		_afterReadPt(this);
	}
}*/
void ESP_dht11::read(){
    
}




void ESP_dht11::sendStart(){
      // low for 20ms
    pinMode(_pin,OUTPUT);
    digitalWrite(_pin,LOW);
    //keep it low for 20 ms
    delay(18);
    pinMode(_pin,INPUT);// switch the bus for reading data. The pull up resistor will make it HIGH

}