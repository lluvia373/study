//
//  main.cpp
//  double linked list
//
//  Created by 이시윤 on 2021/02/16.
//  더블

#include <iostream>
using namespace std;

class Node{
public:
    friend class List;
private:
    int value;
    Node *next;
    Node *prev;
    Node(Node *p, int v, Node *n):prev(p), value(v), next(n){};
};

class List{
public:
    List(int v);
    void push(int);
    void del();
    void print();
    void print_backwards();
    
private:
    Node *head;
    Node *tail;
};

List::List(int v){
    head = tail = new Node(NULL, v, NULL);
}

void List::push(int value){
    
    
    if(head == NULL){
        head = tail = newNode;    // 첫생성때 next와 previous가 같다고 해도 되는지 잘 모르겠다
    }
    
    else{
        
        Node *n_memory; // 전의 주소를 옮길 저장 공간
        n_memory = tail; //전의 주소를 저장함
        
        tail->next = newNode; // tail의 다음은 뉴노드
        tail = newNode; //newnode가 tail 이 되었으므로 교체
        
        Node *p_memory;
        p_memory = tail;
        
        tail = newNode;
        tail->prev = p_memory;
        
        
        }
}
    
void List::print(){
   Node *scan = head;
   while(scan != NULL)
   {
       cout << scan->value << endl;
       scan = scan->next;
   }
}
void List::print_backwards(){
    Node *backscan = tail;
    while(backscan != NULL)
    {
        cout << backscan->value << endl;
        backscan = backscan->prev;
    }
    
    
}
int main(){
    List list(3);
    list.push(2);
    list.push(7);
    list.push(19);
    list.push(193);
    list.push(4883794);
    list.push(33);
    
    
    //list.print();
    list.print_backwards();
    
    return 0;
}
