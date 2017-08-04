#pragma once

#include <queue>
#include "passenger.h"
#include "elevator_system.h"
#include <string>
#include "simulator.h"
// Controls
#ifndef FLOOR
#define FLOOR


//Controls interactions between the Floors and Cars
class Simulator::Elevator_System::Floor
{
    friend class Elevator_System::Car;
public:
    Floor();
    Floor(int number);
	void add_to_queue(Passenger *passenger, string direction);

protected:
    queue<Passenger>* up_queue = new queue<Passenger>; 
    queue<Passenger>* down_queue = new queue<Passenger>;
};
#endif