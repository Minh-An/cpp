#include <iostream>
#include <cstdint>

using namespace std;

//CLASS DAYS EXTENDS int8_t TYPE
enum class days : int8_t 
{
  SUN, MON, TUE, WED, THU, FRI, SAT
};

//overload ++ operator; PREFIX ++d
days operator++(days& d)
{
  d = static_cast<days>((static_cast<int>(d) + 1) % 7);
  return d;
}

//overload ++ operator; POSTFIX d++
days operator++(days& d, int)
{
  days temp = d;
  d = static_cast<days>((static_cast<int>(d) + 1) % 7);
  return temp;
}

//overload output operator; cout << c
ostream& operator<<(ostream& out, const days& d)
{
  switch (d)
  {
    case days::SUN:
      out << "Sunday";
      break;
    case days::MON:
      out << "Monday";
      break;
    case days::TUE:
      out << "Tuesday";
      break;
    case days::WED:
      out << "Wednesday";
      break;
    case days::THU:
      out << "Thursday";
      break;
    case days::FRI:
      out << "Friday";
      break;
    case days::SAT:
      out << "Saturday";
      break;
  }
  return out;
}

int main()
{
  days today = days::FRI;
  cout << "Today is " << today++ << endl;
  cout << "Tomorrow is " << today << endl;
  cout << "The next day is " << ++today << endl;
  return 0;
}

