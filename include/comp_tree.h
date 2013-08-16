
typedef struct comp_tree_t {
	int data;
	struct comp_tree_t* esq;
	struct comp_tree_t* dir;	
}comp_tree;


comp_tree* add(int data, comp_tree* father_node ,comp_tree* root);
comp_tree* delete(comp_tree* node, comp_tree* root);
comp_tree* edit(int new_data, comp_tree* node, comp_tree* root);
comp_tree* search(comp_tree* node, comp_tree* root);
comp_tree* create();
void destroy(comp_tree* root);
