#pragma once
#include "../heap_monitor.h"
#include <string>

using namespace std;
class Scenar
{
private:
	int aParameter1;
	int aParameter2;
	int aParameter3;
	string aNazov;

public:
	Scenar(string paNazov, int paParameter1, int paParameter2, int paParameter3);

	int getParameter1() { return aParameter1; }
	int getParameter2() { return aParameter2; }
	int getParameter3() { return aParameter3; }
	string getNazovScenara() { return aNazov; }
};

