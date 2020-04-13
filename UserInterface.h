#pragma once
#include "Service.h"

class UserInterface{
private:
	Service service;
	void add();
	void del();
	void find();
	void update();
	void showAll();

public:
	UserInterface();
	UserInterface(const Service& s);
	~UserInterface();
	void showUI();
};

