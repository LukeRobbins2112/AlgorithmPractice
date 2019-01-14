/*
Steps:

(1) Sort the edges in non-decreasing order of weight
(2) Pick the smallest edge. Check to see if it forms a cycle with the spanning tree so far; 
			-- If a cycle is formed, discard it. Otherwise add it to the MST
(3) Repeat step (2) until there are (V-1) edges included in the MST


*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct Graph {

	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}

	void addEdge(int src, int dest, int weight) {
		this->edges.push_back({ weight, {src, dest} });
	}

	// Function to find MST using Kruskal's // MST algorithm 
	int KruskalMST();

	int V;
	int E;

	// graph is represented as an array of edges.  
	// Since the graph is undirected, the edge from src to dest is also edge from dest to src. Both are counted as 1 edge here. 
	vector<pair<int, pair<int, int>>> edges;
};


struct DisjointSets {

	DisjointSets(int n) {
		this->n = n;
		this->parent = new int[n + 1];
		this->rank = new int[n + 1];

		// Initially, all vertices are in 
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++) {
			this->parent[i] = i;
			this->rank[i] = 0;
		}
	}

	// Find the parent of a node 'u' 
	// Path Compression
	int find(int u) {
		/* Make the parent of the nodes in the path
		   from u--> parent[u] point to parent[u] */
		if (u != this->parent[u]) {
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}

	// Union by rank 
	void merge(int x, int y) {

		x = find(x);
		y = find(y);

		if (this->rank[x] > this->rank[y]) {
			this->parent[y] = x;
		}
		else {
			this->parent[x] = y;
		}

		if (this->rank[x] == this->rank[y]) {
			this->rank[y]++;
		}
	}

	int * parent;
	int * rank;
	int n;
};

// Main algorithm
int Graph::KruskalMST() {

	int mstWeight = 0;

	// Sort edges by weight, ascending
	sort(begin(this->edges), end(this->edges));

	// Create disjoint sets
	DisjointSets ds(this->V);

	// Iterate through all sorted edges
	for (auto it = this->edges.begin(); it != this->edges.end(); it++) {
		
		// Src, dest
		int u = it->second.first;
		int v = it->second.second;

		int uSet = ds.find(u);
		int vSet = ds.find(v);

		// Check if the selected edge is creating 
	   // a cycle or not (Cycle is created if u 
	   // and v belong to same set)
		if (uSet != vSet) {
			// Current edge will be in the MST so print it 
			cout << u << " - " << v << endl;

			// Update MST weight 
			mstWeight += it->first;

			// Merge two sets 
			ds.merge(uSet, vSet);
		}
	}

	return mstWeight;
}


// Driver program to test above functions 
int main()
{

	/* Let us create above shown weighted
	  and unidrected graph */
	int V = 9, E = 14;
	Graph g(V, E);

	//  making above shown graph 
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	cout << "Edges of MST are \n";
	int mst_wt = g.KruskalMST();

	cout << "\nWeight of MST is " << mst_wt;

	return 0;
	
}