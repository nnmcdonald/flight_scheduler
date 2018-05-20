//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a number of gates, then reads in a flight schedule from a text file
//then it schedules the daily flights for each gate diplaying the result. Then it outputs the flights that couldn't
//be scheduled and why.
//
//The Flights in FlightList.txt MUST be sorted by arrival time

#pragma once
#include "FlightList.h"
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int gates = 0;
	FlightList flightList;
	Node* current = flightList.getHdPtr();
	int n = 0;
	ifstream inData;
	inData.open("FlightList.txt");

	//Creates a linked list where each node contains a string value for airline code, a string vlaue for flight number and an int representing 
	//the arrival time. These values are read in from a text file
	do
	{
			string flight;
			string flightNum;
			int time = 0;
			inData >> flight;
			inData >> flightNum;
			inData >> time;
			if (flight != "")
			{
				if (current != nullptr)
				{
					flightList.add(flight, flightNum, time, current->getNext(), current);
					current = current->getNext();
				}
				else
				{
					flightList.add(flight, flightNum, time, nullptr, current);
					current = flightList.getHdPtr();
				}
				n++;
			}
	} while (inData);

	cout << "How many gates would you like to schedule?" << endl;
	cin >> gates;

	for (int i = 0; i < gates; i++)
	{
		cout << " " << endl;
		cout << "Schedule for Gate " << i + 1 << ": " << endl;
		if (flightList.getHdPtr() != nullptr)
		{
			Node* current = flightList.getHdPtr();
			Node* nextFlight = current->getNext();
			Node* previous = current;

			while (current->getNext() != nullptr)
			{
				//The airport is only open form 0600-2300 and flights are grounded for an hour after landing, and cannot land or take off while
				//the airport is closed
				if (current->getTime() >= 600 && current->getTime() <= 2200)
				{
					//Prints the next available flight to the screen for the current gate
					cout << "Flight Code: " << current->getFlight() << "; Flight Number: " << current->getFlightNum() << "; Arrival Time: "
						<< current->getTime() << endl;
					bool done = false;
					while (!done)
					{
						//finds the next available flight
						if (nextFlight->getTime() > (current->getTime() + 100))
						{
							if (previous == current)
							{
								flightList.remove();
							}
							else
							{
								Node* temp = current;
								previous->setNext(current->getNext());
								delete temp;
							}
							current = nextFlight;
							while (previous->getNext() != current)
								previous = previous->getNext();
							nextFlight = nextFlight->getNext();
							done = true;
						}
						else
						{
							nextFlight = nextFlight->getNext();

						}
					}
				}
				else
				{
					if (previous != current)
						previous = previous->getNext();
					current = current->getNext();
					nextFlight = nextFlight->getNext();
				}
			}
		}
		else
			cout << "None" << endl;
	}
	
	cout << " " << endl;
	cout << "The flights that couldn't be scheduled are listed below with their flight info followed by the reason they couldn't be scheduled." << endl;

	//Flights still in the flightList couldn't be scheduled, so they are printed to the screen then removed from the list.
	while (flightList.getHdPtr() != nullptr)
	{
		if (flightList.getHdPtr()->getTime() < 600 || flightList.getHdPtr()->getTime() > 2200)
			cout << flightList.getHdPtr()->getFlight() << " " << flightList.getHdPtr()->getFlightNum() << " " << flightList.getHdPtr()->getTime() <<
			" Airport closed" << endl;
		else
			cout << flightList.getHdPtr()->getFlight() << " " << flightList.getHdPtr()->getFlightNum() << " " << flightList.getHdPtr()->getTime() <<
			" No available gates" << endl;
		flightList.remove();
	}

	system("pause");
}
