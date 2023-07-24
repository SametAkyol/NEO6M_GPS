/*
 * GPS.h
 *
 *  Created on: 6 Tem 2023
 *      Author: Samet
 */

#ifndef INC_GPS_H_
#define INC_GPS_H_
#include "main.h"
#define NMEA_LEN 16
#include "NMEA.h"
#include "NMEAPckt.h"


typedef struct{
	UART_HandleTypeDef *gps_uart;
	GGAStruct GGA;
	RMCStruct RMC;
}GPS_;

void disableNMEA_Frame(GPS_ *gpsdata, uint8_t *packet);
void changeBaud(GPS_ *gpsdata,uint16_t baudrate);
void printGPSData(GPS_ *gpsdata);
#endif /* INC_GPS_H_ */
