#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "List.h"
using namespace std;


int main() {
	List m(3);
	m.push_back(11);
	m.push_back(11);
	m.push_back(11);
	m.push_back(11);

	

	std::cout<<m<<std::endl;
	List m_d(2);
	m_d.push_back(m);
	m_d.push_back(m);
	m_d.push_back(m);
	std::cout << m_d << std::endl;

	for (int i = 0; 1 < 30; i++) {
		m_d.pop_front();
		std::cout << m;
	}
}