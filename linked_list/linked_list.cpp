#include<bits/stdc++.h>
using namespace std;
//created by Abdullah Al Fahim

int sz;

class Node
{
public:
    int val= 0;
    Node * nxt;
    Node * prev;

    Node(int val)
    {
        this->val =val;
        this->nxt = NULL;
        // this->prev = NULL;
    }
};

void input(Node * &head, Node * &tail, int val)   
{

    Node *temp = new Node(val);
    

    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->nxt = temp;
        tail = temp;
    }
}

void output(Node * head)
{
    cout<<endl <<"Current linked list : "<<endl;
    Node * tmp = head;

    int i = 0;
    while(tmp != NULL)
    {
        // cout <<++i<<" -> "<< tmp->val<<endl;
        cout <<tmp->val<<" ";
        tmp = tmp->nxt;
    }
    cout << endl;

}

void del(Node * &head, int pos)
{
    if(pos == 1)
    {
        Node * tmp = head;
        head = head->nxt;
        delete(tmp);
        return;
    }

    pos--;
    Node * parent = head;

    while(--pos and parent!= NULL)
    {
        parent = parent->nxt;
    }

    // cout << parent->val<<endl;

    parent->nxt = parent->nxt->nxt;
}

void insert(Node * &head, int pos, int val)
{
    Node *temp = new Node(val);

    if(pos == 1)
    {
        temp->nxt = head;
        head = temp;
        return;
    }

    pos--;
    Node * parent = head;

    while(--pos and parent!= NULL)
    {
        parent = parent->nxt;
    }

    // cout << parent->val<<endl;

    temp->nxt = parent->nxt;
    parent->nxt = temp;
}

void srch(Node * head, int pos)
{
    Node * parent = head;

    while(--pos and parent!= NULL)
    {
        parent = parent->nxt;
    }

    cout << "Found : " << parent->val<<endl;
}
void srchVal(Node * head, int val)
{

    Node * parent = head;
    int i = 0;

    while(parent!= NULL)
    {
        i++;
        if(parent->val == val)
        {
            cout << val<<" found at position "<<i<<endl;
            return;
        }
        parent = parent->nxt;
    }

    cout << "Not found"<<endl;
}

int main()
{

    char ch;
    cout <<"Do you want to create a linked list? (y/n) ";
    cin >> ch;

        Node * head;
        Node * tail;
        head = tail = NULL;

    if(ch == 'y')
    {
        int n; 
        cout <<"Enter the size of the linked list: ";
        cin >> n;
    
        int tmp;
        for (int i =0; i<n; i++)
        {
            cout << "Enter value "<<i+1<<" : ";
            cin>> tmp;
            input(head, tail, tmp);
        }

        sz = n;

        output(head);
    }
    else 
    {
        return 0;
    }

    

    int op;
    while(1)
    {
        cout << endl;
        cout <<"\033[32m";
        cout <<"Enter the option number:(operations on linked list)"<<endl;
        cout << "1. INSERT"<<endl;
        cout << "2. DELETE"<<endl;
        cout << "3. DISPLAY"<<endl;
        cout <<"4. SEARCH BY INDEX"<<endl;
        cout <<"5. SEARCH BY VALUE"<<endl;
        cout <<"6. SIZE"<<endl;
        cout << "7. EXIT"<<endl;
        cout << "\033[0m";

        cin >> op;

        if(op == 1) // insert
        {
            int pos, val;
            cout << "Enter position of insertion: "; 
            cin >> pos;

            if(pos > sz+1) 
            {
                cout <<"Segmentation fault"<<endl;
                continue;
            }

            cout <<"Enter a value: ";
            cin >> val;

            insert(head, pos, val);
            sz++;
            output(head);

        }
        else if(op==2) // delete
        {
            int pos;
            cout << "Enter position of deletion: ";
            cin >> pos;

            del(head, pos);
            sz--;
            output(head);
            
        }
        else if(op == 3) // display
        {
            cout << endl;
            output(head);
        }
        else if(op == 4) // search by index
        {
            int pos;
            cout <<"Enter the index number: "<<endl;
            cin >> pos;

            if(pos > sz) cout <<"Segmentation fault"<<endl;
            else srch(head,pos);

        }
        else if(op == 5) // search by value
        {
            int val;
            cout <<"Enter the value to search: "<<endl;
            cin >> val;
            
            srchVal(head,val);
        }
        else if(op == 6) // size
        {
            cout <<"Linked list size = " <<sz<<endl;
        }
        else if(op == 7) // exit
        {
            break;
        }
        else {cout <<"Wrong option"<<endl; break;}

    }
}