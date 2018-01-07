#include <iostream>

using namespace std;

template <class T, int n>
class Container
{
public:

  //default constructor
  Container()
  {
    a = new T[n];
  }

  //conversion constructor
  explicit Container(T* b): Container()
  {
    for(int i = 0; i < n; i++)
    {
      a[i] = b[i];
    }	
  }

  //copy constructor
  Container(Container& b): Container()
  {
    for(int i = 0; i < n; i++)
    {
      a[i] = b.a[i];
    }
	
  }

  //move constructor
  Container(Container &&b) noexcept
  {
    a = b.a;
    b.a = nullptr;
  }

  Container& operator=(Container &&b) noexcept
  {
    a = b.a;
    b.a = nullptr;
    return *this;
  }

  T& operator[](unsigned int i)
  {
    return a[i];
  }

  unsigned int size()
  {
    return n;
  }

  //deconstructor
  ~Container()
  {
    delete[] a;
  }
  
private:
  T* a;
};

int main()
{
  int a[5] = {1,2,3,4,5};
  Container<int, 5> arr1(a);
  Container<int, 5> arr2;
  arr2 = move(arr1);

  for(int i = 0; i < arr2.size(); i++)
  {
    cout << arr2[i] << " ";
  }
  cout << endl;
}
