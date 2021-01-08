char t;
int length;

struct node;
typedef struct node* position;
struct node {
	int number;
	position next;
};

//stack
int WriteStack(position);
int VisualPrintStack(position);
int SlowPrint(position);
int FirstFunctionStack(position);
int SecondFunctionStack(position);
int ThirdFunctionStack(position);
int FourthFunctionStack(position);
int SpaceAndPause();

int Push(position);
int Pop(position);
int RandomNumber();
int Ispis(position);
int Transform(char[]);

// double
struct double_node;
typedef struct double_node* Position;
struct double_node {
	int number;
	Position next;
	Position prev;
};

int WriteDouble(Position);
int VisualPrintDouble(Position);
int SpaceAndSave(Position, Position);
int TopBorderDouble(Position, Position, int);
int FirstBlockDouble(Position, Position);
int SecondBlockDouble(Position, Position);
int ThirdBlockDouble(Position, Position);
int FourthBlockDouble(Position, Position);
int FifthBlockDouble(Position, Position);
int SixthBlockDouble(Position, Position);

int FreeDouble(position);

// single
int WriteSingular(position);
int VisualPrintSingular(position);
int FreeSingular(position);


// circular
int WriteCircular(position);
int VisualPrintCircular(position);
int FreeCircular(position);

// izbornik
int Single();
int SingularInfo();
int Double();
int DoubleInfo();
int Circle();
int CircleInfo();
int Stack();
