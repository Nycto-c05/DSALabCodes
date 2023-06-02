#include <iostream>
#include <cstring>
using namespace std;

class node {
public:
    char k[20];
    char m[20];
    node* left;
    node* right;
};

class dict {
public:
    node* root;
    void create();
    void disp(node*);
    void insert(node* root, node* temp);
    int search(node*, char[]);
    int update(node*, char[]);
    node* del(node*, char[]);
    node* min(node*);
};

void dict::create() {
    node* temp;
    int ch;
    do {
        temp = new node;
        cout << "Enter Keyword: ";
        cin >> temp->k;
        cout << "Enter Meaning: ";
        cin >> temp->m;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL) {
            root = temp;
        }
        else {
            insert(root, temp);
        }
        cout << "Do you want to add more? (1-Yes / 0-No): ";
        cin >> ch;
    } while (ch == 1);
}

void dict::insert(node* root, node* temp) {
    if (strcmp(temp->k, root->k) < 0) {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

void dict::disp(node* root) {
    if (root != NULL) {
        disp(root->left);
        cout << "\nKey Word: " << root->k;
        cout << "\tMeaning: " << root->m;
        disp(root->right);
    }
}

int dict::search(node* root, char k[20]) {
    int c = 0;
    while (root != NULL) {
        c++;
        if (strcmp(k, root->k) == 0) {
            cout << "\nNo of Comparisons: " << c;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        else if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

int dict::update(node* root, char k[20]) {
    while (root != NULL) {
        if (strcmp(k, root->k) == 0) {
            cout << "\nEnter New Meaning of Keyword " << root->k << ": ";
            cin >> root->m;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        else if (strcmp(k, root->k) > 0)
            root = root->right;
    }
    return -1;
}

node* dict::del(node* root, char k[20]) {
    node* temp;
    if (root == NULL) {
        cout << "\nElement Not Found";
        return root;
    }
    if (strcmp(k, root->k) < 0) {
        root->left = del(root->left, k);
        return root;
    }
    else if (strcmp(k, root->k) > 0) {
        root->right = del(root->right, k);
        return root;
    }
    if (root->right == NULL && root->left == NULL) {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL) {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    else if (root->left == NULL) {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }
    temp = min(root->right);
    strcpy(root->k, temp->k);
    root->right = del(root->right, temp->k);
    return root;
}

node* dict::min(node* q) {
    while (q->left != NULL) {
        q = q->left;
    }
    return q;
}

int main() {
    int ch;
    dict d;
    d.root = NULL;

    do {
        cout << "\nMenu\n1. Create\n2. Display\n3. Search\n4. Update\n5. Delete\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL) {
                cout << "\nNo keywords added.";
            }
            else {
                d.disp(d.root);
            }
            break;
        case 3:
            if (d.root == NULL) {
                cout << "\nDictionary is empty. Add keywords first.";
            }
            else {
                cout << "\nEnter the keyword you want to search: ";
                char k[20];
                cin >> k;
                if (d.search(d.root, k) == 1)
                    cout << "\nKeyword found.";
                else
                    cout << "\nKeyword not found.";
            }
            break;
        case 4:
            if (d.root == NULL) {
                cout << "\nDictionary is empty. Add keywords first.";
            }
            else {
                cout << "\nEnter the keyword for which you want to update the meaning: ";
                char k[20];
                cin >> k;
                if (d.update(d.root, k) == 1)
                    cout << "\nMeaning updated.";
                else
                    cout << "\nKeyword not found.";
            }
            break;
        case 5:
            if (d.root == NULL) {
                cout << "\nDictionary is empty. Add keywords first.";
            }
            else {
                cout << "\nEnter the keyword you want to delete: ";
                char k[20];
                cin >> k;
                if (d.root == NULL) {
                    cout << "\nNo keywords.";
                }
                else {
                    d.root = d.del(d.root, k);
                }
            }
            break;
        }
    } while (ch <= 5);

    return 0;
}
