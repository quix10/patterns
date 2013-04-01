/*
 * main.cpp
 *
 *  Created on: Mar 26, 2013
 *      Author: quix
 */
#define MOTIF

#include <stdio.h>
#include <vector>
#include "AbstractFactory.h"
#include "Factory.h"
#include "Prototype.h"

int main()
{
	// Abstract factory

	Factory* factory = 0;
#ifdef MOTIF
	factory = new MotifFactory();
#else
	factory = new WindowsFactory();
#endif
	factory->CreateButton()->draw();
	factory->CreateWindow()->draw();
	getchar();

	// static factory method
	std::vector<Stooge*> Vec;
	std::cout << "1, 2, 0 ?" << std::endl;
	while (true)
	{
		int choice = 0;
		std::cin >> choice;
		if (0 == choice)
			break;
		Vec.push_back(Stooge::make_stooge(choice));
	}
	for (size_t i = 0; i < Vec.size(); i++)
		Vec[i]->slap_stick();
	for (size_t i = 0; i < Vec.size(); i++)
		delete Vec[i];
	getchar();

	// Framework
	MyApp myApp;
	myApp.NewDocument("foo");
	myApp.NewDocument("bar");
	myApp.ReportDocs();
	getchar();
	return 0;
}



