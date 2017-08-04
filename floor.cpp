#include "floor.h"
#include <iostream>
using namespace std;

Simulator::Elevator_System::Floor::Floor() {
    
}

void Simulator::Elevator_System::Floor::add_to_queue(Passenger *passenger, string direction)
{
	if (direction == "down")
	{
		down_queue->push(*passenger);
	}

	else if (direction == "up")
	{
		up_queue->push(*passenger);
	}

	else
	{
		cout << "Something got fucked up";
	}
}
