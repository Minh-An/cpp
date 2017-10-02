//Converted program from C to C++
//changed to C++ io
//changed to one line comments
//changed #define to const
//change array to vector<>
//inline short functions

#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

//given a vector of ints d and a reference to an int p
//store the sum of the elements of d into p
inline void sum(vector<int> d, int& p)
{
  for(const int& e: d) p += e; 
}


//summing all the elements of data (numbers 0 to N-1)
//printing the sum out to the screen
int main()
{
  vector<int> data;
  
  for(int i = 0; i < N; ++i) data.push_back(i);

  int accum;
  sum(data, accum);

  cout << "sum is " << accum << endl;

  return 0;
}
