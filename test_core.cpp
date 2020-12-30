#include <stdio.h>
#include <math.h>
#include "test_core.h"

double goldRef[] = {2000000000.00000, 2000, 500, 222.222222222222, 125, 80, 55.5555555555556, 40.8163265306122, 31.2500000000000, 24.6913580246914};

int main()
{
	printf("Testing gravity for mass m1=10 m2=20\n");
	float errorAcc = 0;
	for (int idx = 0; idx < 10; idx++)
	{
		// Call top function
		float force = myGravity(10, 20,idx);
		
		// Calculate difference between result and reference
		float errorCalc = fabsf(force - goldRef[idx]);
		errorAcc += errorCalc;
		
		// Don't put a printf with the string "Error", because vivado HLS will this 
		printf("%d) Force: %f Ref:%f Diff: %f\n", (idx+1), force, goldRef[idx], errorCalc);
		
		if(errorCalc > 1)
		{
			printf("Error to big abort\n");
			
			// Xilinx recommands error return to be between 1...255
			return 1;
		} // end of if
	} // end of for loop
	
	printf("No errors occured average error: %f\n", errorAcc/10.0f);
	return 0;
}























