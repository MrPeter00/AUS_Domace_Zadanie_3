#pragma once
#include "../table.h"
#include "../sequence_table.h"
#include "../sorted_sequence_table.h"
#include "../binary_tree.h"
#include "../binary_search_tree.h"
#include "../treap.h"
#include "Scenar.h"
#include "../heap_monitor.h"
#include "Casovac.h"
#include "Zapisovac.h"
#include <iostream>
#include <vector>

using namespace structures;
class testTabulky
{
private:
	int getNahodnaHodnota(int paCislo);
	int getNahodnyIndex(int paCislo);
public:
	template <typename T, typename K>
	void testujTabulky(Table<K, T>* paTabulka, const char* nazovSuboru, Scenar Scenare[], int paPocetTabuliek);
};

template<typename T, typename K>
inline void testTabulky::testujTabulky(Table<K, T>* paTabulka, const char* nazovSuboru, Scenar Scenare[], int paPocetTabuliek)
{	
	string typTabulky;
	string typScenara;
	string nazovOperacie;

	if (dynamic_cast<SortedSequenceTable<T, K>*>(paTabulka) != nullptr) 	//stackoverflow
		typTabulky = "SortedSequenceTable";

	else if (dynamic_cast<Treap<K, T>*>(paTabulka) != nullptr) 
		typTabulky = "Treap";
	else 
		typTabulky = "BinarySearchTree";

	vector<int> zoznamKlucov; //zoznam klucov 
	Zapisovac* zapisovac = new Zapisovac(nazovSuboru);
	Casovac casovac;
	
	int rychlostOperacie = 0;
	srand(time(NULL));
	for (int i = 0; i < paPocetTabuliek; i++)
	{
		paTabulka->clear();
		zoznamKlucov.clear();

		int preskoceneOperacie = 0;
		
		int parameter1 = Scenare[i].getParameter1();
		int parameter2 = Scenare[i].getParameter2();
		int parameter3 = Scenare[i].getParameter3();

		for (int j = 0; j < 100000 + preskoceneOperacie; j++) //100000 krat podla zadania + preskocene
		{
			int nahodnaOperacia = getNahodnaHodnota(100);
			int nahodneData = getNahodnaHodnota(20000);
			int nahodnyKluc = getNahodnaHodnota(100000);
			int temp = paTabulka->size();

			//vloz
			if (nahodnaOperacia <= parameter1)
			{	
				if (paTabulka->containsKey(nahodnyKluc) == false)
				{
					zoznamKlucov.push_back(nahodnyKluc);
					casovac.Start();
					paTabulka->insert(nahodnyKluc, nahodneData);
					casovac.Stop();
					rychlostOperacie = (int)casovac.elapsed().count();
					casovac.Reset();
					nazovOperacie = "Insert";
					temp = paTabulka->size();
					temp = paTabulka->size();
				} else {
					preskoceneOperacie++;
					continue;
				}
				
			}
			//remove
			else if (nahodnaOperacia > (parameter1 + parameter2))
			{			

				if (paTabulka->isEmpty())
				{
					preskoceneOperacie++;
					continue;
				}

				int index = getNahodnyIndex(paTabulka->size());
				int klucZTabulky = zoznamKlucov[index]; //size - 1 = index

				if (klucZTabulky == -1 || paTabulka->containsKey(klucZTabulky) == false)
				{
					preskoceneOperacie++;
					continue;
				}

				casovac.Start();
				paTabulka->remove(klucZTabulky);
				casovac.Stop();
				rychlostOperacie = (int)casovac.elapsed().count();
				casovac.Reset();
				nazovOperacie = "Delete";
				zoznamKlucov[index] = -1;
				temp = paTabulka->size();
			}
			//spristupni
			else {

				if (paTabulka->isEmpty()) {
					preskoceneOperacie++;
					continue;
				}

				int index = getNahodnyIndex(paTabulka->size());
				int klucZTabulky = zoznamKlucov[index]; //size - 1 = index

				if(klucZTabulky == -1 || paTabulka->containsKey(klucZTabulky) == false)
				{
					preskoceneOperacie++;
					continue;
				}

				casovac.Start();
				paTabulka[klucZTabulky];
				casovac.Stop();
				rychlostOperacie = (int)casovac.elapsed().count();
				casovac.Reset();
				nazovOperacie = "GetData";

			}			
			
			zapisovac->zapisDoCsv(Scenare[i].getNazovScenara(), typTabulky, nazovOperacie, paTabulka->size(), rychlostOperacie);
		}
	}
	delete zapisovac;
}
