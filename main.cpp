#include <iostream>
#include <vector>
#include <pair>
#include <unordered_set>
#include <queue>

using namespace std;

class SolutionFourtySeven{
public:
	vector<int> minimunTime(int n, vector<vector<int>>& edges, vector<int>& disappear){
		//edges[i]=u,v,length
		//disappear el tiempo que un nodo desaparece para siempre
		vector<pair<int,int>> adj[n];
		for(auto it: edges){
			adj[it[0]].push_back({it[1], it[2]});
			adj[it[1]].push_back({it[0], it[2]}); //porque es un grafo no dirigido
		}
		vector<int> v(n,-1);
		unordered_set<int> s;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
		q.push({0,0});
		while(!q.empty()){
			int dis=q.top().first;
			int node=q.top().second;
			q.pop();
			if(s.find(node) != s.end()) continue;
			s.insert(node);
			v[node]=dis;
			for(auto it: adj[node]){
				if(s.find(it.first)==s.end() && disappear[it.first]>it.second+dis){
					q.push({it.second+dis, it.first});
				}
			}
		}
		return v;
	}
};

int main(){
	return 0;
}