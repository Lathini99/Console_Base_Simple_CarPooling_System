#pragma once
#include <vector>
#include <iostream>

using namespace std;

int NO_PARENT = -1;

class Graph
{
public:

    vector<vector<int> > adj =
            { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };  


    void addEdge(int v1, int v2, int w);
    vector<int> getPath(int currentVertex, vector<int> parents);
    void dijkstra(int startVertex, int endVertex, int* distance, vector<int>* path);
};

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1][v2] = w;
    adj[v2][v1] = w;
}

vector<int> Graph::getPath(int currentVertex, vector<int> parents)
{
    vector<int> path;
    
    if (currentVertex == NO_PARENT) {
        return path;
    }
    
    path=getPath(parents[currentVertex], parents);
    path.push_back(currentVertex);
    
    return path;
}

void Graph::dijkstra(int startVertex, int endVertex, int* distance, vector<int>* path)
{
    int nVertices = adj[0].size();

    vector<int> shortestDistances(nVertices);

    vector<bool> added(nVertices);

    for (int vertexIndex = 0; vertexIndex < nVertices;
        vertexIndex++) {
        shortestDistances[vertexIndex] = INT_MAX;
        added[vertexIndex] = false;
    }

    shortestDistances[startVertex] = 0;

    vector<int> parents(nVertices);

    parents[startVertex] = NO_PARENT;

    for (int i = 1; i < nVertices; i++) {

        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices;
            vertexIndex++) {
            if (!added[vertexIndex]
                && shortestDistances[vertexIndex]
                < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance
                    = shortestDistances[vertexIndex];
            }
        }

        added[nearestVertex] = true;

        for (int vertexIndex = 0; vertexIndex < nVertices;
            vertexIndex++) {
            int edgeDistance
                = adj[nearestVertex]
                [vertexIndex];

            if (edgeDistance > 0
                && ((shortestDistance + edgeDistance)
                    < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex]
                    = shortestDistance + edgeDistance;
            }
        }
    }

    *distance = shortestDistances[endVertex];
    *path = getPath(endVertex, parents);

}