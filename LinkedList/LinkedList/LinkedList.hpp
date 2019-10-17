//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Richard Michael on 10/3/19.
//  Copyright © 2019 Richard Michael. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <utility>
template<class T>
class Node{
       public:
       Node<T>* next;
       T value;
       Node<T>* prev;
       Node(T value){
           this->value = value;
           next = nullptr;
           prev = nullptr;
       }
       Node(){
           next = nullptr;
           prev = nullptr;
       }
       Node(T value,Node* prev, Node* next){
           this->value = value;
           this->next = next;
           this->prev = prev;
       }
    ~Node(){
        /*if(this->prev!=nullptr){
            delete this->prev->next;
        }
        if(this->next!=nullptr){
            delete this->next->prev;
        }*/
    }
      /* Node* operator=(const Node& node){
           this->value = node.value;
           this->prev = node.prev;
           this->next = node.next;
           return *this;
       }*/
       
   };
template<class T>class LinkedList{
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList(){
        
    }
public:
    Node<T>* head;
    Node<T>* tail;
    int size;
    void pushFront(T val){
        Node<T>* temp = new Node<T>(val);
        if(head==nullptr){
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void pushBack(T val){
        Node<T>* dum = new Node<T>();
        dum->next = head;
        while(dum->next!=NULL){
            dum = dum->next;
        }
        dum->next = new Node<T>(val);
        dum->next->prev = dum;
        tail = dum->next;
    }
    
    void printList(){
        Node<T>* dum = new Node<T>();
        dum->next = head;
        while(dum->next!=nullptr){
            dum = dum->next;
            std::cout << dum->value << " ";
        }
        std::cout<< std::endl;
    }
    
    void swapAllNodes(){
        Node<T>* curr = head;
        while(curr && curr->next){
            T temp = curr->value;
            curr->value = curr->next->value;
            curr->next->value = temp;
            curr = curr->next->next;
        }
    }
    void swapNodes(Node<T>** a, Node<T>** b){
        T temp = *a->value;
        *a->value = *b->value;
        *b->value = temp;
    }
    Node<T>* findMid(Node<T>* head){
        if(head==nullptr){
            return head;
        }else{
            Node<T>* slow = head;
            Node<T>* fast = head;
            while(fast->next!=nullptr &&fast->next->next!=nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
             return slow;
        }
        
    }
    void mergeSort(Node<T>** head){
        if(*head==nullptr|| (*head)->next==nullptr){
            return;
        }
        Node<T>* mid = findMid(*head);
        Node<T>* leftH = *head;
        Node<T>* rightH = mid->next;
        rightH->prev = nullptr;
        mid->next = nullptr;
        
        mergeSort(&leftH);
        mergeSort(&rightH);
        
        *head = merge(leftH, rightH);
    }
    Node<T>* merge(Node<T>* l, Node<T>* r){
        if(l==nullptr){
            return r;
        }
        if(r==nullptr){
            return l;
        }
        if(l->value<=r->value){
            l->next = merge(l->next,r);
            l->next->prev = l;
            l->prev = nullptr;
            return l;
        }else{
            r->next = merge(l,r->next);
            r->next->prev = r;
            r->prev = nullptr;
            return r;
        }
    }
    bool checkOrder(){
        Node<T>* dum = new Node<T>();
        dum->next = head;
        while(dum->next!=nullptr&&dum->next->next!=nullptr){
            dum = dum->next;
            if(dum->value>dum->next->value){
                return false;
            }
        }
        return true;
    }
    
};


#endif /* LinkedList_hpp */
