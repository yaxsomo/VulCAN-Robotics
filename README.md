# VulCAN-Robotics
Dedicated repository for the development of the Robotics System VulCAN

VulCAN est un bras robotique conçu pour être le plus fiable possible en exploitant le protocole de communication CAN Bus.

## Pour commencer

Le projet se divise en deux parties : 

- Sender:

- Receiver:

### Pré-requis

Pour lancer ce projet, veuillez avoir les pré-requis suivants :

- PlatformIO (Plug-in VSCode)
- Les dependances indiqués dans le fichier 'VulCAN-Proj/platformio.ini' : 

``ìni
lib_deps = 
	Wire
	CAN
	roboticsbrno/ServoESP32@^1.0.3
	rfetick/MPU6050_light@^1.1.0
```
- Le prototype fonctionnel

### Installation

Pour commencer, clonez le dépôt de ce projet et ouvrez-le à l'aide des commandes ci-dessous.

```bash
git clone https://github.com/yaxsomo/VulCAN-Robotics.git
cd VulCAN-Robotics/
```

Dans la barre laterale, ouvrir l'onglet 'PlatformIO' et selectionner le dossier 'VulCAN-Proj' : 

<img width="346" alt="Capture d’écran 2023-04-23 à 15 06 32" src="https://user-images.githubusercontent.com/71334330/233841659-43921ad1-588e-4be2-b57d-d974d486de2f.png">


- Vous pourrez ensuite vous rendre dans le fichier src/main.cpp et decommenter les methodes en fonction du ESP32 visé :

Sender :

```cpp
void setup()
{


  // IF SENDER
  IMU_Setup();

  // IF RECEIVER
  // servo_setup();
}

void loop()
{

  // IF SENDER
  CAN_Sender();

  // IF RECEIVER 
  // CAN_Receiver();

  delay(1000);
}
```

Receiver :

```cpp
void setup()
{


  // IF SENDER
  //IMU_Setup();

  // IF RECEIVER
  servo_setup();
}

void loop()
{

  // IF SENDER
  // CAN_Sender();

  // IF RECEIVER 
  CAN_Receiver();

  delay(1000);
}
```

Une fois cela fait, vous pouvez charger le code sur l'esp32 via cet onglet :

<img width="920" alt="Capture d’écran 2023-04-23 à 15 15 44" src="https://user-images.githubusercontent.com/71334330/233842035-fd4f6d29-92ef-4667-9c32-5ebdf6a6224e.png">


## Démarrage

....


## Fabriqué avec

* [PlatformIO](https://docs.platformio.org/en/latest/) - Editeur de code pour les microcontroleurs
* [VSCode](https://code.visualstudio.com/) - Editeur de textes
* [Notre cerveau](https://media.tenor.com/yyTPHle1YdQAAAAC/homer-brain.gif) - Incroyable outil


## Auteurs

* **DEHHANI Yassine** _alias_ [@yaxsomo](https://github.com/yaxsomo)
* **BAILEY Emile** _alias_ [@isaiah-dev](https://github.com/isaiah-dev)

