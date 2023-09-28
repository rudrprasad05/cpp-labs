#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>

//9

using namespace std;

struct Student{
   int marks;
   string id;
   char grade;
};

struct NODE {
   NODE *pNext;
   NODE *pPrev;
   // int nData;
   Student studentData;
};

//declare head and tail of list
//originally the list is empty
NODE *pHead=NULL, *pTail=NULL;

void AppendNode(NODE *pNode);
void InsertNode(NODE *pNode, NODE *pAfter);
void RemoveNode(NODE *pNode);
void DeleteAllNodes( );
void discard_line(ifstream &in);
void getGrade(NODE *pNode);

int main( )
{
   NODE * pNode;
   string id;
   int mark;

   //Add items to linked list

   ifstream file;

   file.open("students.txt");

   if (!file) {
		cout << "File not opened!";
      return 0;
	}

   discard_line(file);
   while(!file.eof()){
      file >> id;
      file >> mark;

      pNode = new NODE();
      pNode->studentData.id = id;
      pNode->studentData.marks = mark;

      AppendNode(pNode);
      getGrade(pNode);
   }

   cout << setw(10) << "student id" << setw(5) << "|" << setw(5) << "mark" << setw(5) << "|" << setw(5) << "grade" << endl;
   for(pNode = pHead; pNode != NULL; pNode = pNode->pNext)
      cout << setw(10) << pNode->studentData.id << setw(5) << "|" << setw(5) << pNode->studentData.marks << setw(5) << "|" << setw(5) << pNode->studentData.grade << endl;


}

//function Implementations

void AppendNode(NODE *pNode)
{
   if (pHead == NULL) {     //if list is empty
      pHead = pNode;        //make head point to pNode
      pNode->pPrev = NULL;
   }
   else {
      pTail->pNext = pNode;  //make tail point to pNode
      pNode->pPrev = pTail;
   }
   pTail = pNode;        //tail is now pNode
   pNode->pNext = NULL;  //pNode next now points to NULL
}

// Inserts a node into the list after pAfter
void InsertNode(NODE *pNode, NODE *pAfter)
{
   pNode->pNext = pAfter->pNext; //make next of new node point to "next" node
   pNode->pPrev = pAfter;               //make prev of new node point the "after" node

   if (pAfter->pNext != NULL)       // if we are NOT inserting at the end
      pAfter->pNext->pPrev = pNode;    //make prev of  "next" node point to the new node
   else
      pTail = pNode;                      //if we are inserting at the end, make new node the tail

   pAfter->pNext = pNode;   //make next of  "after" node point to new node
}

// Removes the specified node from the list
void RemoveNode(NODE *pNode)
{
   if (pNode->pPrev == NULL)  //if removing the head
       pHead = pNode->pNext;

   else
      pNode->pPrev->pNext = pNode->pNext;  //if removing a middle node

   if (pNode->pNext == NULL)  //if removing the tail
      pTail = pNode->pPrev;
       
   else
      pNode->pNext->pPrev = pNode->pPrev;

   delete pNode;  //*free the memory
}

//****** Deletes the entire list******
void DeleteAllNodes( )
{
   while (pHead != NULL)   //keep on removing until the 
                           //head points to NULL
      RemoveNode(pHead);
}

void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}

void getGrade(NODE *pNode){
   int mark = pNode->studentData.marks;

   if(mark > 85){
      pNode->studentData.grade = 'A';

   }
   else if (mark > 70)
   {
      pNode->studentData.grade = 'B';
      
   }
   else if (mark >  60)
   {
      pNode->studentData.grade = 'C';

   }
   else if (mark > 50)
   {
      pNode->studentData.grade = 'D';

   }
   else{
      pNode->studentData.grade = 'F';

   }
   
   
   
}








