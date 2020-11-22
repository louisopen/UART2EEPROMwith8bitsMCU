## ��UARTtoEEPROMwith8bitsMCU
* Used HT66F318 control GPIO, LED matrix, EEPROM, ADC, I2C... via UART(Same with RS-485)
* �Q��Holtek MCU HT66F318 28sop UART�����PEEPROM(���m)�Ψ�LGPIO�����q�~�|...�}�u���Ƥu��
* �M�~�K�y�S�n��, ���L�רҳ��M�o�˪���, �ӥi��! �ݤ��U�h! 
* ���}�d�C�O�@��²��Q��PC�n��U�F���O�s��MCU������EEPROM(64byte), ��MCU���s�w�ĬG�N�ˤp, ��ĳ���RS-485�q�T��ĳ�榡. 8bit MCU �귽�������\�h����C�C�����a!

* Project Option:<br>
HXT (External 8MHz X'tal); �i�ﶵ��:HXT(400K~16Mhz),HIRC8M,HIRC12M,HIRC16M<br>
LICR (Low speed internal RC for TB0/TB1); �i�ﶵ��:LXT(32.768Khz),LIRC(32Khz)<br>

* UART Baudrate: 9600,n,8,1 (��ĳ�榡�ѷ�RS-485�q�T��ĳ�榡)<br>

* TB0,1 enable LIRC interrupt for 0.514sec, 0.514sec<br>

* HT-IDE3000 HT66F317/HT66F318 28ssop with HT-IDE3000 & e-Link & e-WriterPro<br>
���[HT66F318 Document](https://www.holtek.com.tw/search?key=ht66F318)<br>
����&����Development & Debug[IDE3000 & ICE](https://www.holtek.com.tw/web/guest/ice)<br>
�N�J��Progrmming & writer[HOPE3000 & e-WriterPro](https://www.holtek.com.tw/web/guest/programmer)<br>

### Relevant information
* HT-IDE3000 V7.99
![Image](HT-IDE3000_version.jpg)
* HOLTEK C Compiler V3/Assembly
![Image](ProjectCompiler.jpg)
* HT66F318 Config
![Image](ProjectOption1.jpg)
![Image](ProjectOption2.jpg)
![Image](ProjectOption3.jpg)
![Image](ProjectOption4.jpg)
* HT66F318 28ssop Schematic Diagram
![Image](CircuitDiagram.jpg)
![Image](MCUdiagram.jpg)

### How to test it
* PC�q�T�n�󰵬��D�ʤu��, ��ĳ(9600,n,8,1), �榡���RS-485�榡 (PC���OCRC�� A0 0A�N��, MCU���X����CRC-16)
* For Example: 
* UART Formate(Get from MCU): 44 03 00 00 00 04 A0 0A   #Ū��EEPROM��}0x0000,4��(�@�p8��bytes)
MCU return�]�p�̤j�C��Ū���|��(8byte) ���X�p: 44 03 08 00 01 02 03 04 05 06 07 CRC CRC

* UART Formate(Write to MCU): 44 06 00 0A EE FF A0 0A   #�g�JEEPROM��}0x000A,��Ƭ�0xEEFF
MCU return: 44 06 00 0A EE FF CRC CRC

### Other
* UART access to ADC internal 10 bits resolution.
* UART access to ADC converter(HY3118 24bit ADC) via I2C bus.
* UART access to OLED 16x2 driver via SPI bus.

