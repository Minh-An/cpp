// File implementing a Minimum PriorityQueue ADT
// Used Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne
// as reference Website: https://algs4.cs.princeton.edu/
// Written by An Doan

#include <vector>

using namespace std;

template <class T>

// class representing a minimum priority queue
class PriorityQueue {
public:
  // PriorityQueue constructor
  PriorityQueue() {
    queue = vector<T>();
    size = 0;
    Edge filler(-1, -1, -1);
    queue.push_back(filler);
  }

  // change the priority of an element in the queue
  void ChangePriority(T priority) {
    // get index of the element
    int i = Contains(priority);
    if (i != -1) {
      // change priority
      T oldPriority = queue[i];
      queue[i] = priority;

      // if element is greater (lower priority), move it down the pq
      if (priority > oldPriority) {
        Lower(i);
      }

      // if element is smaller (higher priority), move it up the pq
      if (priority < oldPriority) {
        Higher(i);
      }
    }
  }

  // get and remove the minimum element
  T MinPriority() {
    T min = queue[1];
    // switch min with max element and move it down the pq
    Exchange(1, size--);
    Lower(1);
    // remove min element
    queue[size + 1] = Edge();
    return min;
  }

  // does the queue contain this element?
  // returns index of element if found
  // if not found, returns -1
  int Contains(T element) {
    // iterate through pq to find element
    for (int n = 1; n <= size; n++) {
      if (queue[n] == element) {
        return n;
      }
    }
    return -1;
  }

  // insert element into the queue
  void Insert(T element) {
    // add element to the end of the pq
    if (queue[++size] == T()) {
      queue[size] = element;
    } else {
      queue.push_back(element);
    }
    // move the new element up the pq
    Higher(size);
  }

  // returns the minimum element
  T Minimum() { return queue[1]; }

  // returns the size of the priority queue
  int Size() { return size; }

  // is the pq empty?
  bool IsEmpty() { return size == 0; }

private:
  int size;
  vector<T> queue;

  // helper functions for Insert and MinPriority

  // moves an element of index i up the pq
  void Higher(int i) {
    while (i > 1 && (queue[i / 2] > queue[i])) {
      Exchange(i, i / 2);
      i = i / 2;
    }
  }

  // moves an element of index i down the pq
  void Lower(int i) {
    while (2 * i <= size) {
      int j = 2 * i;

      if (j < size && (queue[j] > queue[j + 1])) {
        j++;
      }

      if (!(queue[i] > queue[i])) {
        break;
      }

      Exchange(i, j);
      i = j;
    }
  }

  // exchange positions of two elements
  void Exchange(int i, int j) {
    T temp = queue[i];
    queue[i] = queue[j];
    queue[j] = temp;
  }
};
