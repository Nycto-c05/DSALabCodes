/*A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes.
Find the time and space requirements of your method.*/
#include <iostream>
using namespace std;

class node
{
public:
    char label[20];
    int count;
    node *ptr[5];
};

node *root = NULL;

void create()
{
    // Main book data
    root = new node;
    cout << "Enter Name of the Book --> ";
    cin >> root->label;
    cout << "Enter no. of sections --> ";
    cin >> root->count;

    // Section
    for (int i = 0; i < root->count; i++)
    {
        root->ptr[i] = new node;
        cout << "Enter section name : ";
        cin >> root->ptr[i]->label;
        cout << "Enter no. of subsections --> ";
        cin >> root->ptr[i]->count;

        // Sub Section
        for (int j = 0; j < root->ptr[i]->count; j++)
        {
            root->ptr[i]->ptr[j] = new node;

            cout << "Enter name of subsection --> ";
            cin >> root->ptr[i]->ptr[j]->label;
        }
    }
}
void print()
{
    cout << endl<< "Book : " << root->label << endl
         << endl;

    for (int i = 0; i < root->count; i++)
    {
        cout<<"Sections :- "<<endl;
        cout << root->ptr[i]->label << endl;
        for (int j = 0; j < root->ptr[i]->count; j++)
        {
            cout << "\t" << root->ptr[i]->ptr[j]->label << endl;
        }
    }
}

int main()
{
    create();
    print();
    return 0;
}
