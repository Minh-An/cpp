#include <iostream>

using namespace std;

class Point
{

public:

  void SetX(int x_val)
  {
    x = x_val;
  }
  
  void SetY(int y_val)
  {
    y = y_val;
  }

  int GetX()
  {
    return x;
  }

  int GetY()
  {
    return y;
  }
    
private:
  int x;
  int y;
  
};

ostream& operator<<(ostream& out, const)
