#include "graph.h"
#include "priority_queue.h"
#include "mst.h"

using namespace std;

int main(int argc, char ** argv)
{
  //test file constructor for Graph class
  string testFile = argv[1];
  Graph fileGraph(testFile);
  
  MST mst(&fileGraph);  
  cout << "MST of graph generated by txt file:" << endl;
  cout << mst;
  cout << endl;
  
}