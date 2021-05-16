#include "Zapisovac.h"

Zapisovac::Zapisovac(const char* nazovSubora)
{
	fileHandle = nullptr;
	if (nazovSubora != nullptr && nazovSubora[0] != 0)
	{
		fileHandle = fopen(nazovSubora, "at"); //at zapisuje text, pokracuje v subore
	}
}

void Zapisovac::zapisDoCsv(string paScenar, string paStruktura, string paOperacia, int paPocetPrvkov, int paCas)
{
	if (fileHandle)
	{
		fprintf(fileHandle, "%s;%s;%s;%d;%d\n", paScenar.c_str(), paStruktura.c_str(), paOperacia.c_str(), paPocetPrvkov, paCas); //c_str = char*
	}
	else {
		cout << "File is closed!";
	}
}

Zapisovac::~Zapisovac()
{
	if (fileHandle)
	{
		fclose(fileHandle);
	}
}
