
typedef struct adjacencyList_t{
	struct comp_graph_t* node;
	struct adjacencyList_t* next;
}adjList;


typedef struct comp_graph_t {
	int data;
	struct comp_graph_t* left;  //pointers for an auxiliary tree structure
	struct comp_graph_t* right;
	struct adjList* list;	
}comp_graph;

adjList* insertEnd(comp_graph* node, adjList* list);
adjList* removeFirst(adjList* list);
adjList* removeItem(comp_graph* node, adjList* list);
adjList* createList();
adjList* destroyList(adjList* list);

comp_graph* add(int data,comp_graph* root, adjList* adj);
comp_graph* delete(comp_graph* node, comp_graph* root);
comp_graph* edit(int new_data, comp_graph* node, comp_graph* root, adjList* adj);
comp_graph* findFatherNode(comp_graph* node, comp_graph* root);
comp_graph* contains(comp_graph* node, comp_graph* root);
comp_graph* create();
void destroy(comp_graph* root);

