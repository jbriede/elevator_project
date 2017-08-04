#include "passenger.h"
#include <iostream>
#include "simulator.h"

// Constructors

// create function to output information (time it took to do whatever)

Passenger::Passenger() {
    
}

Passenger::Passenger(int from, int to) {
    cout << "creating new passenger" << endl;
    set_floor_from(from);
    set_floor_to(to);
    set_call_time(2);
    set_arival_time(4);
    set_exit_time(10);
	
}



// Functions

Passenger::~Passenger() {
    cout << "Passenger went from floor " << this->get_floor_from() << " to " << this->get_floor_to() << endl;
}

int Passenger::calculate_arrival_wait_time() {
    int time = arrive_time - call_time;
    return time;
}

void Passenger::set_floor_from(int floor) {
    floor_from = floor;
}

void Passenger::set_floor_to(int floor) {
    floor_to = floor;
}

void Passenger::passenger_info()
{
	trip_time = Passenger::calculate_trip_time();
	int arrival_time = Passenger::calculate_arrival_wait_time();

	cout << "Passenger went from " << floor_from << " to floor " << floor_to;
	cout << "\nTotal time for elevator to arrive " << arrival_time << " seconds";
	cout << "\nTotal time spent waiting and traveling in elevator " << trip_time << " seconds";  


}