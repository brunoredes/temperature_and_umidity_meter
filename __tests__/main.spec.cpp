#include <cppunit/extensions/HelperMacros.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>

class DHT22_WiFiTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(DHT22_WiFiTest);
    CPPUNIT_TEST(testReadDHT);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
    }

    void tearDown()
    {
    }

    void testReadDHT()
    {
        DHT dht(DHTPIN, DHTTYPE);
        float humidity = 0.0f;
        float temperature = 0.0f;
        bool expected = true;
        bool result = readDHT(humidity, temperature);
        CPPUNIT_ASSERT_EQUAL(expected, result);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(DHT22_WiFiTest);