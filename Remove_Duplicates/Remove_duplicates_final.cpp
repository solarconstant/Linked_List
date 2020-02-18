#include<iostream>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = NULL;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = NULL;
            this->tail = NULL;
        }

        void insert_node(int node_data) {
            /*code to insert new node at the end in linked list having node_data*/
            SinglyLinkedListNode* new_node = new SinglyLinkedListNode(node_data);
            
            new_node->next = NULL;
            if(head == NULL)
            {
                head = new_node;
            }
            else
            {
                SinglyLinkedListNode* x = head;
                while(x->next)
                {
                    x = x->next;
                }
                x->next = new_node;
            }

		}      
};

void print_singly_linked_list(SinglyLinkedListNode* node) {
            /*code to print linked list separated by single space*/
            while(node != NULL)
            {
                cout<<node->data<<" ";
                node = node->next;
            }
            cout<<endl;
        }

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
	/*code to remove duplicates*/	
    SinglyLinkedListNode* x = head;
    SinglyLinkedListNode* y = head->next;
    while(y != NULL)            //x and y act as walker variables
    {
        if(x->data == y->data)
        {
            x->next = y->next;      //skip the node that has duplicate data
            delete y;               //Delete its instance from memory
            y = x->next;            //Move the y pointer further
        }
        else
        {
            x = x->next;
            y = y->next;
        }
    }
    x->next = NULL;
    return head;
}

int main() {
	
	/*code to read input and insert node in linked list*/
	//LS = removeDuplicates(LS->head);
    int t;
    cin>>t; 
    while(t--)
    {
        SinglyLinkedList *LS = new SinglyLinkedList();
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            int data;
            cin>>data;  
            LS->insert_node(data); 
        }
        LS->head = removeDuplicates(LS->head);
        print_singly_linked_list(LS->head);
    }
    
	return 0;
}
