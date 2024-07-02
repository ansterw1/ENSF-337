// OLList.cpp
// ENSF 337 Spring 2024 Lab 4 Exercise E and F

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(nullptr)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
	
    if (headM != nullptr) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != nullptr; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == nullptr || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be nullptr/0 or point to node after new node
        while(after != nullptr && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == nullptr || itemA < headM->item)
        return;
    
    Node *doomed_node = nullptr;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != nullptr && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
			
			if(itemA == maybe_doomed->item){
				
				before->next = maybe_doomed->next;
				doomed_node = maybe_doomed;
				break;
				
			}
			
        }

    }
	
	delete doomed_node;
}

void OLList::destroy()
{
	Node* doomed_node = nullptr;
	while( headM != nullptr ) {
		doomed_node = headM;
		headM = doomed_node->next;
		delete doomed_node;
	}
}

void OLList::copy(const OLList& source)
{
    if (this == &source)
        return;

    if (source.headM != nullptr) {
		Node *last_node = nullptr;
        for (const Node *p = source.headM; p != nullptr; p = p->next){
			Node *new_node = new Node;
			new_node->item = p->item;
			new_node->next = nullptr;
			
			if (headM == nullptr || source.headM == p){
				headM = new_node;
				last_node = new_node;
			}
			else{
				last_node->next = new_node;
				last_node = new_node;
			}
			
		}
    }
}


