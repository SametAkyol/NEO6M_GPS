/*
 * NMEAPckt.h
 *
 *  Created on: 6 Tem 2023
 *      Author: Samet
 */

#ifndef INC_NMEAPCKT_H_
#define INC_NMEAPCKT_H_
#define NMEA_LEN 16
#include <stdint.h>
extern uint8_t disable_GPGSA[NMEA_LEN];
extern uint8_t disable_GPGLL[NMEA_LEN];
extern uint8_t disable_GPVTG[NMEA_LEN];
extern uint8_t disable_GPGLV[NMEA_LEN];


#endif /* INC_NMEAPCKT_H_ */
