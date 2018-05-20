#pragma once
#include "Node.h"

class FlightList
{
public:
	FlightList();
	void sortList(FlightList &list, int n);
	Node* getHdPtr();
	void remove();
	void add(string flight, string flightNum, int time, Node* next, Node* &currentNode);
private:
	Node* hdPtr;
};

