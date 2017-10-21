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
  Graph(int n) : n(n) {
    adj = new vector<Edge>[n];

    // for each node, create a vector of edges to store
    // all the edges from the node to another node in the graph
    for (int i = 0; i < n; ++i) {
      adj[i] = vector<Edge>();
    }
  }

  // constructor that creates a random graph
  // with set density and distance range parameters
  Graph(int n, double density, double distLow, double distHigh) : n(n) {
    adj = new vector<Edge>[n];
    for (int i = 0; i < n; ++i) {
      adj[i] = vector<Edge>();
    }

    srand(time(0));

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((static_cast<double>(rand()) / RAND_MAX) < density) {
          AddEdge(Edge(i, j, (distHigh - distLow) *
                                     (static_cast<double>(rand()) / RAND_MAX) +
                                 distLow));
        }
      }
    }
  }

  // destructor for Graph
  ~Graph() { delete[] adj; }

  // return number of vertices
  int V() const { return n; }

  // return number of edges
  int E() const { return e; }

  // return edges from node x
  const vector<Edge> &AdjacentNodes(int x) const { return adj[x]; }

  // add an edge from node x to node y if edge doesn't already exist
  void AddEdge(Edge e) {

    // check if edge already exists
    if (!this->Adjacent(e.from, e.to)) {
      vector<Edge> &fromList = adj[e.from];
      vector<Edge> &toList = adj[e.to];

      fromList.push_back(e);
      toList.push_back(Edge(e.to, e.from, e.dist));
    }
  }

  // does the edge from node x to node y exist?
  bool Adjacent(int x, int y) {
    for (Edge &e : adj[x]) {
      if (e.to == y) {
        return true;
      }
    }
    return false;
  }

private:
  const int n;
  int e;
  vector<Edge> *adj;
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
