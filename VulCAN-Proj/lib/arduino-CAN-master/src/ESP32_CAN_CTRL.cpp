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

#include <ESP32_CAN_CTRL.h>
#include <motors.h>
#include <IMU.h>
#include <stdint.h>

uint8_t int_to_uint8(int valeur) {
    uint8_t valeur_uint8 = (uint8_t)valeur; // conversion explicite en uint_8
    return valeur_uint8;
}

int cuint8_to_int(uint8_t valeur_uint8) {
    int valeur = (int)valeur_uint8; // conversion explicite en int
    return valeur;
}

void CAN_Setup(int RX_PIN, int TX_PIN)
{

  Serial.println("Initiating CAN Receiver/Receiver");

  // Set the pins
  CAN.setPins(RX_PIN, TX_PIN);

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3))
  {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  }
  else
  {
    Serial.println("CAN Initialized");
  }
}

void CAN_Sender() {

  char *Z = get_Z_axis();
  char *X = get_X_axis();
  // char Z[] = {'1','8','0','\0'};
  // char X[] = {'-','1','8','0','\0'};
 
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.println("Sending packet ... ");

// Envoie du premier paquet avec l'ID 0x12

  CAN.beginPacket(0x12); // sets the ID and clears the transmit buffer
  // CAN.beginExtendedPacket(0xabcdef);

  for (int i = 0 ; i < strlen(Z); i++) {
    CAN.write(Z[i]);
  }
  Serial.println(Z);
  CAN.endPacket();

// Envoie du deuxieme paquet avec l'ID 0x13

  CAN.beginPacket(0x13);
  for (int i = 0 ; i < strlen(X); i++) {
    CAN.write(X[i]);
  }
  Serial.println(X);

  CAN.endPacket();

  // RTR packet with a requested data length
  //  CAN.beginPacket (0x13, 3, true);
  //  CAN.endPacket();

  Serial.println("packet sent");

}

void CAN_Receiver()
{

  int pos_Z = 0;
  int pos_X = 0;
   // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize || CAN.packetId() != -1) {
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

        switch(CAN.packetId()) {

        case 0x12:
            pos_Z = CAN.read();
            Serial.println((char)CAN.read());
            break;
        case 0x13:
            pos_X = CAN.read();
            Serial.println((int)CAN.read());
          break;
        default:
          Serial.println("BAD PACKET ID");
          break;
        }
        turn_servos(pos_Z, pos_X);
        Serial.print((int)CAN.read());
      }
      Serial.println();
    }

    Serial.println();
  }
}

void parseMessage(char *data)
{

  for (int i = 0; data[i] != '\0'; i++)
  {
    printf("%c", data[i]);
  }
}
