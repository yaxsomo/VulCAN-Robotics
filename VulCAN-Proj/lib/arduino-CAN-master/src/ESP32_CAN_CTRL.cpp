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

void CAN_Sender()
{
  uint8_t Z = int_to_uint8(get_Z_axis());
  uint8_t X = int_to_uint8(get_X_axis());
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");

  CAN.beginPacket(0x12); // sets the ID and clears the transmit buffer
  // CAN.beginExtendedPacket(0xabcdef);

  CAN.write(Z);
  Serial.print("Z : ");
  Serial.print(Z);
  CAN.endPacket();

  CAN.beginPacket(0x13);

  CAN.write(X);
  Serial.print(", X : ");
  Serial.println(X);
  CAN.endPacket();

  // RTR packet with a requested data length
  //  CAN.beginPacket (0x13, 3, true);
  //  CAN.endPacket();

  Serial.println("done");

  // delay(1000);
}

void CAN_Receiver()
{
  int f = 0;
  int g = 0;
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize)
  {
    // received a packet
    Serial.print("Received ");

    if (CAN.packetExtended())
    {
      Serial.print("extended ");
    }

    if (CAN.packetRtr())
    {
      // Remote transmission request, packet contains no data
      Serial.print("RTR ");
    }

    Serial.print("packet with id 0x");
    Serial.print(CAN.packetId(), HEX);

    if (CAN.packetRtr())
    {
      Serial.print(" and requested length ");
      Serial.println(CAN.packetDlc());
    }
    else
    {
      Serial.print(" and length ");
      Serial.println(packetSize);

      // only print packet data for non-RTR packets
      while (CAN.available())
      {
        Serial.println(CAN.read());
        switch (CAN.packetId())
        {
        case 0x12:
          f = cuint8_to_int(CAN.read());
          break;
        case 0x13:
          g = cuint8_to_int(CAN.read());
          break;
        default:
          Serial.print("Bad packet ID");
          break;
        }
      }
        convert_360_to_180(f,g);
        Serial.print("Sent coordinate Z : ");
        Serial.print(f);
        Serial.print(" and X : ");
        Serial.print(g);
        Serial.println(" To the motors ");
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
