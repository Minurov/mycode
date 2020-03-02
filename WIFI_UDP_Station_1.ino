#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
//WiFiServer server(80);  //  порт веб-сервераvoid 
const char* ssid = "Internet";  // для SSID точки доступа
const char* password = "87654321";  // для пароля к точке доступа
int a;
WiFiUDP Udp;
unsigned int localUdpPort = 4210;
char incomingPacket[255];// переменная запроса от сервера
char  replyPacekt; // Переменная ответа на запрос от сервера
int packetSize;
int rd=15;
int bl=13;
int gr=12;
 void setup() {
  pinMode(rd, OUTPUT);// red
  pinMode(gr, OUTPUT);//gr
  pinMode(bl, OUTPUT);//bl
  Serial.begin(115200);
  delay(10);
  WiFi.begin(ssid, password);
  delay(1000);
  Serial.print("Connecting to ");  //  "Подключение к "
  Serial.print(ssid); Serial.print(" "); Serial.println(password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    digitalWrite(rd,HIGH); delay(50);digitalWrite(rd,LOW);
    Serial.print(".");
  }
  digitalWrite(gr,HIGH);delay(500);digitalWrite(gr,LOW);
  Serial.println();
 
  Serial.print("Connected, IP address: ");
           //  "Подключились, IP-адрес: "
  Serial.println(WiFi.localIP());
  Udp.begin(localUdpPort);// Установив соединение, начинаем прослушивать входящие пакеты.
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
            //  "Теперь прослушиваем IP-адрес %s, UDP-порт %d"
}
 
void loop()
{   
  int a=analogRead(A0);
  replyPacekt=char(a);
  Serial.print   (a);Serial.print("-"); Serial.println(replyPacekt);
  digitalWrite(rd,HIGH);
  delay(5);
  digitalWrite(gr,LOW);
  getUDP();
  

  
  
  delay(1000);
}
