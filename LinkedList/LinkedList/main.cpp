//
//  main.cpp
//  LinkedList
//
//  Created by Richard Michael on 10/3/19.
//  Copyright © 2019 Richard Michael. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "LinkedList.hpp"



int main(int argc, const char * argv[]) {
    
   /*
    int h = 0;
    int j = 10;
    int k = 20;
    int l = 30;
    int p = 40;
    int o = 50;
    LinkedList<int>* list1 = new LinkedList<int>();
    
    list1->pushFront(o);
    list1->pushFront(p);
    list1->pushFront(l);
    list1->pushFront(k);
    list1->pushFront(j);
    list1->pushFront(h);
    list1->pushBack(h);
    list1->printList();
    
    list1->swapAllNodes();
    list1->mergeSort(&list1->head);
    list1->printList();
    int e = 0;
    */
    LinkedList<int>* list1 = new LinkedList<int>();
    for(int i = 0;i<1000;i++){
        int temp = rand();
        list1->pushFront(temp);
    }
    list1->printList();
    list1->mergeSort(&list1->head);
    list1->printList();
    (list1->checkOrder())?std::cout<<"ok":std::cout<<"error";
    
    /*
    std::ofstream file;
    std::vector<std::string> vec;
    std::string str;
    file.open("words.txt");
    while(file.is_open()){
        while(getline(file,str)){
            get
        }
    
          }*/
    int i = 0;
    
    
    return 0;
}
