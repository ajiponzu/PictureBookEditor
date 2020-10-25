#pragma once

class Controller
{
private:

public:
	Controller() {}
	~Controller() {}
	
	virtual void notify();
	virtual void response();
};

