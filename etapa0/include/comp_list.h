
typedef struct item{
	int data;
	struct comp_list_t *next;
	struct comp_list_t *prev;
} comp_list_t;


comp_list_t* create();
comp_list_t* add(int data, comp_list_t* first);
comp_list_t* search(int data, comp_list_t* first);
comp_list_t* rmv(comp_list_t* node);
comp_list_t* concat(comp_list_t* list1, comp_list_t* list2);
