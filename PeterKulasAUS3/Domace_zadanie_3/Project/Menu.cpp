#include "Menu.h"
#include "Zapisovac.h"
#include "Scenar.h"
#include "../table.h"
#include "../heap_monitor.h"
#include "../binary_search_tree.h"
#include "../treap.h"
#include "../sorted_sequence_table.h"
#include "testTabulky.h"
#include <iostream>

using namespace structures;
using namespace std;
void Menu::vyberTabulku() {
  cout << endl << "Vyberte druh tabulky" << endl;
  cout << "1.-Utriedena sekvencna tabulka" << endl;
  cout << "2.-Binarny vyhladavaci strom" << endl;
  cout << "3.-Treap" << endl;
  cout << "0.-Koniec" << endl;
  cout << ">> ";
}

void Menu::vyberScenar() {
  cout << endl << "Vyberte si scenar" << endl;
  cout << "1.-Vsetky 3 scenare" << endl;
  cout << "2.-Scenar A (30, 60, 10)" << endl;
  cout << "3.-Scenar B (45, 10, 45)" << endl;
  cout << "4.-Scenar C (80, 10 ,10)" << endl;
  cout << ">> ";
}

void Menu::spustiProgram() {
  int podmienka = -1;
  int moznostScenar;
  testTabulky test;

  Scenar scenarA("ScenarA", 30, 60, 10);
  Scenar scenarB("ScenarB", 45, 10, 45);
  Scenar scenarC("ScenarC", 80, 10, 10);

  while (podmienka != 0) {
    vyberTabulku();
    cin >> podmienka;

    switch (podmienka) {
    case 1: //utriedena sekvencna tabulka
    {
      vyberScenar();
      cin >> moznostScenar;
      cout << endl;

      SortedSequenceTable < int, int > * sortedSequenceTable = new SortedSequenceTable < int, int > ();

      if (moznostScenar == 1) {
        Scenar ZoznamScenarov[3] = {
          scenarA,
          scenarB,
          scenarC
        };
        cout << "Vykonavam pre vsetky scenare(final_SortedSequence.csv)";
        test.testujTabulky(sortedSequenceTable, "final_SortedSequence.csv", ZoznamScenarov, 3);
      } else if (moznostScenar == 2) {
        Scenar ZoznamScenarov[1] = { scenarA };
        cout << "Vykonavam test pre Scenar A(scenarA_utriedenaSekvencnaTabulka.csv)";
        test.testujTabulky(sortedSequenceTable, "scenarA_utriedenaSekvencnaTabulka.csv", ZoznamScenarov, 1);
      } else if (moznostScenar == 3) {
        Scenar ZoznamScenarov[1] = { scenarB };

        cout << "Vykonavam test pre Scenar B(scenarB_utriedenaSekvencnaTabulka.csv)";
        test.testujTabulky(sortedSequenceTable, "scenarB_utriedenaSekvencnaTabulka.csv", ZoznamScenarov, 1);
      } else {
        Scenar ZoznamScenarov[1] = {
          scenarC
        };
        cout << "Vykonavam test pre Scenar C(scenarC_utriedenaSekvencnaTabulka.csv)";
        test.testujTabulky(sortedSequenceTable, "scenarC_utriedenaSekvencnaTabulka.csv", ZoznamScenarov, 1);
      }

      delete sortedSequenceTable;

    }
    break;
    case 2: // binarny vyhladavaci strom
    {
      vyberScenar();
      cin >> moznostScenar;
      cout << endl;

      BinarySearchTree < int, int > * binarySeachTree = new BinarySearchTree < int, int > ();

      if (moznostScenar == 1) {
        Scenar ZoznamScenarov[3] = { scenarA, scenarB, scenarC };
        cout << "Vykonavam test pre vsetky scenare(final_BinarySearch.csv)";
        test.testujTabulky(binarySeachTree, "final_BinarySearch.csv", ZoznamScenarov, 3);
        }
         else if (moznostScenar == 2) {
            Scenar ZoznamScenarov[1] = { scenarA };
        cout << "Vykonavam test pre Scenar A(scenarA_BinarySearch.csv)";
        test.testujTabulky(binarySeachTree, "scenarA_BinarySearch.csv", ZoznamScenarov, 1);
      } else if (moznostScenar == 3) {
        Scenar ZoznamScenarov[1] = {
          scenarB
        };
        cout << "Vykonavam test pre Scenar B(scenarB_BinarySearch.csv)";
        test.testujTabulky(binarySeachTree, "scenarB_BinarySearch.csv", ZoznamScenarov, 1);
      } else {
        Scenar ZoznamScenarov[1] = {
          scenarC
        };
        cout << "Vykonavam test pre Scenar C(scenarC_BinarySearch.csv)";
        test.testujTabulky(binarySeachTree, "scenarC_BinarySearch.csv", ZoznamScenarov, 1);
      }

      delete binarySeachTree;
    }
    break;
    case 3: //treap
    {
      vyberScenar();
      cin >> moznostScenar;
      cout << endl;

      Treap < int, int > * treap = new Treap < int, int > ();

      if (moznostScenar == 1) {
        Scenar ZoznamScenarov[3] = {
          scenarA,
          scenarB,
          scenarC
        };
        cout << "Vykonavam test pre vsetky scenare(final_Treap.csv)";
        test.testujTabulky(treap, "final_Treap.csv", ZoznamScenarov, 3); 
      } else if (moznostScenar == 2) {
        Scenar ZoznamScenarov[1] = {
          scenarA
        };
        cout << "Vykonavam test pre Scenar A(scenarA_Treap.csv)";
        test.testujTabulky(treap, "scenarA_Treap.csv", ZoznamScenarov, 1);
      } else if (moznostScenar == 3) {
        Scenar ZoznamScenarov[1] = {
          scenarB
        };
        cout << "Vykonavam test pre Scenar B(scenarB_Treap.csv)";
        test.testujTabulky(treap, "scenarB_Treap.csv", ZoznamScenarov, 1);
      } else {
        Scenar ZoznamScenarov[1] = {
          scenarC
        };
        cout << "Vykonavam test pre Scenar C(scenarC_Treap.csv)";
        test.testujTabulky(treap, "scenarC_Treap.csv", ZoznamScenarov, 1);
      }

      delete treap;
    }
    break;
    default:
      break;
    }

  }
 
}