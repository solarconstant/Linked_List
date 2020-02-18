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
                    x = x->next;        //Traversing uptil the end
                }
                x->next = new_node;     //Since addition is happening at the end
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

/*SinglyLinkedListNode* rearrange(SinglyLinkedListNode* head) {
	/*code to rearrange nodes*/	
    /*SinglyLinkedListNode *n1 = head, *n2 = n1->next;
    while (n2 && n2->next)
    {
        n1 = n1->next;
        n2 = n2->next->next;
    }
    SinglyLinkedListNode *list1 = head;
    SinglyLinkedListNode *list2 = n1->next;
    n1->next = NULL;
    
    SinglyLinkedListNode *previous = NULL, *current = list2, *next;
    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list2 = previous;
    
    head=new SinglyLinkedListNode(0);
    
    SinglyLinkedListNode *result = head;
    while (list1 || list2)
    {
        if (list1)
        {
            result->next = list1;
            result = result->next;
            list1 = list1->next;
        }
 
        if (list2)
        {
            result->next = list2;
            result = result->next;
            list2 = list2->next;
        }
    }
    
    head = head->next;
    return head;
}*/

SinglyLinkedListNode* rearrange(SinglyLinkedListNode* head) {
	SinglyLinkedListNode *curr = head,*front = head, *back = head;
    while(curr != NULL && curr->next != NULL)       //Since curr = curr->next->next so the previous two nodes cannot be null
    {
        front = back = curr;
        while(front->next != NULL)      //traversing uptill the end to set a pointer to the second last and last node
        {
            back = front;               //second last
            front = front->next;        //last
        }
        back->next = NULL;              //second last now points to null since last has been moved next to the first
        front->next = curr->next;       //last's next points to the next of the first node because it is added between first and second 
        curr ->next = front;            //first's next points to the shifted last(front)
        curr = curr->next->next;        //curr moves two nodes further since the next node is the one shifted from the end
    }       //this repeats until curr or its next become NULL
    return head;
}

int main() {

	/*code to read input and insert node in linked list*/
    int t;
    cin>>t;
    while(t--)
    {
        SinglyLinkedList *LS = new SinglyLinkedList();
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            LS->insert_node(x);
        }
        rearrange(LS->head);
	    print_singly_linked_list(LS->head);
    }
    
	return 0;
}
