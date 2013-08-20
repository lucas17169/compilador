#include "comp_graph.h"


adjList* insertEnd(comp_graph* node, adjList* list){
	adjList* aux = list;
	adjList* new = malloc(sizeof(adjList*));
	new->node = node;
	if(aux == NULL){
		return new;
	}
	else{
		while(aux->next!=NULL){
			aux = aux->next;
		}
		aux->next = new;
	}
	return list;
}
adjList* removeFirst(adjList* list){
	adjList* aux = list->next;
	free(list);
	return aux;
}

adjList* removeItem(comp_graph* node, adjList* list){
	adjList* current = list, previous = NULL, aux = list;
	while(current!=NULL){
		if(current->node == node){
			if(previous == NULL)
				 aux = current->next;
			else
				previous->next = current->next;
			free(current);
		}
		else{
			previous = current;
			current = previous->next;
		}
	}
	return aux;
}

adjList* createList(){
	return NULL;
}

adjList* destroyList(adjList* list);
	adjList* aux;
	while(list != NULL){
		aux = list->next;
		free(list);
		list = aux;
	}
	return NULL
}


comp_graph* add(int data, comp_graph* root, adjList* adj){
		comp_graph* new = malloc(sizeof(comp_graph));
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		new->list = adj;
		if(new->list!=NULL && root!=NULL){
			adjList* auxList = new->list;
			while(auxList != NULL){
				auxList->node->list = insertEnd(new, auxList->node->list);
				auxList = auxList->next;
			}
		}
		if(root!=NULL){
			comp_graph* fatherNode  = root;
			adjList* treeSearch = createList();
			treeSearch = insertEnd(fatherNode, treeSearch);
			while(treeSearch != NULL){
				if(treeSearch->node->left != NULL && treeSearch->node->right != NULL){
					treeSearch = insertEnd(treeSearch->node->left, treeSearch);
					treeSearch = insertEnd(treeSearch->node->right, treeSearch);
					treeSearch = removeFirst(treeSearch);
				}
				else{
					fatherNode = treeSearch->node;
					treeSearch = destroyList(treeSearch);
				}
			}
			if(fatherNode->left == NULL)
				fatherNode->left = new;
			else fatherNode->right = new;
			return root;			
		}
		else{
			return new;
		}
}


comp_graph* delete(comp_graph* node, comp_graph* root){
	if(root == NULL)
		return NULL;
	else{
		adjList* auxList = node->list;
		while(auxList != NULL){
			auxlist->node->list = removeItem(node, auxlist->node->list);
			auxList = auxList->next;
		}
		comp_graph* fatherNode = findFatherNode(node, root);
		if(node->left == NULL && node->right == NULL){
			if(fatherNode != NULL){
				if(fatherNode->left == node)
					fatherNode->left = NULL;
				else fatherNode->right = NULL;
				free(node);
				return root;
			}
			else{
				free(node);
				return NULL;
			}
		}
		else{
			comp_graph* auxNode = node;
			do{
				while(auxNode->left != NULL)
					auxNode = auxNode->left;
				while(auxNode->right != NULL)
					auxNode = auxNode->right;
			}while(auxNode->left != NULL || auxNode->right !=NULL);
			if(fatherNode != NULL)
				if(fatherNode->left == node)
					fatherNode->left = auxNode;
				else
					fatherNode->right = auxNode;
			else{
				auxNode->right = node->right;
				ausNode->left = node->left;
				free(node);
				return root;
			}		
		}	
	}
}

comp_graph* findFatherNode(comp_graph* node, comp_graph* root){
	comp_graph* auxGraph = root;
	comp_graph* fatherNode = NULL;
	adjList* auxList = insertEnd(auxGraph, auxList);
	while(auxList != NULL && fatherNode == NULL){
		if(auxList->node->left == node || auxList->node->right == node){
			fatherNode = auxList->node;
			auxList = destroyList(auxList);
		}
		else{
			auxList = insertEnd(auxList->node->left, auxList);
			auxList = insertEnd(auxList->node->right, auxList);
			auxList = removeFirst(auxList);
		}
	}
	return fatherNode;
}

comp_graph* edit(int new_data, comp_graph* node, comp_graph* root, adjList* adj);

comp_graph* contains(comp_graph* node, comp_graph* root){
	if(root == NULL)
			return NULL;
		else{
			if(node == root)
				return node;
			else if(search(node, root->esq) != NULL || search(node, root->dir) != NULL)
					return node;
				else return NULL;		
		}
}


comp_graph* create(){
	return NULL;
}


void destroy(comp_graph* root);
