#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* next;
    public:
    node(string d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node* &head , string d){
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

// for inserting at head 
void print(node* &head  ){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"|     |";
        temp = temp->next;
        
    }
}

// for counting the length 
int lengthoflist(node* &head){
    node* temp  = head;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

// for inserting at tail
void insertAtTail(node* &tail , string d){
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

// for inserting at desired position 
void insertAtPosition(node* &head , node* &tail , int position  , string d){
    if(position == 1){
        insertAtHead(head , d);
        return ;
    }
    node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    if(temp -> next == NULL){
        insertAtTail(tail , d);
        return ;
    }
    
    node* temp2 = new node(d);
    temp2->next = temp->next;
    temp->next = temp2;
    
}


int main(){
    
    node* obj = new node("Object");
    // cout<<obj->data<<"   "<<obj->next;
    
    node* head = obj;
    node* tail = obj;
    
    insertAtHead(head , "At head");
    print(head);
    cout<<endl;
    insertAtTail(tail , "At Tail");
    print(head);
    cout<<endl;
    insertAtPosition(head, tail , 3, "At Position ");
    print(head);
    cout<<endl;

    cout<<"length of linked list is : "<<lengthoflist(head);
    
    
    
    return 0;
}
