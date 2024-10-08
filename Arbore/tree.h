/*********************************/
/* Test Lab 2 - SD/tree.h        */
/* iulian (iulian@firemail.cc)   */
/*********************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

/*******************************/

// Nodul model din arbore
struct nod{
	int Elem;
	struct nod* SX;
	struct nod* DX;
};

// Trunchiul aroborelui, folosita doar pentru a usora algoritmul de printare
struct trunchi{
	trunchi *prev;
	string str;

	trunchi(trunchi *prev,string str){
		this->prev = prev;
		this->str = str;
	}
};

/*******************************/

nod* treeMinVal(nod*);							// Returneaza nodul care contine cel mai mic valor din arbore
void treeInsert(nod* &);                        // Adauga un nod in arbore
void treePrintPreorder(nod*);                   // Printeaza arborele (preorder)
void treePrintInorder(nod*);                    // Printeaza arborele (inorder)
void treePrintPostorder(nod*);                  // Printeaza arborele (postorder)
bool treeSearch(nod*,int); 	         	        // Cauta un nod in arbore
void trunkPrint(nod*,trunchi,bool);				// Printeaza ramurile arobrelui
nod* treeDelete(nod*,int);						// Elimineaza nodul continand elementul dat (primul gasit)
void trunkShow(trunchi);						// Printeaza aroborele (grafic) 

/*******************************/

nod* treeMinVal(nod* Root){
	nod* curr = Root; 
	while(curr && curr -> SX != NULL)
		curr = curr -> SX;

	return curr;
}

/*******************************/

void treeInsert(nod* &Root,int Num){
	// Daca aroberele este vid, creaza un nod radacina cu elementul dat
	if(!Root){
		Root = new nod;
		Root -> Elem = Num;
		Root -> DX = NULL;
		Root -> SX = NULL;
	}else
		if(Num <= Root -> Elem)
			// Daca elementul dat este mai mic decat elementul nodului curent, ne mutam la stanga
			treeInsert(Root->SX,Num);
		else
			// Daca elementul dat este mai mare decat elementul nodului curent, ne mutam la dreapta
			treeInsert(Root->DX,Num);
}

/*******************************/

void treePrintPreorder(nod* Root){
	if(Root){
		cout<<Root -> Elem << ' ';
		treePrintPreorder(Root -> SX);
		treePrintPreorder(Root -> DX);
	}
}

void treePrintPostorder(nod* Root){
	if(Root){
		treePrintPostorder(Root -> SX);
		treePrintPostorder(Root -> DX);
		cout<<Root -> Elem << ' ';
	}
}

void treePrintInorder(nod* Root){
	if(Root){
		treePrintInorder(Root -> SX);
		cout<<Root -> Elem << ' ';
		treePrintInorder(Root -> DX);
	}
}

/*******************************/

bool treeSearch(nod* Root,int S){
	// Daca arborele este vid, iesim
	if(!Root) return false;
	// Daca elementul este prezent in radacina, iesim
	if(Root->Elem == S) return true;

	// Cautam la stanga
	bool res1 = treeSearch(Root->SX,S);
	if(res1) return true;

	// Si la dreapta
	bool res2 = treeSearch(Root->DX,S);
	return res2;
}

/*******************************/

nod* treeDelete(nod* Root,int D){
	// Daca arborele este vid
	if(Root == NULL) return Root;
	
	// Daca este mai mic
	if(D < Root -> Elem)
		Root -> SX = treeDelete(Root -> SX,D);
	// Daca este mai mare
	else if(D > Root -> Elem)
		Root -> DX = treeDelete(Root -> DX,D);

	// Cand se gaseste nodul de eliminat
	else{
		//Daca nodul curent are 1 sau 0 ramuri
		if(Root -> SX == NULL){
			struct nod* tmp = Root -> DX;
			free(Root);

			return tmp;
		}else if(Root -> DX == NULL){
			struct nod* tmp = Root -> SX;
			free(Root);
			
			return tmp;
		}

		// Daca nodul curent are 2 ramuri
		// Loam succesorul (inorder)
		struct nod* tmp = treeMinVal(Root -> DX);
		// Si il copiem pe nodul acesta
		Root -> Elem = tmp -> Elem;
		// Stergem succesorul
		Root -> DX = treeDelete(Root -> DX,tmp -> Elem);
	}
	return Root;
}

/*******************************/

// Folosita ca suport pentru trunkPrint()
void trunkShow(trunchi *P){
	if(!P) return;

	trunkShow(P->prev);
	cout<<P->str;
}

/*******************************/

void trunkPrint(nod* Root,trunchi *prev,bool isLeft){
	// Daca este vid, iesim
	if(!Root) return;

	string prev_str = "    ";
    trunchi *T = new trunchi(prev, prev_str);

    // Ne mutam recursiv la stanga
    trunkPrint(Root->SX,T,true);

    if(!prev) T->str = "---";
    else if(isLeft){
        T->str = ".---";
        prev_str = "   |";
    }else{
        T->str = "`---";
        prev->str = prev_str;
    }

    // Aratam elementul curent
    trunkShow(T);
    cout<<Root->Elem<<endl;

    if(prev)
       prev->str = prev_str;
    T->str = "   |";

    // Ne mutam recursiv la dreapta
    trunkPrint(Root->DX,T,false);
}