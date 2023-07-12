#include <stdio.h>          
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

#define present 1
#define absent 0

#define crossingTime 15

typedef struct node{
    int vertexID;
    int numHalls;
    int numEdge;
    float totalTraffic;

    int edgeId;
    float trafDensity;
    float distance;
    int speedLim;

    struct node* next;
}Node;

typedef struct graph
{
    int numVertex;
    int numEdge;
    Node** AdjList;
}Graph;

Node* createNode();
Graph* createGraph(int numVertex);
void addEdge(Graph* g, int start, int end, float distance, int speedLim, float trafDensity);
void deleteEdge(Graph* g, int src, int dest);
void printGraph(Graph* g);
Graph* createMap();

