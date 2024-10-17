#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class Datatype>
class Node{
public:
    Datatype data; // khoi tao 1 data
    Node* next; // khoi tao 1 mui ten
public:
    Node(Datatype _data){ // tao cau truc nhap xuat
        data = _data; 
        next = nullptr;
    }
    void Display(){
        cout << data << " "; // xuat data ra man hinh
    }
};
 
template <class Datatype>
class LinkListed{
public:
    typedef Node<Datatype>* NodePtr; // thay doi mac dinh node* thanh nodePtr
    NodePtr Head; // khoi tao node dau
    NodePtr Tail; // khoi tao node duoi
    int Size; // khoi tao bo dem
public:
    //Constructor
    LinkListed() : Head(nullptr), Tail(nullptr), Size(0){}
    // function()
    void AddHead(Datatype Data){
        NodePtr Add = new Node<Datatype>(Data);
        if(Head == nullptr){
            Head = Add;
            Tail = Add;
        }
        else {
            Add->next = Head;
            Head = Add;
        }
        Size++;
    }
    void AddTail(Datatype Data){
        NodePtr Add = new Node<Datatype>(Data);
        if(Head == nullptr){
            Head = Add;
            Tail = Add;
        }
        else {
            Tail->next = Add;
            Tail = Add;
        }
        Size++;
    }
    void AddMid(Datatype Data, NodePtr current){
        NodePtr Add = new Node<Datatype>(Data);
        NodePtr find = Head;
        if (Head == nullptr){
            AddHead(Data);
            return;
        }
        while (find != nullptr){
            if(current == find){
                NodePtr nextNode = current->next;
                Add->next = nextNode;
                current->next = Add;
                return;
            }
            find = find->next;
        }
        Size++;
    }
    NodePtr search(Datatype Data){
        NodePtr walker = Head;
        while (walker != nullptr && walker->data != Data){
            walker = walker->next;
        }
        return walker;
    }
    NodePtr searchPre(NodePtr node){
        NodePtr walker = Head;
        if (walker == node){
            return nullptr;
        }
        while (walker != nullptr && walker->next != node){
            walker = walker->next;
        }
        
        return walker;
    }
    void DeleteFirst(){
        if(Head == nullptr){
            return;
        }
        NodePtr temp = Head;
        Head = Head->next;
        delete temp;
        Size--;
    }
    void DeleteLast(){
        if(Head == nullptr){
            return;
        }
        if(Head == Tail){
            delete Head;
            Head = nullptr;
            Tail = nullptr;
            Size--;
            return;
        }
        NodePtr areaLast = searchPre(Tail);
        areaLast->next = nullptr;
        delete Tail;
        Tail = areaLast;
        Size--;
    }
    
    void DeleteMidAfterNode(NodePtr node){
        if(node != nullptr){
            NodePtr temp = node->next;
            if(temp != nullptr){
                if(temp == Tail){
                    Tail = node;
                }
                NodePtr aftertemp = temp->next;
                delete temp;
                node->next = aftertemp;
                Size--;
            }
        }
        else{
            DeleteFirst();
        }
    }
    void DeleteSearch(Datatype Data){
        NodePtr node = search(Data);
        if (node == nullptr){
           return;
        }
        if (node == Head){
            DeleteFirst();
            return;
        }
        if (node == Tail){
            DeleteLast();
            return;
        }
        NodePtr prenode = searchPre(node);
        NodePtr afternode = node->next;
        prenode->next = afternode;
        delete node;
        Size--;
    }
    void SelectionSort(){
        NodePtr pmin;
        NodePtr p, q;
        for(p = Head; p != nullptr; p = p->next){
            pmin = p;
            for(q = p; q != nullptr; q = q->next){
                if(q->data < pmin->data){
                    pmin = q;
                }
            } 
            swap(pmin->data, p->data);
        }
    }
    void DeleteAll(){
        while(Head != nullptr){
            DeleteFirst();
        }
        Size = 0;
    }
    void DisplayLinkedListed(){
        NodePtr current = Head;
        while (current != nullptr){
            current->Display();
            current = current->next;
        }
    }
    void DeleteNode(NodePtr node){
        if(node == Head){
            DeleteFirst();
            return;
        }
        if(node == Tail){
            DeleteLast();
            return;
        }
        NodePtr temp = node;
        NodePtr beforenode = searchPre(node);
        delete temp;
        node = node->next;
        beforenode->next = node;
        Size--;
    }
    void Timphantuvipham(){
        NodePtr p, q;
        for(p = Head; p != nullptr; p = p->next){
            for(q = p->next; q != nullptr; q = q->next){
                if(q->data < p->data){
                    DeleteNode(search(q->data));
                }
            }
        }
        
    }
    
};

int main(){
    LinkListed<char> Lmao;
    char word;
    while(cin >> word){
        Lmao.AddTail(word);
    }
    Lmao.Timphantuvipham();
    Lmao.DisplayLinkedListed(); 
}

