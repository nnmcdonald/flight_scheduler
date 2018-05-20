#pragma once
#include <string>
using namespace std;

class Node
{
public:
	Node();
	Node(string flight, string flightNum, int time, Node* next);
	Node* getNext();
	void setNext(Node* next);
	int getTime();
	string getFlight();
	string getFlightNum();
private:
	string flight;
	string flightNum;
	int time;
	Node* next;
};

