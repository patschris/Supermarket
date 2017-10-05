#ifndef __CH2_QARRAY__ 
#define __CH2_QARRAY__

#include "TStoixeiouOuras.h"

#define QSIZE 1000 // Maximum customers in a queue

typedef struct {
	int embros;		// position of first element 
	int piso;		// position of last  element
	int metritis;   // counter - elements in queue
	int CountIn;	// counter - total amount of customer entered the queue
	int CountOut;	// counter - total amount of customer exited the queue
	TSOuras pinakas[QSIZE];	// array of queue elements
} TOuras;	   // New Name of Type Queue

void OuraDimiourgia(TOuras *);
int	OuraKeni (TOuras); 
int OuraProsthesi (TOuras *, TSOuras);
int OuraApomakrynsh (TOuras *, TSOuras *);
int OuraGetSize (TOuras);
int OuraGetCountIn (TOuras);
int OuraGetCountOut (TOuras);

#endif
