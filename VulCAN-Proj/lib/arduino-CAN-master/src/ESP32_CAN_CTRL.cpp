/*
 ┌───────────────────────────────────────────────┐
 │ ██████╗  ██████╗ ██████╗  ██████╗ ████████╗   │
 │ ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗╚══██╔══╝   │
 │ ██████╔╝██║   ██║██████╔╝██║   ██║   ██║      │
 │ ██╔══██╗██║   ██║██╔══██╗██║   ██║   ██║      │
 │ ██║  ██║╚██████╔╝██████╔╝╚██████╔╝   ██║      │
 │ ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝    ╚═╝      │
 ├──────────────┬────────────────────────────────┤
 │Projet Dev B2 │ YASSINE DEHHANI & EMILE BAILEY │
 │   17/04/2023 │       www.github.com/lien_ici  │
 └──────────────┴────────────────────────────────┘
*/

#include "ESP32_CAN_CTRL.h"


void CAN_Setup(int RX_PIN, int TX_PIN) {
  
  Serial.println("Initiating CAN Receiver/Receiver");

  // Set the pins
  CAN.setPins(RX_PIN, TX_PIN);

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  } else {
    Serial.println("CAN Initialized");
  }
}

void CAN_Sender() {
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");

  CAN.beginPacket(0x12);  //sets the ID and clears the transmit buffer
  // CAN.beginExtendedPacket(0xabcdef);
  CAN.write('h');  //write data to buffer. data is not sent until endPacket() is called.
  CAN.write('e');
  CAN.write('l');
  CAN.write('l');
  CAN.write('o');
  CAN.endPacket();

  CAN.beginPacket(0x13);
  CAN.write('w');
  CAN.write('o');
  CAN.write('r');
  CAN.write('l');
  CAN.write('d');
  CAN.endPacket();


  //RTR packet with a requested data length
  // CAN.beginPacket (0x13, 3, true);
  // CAN.endPacket();

  Serial.println("done");

  delay(1000);
}

void CAN_Receiver() {
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print("Received ");

    if (CAN.packetExtended()) {
      Serial.print("extended ");
    }

    if (CAN.packetRtr()) {
      // Remote transmission request, packet contains no data
      Serial.print("RTR ");
    }

    Serial.print("packet with id 0x");
    Serial.print(CAN.packetId(), HEX);

    if (CAN.packetRtr()) {
      Serial.print(" and requested length ");
      Serial.println(CAN.packetDlc());
    } else {
      Serial.print(" and length ");
      Serial.println(packetSize);

      // only print packet data for non-RTR packets
      while (CAN.available()) {
        Serial.print((char)CAN.read());
      }
      Serial.println();
    }

    Serial.println();
  }
}

void parseMessage(char* data) {

  for (int i = 0; data[i] != '\0'; i++) {
    printf("%c", data[i]);
  }
}
