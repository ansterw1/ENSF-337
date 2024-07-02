//  ENSF 337- Spring 2024 lab 4, Exercise C
//  lab4Clock.h
//	By: Andy Wang

#ifndef lab4Clock.h
#define lab4Clock.h

class Clock {
public:
    
	//Constructors
	
	Clock ();
	//Promises:
	//Sets all data members to zero
	Clock (int time);
	//receives an integer argument in seconds, and initializes the Clock data members
	//with the number of hour, minute, and second in this argument
	//If the given argument value is negative the constructor should simply initialize the data members all to zeros
	Clock (int time_hours, int time_minutes, int time_seconds);
	//Promises:
	//receives three integer arguments and initializes the data members hour, minute,
	//and second with the values of these arguments. If any of the following conditions are true this constructor
	//should simply initialize the data members of the Clock object all to zeros:
	//• If the given values for second or minute are greater than 59 or less than zero.
	//• If the given value for hour is greater than 23 or less than zero.
	
	//Getters
	int get_hour () const;
	int get_minute () const;
	int get_second () const;
	
	//Setters
	void set_hour(int arg);
	void set_minute(int arg);
	void set_second(int arg);
	
	//Implementer functions
	void increment();
	//Promises:
	//increments the value of the clock’s time by one
	
	void decrement();
	//Promises:
	// that decrements the value of the clock’s time by one
	
	void add_seconds(int time_seconds);
	//Requirements:
	//receive a positive integer argument in
	//seconds
	//Promises:
	//adds the value of given seconds to the value of the current time
	
private:
	
	//values
    int hour;
    int minute;
	int second;
	
	//Helper functions
	int hms_to_sec () const;
	//converts hours, minutes, and seconds into seconds and returns it in  a clock object
	void sec_to_hms (int time);
	//converts seconds into hours, minutes, and seconds and sets the data members based on the argument
};

#endif /* lab4Clock.h */