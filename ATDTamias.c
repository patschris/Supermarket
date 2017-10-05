#include "ATDTamias.h"


/* Creates a new cashier */
void TamiasDimiourgia (TTamias *Tamias) {
	Tamias->enapomenonXronos = 0;
	Tamias->TimeBusy = 0;
	Tamias->TimeInactive = 0;
	Tamias->ArithmoPelaton = 0;
}


/* A new customer arrives in the queue */
void TamiasNewCustomer (TTamias *Tamias) {
	Tamias->ArithmoPelaton++;
}


/* Cashier has no customer waiting (inactive cashier) */
void TamiasNoWork (TTamias *Tamias) {
	Tamias->TimeInactive++;
}


/* Check if a cashier is free to serve */
int TamiasFree (TTamias Tamias) {
	return (Tamias.enapomenonXronos == 0);
}


/* Setters and getters for Tamias' fields */

void TamiasSetXrono (TTamias *Tamias, int xronosEksipiretisis) {
	Tamias->enapomenonXronos = xronosEksipiretisis;
}

/* Cashier serves a customer. We should decrease remaining time until a cashier serves the customer */
void TamiasSetBusy (TTamias *Tamias) {
	Tamias->TimeBusy++;
	Tamias->enapomenonXronos--;
}


int TamiasGetArithmosPelatwn (TTamias Tamias) {
	return Tamias.ArithmoPelaton;
} 


int TamiasGetEnapomenonXronos (TTamias Tamias) {
	return Tamias.enapomenonXronos;
}


int TamiasGetInactiveXronos (TTamias Tamias) {
	return Tamias.TimeInactive;
}


int TamiasGetBusyXronos (TTamias Tamias) {
	return Tamias.TimeBusy;
}
