struct node;
typedef struct node* position;
struct node {
	int number;
	position next;
};

int Entry(int, position);
int Print(position);
int VisualPrintCircular(position);