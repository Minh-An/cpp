#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

// calculates the average shortest path for one node
// to all other nodes in a graph

double AverageShortestPath(Graph *g, int source) {
  ShortestPath sp(g, source);
  double sum = 0;
  int n = 0;

  // summing all shortest paths that exist
  for (int i = 0; i < g->V(); i++) {
    if (i != source &&
        sp.PathDistance(i) != numeric_limits<double>::infinity()) {
      sum += sp.PathDistance(i);
      n++;
    }
  }

  //return the average
  return sum / n;
}

// test main
int main(void) {

  //random graph of density .20
  Graph randGraph1(50, .2, 1.0, 10.0);

  //random graph of density .40
  Graph randGraph2(50, .4, 1.0, 10.0);

  double average1 = AverageShortestPath(&randGraph1, 0);
  double average2 = AverageShortestPath(&randGraph2, 0);
  cout << "Average Shortest Path for Node 0 For Graph 1: " << average1 << endl;
  cout << "Average Shortest Path for Node 0 For Graph 2: " << average2 << endl;
}
