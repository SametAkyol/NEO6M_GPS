/*
 *NMEA.c
 *
 *Created on: 2 Tem 2023
 *     Author: Samet
 */
#include "NMEA.h"
#define GMT 3

static float convertToDecimalDegrees(const char *latLon, char *direction) {
	char deg[4] = { 0 };

	char *dot, *min;
	int len;
	float dec = 0;

	if ((dot = strchr(latLon, '.'))) {

		min = dot - 2;
		len = min - latLon;
		strncpy(deg, latLon, len);
		dec = atof(deg) + atof(min) / 60;
		if (strcmp(direction, "S") == 0 || strcmp(direction, "W") == 0)
			dec *= -1;
	}
	return dec;
}
static void decodeGGA(char **parse, GGAStruct *gga) {
	int temp = atoi(parse[1]);
	if (temp / 10000 + GMT > 24) {
		gga->time.hour = ((temp / 10000) + GMT) - 24;
	} else {
		gga->time.hour = (temp / 10000) + GMT;
	}

	if (((temp / 100) % 100) + (GMT % 100) > 60) {
		gga->time.min = ((temp / 100) % 100) + (GMT % 100) - 60;
	}else{
		gga->time.min = ((temp / 100) % 100);
	}

	gga->time.sec = (temp % 100);

	gga->location.latitude = convertToDecimalDegrees(parse[2], parse[3]);
	gga->location.NS = *parse[3];
	gga->location.longitude = convertToDecimalDegrees(parse[4], parse[5]);
	gga->location.EW = *parse[5];
	gga->fixValid = atoi(parse[6]);
	gga->numOfSat = atoi(parse[7]);
	gga->alt.altitude = atof(parse[9]);
}

/*
 *We just need speed and date for now
 *
 **/

static void decodeRMC(char **parse, RMCStruct *rmc) {
	int temp = atoi(parse[9]);
	rmc->date.day = temp / 10000;
	rmc->date.mon = (temp / 100) % 100;
	rmc->date.yr = (temp % 100) + 2000;
	rmc->speed = atoi(parse[7]) * 1.852;
}

bool extractNMEAMessage(uint8_t *buffer1, char *RMC, char *GPGGA) {
	int indx = 0;
	int indx2 = 0;
	while (buffer1[indx] != '\r') {
		RMC[indx] = buffer1[indx];
		indx++;
	}
	RMC[indx] = '\0';
	indx += 2;
	while (buffer1[indx] != '\r') {
		GPGGA[indx2] = buffer1[indx];
		indx++;
		indx2++;
	}
	GPGGA[indx2] = '\0';
	return 0;
}

bool parseMessage(uint8_t *buffer1, GGAStruct *gga, RMCStruct *rmc) {

	char GPRMC[80];
	char GPGGA[80];

    char *token = NULL;
    char *parse[20] = {NULL};

    int parsecount = 0;
    char *context = NULL;
	extractNMEAMessage(buffer1, GPRMC, GPGGA);


    token = strtok_r(GPRMC, ",", &context);

    while ((token != NULL) && parsecount < 20) {
        parse[parsecount++] = token;
        while (*context == ',') {
            parsecount++;
            context++;
        }

        token = strtok_r(NULL, ",", &context);
    }
    decodeRMC(parse, rmc);

     *parse = NULL;
     context = NULL;
     parsecount=0;
     token =NULL;
     token = strtok_r(GPGGA, ",", &context);
     while ((token != NULL) && parsecount < 20) {
         parse[parsecount++] = token;
 		/*If there is no character between two commas, we increment the index of "parsermc" until a character other than a comma is encountered by the context pointer.  */
         while (*context == ',') {
             parsecount++;
             context++;
         }
         token = strtok_r(NULL, ",", &context);
     }
        decodeGGA(parse, gga);

    return 0;
}
