// File implementing an ADT for a weighted undirected graph
// Written by An Doan

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// class to represent an edge from one node to another
class Edge {
public:
  // constructor for Edge
  Edge(int from = -1, int to = -1, double dist = -1.0)
      : from(from), to(to), dist(dist) {}

  // Edge data
  int from;
  int to;
  double dist;

  Edge &operator=(const Edge &other) {
    from = other.from;
    to = other.to;
    dist = other.dist;

    return *this;
  }
};

// Edge compare operators
bool operator>(const Edge &e1, const Edge &e2) { return e1.dist > e2.dist; }

bool operator<(const Edge &e1, const Edge &e2) { return e1.dist < e2.dist; }

bool operator==(const Edge &e1, const Edge &e2) {
  return ((e1.to == e2.to && e1.from == e2.from) ||
	  (e1.from == e2.to && e1.to == e2.from));
}

bool operator!=(const Edge &e1, const Edge &e2) { return e1.dist != e2.dist; }

// overload operator for output stream (Edge class)
ostream &operator<<(ostream &out, Edge &e) {
  out << "(" << e.to << "->" << e.from << ": " << e.dist << ") ";
  return out;
}

// class to represent a weighted undirected graph
// using the edge list implementation for graphs
class Graph {
public:
  // default constructor for Graph
 Graph(int nodes) : nodes(nodes),edges(0) {
    
    adj = new vector<Edge>[nodes];

    // for each node, create a vector of edges to store
    // all the edges from the node to another node in the graph
    for (int i = 0; i < nodes; ++i) {
      adj[i] = vector<Edge>();
    }
  }

  // constructor that creates a random graph
  // with set density and distance range parameters
 Graph(int nodes, double density, double distLow, double distHigh) : nodes(nodes),edges(0) {
    adj = new vector<Edge>[nodes];
    for (int i = 0; i < nodes; ++i) {
      adj[i] = vector<Edge>();
    }

    srand(time(0));

    for (int i = 0; i < nodes; i++) {
      for (int j = i + 1; j < nodes; j++) {
        if (prob() < density) {
	  double distance = (distHigh - distLow) * prob() + distLow;
	  AddEdge(Edge(i, j, distance));
        }
      }
    }
  }

  // destructor for Graph
  ~Graph() { delete[] adj; }

  // return number of vertices
  int V() const { return nodes; }

  // return number of edges
  int E() const { return edges; }

  // return edges from node x
  const vector<Edge> &AdjacentNodes(int x) const { return adj[x]; }

  // add an edge from node x to node y if edge doesn't already exist
  void AddEdge(Edge e) {

    // check if edge already exists
    if (!this->adjacent(e.from, e.to)) {
      adj[e.from].push_back(e);
      adj[e.to].push_back(Edge(e.to, e.from, e.dist));
    }
    edges++;
  }
  
private:
  const int nodes;
  int edges;
  vector<Edge> *adj;

  // does the edge from node x to node y exist?
  bool adjacent(int x, int y) {
    for (Edge &e : adj[x]) {
      if (e.to == y) {
        return true;
      }
    }
    return false;
  }

  // compute a random double from 0 to 1
  double prob()
  {
    return (static_cast<double>(rand()) / RAND_MAX);
  }

  
};

// overload operator for output stream (Graph class)
ostream &operator<<(ostream &out, Graph &g) {
  for (int i = 0; i < g.V(); ++i) {
    out << i << ":  ";
    for (const Edge e : g.AdjacentNodes(i)) {
      out << "(" << e.from << "," << e.to << ") : " << e.dist << " ; ";
    }
    out << endl;
  }
  return out;
}
