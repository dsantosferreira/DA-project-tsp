// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <unordered_set>
#include <climits>
#include <cfloat>

#include "VertexEdge.h"

using namespace std;

typedef unsigned int uint;
typedef vector<int> vInt;

class Graph {
public:
    /**
     * Default constructor for the Graph class;
     */
    ~Graph();

    /**
     * Auxiliary function to find a vertex with a given ID.
     * @param id - the id of the vertex;
     * @return the vertex with the given id;
    */
    Vertex *findVertex(const int &id) const;

    /**
     *  Adds a vertex with a given string id to a graph (this).
     *  @param id - the id of the vertex;
     *  @return true - if successful
     *          false - if a vertex with that id already exists.
     */
    bool addVertex(const int &id);

    /**
     * Adds a vertex to a graph (this).
     * @param v - the vertex to be added;
     * @return true - if successful
     *         false - if a vertex with that id already exists.
     */
    bool addVertex(Vertex *v);

    /**
     * Removes a vertex with a given string id from a graph (this).
     * @param id - the id of the vertex;
     * @return true - if successful
     *         false - if a vertex with that id does not exist.
     */
    bool removeVertex(const int &id);

    /**
     * Removes a vertex from a graph (this).
     * @param v - the vertex to be removed;
     * @return true - if successful
     *         false - if a vertex with that id does not exist.
     */
    bool removeVertex(Vertex *v);

    /**
     * Gets the vertex set of a graph (this).
     * @return the vertex set.
     */
    unordered_map<int, Vertex *> getVertexSet() const;

    /**
     * Depth first search that gives each vertex the number of the connected component it is in
     * Time Complexity: O(V+E) where V is the number of vertexes and E the number of edges of the graph (this)
     * @param src - Vertex we are in
     * @param i - number of the connected component
     */
    void connectedComponentsDfs(Vertex *src, int i);

    bool addEdge(Vertex *v1, Vertex *v2, double distance);

    /**
     * Adds a bidirectional edge to the graph between two vertexes with a given distance.
     * Time Complexity: O(1)
     * @param v1 - the first vertex
     * @param v2 - the second vertex
     * @param distance - the distance of the edge
     * @return true if successful, false otherwise
     */
    bool addBidirectionalEdge(Vertex * &v1, Vertex * &v2, double dist);

    /**
     * Calls the backtracking algorithm for the travelling salesman problem
     * @param path vector that keeps the vertexs in the order they were visited
     * @return distance travelled in the backtracking algorithm for the travelling salesman problem
     */
    double tspBT(vInt &path);

    /**
     * Recursive backtracking algorithm that gives the optimal solution to the traveling salesman problem
     * @param path vector that keeps the vertexs in the order they were visited
     * @param currVertexId id of the currently visited vertex
     * @param currSum distance travelled through the vertexes that were visited
     * @param bestSum least distance travelled through all the vertexes until now
     * @param step number of vertexes that were already visited
     * @return best distance travelled from all the sets that were already experimented
     */
    double tspBacktracking(vInt &path, int currVertexId, double currSum, double bestSum, uint step);

protected:
    std::unordered_map<int, Vertex *> vertexSet; /**< The vertex set of the graph. */

};

#endif /** DA_TP_CLASSES_GRAPH */