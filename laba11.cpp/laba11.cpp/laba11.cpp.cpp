#include <iostream>
using namespace std;
//Дано бинарное дерево, в узлах которого расположены целые числа
//величиной от 0 до 50 000. Числа, меньшие 3000, вывести на экран и удалить из
//структуры дерева.
// Определяем структуру для узла дерева

struct Node {
    int data; // значение в узле
    Node* left; // указатель на левого потомка
    Node* right; // указатель на правого потомка
    Node(int d) : data(d), left(NULL), right(NULL) {} // конструктор
};

Node* insert(Node* root, int data); 
void print(Node* root); 
Node* remove(Node* root, int data); 
Node* findMin(Node* root); 
Node* findMax(Node* root); 

int main() {
    setlocale(LC_ALL, "Rus");
    // Создаем пустое дерево
    Node* root = NULL;
    for (int i = 0; i < 20; i++)
    {
        int value = rand() % 50001;
        root = insert(root, value);
    }
    cout << "Элементы дерева: " << endl;
    print(root);
    cout << endl;
    // Находим минимальный и максимальный элементы в дереве
    Node* min = findMin(root);
    Node* max = findMax(root);
    cout << "Минимальный элемент: " << min->data << endl;
    cout << "Максимальный элемент: " << max->data << endl;
    // Удаляем элементы, меньшие 3000, из дерева и выводим их на экран
    cout << "Удаляем элементы, меньшие 3000: ";
    while (min->data < 3000) {
        cout << min->data << " ";
        root = remove(root, min->data);
        min = findMin(root);
    }
    cout << endl;
    // Выводим элементы дерева после удаления
    cout << "Элементы дерева после удаления: " << endl;
    print(root);
    cout << endl;
    return 0;
}

Node* insert(Node* root, int data) {
    // Если дерево пусто, то создаем новый узел и возвращаем его
    if (root == NULL) {
        return new Node(data);
    }
    // Иначе ищем место для вставки
    // Если значение меньше, чем в корне, то вставляем в левое поддерево
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Если значение больше, чем в корне, то вставляем в правое поддерево
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Если значение равно корню, то ничего не делаем
    // Возвращаем корень дерева
    return root;
}

void print(Node* root) {
    // Если дерево не пусто, то выводим его в порядке возрастания
    if (root != NULL) {
        // Выводим левое поддерево
        print(root->left);
        // Выводим корень
        cout << root->data << " ";
        // Выводим правое поддерево
        print(root->right);
    }
}

Node* remove(Node* root, int data) {
    // root - дерево
    if (root == NULL) {
        return NULL;
    }
    // Иначе ищем элемент для удаления
    // Если значение меньше, чем в корне, то удаляем из левого поддерева
    if (data < root->data) {
        root->left = remove(root->left, data);
    }
    // Если значение больше, чем в корне, то удаляем из правого поддерева
    else if (data > root->data) {
        root->right = remove(root->right, data);
    }
    // Если значение равно корню, то удаляем корень
    else {
        // Если у корня нет потомков, то просто удаляем его
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Если у корня есть только левый потомок, то заменяем его на него
        else if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Если у корня есть только правый потомок, то заменяем его на него
        else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Если у корня есть оба потомка, то заменяем его на минимальный элемент в правом поддереве
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}

Node* findMin(Node* root) {
    // root - дерево
    if (root == NULL) {
        return NULL;
    }
    // Иначе ищем самый левый узел в дереве
    while (root->left != NULL) {
        root = root->left;
    }
    // Возвращаем указатель на него
    return root;
}

Node* findMax(Node* root) {
    // root - дерево 
    if (root == NULL) {
        return NULL;
    }
    // Иначе ищем самый правый узел в дереве
    while (root->right != NULL) {
        root = root->right;
    }
    // Возвращаем указатель на него
    return root;
}