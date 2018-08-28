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

        void print_reverse(Node<T>* node){
            if(node != nullptr){
                print_reverse(node->next);
                std::cout << node->data << " ";
            }
        }

    public:
        List(){
            this->tail = nullptr;
            this->head = nullptr;
            this->nodes = 0;
        }

        T front(){

            return head->data;
        }
        T back(){
            return tail->data;
        }
        void push_front(T value){
            Node<T>* temp = new Node<T>;
            temp->data = value;
            temp->next = this->head;

            (this->nodes)++;

            //cout << "Pushing " << value << " to front \n";
            if(this->head != nullptr){
                this->head = temp;
            }
            else{
                this->head = this->tail = temp;
                temp = nullptr;
            }
        }
        void push_back(T value){
            Node<T>* temp = new Node<T>;
            temp->data = value;
            temp->next = nullptr;

            (this->nodes)++;

            //cout << "Pushing " << value << " to back \n";

            if(this->head != nullptr){
                this->tail->next = temp;
                this->tail = temp;

            }
            else{
                this->head = temp;
                this->tail = temp;
                temp = nullptr;

            }
        }
        void pop_front(){
            if(this->size()>1){
                //cout << "Popping value in front"<< endl;
                Node<T>* temp = new Node<T>;
                temp = this->head;


                this->head = head->next;

                (this->nodes)--;

                delete temp;


            }
            else if(this->size()==1){
                this->tail=nullptr;
                (this->nodes)--;
                delete this->head;
            }
            else{
                std::cout<<"Empty list, there's nothing to delete."<<'\n';
            }
        }
        void pop_back(){

            if(this->size()>1){

                Node<T>* temp = head;

                while(temp->next != tail){
                    temp = temp->next;
                }

                temp->next = nullptr;

                (this->nodes)--;
                delete tail;
                this->tail = temp;
            }
            else if(this->size()==1){
                this->head=nullptr;
                (this->nodes)--;
                delete this->tail;
            }
            else{
                std::cout<<"Empty list, there's nothing to delete."<<'\n';
            }
        }
        T get(int position){
            try{
                if(position<=nodes){
                    if(position==0){
                        return head->data;
                    }
                    else if(position == nodes-1){
                        return tail->data;
                    }
                    else{
                        Node<T>* temp = head;
                        while(position--){
                            temp = temp->next;
                        }
                        return temp->data;
                    }
                }
                else{
                    throw position;
                }
            } catch(int position){
                std::cout << "Segmentation fault. Tried to access non-existing index.\n";
                std::cout << "Index: "<< position << "Size of list: "<< this->size();
            }
        }
        void concat(List<T> &other){
            if(this->size() || other->size()){
                this->tail->next = other->head;
                this->nodes += other->nodes;
            }
        }
        bool empty(){
            return !(size());
        }
        int size() const{
            return(this->nodes);
        }
        void print(){
            cout << "size: "<<this->size() << " -> ";
            if(this->size()){

                Node<T>* temp = head;

                while(temp){
                    std::cout<<temp->data<<" ";
                    temp=temp->next;
                }
                std::cout<<'\n';
            }
            /*
            else{
                cout<<"List is empty."
            }
            */
        }
        void print_reverse(){
            if(this->size()>0){
                print_reverse(this->head);
            }
            cout << endl;
            /*
            else{
                cout<<"List is empty."
            }
            */
        }
        void clear(){
            if(head){
                head->killSelf();
            }
            head = nullptr;
        }
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){
            if(head){
                head->killSelf();
            }
            head = nullptr;
        }
};
#endif
