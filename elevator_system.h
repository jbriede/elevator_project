#pragma once
// Controls

// The cars will run on their own and pick up passengers from floors that are on the way and the same direction
// When a car is finished serving floors it is assigned or picking up people along the way, it will not be busy
// and the elevator system can assign it a floor to go to if there is a passenger.

#include "bst.h"
#include <string>
#include <vector>
#include "simulator.h"
#include "passenger.h"
#include <forward_list>
#include <queue>
#ifndef ELEVATOR_SYSTEM
#define ELEVATOR_SYSTEM

using namespace std;

//Controls interactions between the Floors and Cars
class Simulator::Elevator_System
{
protected:
    // Cars check these to see if they can pick up a passengers traveling in the same direction,
    // similar to a real elevator.
    BinarySearchTree<int, bool>*up_list = new BinarySearchTree<int, bool>; // up binary search tree
    BinarySearchTree<int, bool>*down_list = new BinarySearchTree<int, bool>; // down binary search tree
    
public:
    class Car;
    class Floor;
    Elevator_System(int number_of_cars, Simulator * Simulator_ptr);
    
    // See if any cars can services the requsts in the queue
    void service_requests();
    
    // Execute next move for cars
    void tick(int time);
    
    // Address a call
    void call_elevator(Passenger* passenger);

private:
    int number_of_floors;
    int number_of_cars;
	void add_request(int floor, string direction);
    // Inplementing as vector because specific floors will have to be accessed.
    vector<Floor> floors;
    
    // Implementing Cars as single linked list (front list) because there is no need to access a specific car, just find first available one
    forward_list<Car *> cars;
    
    // To keep program modular, we will not keep a que of passengers, as that's the floors job
    // instead there the elevator will have a queue of requests for particlular floors as a real eleators do
    struct Request {
        int floor;
        string direction;
    };
    
    // If no elevador can get someone, request gets temporarily stored
    queue<Request> * requests = new queue<Request>;
    
    // Add passenger to FLOOR que
    void add_to_que(int floor, Passenger * passenger, string direction);
    
    // Add floor to BST
    void add_floor(int floor, string direction);
    
    // Check to see if a car is alreay going to pass the floor called
    bool car_in_route(int floor, string direction);

    // Pick a car that isn't busy **
    // If no car is picked, add request to the request queue
    Car * pick_car();
};
#endif