//  ENSF 337, Spring 2024 Exercise C
//  lab4Clock.cpp
//  By: Andy Wang

#include "lab4Clock.h"

//Constructors
Clock::Clock(){
	//default constructor setting the time to 00:00:00
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::Clock(int time){
	
	//convert time into seconds into hours, minutes, and seconds
	
	if(time < 0){ //if the argument is negative, then make the time 0,0,0
		hour = 0;
		minute = 0;
		second = 0;
	}
	else{
		sec_to_hms(time);
		
	}
}

Clock::Clock(int time_hours, int time_minutes, int time_seconds){
	// if time_hours is not from 0 to 23 or time_minutes and time_seconds is not from 59 to 0, make the time 0,0,0.
	if(time_hours > 23 || time_hours < 0 || time_minutes > 59 || time_minutes < 0 || time_seconds > 59 || time_seconds < 0){
		hour = 0;
		minute = 0;
		second = 0;
	}
	//if the parameters are met, make the time have the same value as their respective arguments.
	else{
		hour = time_hours;
		minute = time_minutes;
		second = time_seconds;
	}
	
}

//Getters
int Clock::get_hour () const{
	return hour;
}

int Clock::get_minute () const{
	return minute;
}

int Clock::get_second () const{
	return second;
}

//Setters
void Clock::set_hour(int arg){
	if(0<arg && arg<24)hour = arg;
}

void Clock::set_minute(int arg){
	if(0<arg && arg<60)minute = arg;
}

void Clock::set_second(int arg){
	if(0<arg && arg<60)second = arg;
}

//Implementer Functions
void Clock::increment(){
	sec_to_hms(hms_to_sec() + 1);
}

void Clock::decrement(){
	sec_to_hms(hms_to_sec() - 1);
}

void Clock::add_seconds(int time_seconds){
	sec_to_hms(hms_to_sec() + time_seconds);
}

//Helper functions
int Clock::hms_to_sec () const{
	//converts hour, minute, and second into seconds.
	return hour*3600 + minute*60 + second;
}

void Clock::sec_to_hms (int time) {
		while(time < 0){ //if time is negative, add it to 24 hours to move the time backwards.
			time = 86400 + time;
		}
		while(time/3600 >= 24){ //if the hours converted from the time is greater than or equal to 24 hours, remove 24 hours until time converted is less than 24 hours
			time = time - 86400;
		}
		hour = time/3600;
		time = time - hour*3600;
			
		minute = time/60;
		second = time - minute*60;
}


	
