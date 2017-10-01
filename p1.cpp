//change to C++ io
//change to one line comments
//change defines of constants to const
//change array to vector<>
//inline any short functions


#include <iostream>
#include <vector>

using namespace std;
const int N = 40;

inline void avg(const vector<int>& v, double* p)
{
  int sum = 0;
  for(const int& e: v) sum += e;
  *p = static_cast<double> (sum)/v.size();
}

int main(void)
{
  vector<int> data;
  for (int i = 0; i < N; ++i)
    data.push_back(i);

  double average = 0;
  avg(data, &average);
  cout << "average is " << average << endl;
  return 0;
} 
