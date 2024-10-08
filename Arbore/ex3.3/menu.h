/*********************************/
/* Test Lab 2 - SD/menu.h        */
/* iulian (iulian@firemail.cc)   */
/*********************************/

#include <iostream>
using namespace std;

/*******************************/

void splashscreen();

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
  cout<<"         [1] Printare A1\n";
  cout<<"         [2] Printare A2\n";
  cout<<"         [3] a) A1 (X) A2\n";
  cout<<"         [4] b) A1 (X) A2\n";
  cout<<"         [0] Iesire\n\n";
  cout<<"[INPUT]: ";

  return;
}