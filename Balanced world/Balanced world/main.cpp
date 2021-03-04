//
//  main.cpp
//  Balanced world
//
//  Created by 이시윤 on 2021/03/04.
//

#include <iostream>
#include <string.h>
using namespace std;

/* print
 for(int size = 0; size < v; a++){
     cout << text[size] << endl;
 }
 */

 
int main(){
    
    string text;
    getline(cin ,text);
    
    int a;
    for(a = 0; text[a] != NULL;){
        a++;
    }
    
    //ok
    
    int t = 0;
    int s = 0;
    char arr[1000];
    while(t != a+1) {
       if(text[t] == ']'){
            arr[s] = text[t];
            s++;
            t++;
        }
       else if(text[t] == '['){
           arr[s] = text[t];
           s++;
           t++;
        }
       else if(text[t] == '('){
           arr[s] = text[t];
           s++;
           t++;
       }
       else if(text[t] == ')'){
           arr[s] = text[t];
           s++;
           t++;
       }
       else{
           t++;
       }
    }
   /* print arr
    for(int v = 0; v < s; v++){
        cout << arr[v] << endl;
    }*/
    
    int left_small = 0,left_big = 0;
    int size;
    for(size = 0; size <= s; size++){
        if(arr[size] == '('){
            left_small++;
        }
        else if(arr[size] == '['){
            left_big++;
        }
        else if(arr[size] == ')' && left_small > 0 ){
            left_small--;
        }
        else if(arr[size] == ']' && left_big > 0 ){
            left_big--;
        }
    }
    if(left_small + left_big == 0){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
     
     
    
    


    return 0;
}
