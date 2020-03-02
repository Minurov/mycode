void getUDP(){
   digitalWrite(rd,LOW);
   packetSize = Udp.parsePacket();
  if (packetSize)
  {  
    digitalWrite(bl,HIGH);
    
    // получаем входящие UDP-пакеты:
    //----Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
              //  "Получено %d байт от %s, порт %d%"
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    //----Serial.printf("UDP packet contents: %s\n", incomingPacket);
              //  "Содержимое UDP-пакета: %s"
 
    // отправляем ответ на IP-адрес и порт, с которых пришел пакет:
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(replyPacekt);
    Udp.endPacket();
  
    delay(5);
    digitalWrite(bl,LOW);
  }
}
