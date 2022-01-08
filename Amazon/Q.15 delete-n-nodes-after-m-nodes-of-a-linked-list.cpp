// Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

// Input:
// First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the linked list and next M and N respectively space separated. The last line contains the elements of the linked list.

// Output:
// Function should not print any output to stdin/console.

// User Task:
// The task is to complete the function linkdelete() which should modify the linked list as required.

// Example:
// Input:
// 2
// 8
// 2 1
// 9 1 3 5 9 4 10 1
// 6
// 6 1
// 1 2 3 4 5 6

// Output: 
// 9 1 5 9 10 1
// 1 2 3 4 5 6

// Explanation:
// Testcase 1: Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.

// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

 // } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        Node* temp=head;
        int m=1, n=1;
        
        
        while(temp!=NULL){
            if(m==M){
              while(n<=N) {
                  if(temp->next==NULL){
                      return;
                  }
                // while(temp!=NULL){
                    temp->next=temp->next->next;
                    n++;
                // }
                //   temp->next=temp->next->next;
                //   n++;
              }
              m=0;
              n=1;
            }
            m++;
            temp=temp->next;
        }
        
    }
};



// { Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
  // } Driver Code Ends