
// Knows where elevator is going from/to, records time for events

#pragma once
#ifndef PASSENGER_H
#define PASSENGER_H

using namespace std;


class Passenger
{
protected:  //Made protected so can be accessed by simulator class

	int floor_from; 
	int floor_to;

	int arrive_time; //when the elevator gets to the person
	int call_time;
	int exit_time;
	int trip_time;
	




public:
    ~Passenger();

    //Constructors
    
    Passenger();
    Passenger(int from, int to);

	int calculate_arrival_wait_time();
    
	//setters


	void set_call_time(int time)
	{
		call_time = time;
	}

	void set_arival_time(int time)
	{
		arrive_time = time;
	}
    
    void set_exit_time(int time)
    {
        exit_time = time;
    }
    
    void set_floor_from(int floor);
    
    void set_floor_to(int floor);


	//Getter

    int get_floor_to() {
        return floor_to;
    }
    
	int get_floor_from() {
		return floor_from;
	}
	int calculate_trip_time()
	{
		trip_time = exit_time - call_time;
		return trip_time;
	}

	void passenger_info();
	

};

#endif
