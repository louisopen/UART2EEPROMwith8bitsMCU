### UARTtoEEPROMwith8bitsMCU
* HT-IDE3000 V7.99  HT66F317/HT66F318 28ssop
* Used HT66F318 control GPIO, LED matrix, EEPROM, ADC, I2C... via UART(Same with RS-485)
* 利用Holtek MCU HT66F318 28sop UART做為與EEPROM(內置)或其他GPIO的溝通途徑...開工必備工具
* 專業便宜又好用, 不過案例竟然這樣的少, 太可憐! 看不下去! 
* 首開範列是一個簡單利用PC軟件下達指令存取MCU內部的EEPROM(64byte), 但MCU內存緩衝故意弄小, 協議比照RS-485通訊協議格式. 8bit MCU 資源有限有許多限制慢慢挖掘吧!

* HT-IDE3000 V7.99
![Image](HT-IDE3000_version.jpg)
* HOLTEK C Compiler V3/Assembly
![Image](ProjectCompiler.jpg)
* HT66F318 Config
![Image](ProjectOption1.jpg)
![Image](ProjectOption2.jpg)
![Image](ProjectOption3.jpg)
![Image](ProjectOption4.jpg)


#### How to test it:
* PC通訊軟件做為主動工具, 協議(9600,n,8,1), 格式比照RS-485格式 
* For Example: 
* UART Formate(Get from MCU): 44 03 00 00 00 04 A0 0A   #讀取EEPROM位址0x0000,4組(共計8個bytes)

* UART Formate(Write to MCU): 44 06 00 0A EE FF A0 0A   #寫入EEPROM位址0x000A,資料為0xEEFF


#### Other:
* UART access to ADC internal 10 bits resolution.
* UART access to ADC converter(HY3118 24bit ADC) via I2C bus.
* UART access to OLED 16x2 driver via SPI bus.

