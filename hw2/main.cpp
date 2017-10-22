#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

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

// Monte Carlo simulation to find average of average shortest paths
// Goes through 1000 trials to get average shortest path from source vertices 0, 10, 20, 30, 40
int main(void) {

  for (int i = 0; i < 50; i += 10)
  {
    double sum1 = 0;
    double sum2 = 0;
    for (int j = 0; j < 1000; j++)
    {
      //random graph of density .20
      Graph randGraph1(50, .2, 1.0, 10.0);
      
      //random graph of density .40
      Graph randGraph2(50, .4, 1.0, 10.0);
      
      sum1 += AverageShortestPath(&randGraph1, 0);
      sum2 += AverageShortestPath(&randGraph2, 0);
      
    }
    
    cout << "Average shortest path for node " << i << " and Density .20: " << (sum1/1000) << endl;
    cout << "Average shortest path for node " << i << " and Density .40: " << (sum2/1000) << endl;
    cout << endl;
  }
  
}
