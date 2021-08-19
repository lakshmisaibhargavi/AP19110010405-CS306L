#include <iostream>
#define MAX_NAME 256
#define TABLE_SIZE 25
using namespace std;

struct Node{
    string name;
    struct dt *para;
    struct arr *arrayPara;
}*head=NULL;

struct dt{
    string type;
    string scope;
};

struct arr{
    string type;
    int noOfDimensions;
    int *dimensions;
};

Node* table[TABLE_SIZE];

//the index values for the given keys in the hash table
int HashFunction(string name) 
{
    int length = name.length();
    int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += (name[i]);
    }
    hash_value = hash_value % TABLE_SIZE;
    return hash_value;
}

//initialising all the values in the table as null
void IntiTable() 
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
}

//insertion of a new node in the table
bool InsertInTable(Node *p)
{
    if(p == NULL) return false;
    int index = HashFunction(p -> name);
    if(table[index] != NULL)
    {
        return false;
    }
    table[index] = p;
    return true;
}

//printing the values in the table
void PrintTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == NULL)
        {
            cout << "---- \n";
        }
        else
        {
            cout << table[i] -> name << "\n";
        }
    }
}

//finds the address of the given string name
Node* Table_Lookup(string name)
{
  int index = HashFunction(name);
  if(table[index] != NULL && name == (table[index] -> name))
  {
    return table[index];
  }
  else
  {
    return NULL;
  }
}

int main()
{
    struct Node* temp = ( struct Node* )malloc(sizeof(struct Node));
    struct arr* arrayPointer = ( struct arr* )malloc(sizeof(struct arr));
    head = temp;
    temp->para=NULL;
    head->arrayPara=arrayPointer;
    head->name="abc";
    head->arrayPara->type="int";
    head->arrayPara->noOfDimensions=3;
    head->arrayPara->dimensions = (int*)malloc(sizeof(int)*head->arrayPara->noOfDimensions);

  InsertInTable(head);
  cout << "\n";
  PrintTable();
  cout << Table_Lookup("abc")->name;

    return 0;
}