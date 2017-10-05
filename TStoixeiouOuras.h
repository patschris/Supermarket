#ifndef __TStoixeiouOuras__ 
#define __TStoixeiouOuras__

typedef struct {
	int XronosEisodou; /* Time of entering queue */
	int XronosEksipiretisis; /* Service Time */
} TSOuras; /* name TSOuras is used in ATD Oura - not to be changed */

/* name TSOurasSetValue is used in ATD Oura - not to be changed */
void TSOurasSetValue(TSOuras *, TSOuras); 

/* All names below indicate that Typos Stoixeiou is Pelatis */
void PelatisSetXronoEisodou (TSOuras *, int);
int  PelatisGetXronoEisodou (TSOuras);
void PelatisSetXronoEksipiretisis (TSOuras *, int);
int PelatisGetXronoEksipiretisis (TSOuras);

#endif
