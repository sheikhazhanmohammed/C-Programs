#include<iostream>
using namespace std;
class Node
{
  public:
    int data;
    Node* next;
    Node(int d)
    {
      data=d;
      next=NULL;
    }
};
void InsertAtHead(Node* &head, int d, Node* &tail)
{
  if(head==NULL)
  {
    Node* a= new Node(d);
    a->next=head;
    head=a;
    tail=a;
  }
  else
  {
  Node* a= new Node(d);
  a->next=head;
  head=a;
  }
}
void InsertAtTail(Node* &head, int d, Node* &tail)
{
  if(tail==NULL)
  {
    Node* a = new Node(d);
    tail->next=a;
    tail=a;
    head=a;
  }
  else
  {
    Node* a= new Node(d);
    tail->next=a;
    tail=a;
  }
}
void Printlist(Node* head)
{
  Node* temp=head;
  while(temp)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
main()
{
  Node* head=NULL;
  Node* tail=NULL;
  InsertAtHead(head,5,tail);
  InsertAtHead(head,3,tail);
  InsertAtHead(head,2,tail);
  InsertAtHead(head,6,tail);
  InsertAtTail(head,1,tail);
  InsertAtTail(head,71,tail);
  InsertAtTail(head,41,tail);
  InsertAtTail(head,12,tail);
  Printlist(head);
}
