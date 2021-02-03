/*
 * Ladesaeule_mit_ID.c
 *
 * Created: 04.02.2020 14:25:45
 * Author : Marcel Hammerl
 */ 

#include "CalcMain.h"


int main(void)
{
	vCalcSysInit();
    while (1) 
    {
		

// 		1. Ladevorgang starten
// 		2. vCalcSetLoadingCapacity() aufrufen	-> berechnen der Ladeleistung und Ausgabe der aktuellen Ladeleistung
//		3. vCalcSetLoadingCapacity() schließt wenn Ladevrogang vorbei	-> Relay abschalten
// 		4. nach Beenden des Ladens vCalcGetLoadingCapacity() aufrufen	-> gesamte Ladeleistung abrufen
// 		
		
    }
}

void vCalcSysInit (){

	
	vCalcCalculationInit();
	vCalcADCInit();
	vCalcTimerInit();
}

