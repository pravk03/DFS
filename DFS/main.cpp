//
//  main.cpp
//  DFS
//
//  Created by praveen krishna on 1/1/16.
//  Copyright © 2016 praveen krishna. All rights reserved.
//

#include <iostream>
#include "list"
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool *visited;
    void DFSutil(int v);
    public :
    Graph(int V);
    void addedge (int v , int w);
    void DFS(void);
    void BFS (int s);
    
};

Graph::Graph(int V)
{
    this->V = V;
    adj =new list<int>[V];
    visited = new bool[V];
    
    for(int i = 0 ; i < V ; i++)
    {
        visited[i] = false;
    }
}

void Graph::addedge (int v , int w)
{
    
    adj[v].push_back(w);
}

void Graph :: DFSutil (int v)
{
    visited[v] = true;
    cout << v << endl;
    
    list<int> :: iterator i;
    
    for(i = adj[v].begin();i != adj[v].end();
        i++)
    {
        if(visited[*i] == false)
        {
            this->DFSutil(*i);
        }
    }
    
}

void Graph::DFS(void)
{
    
    int i;
    for(i=0;i < V;i++)
    {
        if(visited[i]==false)
        {
            DFSutil(i);
        }
    }
}


void Graph::BFS(int s)
{
 //   bool *visited = new bool[V];
    
    for(int i = 0 ; i< V ; i++)
    {
        visited[i] = false;
    }
    
    list<int> queue;
    list <int>:: iterator i;
    visited[s]=true;
    queue.push_back(s);
    
    while(!queue.empty())
    {
        s=queue.front();
        cout<<s<<endl;
        queue.pop_front();
        
        for(i = adj[s].begin();i!= adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {

    Graph g(4);
    
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,3);
    g.addedge(1,3);

    
    
    cout<<"DFS"<<endl;
    g.DFS();
    
    cout<<"BFS"<<endl;
    g.BFS(0);
    
    printf("done\n");
    
    return 0;
}
