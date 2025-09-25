#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int>adj[vertices+1];
    vector<int>Indegree(vertices+1,0);
    int u,v;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        Indegree[v]++;
    }
    queue<int>Q;
    for(int i=1;i<Indegree.size();i++){
        if(Indegree[i]==0){
            Q.push(i);
        }
        
    }
    while(!Q.empty()){
        int idx=Q.front();
        cout<<idx<<" ";
        Q.pop();
        for(auto i: adj[idx]){
            Indegree[i]--;
            if(Indegree[i]==0){
                Q.push(i);
            }
        }
    }
}