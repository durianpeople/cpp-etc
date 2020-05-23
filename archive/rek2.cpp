#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
    void insert(int value)
    {
        if (value <= this->value)
        {
            if (this->left == NULL)
                this->left = new Node(value);
            else
                this->left->insert(value);
        }

        if (value > this->value)
        {
            if (this->right == NULL)
                this->right = new Node(value);
            else
                this->right->insert(value);
        }
    }
    void printLeaves()
    {
        if (this->left == NULL && this->right == NULL)
            cout << this->value << endl;
        else
        {
            if (this->left != NULL)
                this->left->printLeaves();
            if (this->right != NULL)
                this->right->printLeaves();
        }
    }
};

int main()
{
    int N;
    cin >> N;
    int r;
    cin >> r;
    Node *root = new Node(r);
    for (int i = 0; i < N - 1; i++)
    {
        int member;
        cin >> member;
        root->insert(member);
    }
    root->printLeaves();
    return 0;
}