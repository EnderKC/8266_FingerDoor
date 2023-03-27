#ifndef MYMQTT_H
#define MYMQTT_H

const char *mqtt_broker = "broker-cn.emqx.io";
const char *topic = "80055ed4-7c6e-43da-88b2-13c07537aebe";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void mqttCallback(char *topic, byte *payload, unsigned int length);

void myMqtt_init()
{
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(mqttCallback);
    while (!client.connected())
    {
        String client_id = "esp8266-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
        {
            Serial.println("Public emqx mqtt broker connected");
        }
        else
        {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    // publish and subscribe
    client.publish(topic, "hello emqx");
    client.subscribe(topic);
}

void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    // for (int i = 0; i < length; i++)
    // {
    //     Serial.print((char)payload[i]);
    // }
    char *str = (char *)payload;
    if (strcmp(str,"open") == 0)
    {
        openDoor();
    }
    Serial.println(str);
    Serial.println("-----------------------");
}
#endif