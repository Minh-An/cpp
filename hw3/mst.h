// File implementing a MST (minimum spanning tree) class using Prim's algorithm
// of taking a node and getting the minimum edge in the open set and adding the
// corresponding node to the closed set until there are V-1 edges in the tree.
// Written by An Doan

#include <vector>
#include <memory>

using namespace std;

// class to find the minimum spanning tree
class MST {

public:
  // constructor for MST class takes in a graph
 MST(Graph *graph) : graph(graph), cost(0), pq(new PriorityQueue<Edge>()) {

    edges = vector<Edge>();

    // initialize all nodes to not marked
    marked = vector<bool>(graph->V());
    for (int i = 0; i < graph->V(); i++) {
      marked[i] = false;
    }
    Visit(0);

    while (!pq->IsEmpty()) {
      Edge min = pq->RemoveMin();
      int to = min.to;
      int from = min.from;

      // if both node on the edge are already in the MST, don't add the edge
      if (marked[to] && marked[from]) {
        continue;
      }

      edges.push_back(min);
      cost += min.dist;

      // visit the added node
      if (!marked[to]) {
        Visit(to);
      }
      if (!marked[from]) {
        Visit(from);
      }
    }
  }

  // returns the cost of the MST
  double Cost() { return cost; }

  // returns all the edges in the MST
  vector<Edge> TreeEdges() { return edges; }

private:
  Graph *graph;

  // cost of the MST
  double cost;

  // array of booleans to determine if a node is already in the MST
  vector<bool> marked;

  // vector of all the edges in the MST
  vector<Edge> edges;

  // open set to add to MST
  const unique_ptr<PriorityQueue<Edge>> pq;

  // adds a node to the MST and marks it
  // adds all adjacent nodes
  void Visit(int n) {
    marked[n] = true;
    for (Edge e : graph->AdjacentNodes(n)) {
      // if the other node on the edge is already in the tree, ignore it
      if (!marked[e.to]) {
        // insert the edges from n to the open set
        pq->Insert(e);
      }
    }
  }
};

ostream &operator<<(ostream &out, MST &mst) {
  out << "Cost of MST: " << mst.Cost() << endl;

  for (Edge e : mst.TreeEdges()) {
    out << e << endl;
  }
  return out;
}
