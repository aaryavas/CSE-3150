#include "ECListNode.h"
#include "ECList.h"

// Linked list 
ECList :: ECList() 
{
    //create linked list
    pHead = nullptr;
    numNodes = 0;

}
  
// insert node with value val after a node
// if node is NULL, insert to the front
void ECList :: Insert(int val, ECListNode *pPre)
{
    ECListNode *newNode =  new ECListNode(val);

    if(pPre == nullptr){
        newNode -> SetNext(pHead);
        pHead = newNode;

    }
    else{
        newNode -> SetNext(pPre)
    }
}

// delete a node
void ECList :: Delete(ECListNode *pNode)
{
    
}

// get a node with value; if multiple nodes with the same value, return the first from head
ECListNode * ECList::GetNode(int val)
{
}

// get the number of nodes in the list
int ECList:: GetSize() const
{
}

