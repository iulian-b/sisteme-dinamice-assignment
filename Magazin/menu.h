/*******************************/
/* Test Lab - SD/menu.h        */
/* iulian (iulian@firemail.cc) */
/*******************************/

#include <iostream>
using namespace std;

/*******************************/

void splashscreen();
string menuSearch();
string menuDelete();

/*******************************/

int showMenu(){
  splashscreen();

  while(1){
    int sel = 0;
    cin>>sel;
    
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
  cout<<" _____ _____ _____ _____ _____ _ _____ \n";
  cout<<"|     |  _  |   __|  _  |__   |_|   | |\n";
  cout<<"| | | |     |  |  |     |   __| | | | |\n";
  cout<<"|_|_|_|__|__|_____|__|__|_____|_|_|___|\n\n";
  cout<<"         [1] Printare\n";
  cout<<"         [2] Adaugare\n";
  cout<<"         [3] Eliminare\n";
  cout<<"         [4] Cautare\n\n";
  cout<<"         [0] Iesire\n\n";
  cout<<"[INPUT]: ";

  return;
}

/*******************************/

string menuSearch(){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"______________________________________\n";
  cout<<"|    CAUTATI UN PRODUS IN MAGAZIN    |\n";
  cout<<"--------------------------------------\n\n";

  string srch;

  cout<<"[NUMELE sau CODUL produsului care doriti sa-l cautati]: ";
  cin>>srch;
  
  bool isCode = false;
  bool isName = false;
  for(int i=0;i<srch.length();i++){
    if(isdigit(srch[i])) isCode = true;
    else if(isalpha(srch[i])) isName = true;
  }
  
  if(isCode && !isName){
    string R = "#";
    R.append(srch);
    return R;
  } 
  else if(isName && !isCode) return srch;
  else{
    cout<<"//EROARE: Valoarea inserita nu este un COD sau un NUME!";
    cin.ignore().get();
  }

  return NULL;
}

/*******************************/

string menuDelete(){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"_________________________________________\n";
  cout<<"|    ELIMINATI UN PRODUS DIN MAGAZIN    |\n";
  cout<<"-----------------------------------------\n\n";

  string srch;

  cout<<"[NUMELE sau CODUL produsului care doriti sa-l eliminati]: ";
  cin>>srch;
  
  bool isCode = false;
  bool isName = false;
  for(int i=0;i<srch.length();i++){
    if(isdigit(srch[i])) isCode = true;
    else if(isalpha(srch[i])) isName = true;
  }
  
  if(isCode && !isName){
    string R = "#";
    R.append(srch);
    return R;
  } 
  else if(isName && !isCode) return srch;
  else{
    cout<<"//EROARE: Valoarea inserita nu este un COD sau un NUME!";
    cin.ignore().get();
  }
  
  return NULL;
}