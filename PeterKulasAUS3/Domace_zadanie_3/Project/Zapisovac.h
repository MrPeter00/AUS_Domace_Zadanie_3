#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 
#include <iostream>
#include <cstdio>

using namespace std;
class Zapisovac
{
private:
	FILE* fileHandle = nullptr;

public:
	Zapisovac(const char* nazovSubora);
	void zapisDoCsv(string paScenar, string paStruktura, string paOperacia, int paPocetPrvkov, int paCas);
	~Zapisovac();
};

