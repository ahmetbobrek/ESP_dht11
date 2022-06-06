#if !defined(ESP_DHT11_H_)
#define ESP_DHT11_H_

#include <Arduino.h>
typedef struct{
    int errorNum;
    String errorMsg;
}ESP_dht11_error_t;

class ESP_dht11;

typedef std::function<void(float humid,float temp)>afterRead_CB;
typedef std::function<void(ESP_dht11 *dht11)>afterReadPt_CB;
typedef std::function<void(ESP_dht11_error_t _error)>onError_CB;

typedef enum(
    NO_RESPONSE_SIGNAL,
)SENSOR_ERROR_t;

class ESP_dht11{
    public:
    ESP_dht11();
    ESP_dht11(uint8_t pin);
    void setPin(uint8_t pin);
    void afterRead(afterRead_CB callback);
    void afterRead(afterReadPt_CB callback);
    void onError(onError_CB callback);
    void read();
    
    protected:



    private:
    uint8_t _pin;
    void sendStart();

};


#endif // ESP_DHT11_H
