/*
 * GPS.c
 *
 *  Created on: 6 Tem 2023
 *      Author: Samet
 */
#include "GPS.h"

void disableNMEA_Frame(GPS_ *gpsdata, uint8_t *packet) {
	HAL_UART_Transmit(gpsdata->gps_uart, packet, 16, 100);
}

void changeBaud(GPS_ *gpsdata, uint16_t baudrate) {

}
/*
void printGPSData(GPS_ *gpsdata) {
	char buff[200];
	int len =
			sprintf(buff,
					"Long= %.5f Lat = %.5f Alt= %.5f \n EW=%c NS=%c \n Time= %d:%d:%d Date:%d:%d:%d  %d\n",
					gpsdata->GGA.location.longitude, gpsdata->GGA.location.latitude,
					gpsdata->GGA.alt.altitude, gpsdata->GGA.location.EW, gpsdata->GGA.location.NS,
					gpsdata->GGA.time.hour, gpsdata->GGA.time.min, gpsdata->GGA.time.sec, gpsdata->RMC.date.day,
					gpsdata->RMC.date.mon, gpsdata->RMC.date.yr, gpsdata->GGA.numOfSat);
	HAL_UART_Transmit(&huart2, (uint8_t*) buff, len, 1000);
}
*/
