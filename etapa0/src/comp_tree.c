#include <stdlib.h>
#include "comp_tree.h"


comp_tree* add(int data, comp_tree* father_node, comp_tree* root){
	if(search(father_node, root)!=NULL && (father_node->esq == NULL || father_node->dir == NULL)){
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

comp_tree* delete(comp_tree* node, comp_tree* root){
		if(search(node, root)!=NULL && (node->esq == NULL && node->dir == NULL)){
			free(node);
			return root;
		}
		else return NULL;
			
}

comp_tree* edit(int new_data, comp_tree* node, comp_tree* root){
	if(search(node, root)!=NULL){
		node->data = new_data;
	}
	return node;
}

comp_tree* search(comp_tree* node, comp_tree* root){
	if(node == NULL)
		return NULL;
	else{
		if(node == root)
			return node;
		else if(search(node, root->esq) != NULL || search(node, root->dir) != NULL)
				return node;
			else return NULL;		
	}
}

comp_tree* create(){
	return NULL;
}
void destroy(comp_tree* root){
	if(root!=NULL){
		destroy(root->esq);
		destroy(root->dir);
		free(root);
	}
}

