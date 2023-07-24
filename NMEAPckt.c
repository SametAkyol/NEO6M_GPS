/*
 * NMEAPckt.c
 *
 *  Created on: 7 Tem 2023
 *      Author: Samet
 */

#include "NMEAPckt.h"


uint8_t disable_GPGLV[NMEA_LEN] = { //---------------------------------------------//GPGSV off
		0xB5, // Header char 1
				0x62, // Header char 2
				0x06, // class
				0x01, // id
				0x08, // length char 1
				0x00, // length char 2
				0xF0, // payload (NMEA sentence ID char 1)
				0x03, // payload (NMEA sentence ID char 2)
				0x00, // payload I/O Target 0 - DDC			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 1 - Serial Port 1 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 2 - Serial Port 2 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 3 - USB			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 4 - SPI			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 5 - Reserved		- (1 - enable sentence, 0 - disable)
				0x02, // CK_A
				0x38  // CK_B
		};
uint8_t disable_GPVTG[NMEA_LEN] = { //---------------------------------------------//GPVTG off
		0xB5, // Header char 1
				0x62, // Header char 2
				0x06, // class
				0x01, // id
				0x08, // length char 1
				0x00, // length char 2
				0xF0, // payload (NMEA sentence ID char 1)
				0x05, // payload (NMEA sentence ID char 2)
				0x00, // payload I/O Target 0 - DDC			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 1 - Serial Port 1 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 2 - Serial Port 2 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 3 - USB			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 4 - SPI			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 5 - Reserved		- (1 - enable sentence, 0 - disable)
				0x04, // CK_A
				0x46  // CK_B
		};

uint8_t disable_GPGLL[NMEA_LEN] = { //---------------------------------------------//GPGLL off
		0xB5, // Header char 1
				0x62, // Header char 2
				0x06, // class
				0x01, // id
				0x08, // length char 1
				0x00, // length char 2
				0xF0, // payload (NMEA sentence ID char 1)
				0x01, // payload (NMEA sentence ID char 2)
				0x00, // payload I/O Target 0 - DDC       - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 1 - Serial Port 1 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 2 - Serial Port 2 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 3 - USB       - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 4 - SPI       - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 5 - Reserved    - (1 - enable sentence, 0 - disable)
				0x00, // CK_A
				0x2A  // CK_B
		};

uint8_t disable_GPGSA[NMEA_LEN] = { //---------------------------------------------//GPGSA off
		0xB5, // Header char 1
				0x62, // Header char 2
				0x06, // class
				0x01, // id
				0x08, // length char 1
				0x00, // length char 2
				0xF0, // payload (NMEA sentence ID char 1)
				0x02, // payload (NMEA sentence ID char 2)
				0x00, // payload I/O Target 0 - DDC			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 1 - Serial Port 1 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 2 - Serial Port 2 - (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 3 - USB			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 4 - SPI			- (1 - enable sentence, 0 - disable)
				0x00, // payload I/O Target 5 - Reserved		- (1 - enable sentence, 0 - disable)
				0x01, // CK_A
				0x31  // CK_B
		};
