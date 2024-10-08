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
  nod* Root = NULL;
  // Unplem arborele cu cateva noduri de default
  treeInsert(Root,50);
  treeInsert(Root,30);
  treeInsert(Root,20);
  treeInsert(Root,40);
  treeInsert(Root,70);
  treeInsert(Root,60);
  treeInsert(Root,80);

  while(1){
  	int sel = showMenu();
 	if(sel == -1) continue;

	switch(sel){
		case 0:{cout << "\033[2J\033[1;1H";return 1;}
		case 1:{
			cout << "\033[2J\033[1;1H";
			trunkPrint(Root,nullptr,false);

			cout<<"\n\nApasati orice tasta pentru a va intoarce la meniu";
			cin.ignore().get();
			break;
		}
		case 2:{
			int t = menuInsert();
			treeInsert(Root,t);
			break;
		}
		case 3:{
			int d = menuDelete();
			treeDelete(Root,d);
			break;
		}
	  	case 4:{
	  		int t = menuSearch();
	  		cout << "\033[2J\033[1;1H";
	  		
	  		if(treeSearch(Root,t))
	  	  		cout<<"[Elementul '"<<t<<"' a fost gasit!]: ";
	  		else
	  	  		cout<<"[Elementul '"<<t<<"' nu a fost gasit!]: ";

	  	  	cin.ignore().get();
	  		break;
	  	}
	  	case 5:{
	  		cout<<"\033[2J\033[1;1H";
	  		
	  		cout<<"PREORDER: "; treePrintPreorder(Root); cout<<"\n";
	  		cout<<"INORDER: "; treePrintInorder(Root); cout<<"\n";
	  		cout<<"POSTORDER: "; treePrintPostorder(Root); cout<<"\n";
	  		
	  		cout<<"\n\nApasati orice tasta pentru a va intoarce la meniu";
	  		cin.ignore().get();
	  		break;
	  	}
	}
  }
  
  return 0;
}