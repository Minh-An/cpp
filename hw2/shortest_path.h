// This File implements a ShortestPath class that calculates the shortest path
// from a source node to all other nodes using Dijkstra's algorithm
// Used Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne
// as reference Website: https://algs4.cs.princeton.edu/
// distance from a source node to all other nodes

#include <limits>
#include <list>

using namespace std;

// ShortestPath class to find the shortest path from a source node to all other
// nodes in the graph if there is one
class ShortestPath {
public:
  // Constructor takes in a graph and an int for the source node
  ShortestPath(Graph *graph, int source) : graph(graph), source(source) {
    distTo = new double[graph->V()];
    edgeTo = new Edge[graph->V()];

    // set all distances to infinity
    // except distance to source node is equal to 0
    for (int v = 0; v < graph->V(); v++) {
      distTo[v] = numeric_limits<double>::infinity();
    }
    distTo[source] = 0.0;

    // create priority queue and add the source node
    pq = new PriorityQueue<Edge>();
    pq->Insert(Edge(source, source, distTo[source]));

    // until the pq is empty and there are no more possible paths
    // continue to add possible paths and relax edges
    while (!pq->IsEmpty()) {
      Edge e = pq->MinPriority();
      for (Edge adj : graph->AdjacentNodes(e.to)) {
        relax(adj, e);
      }
    }
  }

  // destructor for ShortestPath class
  ~ShortestPath() {
    delete[] distTo;
    delete[] edgeTo;
    delete pq;
  }

  // returns the shortest path from the source node to node v
  list<Edge> Path(int v) {
    list<Edge> path = list<Edge>();
    // check if path exists
    if (distTo[v] != numeric_limits<double>::infinity()) {
      int x = v;
      Edge empty = Edge();
      // goes through the edgeTo[] to find the path in reverse order
      // stops when it reaches the source node and there is no edgeTo element
      for (Edge e = edgeTo[v]; !(edgeTo[x] == empty); e = edgeTo[x]) {
        path.push_front(e);
        x = e.from;
      }
    }
    return path;
  }

  // returns the distance of the shortest path from the source node to v
  // if path doesn't exist, returns numeric_limits<double>::infinity()
  double PathDistance(int v) { return distTo[v]; }

private:
  Graph* graph;

  // source node
  int source;

  // array of distances to each node
  double* distTo;

  // last edge connecting the path to the nodes
  Edge* edgeTo;

  PriorityQueue<Edge>* pq;

  // helper function that relaxes edge adj and updates the pq
  void relax(Edge adj, Edge e) {
    int v = adj.to;

    // if new path found is less than previous path
    // or this is the first path found
    // update or insert the new path
    if (distTo[v] > distTo[e.to] + adj.dist) {

      distTo[v] = distTo[e.to] + adj.dist;
      edgeTo[v] = adj;

      Edge updated(adj.from, v, distTo[v]);

      if (pq->Contains(adj) > -1) {
        pq->ChangePriority(updated);
      }

      else {
        pq->Insert(updated);
      }
    }
  }
};
