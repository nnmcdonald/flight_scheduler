//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a number of gates, then reads in a flight schedule from a text file
//then it schedules the daily flights for each gate diplaying the result. Then it outputs the flights that couldn't
//be scheduled and why.
//

#pragma once
#include "Node.h"

Node::Node()
{
	next = nullptr;
}

Node::Node(string flight, string flightNum, int time, Node* next) : flight(flight), flightNum(flightNum), time(time), next(next)
{

}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* newNext)
{
	next = newNext;
}

int Node::getTime()
{
	return time;
}

string Node::getFlight()
{
	return flight;
}

string Node::getFlightNum()
{
	return flightNum;
}