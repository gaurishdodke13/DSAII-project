#include"graph_mine.h"

Graph* createGraph(int numVertex)
{
    Graph* g;
    g = (Graph*)malloc(sizeof(Graph));
    if(g==NULL)
    {
        printf("Graph is not created!");
        return NULL;
    }

    g->numVertex = numVertex;
    g->numEdge = 0;
    g->AdjList = (Node**)malloc(numVertex * sizeof(Node*));
    if(g->AdjList==NULL)
    {
        printf("Adjacency List is not created!");
        return NULL;
    }

    for(int i=0; i<numVertex; i++)
    {
        g->AdjList[i] = (Node*)malloc(sizeof(Node));
        if(g->AdjList[i] == NULL)
        {
            printf("Adjacency List Node is not created!");
            return NULL;
        }

          g->AdjList[i]->vertexID = i;
          g->AdjList[i]->trafDensity = 0;
          g->AdjList[i]->totalTraffic = 0;
          g->AdjList[i]->speedLim = 0;
          g->AdjList[i]->numHalls = 0;
          g->AdjList[i]->numEdge = 0;
          g->AdjList[i]->edgeId = -1;
          g->AdjList[i]->distance = 0;

          g->AdjList[i]->next = NULL;
    }
    return g;
}

Node* createNode()
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Node is not created!");
        return NULL;
    }

    temp->vertexID = -1;
    temp->trafDensity = 0;
    temp->totalTraffic = 0;
    temp->speedLim = 0;
    temp->numHalls = 0;
    temp->numEdge = 0;
    temp->edgeId = -1;
    temp->distance = 0;

    temp->next = NULL;

    return temp;
}

void addEdge(Graph* g, int start, int end, float distance, int speedLim, float trafDensity)
{
    g->numEdge +=1;
    Node* temp = createNode();

    temp->vertexID = end;
    temp->edgeId = g->numEdge;
    temp->distance = distance;
    temp->speedLim = speedLim;
    temp->trafDensity = trafDensity;

    Node* new = g->AdjList[start]->next;
    temp->next = new;
    g->AdjList[start]->next = temp;

    g->AdjList[start]->numEdge +=1;
    g->AdjList[end]->totalTraffic += trafDensity;
}

void deleteEdge(Graph* g, int src, int dest)
{
    Node* ptr = g->AdjList[src];
    while(ptr->next!=NULL)
    {
        if(ptr->vertexID == dest)
        {
            Node* temp;
            temp = ptr->next->next;
            free(ptr->next);
            ptr->next = temp;

            break;
        }

        ptr = ptr->next;
    }
}

Graph* createMap()
{
    int numVertex;
    int numHalls;

    FILE* ptr = fopen("graphinput.txt", "r");
    fscanf(ptr, "%d", &numVertex);

    Graph* g = createGraph(numVertex);

    for(int i=0; i<numVertex; i++)
    {
        fscanf(ptr, "%d", &numHalls);
        g->AdjList[i]->numHalls = numHalls;
    }

    int numEdge;
    int start, end, distance, trafDensity, speedLim;

    fscanf(ptr, "%d", &numEdge);

    for(int i=0; i<numEdge; i++)
    {
        fscanf(ptr, "%d %d", &start, &end);
        fscanf(ptr, "%f %d %f", &distance, &speedLim, &trafDensity);

        addEdge(g, start, end, distance, speedLim, trafDensity);
    }

    return g;
}

void printGraph(Graph* g)
{
    Node* temp;
    for(int i=0; i<g->numVertex; i++)
    {
        temp = g->AdjList[i]->next;
        printf("%d -> [", g->AdjList[i]->vertexID);

        while(temp!=NULL)
        {
            printf("%d ", temp->vertexID);
            temp = temp->next;
        }

        printf("]\n");
    }
}

int main()
{
    printf("HI EVERYTHING IS GOOD HERE");
}