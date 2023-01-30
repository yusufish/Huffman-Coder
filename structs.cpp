//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname: Yusuf ŞAHİN
//--------------------------//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "structs.h"
using namespace std;

PriorityQueue::PriorityQueue(){
    this->head = NULL;
};

void PriorityQueue::enque(Node* newnode){ // This function adds given node to priority queue && newnode is initialized at where enque() has been called
    //TODO

    if (this->head == NULL) { // Priority queue is empty
        this->head = newnode;
        return;
    }
    Node* initial = this->head;
    Node* terminal = NULL;
    while (initial->token.val <= newnode->token.val){
        terminal = initial;
        initial = initial->next;
        if (initial == NULL) break;
    }
    if (terminal != NULL){
        terminal->next = newnode;
        newnode->next = initial;
    }
    else {
        terminal = newnode;
        head = newnode;
        newnode->next = initial;
    }
};

Node* PriorityQueue::dequeue(){ // Removes front element of the queue

    if (head == NULL) { // Queue is empty
        return NULL;
    }
    Node* temp = this->head;
    this->head = this->head->next;
    return temp;     
};

Tree::Tree(){

    this->root = NULL;
};

Tree::~Tree(){

    this->deleteTree(root);
};

void Tree::deleteTree(Node* node){ // Deletes nodes of the tree using depth first search algorithm
    
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
    return;
}

Node* Tree::mergeNodes(Node* temp1, Node* temp2){ // Using 2 given nodes creates a new node

   Node* merged = new Node();
   merged->token.symbol = temp1->token.symbol + temp2->token.symbol;
   merged->token.val = temp1->token.val + temp2->token.val;
   return merged;
};

void Tree::printTree(Node* traverse, int level){
    cout << level << "\t";
    for (int i = 0; i < level; i++)
        cout << "\t"; 

    cout << traverse->token.symbol << "(" << traverse->token.val << ")" << endl;

    if(traverse->left)
        printTree(traverse->left, level + 1);  
    if(traverse->right)
        printTree(traverse->right, level + 1);
};