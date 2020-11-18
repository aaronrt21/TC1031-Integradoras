#ifndef GRAPH_H 
#define GRAPH_H
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string show(vector<int>);

class Graph{
    private:
        int vertex;
        int edges;
        vector<vector<int> > adjList;
        vector<vector<int> > adjMat;

    public:
        Graph(){}
        void loadGraphList(string nombre, int nodos, int arcos);
        string printAdjList();
        string BFS(int x, int z);
};

void Graph::loadGraphList(string nombre, int nodos, int arcos){
    vertex = nodos;
    edges = arcos;
    for(int i = 0; i < nodos; i++){
        vector<int> list;          
        adjList.push_back(list);
    }
    ifstream file;                  
    file.open(nombre);
    while(file.good()){
        string x;
        string y;
        getline(file, x, ','); 
      if (x != ""){
        getline(file, y, '\n');
        x = x.substr(1, x.length()-1);
        y = y.substr(1, y.length()-2);
        int u = stoi(x);
        int v = stoi(y);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }     
    }
}

string Graph::printAdjList(){
  string data = "";
	for(int i = 0; i < adjList.size(); i++){
		data += "\nID: " + to_string(i) + "\n Amigos: ";
		sort(adjList[i].begin(), adjList[i].end());
		for(int j = 0; j < adjList[i].size(); j++){
			data += to_string(adjList[i][j]) + " ";
		}
	}
	return data;
}

#endif