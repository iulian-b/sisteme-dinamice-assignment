/*******************************/
/* Test Lab - SD               */
/* iulian (iulian@firemail.cc) */
/*******************************/

#include <iostream>
#include "menu.h"
#include "list.h"
using namespace std;

/*******************************/

int main(){
  nod* Cap = NULL;

  // Unplem lista cu cateva noduri de default
  listInit(Cap,"1834","Apa_plata",1.50);
  listInit(Cap,"2816","Carne_de_porc",12.20);
  listInit(Cap,"4416","Branza",2.00);
  listInit(Cap,"1012","Tigari",19.00);
  listInit(Cap,"1285","Paine_integrala",7.80);
  listInit(Cap,"3714","Cartofi",0.90);
  
  while(1){
  	int sel = showMenu();
 	if(sel == -1) continue;

	switch(sel){
		case 0:{cout << "\033[2J\033[1;1H";return 1;}
		case 1:{listPrint(Cap);break;}
		case 2:{listInsert(Cap);break;}
	  	case 3:{
	  		string t = menuDelete();
	  		int sz = t.length();
	  		if (t[0] == '#') listCodeDelete(Cap,t.substr(1,sz));
	  		else listNameDelete(Cap,t);
	  		break;
	  	}
	  	case 4:{
	  		string t = menuSearch();
	  		int sz = t.length();
	  		if (t[0] == '#') listCodeSearch(Cap,t.substr(1,sz));
	  		else listNameSearch(Cap,t);
	  		break;
	  	}
	}
  }
  
  return 0;
}