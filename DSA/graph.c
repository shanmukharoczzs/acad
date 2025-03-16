#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
    int data;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    int no_of_nodes;
    GraphNode** adjlist;
} Graph;

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->no_of_nodes = n;
    graph->adjlist = (GraphNode**)malloc(n * sizeof(GraphNode*));
    for (int i = 0; i < n; i++) {
        graph->adjlist[i] = NULL;
    }
    return graph; 
}

GraphNode* createNode(int val){
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->data = val;
    node->next = NULL;
    return node;
}

void addEdge(int u , int v , Graph *graph){
    //connect u ,v
    GraphNode* node = createNode(v);
    node->next = graph->adjlist[u];
    graph->adjlist[u] = node;
    // connect v ,u
    GraphNode* node = createNode(u);
    node->next = graph->adjlist[v];
    graph->adjlist[v] = node;
}

void DFS(){
    int visited[];
    for (int i = 0; i < size; i++){
        visited[i] = 0;
    }
    
}

int main() {
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);
    Graph* graph = createGraph(nodes);

    for(int i = 0 ; i < edges ; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(u, v, graph);
    }
    return 0;
}