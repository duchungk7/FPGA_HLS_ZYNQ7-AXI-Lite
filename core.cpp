/*
* Calculate the gravity between 2 bodies mass(m1, m2) and distance dist 
* Use all parameters/results with AXI4-Lite slave ports
* (Group all parameters on a single AXI4-Lites interface CRTLS)
*
*
*/
#include "test_core.h"
float myGravity(float m1, float m2, float dist)
{
#pragma HLS INTERFACE s_axilite port=dist bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=m2 bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=m1 bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTLS

	float force = 0;
	float distSquare = 0;
	
	//Avoid division by zero
	if(dist == 0){
		distSquare = 0.000001f; // (0.001^2)
	}else{
		distSquare = (dist*dist);
	}
	
	force = 10.0f * (m1 * m2) / distSquare;
	
	return force;
}
