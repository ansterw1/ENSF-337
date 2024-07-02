/*
	File Name: lab1_exe_D.c
	Assignment: Lab 1 Exercise D
	Lab Section: B01
	Completed By: Andy Wang and Sebastian Silva
	Development Date: May 9, 2024
*/


#include <stdio.h>
#include <math.h>
int main()
{
	double angle_in_radian;
	printf("Enter the angle in radian:\n");
	scanf("%lf", &angle_in_radian);
	printf("Sine of %f is %f.\n", angle_in_radian, sin(angle_in_radian));
	// Complete the program by calculating and displaying the Taylor's approximation.
	
	printf("Sine of %f is %f.\n", angle_in_radian, (angle_in_radian - pow(angle_in_radian,3.0)/6.0 + pow(angle_in_radian,5.0)/120.0 - pow(angle_in_radian,7.0)/5040.0));
	
	return 0;
}

