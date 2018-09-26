#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "ATDTamias.h"
#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"

#define MAX_TIME 10 

int main(void) {	
	time_t	t;
	float pithanotita_afiksis; // arrival probability
	unsigned int xronos; // simulation's clock
	unsigned int xronos_kleisimatos;  // closing time
	TSOuras	Pelatis; // Customer
	float randomAfixi; // random arrival
	int K, i, index, qcount, paratasi, first;

	printf("Give closing hour (>0), arrival probability in unit of time (0,1), amount of cashiers(> 0)\n");
	scanf("%u %f %d",&xronos_kleisimatos,&pithanotita_afiksis,&K); // orismata apo ti grammi entolwn

	printf("The super market closes after %d units of time \n", xronos_kleisimatos);
	printf("The probability of a customer's arrival in units of time : %3.2f\n",pithanotita_afiksis);
	printf("The super market has %d cashiers\n", K);
	
	xronos = 0;	
	srand(time(&t));

	TOuras pinakas_ouron [K]; // array that contains supermarket's queues
	TTamias pinakas_tamion [K]; // cashiers for the queues
	unsigned int pinakas_xronosAnamonis[K]; // total waiting time for each queue
	float pinakas_mesosXronos[K]; // average time of waiting time for each queue

	for (i=0;i<K;i++) {
		OuraDimiourgia(&pinakas_ouron[i]); // create queues
		TamiasDimiourgia(&pinakas_tamion[i]); // create cashiers
		pinakas_xronosAnamonis[i] = 0; // initialize arrays
		pinakas_mesosXronos[i] = 0;
	}
	index=0;
	while( xronos < xronos_kleisimatos ) { // super market closes at xrono kleisimatis
		randomAfixi = (float)rand()/(float)RAND_MAX; // random arrival
		if (randomAfixi < pithanotita_afiksis) { 
			PelatisSetXronoEisodou(&Pelatis, xronos); // create a customer
			PelatisSetXronoEksipiretisis (&Pelatis,(int)rand() % MAX_TIME + 1); // random service time between 1 and MAX_TIME
			if (!OuraProsthesi(&pinakas_ouron[index], Pelatis)) {
                  printf("Too small queue. Simulation is over\n");
                  return -1;
        	}
			index = (index+1) % K; // go to next cashier (next cashier of the last is the first cashier)
    	}	
    	for(i=0;i<K;i++) {
			/* Cashier i serves queue i */
			if (TamiasFree(pinakas_tamion[i]) == 0) {	// free cashier
				if (!OuraKeni(pinakas_ouron[i])) {			// if customer exists
					OuraApomakrynsh(&pinakas_ouron[i],&Pelatis); // Remove customer from queue because the cashier is serving him				
					pinakas_xronosAnamonis[i] += xronos - PelatisGetXronoEisodou(Pelatis);	// waiting time
					TamiasNewCustomer(&pinakas_tamion[i]);
					TamiasSetXrono(&pinakas_tamion[i],PelatisGetXronoEksipiretisis(Pelatis)-1); // remaining time to serve this customer
				}
				else {
					TamiasNoWork(&pinakas_tamion[i]); // There is no customer. Cashier is inactive
				}
			}
			else {
				TamiasSetBusy(&pinakas_tamion[i]); // Cashier is busy with a customer
			}
		}		
		xronos++; // increase simulation time
	}

	paratasi = 0; // Extra time to serve remaining customers after the closing hour
	first = 0;	
	do {
		qcount = 0;
		for(i=0;i<K;i++) {
			/* Same code until there is no other customer */
			if ( TamiasGetEnapomenonXronos(pinakas_tamion[i]) == 0) {
				if (!OuraKeni(pinakas_ouron[i])) {
					OuraApomakrynsh(&pinakas_ouron[i],&Pelatis);				
					pinakas_xronosAnamonis[i] += xronos - PelatisGetXronoEisodou(Pelatis);
					TamiasNewCustomer(&pinakas_tamion[i]);
					TamiasSetXrono(&pinakas_tamion[i],PelatisGetXronoEksipiretisis (Pelatis)-1);
				}
				else {
					TamiasNoWork(&pinakas_tamion[i]);
				}
			}
			else {
				TamiasSetBusy(&pinakas_tamion[i]);
			}
			qcount = qcount + OuraGetSize(pinakas_ouron[i]); // remaining customers in the super markrt
		}	
		if (first !=0) paratasi++; 
		first=1;
	} while (qcount!=0);

    /* Printing cashier's data */
	for(i=0;i<K;i++) {
		if (TamiasGetArithmosPelatwn(pinakas_tamion[i])  == 0) pinakas_mesosXronos[i] = 0.0;
		else pinakas_mesosXronos[i] = (float)pinakas_xronosAnamonis[i]/(float)TamiasGetArithmosPelatwn(pinakas_tamion[i]);
		printf("\nCashier's data %d\n", i+1);
		printf("Customers served: %d\n",TamiasGetArithmosPelatwn(pinakas_tamion[i]));
		printf("Customers didn't served: %d\n",OuraGetSize(pinakas_ouron[i]));
		printf("Total amount of customers entered the queue: %d\n",OuraGetCountIn(pinakas_ouron[i]));
		printf("Total amount of customers exited the queue: n %d\n",OuraGetCountOut(pinakas_ouron[i]));
		printf("Cashier was inactive for %d units of time\n", TamiasGetInactiveXronos(pinakas_tamion[i]));
		printf("Average waiting time was %4.2f units of time\n\n", pinakas_mesosXronos[i]);
		assert(OuraGetCountIn(pinakas_ouron[i])-OuraGetCountOut(pinakas_ouron[i]) == OuraGetSize(pinakas_ouron[i]));
	}
    printf("The supermarket was open for %d units of time after the closing hour\n",paratasi);
    printf("The supermarket was open for %d units of time in total\n", xronos_kleisimatos + paratasi);
	return 0;
}
