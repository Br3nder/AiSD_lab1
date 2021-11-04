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
	cout << "adding an item 1 to the end of the list: " << list << endl;

	list.push_front(-1);
	cout << "adding an item -1 to the top of the list: " << list << endl;

	list.insert(-2, 0);
	cout << "inserting an item -2 with index 0: " << list << endl;

	list.remove(1);
	cout << "deleting an item with index 1: " << list << endl;

	list.set(0, -1);
	cout << "replacing an item with index 0 with item -1: " << list << endl;

	List list_2(2);
	list_2.push_back(3);
	list.push_back(list_2);
	cout << "adding the list with items {2, 3} to the end of the list: " << list << endl;

	list.pop_back();
	cout << "removing an item from the end of the list: " << list << endl;

	list.pop_front();
	cout << "removing an item from the top of the list: " << list << endl;

	cout << "the item with index 0: " << list.at(0) << endl;;

	cout << "size of the list: " << list.get_size() << endl;

	return 0;
}