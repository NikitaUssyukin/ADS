#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node * next;
Node(int data){
    this->data=data; 
    this->next = NULL;
}
Node(int data, Node * next){
    this->data=data; 
    this->next = NULL;
}
};

class LL{
    public:
        Node * first;
    LL(){
        this->first=NULL;
    }
    Node * insert(Node * first, int data){
        if(first == NULL) return new Node(data);
        first->next = insert(first->next, data); 
        return first;
    }
    void print(Node * first){
        if(first==NULL) return;
        print(first->next);
        cout << first->data << endl;
    }
    /*Node * insertLast(Node * first, int data){
        if(first == NULL) return new Node(data);
        this->first = new Node(data, this->first);
    }*/
    int count(Node * first, int x){
        int cnt = 0;
        Node * checked = first;
        while (checked!=NULL){
            if(checked->data == x) cnt+=1;
            checked = checked -> next;
        }
        return cnt;
    }
    int getNth(Node * first, int x){
        int cnt = 0;
        int element;
        Node * checked = first;
        while(cnt<=x){
            cnt++;
            if (checked -> next == NULL && cnt < x-1) return -1;
            else  element = checked -> data;
            checked = checked -> next;
        }
        return element;
    }
};

int main(){
    LL *ll = new LL();
    int n, x, cnt=0;
    while(cin>>n){
        if (n!=0) ll -> first = ll -> insert(ll->first, n);
        else break;
    }

    cin>>x;

    cnt = ll->count(ll->first, x);

    cout << cnt << endl;

    cout<<(ll->getNth(ll->first, 3));

    return 0;
}