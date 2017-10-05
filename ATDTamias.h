#ifndef __ATDTAMIAS__
#define __ATDTAMIAS__

typedef struct {
	int enapomenonXronos; // remaining time until cashier serves a customer
	int TimeBusy; // total time when a cashier is busy
	int TimeInactive; // total time when a cashier is inactive
	int ArithmoPelaton; // amount of customer that a cashier served
} TTamias;

void TamiasDimiourgia (TTamias *);
void TamiasNewCustomer (TTamias *);
void TamiasSetXrono (TTamias *, int);
void TamiasSetBusy (TTamias *);
void TamiasNoWork (TTamias *);
int TamiasFree (TTamias);
int TamiasGetArithmosPelatwn (TTamias);
int TamiasGetEnapomenonXronos (TTamias);
int TamiasGetInactiveXronos (TTamias);
int TamiasGetBusyXronos (TTamias);

#endif
