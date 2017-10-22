In this homework assignment, I learned about object oriented programming in C++.I
learned how to define classes and create different constructors, including default
constructors. I learned how to implement overload operators, especially the compare
operators for the Edge class.

I learned how to implement a graph ADT and how to represent the Graph class as a edge
lists. I learned about how Dijkstra's algorithm could find the shortest path from a
source node by repeatedly finding the minimum distance edge and putting it in the closed
set until there are no edges left. The shortest paths would be updated when there is no
previous shortest path or when the new path found is shorter than the previous one.

I learned how to implement a priority queue ADT and use it to speed up Dijkstra's
algorithm for finding the shortest path. Using a priority queue, finding the shortest
path will take O(E+v*logV) instead of O(V^2).

I learned about how Monte Carlo simulations work by creating one to find the average
shortest path length. I created many trials to average the average shortest path from
a source node to all other nodes. I learned from this Monte Carlo simulation that the
graph with a large edge density had a shorter average path length. 
