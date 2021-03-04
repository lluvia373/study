//
//  main.cpp
//  Binary tree
//
//  Created by 이시윤 on 2021/02/25.
//


#include <iostream>
using namespace std;

class Node{
private:
    friend class Tree;
public:
    int value;
    Node *left;
    Node *right;
    Node *prev;
    Node (Node *l, Node *r, Node *p, int v) : left(l), right(r), prev(p), value(v) { };
};

class Tree{
private:
    Node *head; //시작지점
    Node *tail; //가장 마지막으로 만든 노드
public:
    Tree();
    Tree(int v);
    void push(int v);
    void print();
};
Tree::Tree(){
    head = tail = NULL;
}
Tree::Tree(int v){
    head = tail = new Node(NULL, NULL, NULL, v);
}

void Tree::push(int v){
    int x,y = 0;
    Node *newNode = new Node(NULL, NULL, NULL, v);
    if(head == NULL){
        cout << "push NULL head " << endl;
        head = tail = newNode;
        cout << x << y << endl;
    } //push when is empty
    
   /* else if(head !=NULL && tail == NULL){
        cout << "prev" << endl;
        
    } //left right blank*/
    else{
        cout << "choose left,right,prev" << endl;
        int b;
        cin >> b;
        if(b == 1){
            cout << "left" << endl;
            tail->left = newNode;
            newNode->prev = tail;
            tail = newNode;
            x++;
            cout << x << y << endl;
        } //push left
        else if(b == 2){
            cout << "right" << endl;
            int v;
            cin >> v;
            tail->right = newNode;
            newNode->prev = tail;
            tail = newNode;
            y++;
            cout << x << y << endl;
        }//push right
        else if(b == 3){
            tail = tail->prev;
            cout <<" choose left,right,prev" <<endl;
            cin >> b;
            x--;
            cout << x << y << endl;
        }
    }
}


void Tree::print(){
    Node *scan = head;
    Node *memory = head;
    while(scan != tail){
        cout << scan->value << endl;
        if(scan != NULL){
            scan = scan->left;
            memory = scan;
        }
        
        }
    }

int main(){
    cout << "push number" << endl;
    int a;
    cin >> a;
    Tree tree1;
    while(a != 0){
        tree1.push(a);
        cout << "repush" << endl;
        cin >> a;
    }
    tree1.print();
    return 0;
}
