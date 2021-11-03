#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "List.h"
using namespace std;


int main() {
	List list(0);
	cout << "List with the item 0: " << list << endl;

	list.push_back(1);
	cout << "pushing back an item 1: " << list << endl;

	list.push_front(-1);
	cout << "pushing front an item -1: " << list << endl;

	list.insert(-2, 0);
	cout << "inserting item -2 by index 0: " << list << endl;

	list.remove(1);
	cout << "deletion an element with index 1: " << list << endl;

	list.set(0, -1);
	cout << "replacing an element with index 0 with element -1: " << list << endl;



	return 0;
}