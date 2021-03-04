//
//  main.cpp
//  달팽이 리스트
//
//  Created by 이시윤 on 2021/02/19.
//


#include <iostream>
using namespace std;

class Node
{
public:
    friend class List;
private:
    int value;
    Node *next;
    Node(int v, Node *n) : value(v), next(n) { };
};

class List
{
public:
    List();
    List(int v);
    void push(int a);
    void print(int k);
    void del();
    void snail(int i);
    void slug(int i);
    void justprint();
    
private:
    Node *head;
    Node *tail;
    int size;
};

List::List() {
    head = tail = NULL;
    
    size = 0;
}

List::List(int value)
{
    head = tail = new Node(value, NULL);
}

void List::push(int value){
    Node *newNode = new Node(value, NULL);
    if(head == NULL){
        head = tail = newNode;
        
    }
    else{
        tail->next = newNode;
        tail = newNode;
        
    }
}

void List::snail(int i){
    
    Node *scan = head;
    int a = 1;
    while(a != i){
        scan = scan->next;
        a++;
    }
    tail->next = scan;
}

void List::slug(int j){
    cout << tail->value << endl;
}

void List::print(int j)
{
   Node *scan = head;
    int b = 1;
    while(b != j)
   {
      scan = scan->next;
       b++;
   }
    cout << scan->value << endl;
}

void List::justprint(){
    Node *scan = head;
    while(scan != NULL){
        scan = scan->next;
        cout << scan->value <<endl;
    }
}

 
int main(){
    List list; // 생섬자
    int max = 0; // 초기사이즈
    int value;
    cin >> value; // 노드에 넣을 값
    
    while (value != 0){
        
        list.push(value);
        cin >> value;
        max++;
        } //계속 넣어라
    
    cout << "마지막 노드가 가르킬 노드의 순서는??  " << "("<< "0보다 크고 " <<max<< " 보다 같거나 작은값을 입력) " << endl;
    int i;//가르킬 노드의 순서
    int j;//몇번째 값인가요?
    cin >> i;
    /*if(i == max){
        cout << "몇번째 값을 출력할까요?? 종료는 0입력." << endl;
        cin >> j;
        while(j != 0){
        list.slug(j);
            cin >> j;
        }
    }
    else{*/
        cout << "몇번째 값을 출력할까요?? 종료는 0입력." << endl;
        cin >> j;
        list.snail(i);
        while(j != 0){
            list.print(j);
            cin >> j;
        }
            
    //}
    return 0;
}
