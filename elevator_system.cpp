//
//  elevator_system.cpp
//  HW4
//
//  Created by Jacob Briede on 7/28/16.
//  Copyright © 2016 JacobBriede. All rights reserved.
//
#include "elevator_system.h"
#include <stdio.h>
#include "car.h"
#include "simulator.h"


Simulator::Elevator_System::Elevator_System(int num_of_cars, Simulator * Simulator_ptr) {
    number_of_cars = num_of_cars;
    // Create list of cars
    
    for (int c = 0; c < number_of_cars; c++) {
        
        cars.push_front(new Car(this, Simulator_ptr));
    }
    for (int c = 0; c < 12; c++) {
        floors.push_back(Floor());
    }
    // Create list of floors
    
    
}

void Simulator::Elevator_System::tick(int time) {
    for (auto it = cars.begin(); it != cars.end(); ++it)
    {
        
        (*it)->move(time);
       // (*it)->stats();
        service_requests();
    }
}
// Access que of correct floor and direction, add passenger to that queue
void Simulator::Elevator_System::add_to_que(int floor, Passenger *passenger, string direction) {
	floors[floor].add_to_queue(passenger, direction);
}

// Add floor to bst
void Simulator::Elevator_System::add_floor(int floor, string direction)
{

	if (direction == "up")
	{
		up_list->Add(floor, true);
	}
	else if (direction == "down")
	{
		down_list->Add(floor, true);

	}
	else
	{
		//cout << "\n\nfloor error";
	}

}

bool Simulator::Elevator_System::car_in_route(int floor, string direction) // iterates through all the cars, for each car, looks at floors each car has to go to (array) wip, check if same direction as front of stack (request->front)

{
	for (auto it = cars.begin(); it != cars.end(); ++it)
	{

//        cout << "Car supposidly going " << (*it)->get_direction() << endl;
//        cout << "Person supposidly goin " << direction << endl;
		if (((*it)->get_direction() == direction) && (direction == "down"))
		{
           // cout << "Lowest Car Floor: " << (*it)->get_lowest_floor() << endl;
           // cout << "Floor: " << floor << endl;
			if (((*it)->get_lowest_floor() <= floor) && (floor > (*it)->get_current_floor()))
			{
				return true;
			}

		}

		if (((*it)->get_direction() == direction) && (direction == "up"))
           // cout << "Highest Car Floor: " << (*it)->get_highest_floor() << endl;
           // cout << "Floor: " << floor << endl;
			if (((*it)->get_highest_floor() >= floor) && (floor < (*it)->get_current_floor()) )
			{
				return true;
			}
	}
	return false;
}



void Simulator::Elevator_System::add_request(int floor, string direction)
{

	struct Request temp_request = {floor, direction};
	requests->push(temp_request);
	
}

Simulator::Elevator_System::Car * Simulator::Elevator_System::pick_car()
{
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        //Pick first car that isn't busy
		if (!((*it)->is_busy())) {
            return (*it);
		}
    }
    return NULL;
}



void Simulator::Elevator_System::call_elevator(Passenger* passenger)
{
    string direction = "up";
    int floor = passenger->get_floor_from();
    if (passenger->get_floor_from() > passenger->get_floor_to()) {
        direction = "down";
    }
	add_to_que(floor, passenger, direction);
	add_floor(floor, direction);

	if (car_in_route(floor, direction))
	{
        cout << "A car is already in route" << endl;
		return;
	}
	else
	{
        Car * temp_car = NULL;
        temp_car = pick_car();
        
		if (temp_car != NULL) //if car is found
		{
			temp_car->send_to_floor(passenger->get_floor_from(), direction);
            cout << "a car is available" << endl;
		}

		else
		{
			add_request(floor, direction);
		}
		//delete temp_car;

	}
}

// Try to find a car to get backed up requests
void Simulator::Elevator_System::service_requests() {
    if (requests->empty()) {
       // cout << "No requests";
        return;
    }
    Car * temp_car = NULL;
    temp_car = pick_car();
    Request request1 = requests->front();
    if (temp_car != NULL) {
        temp_car->send_to_floor(request1.floor, request1.direction);
        requests->pop();
    }
    else if (car_in_route(request1.floor, request1.direction)) {
        requests->pop();
    }
}
