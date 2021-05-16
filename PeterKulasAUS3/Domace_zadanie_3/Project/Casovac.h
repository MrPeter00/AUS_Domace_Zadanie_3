#pragma once
#include <chrono>
#include "../heap_monitor.h"
class Casovac
{
public:
	typedef std::chrono::nanoseconds TimerUnits;
public:
	Casovac();
	void Start();
	void Stop();
	void Reset();
	TimerUnits elapsed();

private:
	std::chrono::high_resolution_clock clock_;
	std::chrono::high_resolution_clock::time_point timeStart_;
	TimerUnits timeSum_;

	bool started_;
};

