#pragma once

#include <iostream>
#include "List.cpp"

//overloading the output operator
std::ostream& operator<< (std::ostream& out, const List& list) {
	if (list.get_size() == 0) std::cout << "List is empty\n";
	else {
		List::Item* item = list.head;
		out << item->data << ' ';
		while (item != list.tail) {
			item = item->next;
			std::cout << item->data << ' ';
		}
	}
	return out;
}
