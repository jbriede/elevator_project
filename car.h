#pragma once

// knows wait times, knows how long at each floor, knows passengers

#ifndef CAR
#define CAR
#include <iostream>
#include <queue>
#include "passenger.h"
#include "floor.h"
#include <forward_list>
#include "elevator_system.h"
#include <string>
#include "bst.h"
#include "simulator.h"

using namespace std;



class Simulator::Elevator_System::Car
{
    
private:

	int current_time;
    const static int number_of_floors = 12;
	int time_between_floors = 3; // seconds
	int const min_floor_time = 5; // seconds
	int const pass_load_time = 1; // Time for each passenger to load
    
    // These calls have priority and hold the direction which the passenger who
    // has been waiting the longest needs to go *
    string floors_to_stop_at[number_of_floors];
    
    bool busy;
    int const home_floor = 0; // home floor
    int current_floor;
    int change_direction_floor;
    int time_to_next_floor; // time until the elevator will reach next floor
    int time_until_departure;
    
    //pointer to ancestor
    Simulator * Simulator_ptr;
    string direction;
    
    //foreward_list(single linked list) of passengers
    forward_list<Passenger>* passengers = new forward_list<Passenger>;
    
    // Ptr to parent
    Elevator_System * elevator_system_ptr;
    
    void handle_floor_load_unload();
    
    void unload_car();
    
public:
    Car(Elevator_System * Elevator_System_ptr, Simulator * Simulator_ptr1);

    bool is_busy();
    
    // Move the car (car decides where it goes on it's own)
    void move(int time);
    
    int get_current_floor() {
        return current_floor;
    }
    
    //Print out some information about what the elevator is doing
    void stats();
    
    void send_home();
    
    //Take people from floor que and ad them to Car Que
    void load_car(queue<Passenger>* new_passengers);
    
    
    // Tell elevator someone needs picked up
	void send_to_floor(int floor, string intended_direction);

	string get_direction();
	int get_lowest_floor();
	int get_highest_floor();
    
    bool check_floor();

};
#endif