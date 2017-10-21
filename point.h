namespace ad
{
  class Point
  {

  public:
    Point();

    Point(int x, int y);
    
    void SetX(int);
  
    void SetY(int);
    
    int GetX();

    int GetY();

  private:
    int x;
    int y;
    
  };

}
