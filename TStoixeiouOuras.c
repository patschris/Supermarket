#include "TStoixeiouOuras.h"

/* Abstraction of = for any type */
void TSOurasSetValue (TSOuras *stoixeioPtr, TSOuras data) {   
	*stoixeioPtr = data;  /* basic type assignment */
}


/* Sets time where customer entries a queue */
void PelatisSetXronoEisodou (TSOuras *stoixeioPtr, int xronos) {
	stoixeioPtr->XronosEisodou=xronos;
}


/* Returns time where customer entried a queue */
int PelatisGetXronoEisodou (TSOuras stoixeio) {
	return stoixeio.XronosEisodou;
}


/* Sets service time */
void PelatisSetXronoEksipiretisis (TSOuras *stoixeioPtr, int duration) {
	stoixeioPtr->XronosEksipiretisis = duration;
}


/* Returns service time */
int PelatisGetXronoEksipiretisis (TSOuras stoixeio) {
	return stoixeio.XronosEksipiretisis;
}
