//change to C++ io
//change to one line comments
//change defines of constants to const
//change array to vector<>
//inline any short functions


#include <iostream>
#include <vector>
#include <complex>

using namespace std;
const int N = 40;

template <class summable>
inline void sum(const vector<summable>& v, summable& s)
{
  for(const summable& e: v) s += e;
}

int main(void)
{
  vector< complex<double> > data;
  vector< double > data2;
  for (int i = 0; i < N; ++i)
  {
    data.push_back(complex<double>(i,i));
    data2.push_back(i/4.0);
  }

  complex<double> s;
  sum(data, s);
  cout << endl << "sum is " << s << endl;

  double s2;
  sum(data2, s2);
  cout << endl << "sum is " << s2 << endl;
  
  return 0;
} 
