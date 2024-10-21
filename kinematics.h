#ifndef __KINEMATICS__
#define __KINEMATICS__
#include "xil_printf.h"

typedef struct kinematics{
	float L0;
	float L1;
	float L2;
	float L3;
	
	float servo_angle[6];
	float servo_range[6];
	float servo_pwm[6];
}kinematics_t;

kinematics_t kinematics_arm;

void setup_kinematics(float L0, float L1, float L2, float L3, kinematics_t *kinematics);
int kinematics_analysis(float x, float y, float z, float Alpha, kinematics_t *kinematics);

#endif
