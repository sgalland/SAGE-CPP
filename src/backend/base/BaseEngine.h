#pragma once

class BaseEngine
{
public:
	BaseEngine();
	~BaseEngine();

	virtual void initialize();
	virtual void quit();
};
