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
bool search(node *head, int key)
{
  if (head == NULL)
  {
    return false;
  }
  node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == key)
      return true;
    temp = temp->next;
  }
  return false;
}
void deleteSt(node *&head){
  if(head == NULL)
  return ;
  node*temp = head;
  head=head->next;
  delete temp;
}

// void deletenode(node*&head, int val)
// {
//   if(head == NULL)
//   return;
//   node*temp = head;
//   node*p;
//   if(head->next==NULL)
//   {
//     deleteSt(temp);return;
//   }
//   while(temp->next->data != val)
//   {
//     temp = temp->next;
//   }
//   p=temp->next;
//   temp->next = p->next;
//   p->next = NULL;
//   delete p;

// }

// borh are equal mng 
void deletenode(node*&head, int val)
{
  if(head == NULL)
  return;
  node*temp = head;
  node*p;
  if(head->next==NULL)
  {
    deleteSt(temp);return;
  }
  while(temp->next->data != val and temp->next!=NULL )
  {
    temp = temp->next;
  }
  p=temp->next;
  temp->next = p->next;
  p->next = NULL;
  delete p;

}

int main()
{
  node *head = NULL;
  addatTail(head, 1);
  addatTail(head, 2);
  addatTail(head, 3);
  addatHead(head, 4);
  display(head);
  cout << endl;
  cout << search(head, 3);
  deletenode(head,2);
  cout << endl;
  display(head);
  deleteSt(head);
  cout << endl;
  display(head);
  return 0;
}
