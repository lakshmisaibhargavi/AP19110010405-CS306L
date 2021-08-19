#include <iostream>
using namespace std;

struct Node{
	string name;
	struct Node* next;
	struct dt *para;
	struct arr *arrayPara;
} *head = NULL;


struct dt{
	string type; //for the datatype of the variable
	string scope; // either global or local
};


struct arr{
	string type; //for the datatype of the variable
	int noOfDimensions; //whether it is one dimensional array or 2 dimension or n dimensions => eg. a[3][4] is a 2-D array
	int *dimensions; //and in those the first dimension is 3 and second one is 4
};



int main()
{
	struct Node* temp = ( struct Node* ) malloc(sizeof(struct Node));
	struct arr* arrayPointer = ( struct arr* ) malloc(sizeof(struct arr));
	head = temp;
	temp -> para = NULL;
	head -> arrayPara=arrayPointer;
	head -> name="abc";
	head -> arrayPara->type="int";
	head -> arrayPara->noOfDimensions=3;
	head -> arrayPara->dimensions = (int*) malloc(sizeof(int)*head->arrayPara->noOfDimensions);
	cout <<"Name: "<<head->name<<endl;
	cout <<"Type: "<<head->arrayPara->type << endl;
	cout <<"Number of Dimensions: "<<head->arrayPara->noOfDimensions << endl;
	
	
	return 0;
}