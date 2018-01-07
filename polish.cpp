#include <iostream>
#include <memory>

using namespace std;

int variables[127];

class Tree;

class Node
{
 protected:
  virtual ~Node() {}
  virtual int eval() const = 0;
  virtual void print(ostream&) const = 0;
  
 private:
  friend class Tree;
  friend ostream& operator<<(ostream&, Tree&);
};

class IntNode: public Node
{
private:
  friend class Tree;
  int n;
  IntNode(int n): n(n) {}
  int eval() const {return n;};
  void print(ostream& out) const { out << n; }
};

class IdNode: public Node
{
private:
  friend class Tree;
  
}

class Tree
{
public:
  Tree(int n): p(new IntNode(n)) {}
  int eval() { return p->eval(); }
private:
  friend class Node;
  shared_ptr<Node> p;
  friend ostream& operator<<(ostream&, Tree&);
};

ostream& operator<<(ostream& out, Tree& t)
{
  t.p->print(out);
  return out;
}

int main()
{
  variables['A'] = 3; variables['B'] = 4;
  cout << "A = 3; B = 4;" << endl;
  Tree t1 = Tree(5);
  cout << t1 << endl << t1.eval() << endl;
}
