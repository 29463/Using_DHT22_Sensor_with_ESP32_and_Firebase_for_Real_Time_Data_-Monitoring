

//#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
/*#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif*/
#include "DHT.h"

//Provide the token generation process info.
#include <addons/TokenHelper.h>

//Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 11

/* 1. Define the WiFi credentials */
#define WIFI_SSID "Jazz 4G MIFI_6A5D"
#define WIFI_PASSWORD "18472398"

/* 2. Define the API Key */
#define API_KEY "AIzaSyBGkQdL3RTprVWCYEZMsxRw52BJfoSBm9A"

/* 3. Define the RTDB URL */
#define DATABASE_URL "real-time-data-transfer-ffd16-default-rtdb.asia-southeast1.firebasedatabase.app" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "babumalsuther2020@gmail.com"
#define USER_PASSWORD "iobm36545ABC"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;
DHT dht(DHTPIN, DHTTYPE);

void setup()
{

  Serial.begin(115200);
  dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  
  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h


  Firebase.begin(&config, &auth);

  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

  
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();
    Serial.printf("Set Temperature... %s\n", Firebase.setFloat(fbdo, F("/test/temperature"), t) ? "ok" : fbdo.errorReason().c_str());

    Serial.printf("Get Temperature... %s\n", Firebase.getFloat(fbdo, F("/test/temperature")) ? String(fbdo.to<float>()).c_str() : fbdo.errorReason().c_str());

    Serial.printf("Set Humidity... %s\n", Firebase.setDouble(fbdo, F("/test/humidity"), h) ? "ok" : fbdo.errorReason().c_str());

    Serial.printf("Get Humidity... %s\n", Firebase.getDouble(fbdo, F("/test/humidity")) ? String(fbdo.to<double>()).c_str() : fbdo.errorReason().c_str());

        
    FirebaseJson json;

    if (count == 0)
    {
      json.set("value/round/" + String(count), F("cool!"));
      json.set(F("vaue/ts/.sv"), F("timestamp"));
      Serial.printf("Set json... %s\n", Firebase.set(fbdo, F("/test/json"), json) ? "ok" : fbdo.errorReason().c_str());
    }
    else
    {
      json.add(String(count), "smart!");
      Serial.printf("Update node... %s\n", Firebase.updateNode(fbdo, F("/test/json/value/round"), json) ? "ok" : fbdo.errorReason().c_str());
    }
    
    Serial.println();
    
    


    count++;
  }
}
