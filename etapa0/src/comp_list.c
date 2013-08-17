#include "comp_list.h"

comp_list_t* create(){
	return NULL;	
}

//adds an new item at the end of an circular list
comp_list_t* add(int data, comp_list_t* first){
	comp_list_t* new = malloc(sizeof(comp_list_t*));
		new->data = data;
	if(first!=NULL){
		first->prev->next = new;
		new->prev = first->prev;
		first->prev = new;
		new->next = first;
		return first;
	}
	else{
		new->next = new;
		new->prev = new;
		return new;
	}
}

comp_list_t* search(int data, comp_list_t* first){
	comp_list_t** cmpNode = *first;
	while(&cmpNode->next != first && &cmpNode->data != data){
		cmpNode = cmpNode->next;
	}
	if(&cmpNode->data == data)
		return &cmpNode;
	else return NULL;
}

void rmv(comp_list_t* node){
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node); 
}

comp_list_t* concatList(comp_list_t* list1, comp_list_t* list2){
	comp_list_t* last1 = list1->prev;
	last1->next = list2;
	list2->prev->next = list1;
	list1->prev = list2->prev;
	list2->prev = last1;
	return list1;
}
