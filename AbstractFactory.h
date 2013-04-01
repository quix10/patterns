/*
 * AbstractFactory.h
 *
 *  Created on: Mar 26, 2013
 *      Author: quix
 */
#include <iostream>

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

class Widget
{
public:
	virtual void draw() = 0;
	virtual ~Widget() {}
};

class MotifWindow : public Widget
{
public:
	virtual void draw()
	{
		std::cout << "MotifWindow::Draw" << std::endl;
	}
};

class MotifButton : public Widget
{
public:
	virtual void draw()
	{
		std::cout << "MotifButton::Draw" << std::endl;
	}
};

class WindowsWindow : public Widget
{
public:
	virtual void draw()
	{
		std::cout << "WindowsWindow::Draw" << std::endl;
	}
};

class WindowsButton : public Widget
{
public:
	virtual void draw()
	{
		std::cout << "WindowsButton::Draw" << std::endl;
	}
};

class Factory
{
public:
	virtual Widget* CreateButton() = 0;
	virtual Widget* CreateWindow() = 0;
	virtual ~Factory() {}
};

class MotifFactory : public Factory
{
public:
	virtual Widget* CreateButton()
	{
		return new MotifButton();
	}
	virtual Widget* CreateWindow()
	{
		return new MotifWindow();
	}
};

class WindowsFactory : public Factory
{
public:
	virtual Widget* CreateButton()
	{
		return new WindowsButton();
	}
	virtual Widget* CreateWindow()
	{
		return new WindowsWindow();

	}
};

#endif /* ABSTRACTFACTORY_H_ */
