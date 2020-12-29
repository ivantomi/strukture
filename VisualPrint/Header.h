struct node;
typedef struct node* position;
struct node {
	int number;
	position next;
};

int Write(position);
int Print(position);
int VisualPrint(position);
