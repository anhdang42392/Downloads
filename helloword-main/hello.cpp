#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
   
    int i = 0;
    char idGPS [10] = {0};
    char timeUTC [15] = {0};
    char Latitude[15] = {0};
    char NSindicator[15] = {0};
    char Longtitude[15] = {0};
    char EWindicator[15]= {0};
    char fixIndicator[3]= {0};
    char Satellies[3] = {0};
    char HDOP[10] = {0};
    char altitudeMSL[10] = {0};
    char units[2] = {0};
    char separationGeoid[10] = {0};
    char unitsGeoid[2] = {0};
    char AgeDiff[15]={0};
    char DiffStation[15] = {0};
    char checkSum[5] = {0};
    
    char datatoken[] = "$GPGGA, ,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E" ;
    char *p ;
    char Output[15] = {0};
    printf("size: %ld\n",strlen(datatoken));
    i = 0;
    p = strtok(datatoken,",");
    sprintf(idGPS,"%s\n",p);
    printf ("Message ID: %s", idGPS);
     p = strtok(NULL,",");
     sprintf(timeUTC,"%s\n",p);
      printf ("UTC time: %s", timeUTC);
      p = strtok(NULL,".");
     sprintf(Latitude,"%s\n",p);
      printf ("Latitude: %s", Latitude);
     
    while(p != NULL){
        i++ ;
        switch(i) {
            case 1:
                sprintf(timeUTC,"%s\n",p);
                printf("UTC time: %s", timeUTC);
                p = strtok(NULL, ",");
                break;
            case 2:
                sprintf(Latitude,"%s\n",p);
                printf("Latitude: %s", Latitude);
                p = strtok(NULL, ",");
                break;    
            case 3:
                sprintf(NSindicator,"%s\n",p);
                printf("N/S Indicator: %s",NSindicator);
                p = strtok(NULL, ",");
                break;
            case 4:
                sprintf(Longtitude,"%s\n",p);
                printf("Longitude: %s", Longtitude);
                p = strtok(NULL, ",");
                break;
            case 5:
                sprintf(EWindicator,"%s\n",p);
                printf("E/W Indicator: %s", EWindicator);
                p = strtok(NULL, ",");
                break;
            case 6:
                sprintf(fixIndicator,"%s\n",p);
                printf("Position Fix Indicator: %s", fixIndicator);
                p = strtok(NULL, ",");
                break;
            case 7: 
                sprintf(Satellies,"%s\n",p);
                printf("Satellies Used: %s", Satellies);
                p = strtok(NULL, ",");
                break;
            case 8: 
                sprintf(HDOP,"%s\n",p);
                printf("Horizontal Dilution of Precision: %s", HDOP);
                p = strtok(NULL, ",");
                break;
            case 9:
                sprintf(altitudeMSL,"%s",p);
                p = strtok(NULL, ",");
                sprintf(units,"%s",p);
                printf("MSL Altitude: %s %s\n", altitudeMSL,units);
                p = strtok(NULL, ",");
                break;
            case 10:
                sprintf(separationGeoid,"%s",p);
                p = strtok(NULL, ",");
                sprintf(unitsGeoid,"%s",p);
                printf("Geoid Separation: %s %s\n", separationGeoid, unitsGeoid);
                p = strtok(NULL, ",");
                break;
            case 11:
                sprintf(AgeDiff,"%s",p);
                p = strtok(NULL, "*");
                sprintf(DiffStation,"%s",p);
                printf("Differential GPS: %s, %s\n", AgeDiff, DiffStation);
                p = strtok(NULL, ",");
                break;
            case 12:
                sprintf(checkSum,"%s\n",p);
                printf("Checksum: *%s", checkSum);
                p = strtok(NULL, ",");
                break;
            
        }
        
        
    }

    return 0;
}