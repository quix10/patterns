/*
 * Factory.h
 *
 *  Created on: Mar 26, 2013
 *      Author: quix
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
//#include <stdio.h>
#include <string.h>

/////////// static factory method /////////////////////////

class Stooge
{
public:
	static Stooge* make_stooge(const int choice);
	virtual void slap_stick() = 0;
	virtual ~Stooge() {}
};

class Larry : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Larry" << std::endl;
	}
};

class Page : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Page" << std::endl;
	}
};

class Sam : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Sam" << std::endl;
	}
};

Stooge* Stooge::make_stooge(const int choice)
{
	if  (1 == choice)
		return new Larry();
	else if (2 == choice)
		return new Page();
	else
		return new Sam();
}

///////////////// Framework ///////////////////////////////////

class Document
{
public:
	Document(char* name)
	{
		strcpy(name_, name);
	}
	char* GetName()
	{
		return name_;
	}
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual ~Document() {}

private:
	char name_[20];

};

class MyDoc : public Document
{
public:
	MyDoc(char* name) : Document(name) {}
	void Open()
	{
		std::cout << "MyDoc::Open()" << std::endl;
	}
	void Close()
	{
		std::cout << "MyDoc::Close()" << std::endl;
	}
};

class App
{
public:
	App() : index_(0)
	{
		std::cout << "App::constructor()" << std::endl;
	}
	virtual ~App() {}
	virtual Document* CreateDocument(char* name) = 0;
	void NewDocument(char* name)
	{
		std::cout << "App::NewDocument()" << std::endl;
		docs_[index_] = CreateDocument(name);
		docs_[index_++]->Open();
	}
	void ReportDocs()
	{
		for (int i = 0; i < index_; i++)
		{
			std::cout << docs_[i]->GetName() << std::endl;
		}
	}

private:
	int index_;
	Document* docs_[10];
};

class MyApp : public App
{
public:
	MyApp()
	{
		std::cout << "MyApp::constructor()" << std::endl;
	}
	Document* CreateDocument(char* name)
	{
		std::cout << "MyApp::CreateDocument()" << std::endl;
		return new MyDoc(name);
	}
};


#endif /* FACTORY_H_ */
