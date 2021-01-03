struct node;
typedef struct node* position;
struct node {
	int number;
	position next;
	position prev;
};

int Write(position);
int Print(position);
int VisualPrintDouble(position);
position SpaceAndSave(position, position);
int TopBorderDouble(position, position, int);
int FirstBlockDouble(position, position);
int SecondBlockDouble(position, position);
int ThirdBlockDouble(position, position);
int FourthBlockDouble(position, position);
int FifthBlockDouble(position, position);
int SixthBlockDouble(position, position);