#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <bits/stdc++.h> 
using namespace std; 

class Nodo { 
public: 
    int val; 
    Nodo **next; 
    Nodo(int, int); 
}; 
  
Nodo::Nodo(int val, int level) { 
    this->val = val; 
    next = new Nodo*[level+1]; 
    memset(next, 0, sizeof(Nodo*)*(level+1)); 
}; 
  

class SkipList { 
private:
    int lvl_max; 
    float prob; 
    int level; 
    Nodo *head; 
public: 
    SkipList(int, float); 
    int level_rand(); 
    Nodo* createNodo(int, int); 
    void insert(int); 
    void remove(int); 
    bool search(int); 
    void printList();
	string toString();
}; 
  
SkipList::SkipList(int lvl_max, float prob) { 
    this->lvl_max = lvl_max; 
    this->prob = prob; 
    level = 0; 
  
    head = new Nodo(-1, lvl_max); 
}; 
  
int SkipList::level_rand() { 
    float r = (float)rand()/RAND_MAX; 
    int lvl = 0; 
    while(r < prob && lvl < lvl_max) 
    { 
        lvl++; 
        r = (float)rand()/RAND_MAX; 
    } 
    return lvl; 
}; 
  
Nodo* SkipList::createNodo(int val, int level) { 
    Nodo *n = new Nodo(val, level); 
    return n; 
}; 

//INSERT///////////////////////////////////////////////////////////////////////////////////////////
void SkipList::insert(int val) { 
    Nodo *current = head; 
  
    Nodo *updated[lvl_max+1]; 
    memset(updated, 0, sizeof(Nodo*)*(lvl_max + 1)); 
  
    for(int i = level; i >= 0; i--) { 
        while(current->next[i] != NULL && current->next[i]->val < val) 
            current = current->next[i]; 
        updated[i] = current; 
    } 
  
    current = current->next[0]; 
  
    if (current == NULL || current->val != val) { 

        int lvl_aux = level_rand(); 

        if(lvl_aux > level) { 
            for(int i=level+1;i<lvl_aux+1;i++) 
                updated[i] = head; 
            level = lvl_aux; 
        } 
  
        Nodo* n = createNodo(val, lvl_aux); 
  
        for(int i=0;i<=lvl_aux;i++) { 
            n->next[i] = updated[i]->next[i]; 
            updated[i]->next[i] = n; 
        } 
    } 
}; 
  
//REMOVE///////////////////////////////////////////////////////////////////////////////////////////
void SkipList::remove(int val) { 
    Nodo *current = head; 
  
    Nodo *updated[lvl_max+1]; 
    memset(updated, 0, sizeof(Nodo*)*(lvl_max+1)); 

    for(int i = level; i >= 0; i--) { 
        while(current->next[i] != NULL  && current->next[i]->val < val) 
			current = current->next[i]; 
        updated[i] = current; 
    } 

    current = current->next[0]; 

    if(current != NULL and current->val == val) { 

        for(int i=0;i<=level;i++) { 

            if(updated[i]->next[i] != current) 
                break; 
  
            updated[i]->next[i] = current->next[i]; 
        } 
  
        while(level>0 && head->next[level] == 0) 
            level--;
			cout << "\nValor eliminado: " << val << "\n";
    }
	
	else
		cout << "\nEl valor buscado no existe en la estructura\n";
}; 

//SEARCH///////////////////////////////////////////////////////////////////////////////////////////
bool SkipList::search(int val) { 
    Nodo *current = head; 
	cout << "\nValor buscado: " << val << "\n";
    for(int i = level; i >= 0; i--) { 
        while(current->next[i] && current->next[i]->val < val) 
            current = current->next[i]; 
    } 
	
    current = current->next[0]; 
  
    if(current and current->val == val)  {
        cout<<"El valor buscado si existe en la estructura.\n";
		return true;
	}
	
	else {
		cout << "El valor buscado no existe en la estructura.\n";
		return false;
	}
}; 

//PRINT////////////////////////////////////////////////////////////////////////////////////////////
void SkipList::printList() { 
    for(int i=0; i<=level; i++) { 
        Nodo *Nodo = head->next[i]; 
        cout<<"Nivel "<<i<<": "; 
        while(Nodo != NULL) { 
            cout<<Nodo->val<<" "; 
            Nodo = Nodo->next[i]; 
        } 
        cout<<"\n"; 
    } 
};

#endif