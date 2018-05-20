//Nathaniel McDonald
//CSCE A311 Assignment 1
//
//This program allows the user to enter a number of gates, then reads in a flight schedule from a text file
//then it schedules the daily flights for each gate diplaying the result. Then it outputs the flights that couldn't
//be scheduled and why.
//

#pragma once
#include "FlightList.h"

FlightList::FlightList()
{
	hdPtr = nullptr;
	
}

//This program requires the schedule to be sorted by time

//Removes the top node in the list
void FlightList::remove()
{
	if (hdPtr->getNext() != nullptr)
	{
		Node* temp = hdPtr;
		hdPtr = hdPtr->getNext();
		delete temp;
	}
	else
	{
		Node* temp = hdPtr;
		hdPtr = nullptr;
		delete temp;
	}
}

//Adds a node in the list beetween currentNode and nextNode
void FlightList::add(string flight, string flightNum, int time, Node* nextNode, Node* &currentNode)
{
	Node* node = new Node(flight, flightNum, time, nextNode);
	if (currentNode != nullptr)
		currentNode->setNext(node);
	else
		hdPtr = node;
}

Node* FlightList::getHdPtr()
{
	return hdPtr;
}
