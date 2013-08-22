#include <stdlib.h>
#include "comp_tree.h"


comp_tree* tree_Add(int data, comp_tree* father_node, comp_tree* root){
	if(tree_Search(father_node, root)!=NULL && (father_node->esq == NULL || father_node->dir == NULL)){
		if(father_node->esq == NULL){
			comp_tree *new_node = malloc( sizeof(comp_tree));
			father_node->esq = new_node;
			return new_node;
		}
		else{
			comp_tree *new_node = malloc( sizeof(comp_tree));
			father_node->dir = new_node;
			return new_node;
		}

	}
	else return NULL;
}

comp_tree* tree_Delete(comp_tree* node, comp_tree* root){
		if(tree_Search(node, root)!=NULL && (node->esq == NULL && node->dir == NULL)){
			free(node);
			return root;
		}
		else return NULL;

}

comp_tree* tree_Edit(int new_data, comp_tree* node, comp_tree* root){
	if(tree_Search(node, root)!=NULL){
		node->data = new_data;
	}
	return node;
}

comp_tree* tree_Search(comp_tree* node, comp_tree* root){
	if(root == NULL)
		return NULL;
	else{
		if(node == root)
			return node;
		else if(tree_Search(node, root->esq) != NULL || tree_Search(node, root->dir) != NULL)
				return node;
			else return NULL;
	}
}

comp_tree* tree_Create(){
	return NULL;
}
void tree_Destroy(comp_tree* root){
	if(root!=NULL){
		tree_Destroy(root->esq);
		tree_Destroy(root->dir);
		free(root);
	}
}

