# NAV Projekt
## Autor: Jan Tomeček
### Zadání: Š - ESP32 či jiný HW: Knihovna pro grafický displej na bázi technologie e-ink

Odkaz na video s demo aplikací [Video](https://photos.app.goo.gl/1wRxVXrPR8mtr1B47)

Ve videu je ukázaná demostrační aplikace(viz níže).

Knihovna byla implementována pomocí ESP-IDF frameworku

Knihovna se nachází v adresáři ./components/eink_xtomec09

## Překlad a nahrání
Pro překlad a náhrání lze využít ESP-IDF rozšíření ve VSCode.

Knihovna byla vyvíjena i testována ve VSCode právě s tímto rozšířením (v1.6.1).

## Demonstrace knihovny
Pro demonstraci knihovny byla vytvořena jednoduchá aplikace.

Pro navigavici byl použit modul s joystickem, zapojení:
| joystick pin      | esp32 gpio pin    |
|  :-:              |  :-:              |
|  COM              |  GND              |
|  UP               |  27               |
|  DOWN             |  16               |
|  LEFT             |  17               |
|  RIGHT            |  25               |
|  MIDDLE           |  26               |

Nastavení pinů lze změnit v ./main/app_main.c, konstanty:
- GPIO_UP 27
- GPIO_DOWN 16
- GPIO_LEFT 17
- GPIO_RIGHT 25
- GPIO_MIDDLE 26

### Popis aplikace
Po zapnutí se objeví obrazovka s nápovědou, popisující ovládání.

Následně pomocí joysticku se zvolí jedna z připravených ukázek.

Ukázky:
- Referenční obrazovka - Obrazovka, napodobující stav displeje při jeho obdržení (před začátkem řešení projektu)
- Demo Senzor - obrazovka demonstrující použití displeje s 2 čidly teploty
- Demo Animace - jednoduchá animace pohybujícího je čtverečku na displeji
- Demo eInk - Spuštění demonstrační funkce z knihovny - einkD_Demo()


## Zapojení Displeje
(jednotivé piny se dají změnit - viz dokumentace)

| eInk displej pin  | esp32 gpio pin    |
|  :-:              |  :-:              |
| Data              | Data              |
| BUSY              |  13               |
| RST               |  12               |
| DC                |  14               |
| CS                |  5                |
| CLK               |  18               |
| DIN               |  23               |
| GND               |  GND              |
| 3.3V              | 3.3V              |

## Dokumentace
Pro generování dokumentace byl využit Doxygen

Generovaní:

    cd ./components/eink_xtomec09
    doxygen Doxyfile

Dokumentace knihovny se pak vygeneruje v ./components/eink_xtomec09/doc

Vygenerovaná dokumentace byla také dočasně nahrána na server eva a je dostupná 
na odkazu: [Dokumentace](https://www.stud.fit.vutbr.cz/~xtomec09/NAV/) 



Info o displeji:
- [Produktová stránka](https://www.waveshare.com/product/displays/e-paper/epaper-3/1.54inch-e-paper-module.htm)
- [Wiki stránka](https://www.waveshare.com/wiki/1.54inch_e-Paper_Module)