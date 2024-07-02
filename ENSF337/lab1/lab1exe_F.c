/*
	File Name: lab1exe_F.c
	Assignment: Lab 1 Exercise F
	Lab Section: B01
	Completed By: Andy Wang and Sebastian Silva
	Development Date: May 9, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    return 0;
}

void create_table(double v){
	printf("Angle		t		d\n(deg)		(sec)		(m)\n");
	
	for(double angle = 0; angle <= 90; angle += 5){
		double radian = degree_to_radian(angle);
		printf("%f		%f		%f\n", angle, Projectile_travel_time(radian, v), Projectile_travel_distance(radian, v));
	
	}
}

double Projectile_travel_time(double a, double v){
	return ((sin(a)*v)/G)*2;
}

double Projectile_travel_distance(double a, double v){
	return pow(v,2)/G*sin(2*a);
}

double degree_to_radian(double d){
	return d*PI/180;
}
/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */
