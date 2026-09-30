#include<iostream>

using namespace std;

struct node
  {
    int data;
    // node* prev;
    node* next;
    node(int val){
      data=val;
      // prev=nullptr;
      next=nullptr;
    }
  };

void traverse_linked_list(node* head);
node* reverse_linked_list(node* head);
node* find_1st_middle(node* head);
node* find_2nd_middle(node* head);
bool hasCycle(node* head);
node* startOfCycle(node* head);
node* merge2SortedList(node* head1, node* head2);
node* removeNthElementFromEnd(node* head, int n);
void free_up(node* head);

int main(){
  node* head = new node(10);
  node* second = new node(20);
  node* third = new node(30);
  node* fourth = new node(40);

  head->next=second;
  second->next=third;
  third->next=fourth;
  // second->prev=head;
  // third->prev=second;

  traverse_linked_list(head);
  node* middle = find_1st_middle(head);
  cout<<"Middle: "<<middle->data<<endl;
  middle = find_2nd_middle(head);
  cout<<"Middle: "<<middle->data<<endl;
  cout<<"List has cycle: "<<hasCycle(head)<<endl;
  head = reverse_linked_list(head);
  traverse_linked_list(head);

  free_up(head);

  return 0;
}

void traverse_linked_list(node* head){
  node* current = head;
  while (current!=nullptr)
  {
    cout<<current->data<<" ";
    current=current->next;
  }
  cout<<endl;
  return;
}

node* reverse_linked_list(node* head){
  node* current = head;
  node* prev=nullptr;
  node* tmp=nullptr;
  while (current!=nullptr)
  {
    tmp=current->next;
    current->next=prev;
    prev=current;
    current=tmp;
  }
  return prev;
}

// get 1st middle in even list
node* find_1st_middle(node* head){
  node* fast=head;
  node* slow=head;
  while (fast!=nullptr && fast->next->next!=nullptr)
  {
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}

// get 2nd middle in even list
node* find_2nd_middle(node* head){
  node* fast=head;
  node* slow=head;
  while (fast!=nullptr && fast->next!=nullptr)
  {
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}

bool hasCycle(node* head){
  node* fast=head;
  node* slow=head;
  while (fast!=nullptr && fast->next!=nullptr)
  {
    fast=fast->next->next;
    slow=slow->next;
    if (fast==slow)
    {
      return true;
    }
  }
  return false;
}

node* startOfCycle(node* head){
  node* fast = head;
  node* slow = head;
  while (fast!=nullptr && fast->next!=nullptr)
  {
    fast=fast->next->next;
    slow=slow->next;
    if (fast==slow)
    {
      slow=head;
      while (slow!=fast)
      {
        slow=slow->next;
        fast=fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

node* merge2SortedList(node* head1, node* head2){
  node dummy(0);
  node* tail=&dummy;
  while (head1!=nullptr && head2!=nullptr)
  {
    if (head1->data<=head2->data)
    {
      tail->next=head1;
      head1=head1->next;
    }else{
      tail->next=head2;
      head2=head2->next;
    }
    tail=tail->next;
  }
  if (head1!=nullptr)
  {
    tail->next=head1;
  }else
  {
    tail->next=head2;
  }
  return dummy.next;
}

// Remove Nth Node From the End
node* removeNthElementFromEnd(node* head, int n){
  node dummy(0);
  dummy.next=head;
  node* fast=&dummy;
  node* slow=&dummy;
  for (int16_t i = 0; i < n; i++)
  {
    fast=fast->next;
  }
  while (fast->next!=nullptr)
  {
    fast=fast->next;
    slow=slow->next;
  }
  slow->next=slow->next->next;
  return dummy.next;
}

void free_up(node* head){
  node* current = head;
  node* tmp=nullptr;
  while (current!=nullptr)
  {
    tmp=current->next;
    delete current;
    current=tmp;
  }
  return;
}
