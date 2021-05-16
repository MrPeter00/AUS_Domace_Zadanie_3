#include "Casovac.h"
#include "../heap_monitor.h"

Casovac::Casovac()
{
	Reset();
}

void Casovac::Start()
{
	if (!started_)
	{
		timeStart_ = clock_.now();
		started_ = true;
	}
}

void Casovac::Stop()
{
	if (started_)
	{
		timeSum_ += std::chrono::duration_cast<Casovac::TimerUnits>(clock_.now() - timeStart_);
		started_ = false;
	}
}

void Casovac::Reset()
{
	timeSum_ = Casovac::TimerUnits::zero();
	started_ = false;
}

Casovac::TimerUnits Casovac::elapsed()
{
	return timeSum_;
}
