#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó em uma lista de adjacência
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Estrutura para representar uma lista de adjacência
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Função para criar um novo nó
Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Criar uma lista de adjacência para cada vértice
    graph->adjLists = malloc(vertices * sizeof(Node*));

    // Inicializar cada lista de adjacência como vazia
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest) {
    // Adicionar a aresta de src para dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adicionar a aresta de dest para src (grafo não direcionado)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d\n head ", i);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função principal
int main() {
    // Criar um grafo com 4 vértices
    Graph* graph = createGraph(4);

    // Adicionar arestas
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Imprimir o grafo
    printGraph(graph);

    return 0;
}

/*Estrutura do Nó (Node): Representa um nó na lista de adjacência, contendo o destino da aresta e um ponteiro para o próximo nó.

Estrutura do Grafo (Graph): Contém o número de vértices e um array de listas de adjacência.

Função createNode: Cria e inicializa um novo nó.

Função createGraph: Cria um grafo com um número específico de vértices, inicializando todas as listas de adjacência como vazias.

Função addEdge: Adiciona uma aresta entre dois vértices no grafo. Como o grafo é não direcionado, adiciona a aresta em ambas as direções.

Função printGraph: Imprime a lista de adjacência de cada vértice do grafo.

Função main: Cria um grafo com 4 vértices, adiciona algumas arestas e imprime o grafo. */