# VulCAN-Robotics
Dedicated repository for the development of the Robotics System VulCAN

VulCAN est un bras robotique conçu pour être le plus fiable possible en exploitant le protocole de communication CAN Bus.

## Pour commencer

Le projet se divise en deux parties : 

- Sender:

- Receiver:

### Pré-requis

Pour lancer ce projet, veuillez avoir les pré-requis suivants :

- Arduino IDE
- Les librairies suivantes : 
    - Composer
- La construction du prototype pour la communication

### Installation

Pour commencer, clonez le dépôt de ce projet et ouvrez-le à l'aide des commandes ci-dessous.

```bash
git clone https://github.com/yaxsomo/VulCAN-Robotics.git
cd VulCAN-Robotics
```

Installez le package ESP32 sur Arduino IDE via les preferences : 
- Ajoutez le lien suivant dans les preferences : 
    - https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
    <img width="795" alt="Capture d’écran 2023-04-17 à 14 29 44" src="https://user-images.githubusercontent.com/71334330/232485206-3e3956b8-019d-4d20-9b7d-31b446f0c80e.png">

- Vous pourrez ensuite installer le package esp32 via le Boards Manager : 
    <img width="251" alt="Capture d’écran 2023-04-17 à 14 28 30" src="https://user-images.githubusercontent.com/71334330/232485251-a5767f09-521f-4158-a60d-03b39c085013.png">
...

## Démarrage

Pour démarrer le projet, il vous suffira de charger le code dans les deux ESP32, et cliquer sur le bouton RST des cartes.

Et pour finir de vous rentre sur l'url: 
[http://127.0.0.1:8000](http://127.0.0.1:8000)

Ici vous pourrez controler les stepper motors à l'aide de l'interface graphique

## Fabriqué avec

* [Arduino IDE](https://docs.arduino.cc) - Editeur de code pour les microcontroleurs
* [VSCode](https://code.visualstudio.com/) - Editeur de textes
* [Notre cerveau](https://media.tenor.com/yyTPHle1YdQAAAAC/homer-brain.gif) - Incroyable outil


## Auteurs

* **DEHHANI Yassine** _alias_ [@yaxsomo](https://github.com/yaxsomo)
* **BAILEY Emile** _alias_ [@isaiah-dev](https://github.com/isaiah-dev)

