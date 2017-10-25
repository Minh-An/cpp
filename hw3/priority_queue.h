// File implementing a Minimum PriorityQueue ADT
// Used Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne
// as reference Website: https://algs4.cs.princeton.edu/
// Written by An Doan

#include <vector>

using namespace std;

// class representing a minimum priority queue
template <class T> class PriorityQueue {
public:
  // PriorityQueue constructor
  PriorityQueue() : size(0) {

    // Insert empty object as first element so math for priority queue works
    // (queue index starts at 1)
    T filler;
    queue.push_back(filler);
  }

  // get and remove the minimum element
  T RemoveMin() {
    T min = queue[1];
    // switch min with max element
    Exchange(1, size--);
    // make sure queue is heap invariant
    HeapifyDown(1);
    queue.pop_back();
    return min;
  }

  // insert element into the queue
  void Insert(T element) {
    // add element to the end of the pq
    queue.push_back(element);
    size++;
    // make sure queue is heap invariant
    HeapifyUp(size);
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
  void HeapifyUp(int i) {
    while (i > 1 && (queue[i / 2] > queue[i])) {
      Exchange(i, i / 2);
      i = i / 2;
    }
  }

  // moves an element of index i down the pq
  void HeapifyDown(int i) {
    while (2 * i <= size) {
      int j = 2 * i;

      if (j < size && (queue[j] > queue[j + 1])) {
        j++;
      }

      if (queue[i] < queue[j]) {
        return;
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
