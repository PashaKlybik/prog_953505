//Task 5.2.9
/*В текстовом файле содержатся n целых чисел в двоичной системе
счисления (m бит каждое). Построить бинарное дерево, в котором
числам соответствуют листья дерева, а путь по дереву определяется
двоичным представлением числа (‘1’ – переход к правому потомку,
‘0’ – переход к левому потомку).*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <stack>

struct Node
{
    std::string field;           
    struct Node* left;  
    struct Node* right; 
};

void treeprint(Node* tree) 
{
    if (tree != NULL) 
    { 
        treeprint(tree->left); 
        if (tree->field != "NULL") printf("%s ", tree->field.c_str());
        treeprint(tree->right); 
    }
}

void addnode(std::string x, Node*& tree, std::string x_full, int count) 
{
    if (tree == NULL) 
    {
        tree = new Node; 
        tree->field = "NULL";
        tree->left = NULL;
        tree->right = NULL; 
    }

    if (x == "1" || x == "0")
    {
        if (x == "1")
        {
            Node* tree_new = new Node;
            tree_new->right = tree_new->left = NULL;
            tree->right = tree_new;
            x_full.resize(6);
            tree_new->field = x_full;
        }
        else
        {
            Node* tree_new = new Node;
            tree_new->right = tree_new->left = NULL;
            tree->left = tree_new;
            x_full.resize(6);
            tree_new->field = x_full;
        } // заполняем ячейку, если убедились, что спустились вниз
        return;
    }
    if (x[count] == '0')   // условие добавление левого потомка
    {
        std::string buffer = x;
        buffer.resize(count);
        addnode(buffer, tree->left, x_full, count - 1);
    }
    else    // условие добавление правого потомка
    {
        std::string buffer = x;
        buffer.resize(count);
        addnode(buffer, tree->right, x_full, count - 1);
    }
}

void freemem(Node* tree)
{
    if (tree != nullptr)
    {
        freemem(tree->left);
        freemem(tree->right);
        delete tree;
    }
}

int main()
{
    Node* root = nullptr;
    int n = 0, m = 0;
    printf("Enter n: ");
    scanf_s("%d", &n);
    printf("Enter m: ");
    scanf_s("%d", &m);
    FILE* fp;   
    fopen_s(&fp, "Text.txt", "r");
    char ch = 0;
    int i = 0;
    std::string test = "test";
    auto numbers = new std::string[n];
    do {
        ch = getc(fp);
        if (ch == ' ')
        {
            numbers[i] += '\0';
            i++;
        }
        else numbers[i] += ch;
    } while (ch != EOF);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", numbers[i].c_str());
    }
    for (int i = 0; i < n; i++)
    {
        addnode(numbers[i], root, numbers[i], m - 1);
    }
    treeprint(root);
    fclose(fp);    
    return 0;
}
