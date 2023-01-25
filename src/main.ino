/**
 * @file DHT22_WiFi.ino
 * @brief Reading DHT22 temperature and humidity sensor data and sending it over WiFi
 * @author Bruno Donatelli
 * @date 25/01/2023
 */

#include <DHT.h>
#include <Adafruit_Sensor.h>
// #include <ESP8266WiFi.h>
// #include <dotenv.hpp>

/**
 * @def DHTTYPE
 * @brief Type of DHT sensor
 */
#define DHTTYPE DHT22

/**
 * @def DHTPIN
 * @brief Pin where the DHT sensor is connected
 */
#define DHTPIN A0

/**
 * @var dht
 * @brief DHT sensor object
 */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Setup function, runs once on startup
 */
void setup()
{
    // dotenv::dotenv();

    // /**
    //  * @var ssid
    //  * @brief SSID of the WiFi network to connect to
    //  */
    // const std::char *ssid = std::getenv("WIFI_SSID");

    // /**
    //  * @var password
    //  * @brief Password of the WiFi network to connect to
    //  */
    // const std::char *password = std::getenv("PASSWORD");

    Serial.begin(9600);
    // WiFi.begin(ssid, password);

    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     delay(1000);
    //     Serial.println("Connecting to WiFi...");
    // }

    dht.begin();
    Serial.println("Connected to WiFi");
}

/**
 * @brief Loop function, runs repeatedly
 */
void loop()
{
    float humidity = 0.0f;
    float temperature = 0.0f;
    if (readDHT(humidity, temperature))
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print("°C ");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println("% ");
    }

/**
 * @def DELAY_TIME
 * @brief Time to wait between readings
 */
#define DELAY_TIME 1800000

    delay(DELAY_TIME);
}

bool readDHT(float &humidity, float &temperature)
{
    /**
     * @var humidity
     * @brief Humidity reading from the DHT sensor
     */
    humidity = dht.readHumidity();
    /**
     * @var temperature
     * @brief Temperature reading from the DHT sensor
     */
    temperature = dht.readTemperature();
    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read from DHT");
        return false;
    }
    return true;
}