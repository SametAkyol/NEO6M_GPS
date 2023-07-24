/*
 * NMEA.h
 *
 *  Created on: 2 Tem 2023
 *      Author: Samet
 */

#ifndef INC_NMEA_H_
#define INC_NMEA_H_
#include  <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>

typedef struct {
	uint8_t sec :6;
	uint8_t min :6;
	uint8_t hour :5;
} TIME;

typedef struct {
	float latitude;
	float longitude;
	char NS;
	char EW;
} LOCATION;

typedef struct {
	uint16_t yr :12;
	uint8_t day :5;
	uint8_t mon :4;
} DATE;

typedef struct {
	float altitude;
} ALTITUDE;

typedef struct {
	LOCATION location;
	ALTITUDE alt;
	TIME time;
	bool fixValid;
	uint8_t numOfSat;
} GGAStruct;

typedef struct {
	float speed;
	DATE date;
} RMCStruct;

bool extractNMEAMessage(uint8_t *buffer1, char *RMC, char *GPGGA) ;
bool parseMessage(uint8_t *buffer1, GGAStruct *gga, RMCStruct *rmc);

 #endif /* INC_NMEA_H_ */
