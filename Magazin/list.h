/*******************************/
/* Test Lab - SD/list.h        */
/* iulian (iulian@firemail.cc) */
/*******************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

/*******************************/

// Nodul model din lista
struct nod{
  string Cod;
  string Nume;
  float Pret;
  nod* next;
};

/*******************************/

void listInit(nod* &,string,string,float);      // Populeaza lista cu cateva produse de default
void listPrint(nod*);                           // Printeaza lista
void listInsert(nod* &);                        // Adauga un nod in lista
void listCodeSearch(nod*,string);               // Cauta un nod in lista, dat codul produsului
void listCodeDelete(nod* &,string);             // Elimina un nod in lista, dat codul produsului
void listNameSearch(nod*,string);               // Cauta un nod in lista, dat numele produsului
void listNameDelete(nod* &,string);             // Elimina un nod in lista, dat numele produsului

/*******************************/

void listInit(nod* &C,string Q,string N,float P){
  nod* tmp = new nod; 
  tmp->Cod = Q;
  tmp->Nume = N;
  tmp->Pret = P;
  tmp->next = C;
  C = tmp;
}

/*******************************/

void listPrint(nod* C){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"______________________________________\n";
  cout<<"|    LISTA PRODUSELOR DISPONIBILE    |\n";
  cout<<"--------------------------------------\n\n";

  // Daca lista este vida
  if(C==NULL){
    cout<<"//EROARE: Lista este vida!\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
  }

  // Altfel
  while(C!=NULL){
    cout<<"|  "<<C->Cod<<"   "<<C->Nume<<" --- €"<<C->Pret<<"\n";
    
    C = C->next;
  }

  cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
  cin.ignore().get();
  
  return;
}

/*******************************/

void listInsert(nod* &C){
  cout<< "\033[2J\033[1;1H\n";
  cout<<"______________________________________\n";
  cout<<"|    ADAUGATI UN PRODUS IN MAGAZIN    |\n";
  cout<<"--------------------------------------\n\n";

  // Creez un nod vid, si il unmplu cu valorile date
  nod* tmp = new nod;
  
  cout<<"[CODUL produsului]: ";
  cin>>tmp->Cod;
  
  cout<<"[NUMELE produsului]: ";
  cin>>tmp->Nume;
  
  cout<<"[PRETUL produsului]: ";
  cin>>tmp->Pret;

  tmp->next = C;
  C = tmp;
}

/*******************************/

void listCodeSearch(nod* C,string S){
    while(C!=NULL){
      string s1 = S;
      string s2 = C->Cod;
      
      // Compareaza stringa data cu nodul curent
      if(s1.compare(s2)==0){
        cout<<"\n|  PRODUS GASIT:\n";
        cout<<"|  "<<C->Cod<<"   "<<C->Nume<<" --- €"<<C->Pret<<"\n";
        cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
        cin.ignore().get();

        return;
      }

      //Daca nu este gasit, avanseaza
      C = C->next;
    }

    cout<<"\n|  PRODUSUL NU A FOST GASIT\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
}

void listNameSearch(nod* C,string S){
    while(C!=NULL){
      string s1 = S;
      string s2 = C->Nume;
      transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
      transform(s2.begin(), s2.end(), s2.begin(), ::toupper); 

      if(s1.compare(s2)==0){
        cout<<"\n|  PRODUS GASIT:\n";
        cout<<"|  "<<C->Cod<<"   "<<C->Nume<<" --- €"<<C->Pret<<"\n";
        cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
        cin.ignore().get();

        return;
      }

      C = C->next;
    }

    cout<<"\n|  PRODUSUL NU A FOST GASIT IN LISTA\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
}

/*******************************/

void listCodeDelete(nod* &C,string Q){
  // Daca lista esete vida
  if(!C) {
    cout<<"//EROARE: Lista este vida!\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
    return;
  }
  
  // Se compara nodul curent cu nodul de eliminat
  nod** curent = &C;
  while(*curent){
    string s2 = (*curent)->Cod;
    if(Q.compare(s2)==0) break;
    curent = &(*curent)->next;
  }
  
  // Daca se gaseste se desleaga nodul curent de lista, si se elimina din memorie
  if(*curent){
    string sters = (*curent)->Nume;
    nod* tmp = *curent;
    *curent = (*curent)->next;
    delete tmp;

    cout<<"\n|  PRODUSUL \""<<sters<<"\" A FOST GASIT SI ELIMINAT DIN LISTA\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
  }else{ // Daca nu se gaseste
    cout<<"\n|  PRODUSUL NU A FOST GASIT IN LISTA\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
  }
  return; 
}

void listNameDelete(nod* &C,string Q){
  // Daca lista esete vida
  if(!C) {
    cout<<"//EROARE: Lista este vida!\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
    return;
  }
  
  // Se compara nodul curent cu nodul de eliminat
  nod** curent = &C;
  transform(Q.begin(), Q.end(), Q.begin(), ::toupper);
  while(*curent){
    string s2 = (*curent)->Nume;
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

    // cout<<s2<<' '<<Q<<'\n';
    if(Q.compare(s2)==0) break;
    curent = &(*curent)->next;
  }
  
  // Daca se gaseste se desleaga nodul curent de lista, si se elimina din memorie
  if(*curent){
    string sters = (*curent)->Nume;
    nod* tmp = *curent;
    *curent = (*curent)->next;
    delete tmp;

    cout<<"\n|  PRODUSUL \""<<sters<<"\" A FOST GASIT SI ELIMINAT DIN LISTA\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
  }else{ // Daca nu se gaseste
    cout<<"\n|  PRODUSUL NU A FOST GASIT IN LISTA\n";
    cout<<"\nApasati orice tasta pentru a va intoarce la meniu";
    cin.ignore().get();
  }
  return; 
}