/*********************************/
/* Test Lab 2 - SD               */
/* iulian (iulian@firemail.cc)   */
/*********************************/

#include <iostream>
#include "menu.h"
#include "tree.h"
using namespace std;

/*******************************/

int main(){
  int a1[] = {50,30,20,40,70,60,80};
  int a2[] = {30,70,10,40,90}; 
  nod* A1 = NULL;
  nod* A2 = NULL;
  nod* end = NULL;
  int a = 0;

  for(int i=0;i<7;i++)
  	treeInsert(A1,a1[i]);

  for(int i=0;i<5;i++)
  	treeInsert(A2,a2[i]);

  while(1){
  	int sel = showMenu();
 	if(sel == -1) continue;

	switch(sel){
		case 0:{cout << "\033[2J\033[1;1H";return 1;}
		case 1:{
			cout << "\033[2J\033[1;1H";
			trunkPrint(A1,nullptr,false);

			cout<<"\n\nApasati orice tasta pentru a va intoarce la meniu";
			cin.ignore().get();
			break;
		}
		case 2:{
			cout << "\033[2J\033[1;1H";
			trunkPrint(A2,nullptr,false);

			cout<<"\n\nApasati orice tasta pentru a va intoarce la meniu";
			cin.ignore().get();
			break;
		}
		case 3:{
			for(int i=0;i<5;i++) treeDelete(A1,a2[i]);
			nodeDeepest(A1,end);

			break;
		}
		case 4:{
			for(int i=0;i<5;i++) treeInsert(end,a2[i]);
			break;
		}
	  	case 99:{
	  		cout << "\033[2J\033[1;1H";
	  		treePrint(A1);
	  		cout<<"LAST: "<<a;

	  		cin.ignore().get();
	  		break;
	  	}
	}
  }
  
  return 0;
}