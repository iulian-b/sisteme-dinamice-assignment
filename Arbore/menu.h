/*********************************/
/* Test Lab 2 - SD/menu.h        */
/* iulian (iulian@firemail.cc)   */
/*********************************/

#include <iostream>
using namespace std;

/*******************************/

void splashscreen();
int menuInsert();
int menuDelete();
int menuSearch();

/*******************************/

int showMenu(){
  splashscreen();

  while(1){
    int sel = 0;
    cin>>sel;
    
    if(sel == 99) return sel;
    if(sel < 0 || sel > 5){
      cout << "\033[2J\033[1;1H";
      cout<<"//EROARE: Valoarea inserita este incorecta!";
      cin.ignore().get();
      
      return -1;
    }

    return sel;
  }
}

/*******************************/

void splashscreen(){
  cout<< "\033[2J\033[1;1H\n";
  cout<<" _____ _____ _____ _____ _____ _____ \n";
  cout<<"|  _  | __  | __  |     | __  |   __|\n";
  cout<<"|     |    -| __ -|  |  |    -|   __|\n";
  cout<<"|__|__|__|__|_____|_____|__|__|_____|\n\n";
  cout<<"         [1] Printare\n";
  cout<<"         [2] Adaugare\n";
  cout<<"         [3] Eliminare\n";
  cout<<"         [4] Cautare\n";
  cout<<"         [5] Ordini\n\n";
  cout<<"         [0] Iesire\n\n";
  cout<<"[INPUT]: ";

  return;
}

/*******************************/

int menuInsert(){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"_______________________________________\n";
  cout<<"|    ADAUGATI UN ELEMENT IN AROBRE    |\n";
  cout<<"---------------------------------------\n\n";

  int ins;
  cin>>ins;

  return ins;
}

/*******************************/

int menuDelete(){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"________________________________________\n";
  cout<<"|    STERGETI UN ELEMENT DIN AROBRE    |\n";
  cout<<"----------------------------------------\n\n";

  int del;
  cin>>del;

  return del;
}

/*******************************/

int menuSearch(){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"_____________________________________\n";
  cout<<"|    CAUTATI UN PRODUS IN ARBORE    |\n";
  cout<<"-------------------------------------\n\n";

  int srch;
  cin>>srch;
  
  return srch;
}