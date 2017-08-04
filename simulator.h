#pragma once
#ifndef SIMULATOR_H
#define SIMULATOR_H


#include "passenger.h"
#include <iostream>
#include <vector>
//#include "car.h"

using namespace std;


class Simulator : private Passenger //inherited class to access protected functions of passenger.cpp
{

public:
    class Elevator_System;

	Simulator(int cars, int people);//# cars, # people, # floors);
	
		//save the # passengers

	void handle_data(Passenger passenger);
	void print_data();
	void run_simulation(int time);
	int get_interval(int time);

private:
    
	int average_wait_time = 0;
    int num_cars = 0;
    int num_floors = 0;
    int passenger_num = 0;
    Elevator_System * elevator_system_ptr;
    
    int total_passengers = 0;
    //vector<int> trip_times; //holds the trip time for each passenger
    //vector<int> arrival_times; //holds how long the elevator took to arrive for each passenger
    int total_times = 0;
    int average_time = 0;

};

#endif // !SIMULATOR_H