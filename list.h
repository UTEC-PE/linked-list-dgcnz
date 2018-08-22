#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

/*
TODO: add nullptr to tail
TODO: iterators
TODO: fix possible bugs
*/

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List();

        T front(){
            return head->data;
        }
        T back(){
            return tail->data;
        }
        void push_front(T value){
            (this->nodes)++;
            Node* temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
            delete temp;
        }
        void push_back(T value){
            (this->nodes)++;
            tail->next = new Node;
            tail = tail->next;
            tail->data = value;

        }
        void pop_front(){
            (this->nodes)--;
            Node* temp = head;
            head = head.next;
            temp->next = nullptr;
            temp->killSelf();
            delete temp;
        }
        void pop_back(){
            (this->nodes)--;
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = nullptr;
            tail->killSelf();
            delete temp;
        }
        T get(int position){

            if(position>=nodes){
                if(position==0){
                    return head->data;
                }
                else if(position == nodes-1){
                    return tail->data;
                }
                else{
                    Node* temp = head;
                    while(position--){
                        temp = temp->next;
                    }
                    return temp->data;
                }
            }
        }
        void concat(List<T> &other){
            this->tail->next = other->head;
            (this->nodes)+=(other->nodes)
        }
        bool empty(){
            return !(size());
        }
        int size(){
            return(this->nodes);
        }
        void print(){
            Node* temp = head;
            std::cout(head->data)
            while(temp->next){
                std::cout(temp->next->data);
            }
        }
        void print_reverse(){
            Node* temp = head;
            if(temp->next)temp->next->print_reverse();
            cout << this->value;
        }
        void clear(){
            if(head){
                head->killSelf();
            }
            head = NULL;
        }
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){
            if(head){
                head->killSelf();
            }
            head = NULL;
        }
};
#endif
