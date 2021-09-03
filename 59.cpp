#include <iostream>
using namespace std;

class node
{

public:
  int data;
  node *next;

  node(int val)
  {
    data = val;
    next = NULL;
  }
};

void addatTail(node *&head, int val)
{
  node *n = new node(val);
  if (head == NULL)
  {
    head = n;
    return;
  }
  node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = n;
}
void addatHead(node *&head, int val)
{
  node *n = new node(val);
  if (head == NULL)
  {
    head = n;
    return;
  }
  n->next = head;
  head = n;
}
void display(node *head)
{
  node *temp = head;
  if (head == NULL)
  {
    cout << "Empty LL " << endl;
    return;
  }
  while (temp != NULL)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
}

node *reverseLl(node *&head)
{
  if (head == NULL)
    return head;
  node *prevptr = NULL;
  node *currptr = head;
  node *nextptr ;
  while (currptr != NULL)
  {
    nextptr = currptr->next;

    currptr->next = prevptr;
    prevptr = currptr;
    currptr = nextptr;
  }
  return prevptr;
}
node* recur_reverseLl(node *&head)
{
  //base case
  if(head == NULL or head->next == NULL)
  return head;

  node*newhead = recur_reverseLl(head->next);
  head->next->next = head;
  head->next=NULL;

  return newhead;
}
int main()
{
  node *head = NULL;
  addatTail(head, 1);
  addatTail(head, 2);
  addatTail(head, 3);
  display(head);
  // node *newhead = reverseLl(head);
  cout << endl;
  // display(newhead);
  cout << endl;
  node *newhead = recur_reverseLl(head);
  cout << endl;
  display(newhead);
  cout << endl;
  return 0;
}
