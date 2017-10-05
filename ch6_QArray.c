#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ch6_QArray.h"


/* Creates a queue */
void OuraDimiourgia (TOuras *oura) {
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
	oura->CountIn = 0;
	oura->CountOut = 0;
}


/* Checks if the queue is empty */
int OuraKeni (TOuras oura) {
	return (oura.metritis == 0);
}


/* Check if the queue is full */
int OuraGemati (TOuras oura) {
		return (oura.metritis == QSIZE);
}


/* Add a customer in a queue if the queue isn't full */
int OuraProsthesi (TOuras *oura, TSOuras stoixeio) {
    int status = 0;
	if (!OuraGemati(*oura)) {
        status = 1;
		TSOurasSetValue(&(oura->pinakas[oura->piso]),stoixeio); 
		oura->piso = (oura->piso+1) % QSIZE;
		oura->metritis++;
		oura->CountIn++;
		assert (OuraGetCountIn(*oura)-OuraGetCountOut(*oura) == oura->metritis);
	}
	return status;
}


/* Removes a customer from a queue if the queue isn't empty */
int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio) {
    int status = 0;
	if (!OuraKeni(*oura)) {
        status = 1;		
        TSOurasSetValue(stoixeio, oura->pinakas[oura->embros]);
		oura->embros = (oura->embros+1) % QSIZE;
		oura->metritis--; 
		oura->CountOut++;
		assert (OuraGetCountIn(*oura)-OuraGetCountOut(*oura) == oura->metritis);
	}
	return status;
}


/* Returns the size of the Queue*/
int OuraGetSize (TOuras oura) {
	return oura.metritis;
}


/* Returns the total amount of customer entered the queue */
int OuraGetCountIn (TOuras oura) {
	return oura.CountIn;	
}


/* Returns the total amount of customer exited the queue */
int OuraGetCountOut (TOuras oura) {
	return oura.CountOut;
}
