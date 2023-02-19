#include<iostream>
using namespace std;

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int i);
        void Accept();
        void Display();
};

template <class T>
ArrayX <T> :: ArrayX(int i)
{
    iSize = i;
    Arr = new T[iSize];
}

template <class T>
void ArrayX <T>:: Accept()
{
    cout<<"Enter the elements : "<<"\n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX <T>:: Display()
{
    cout<<"Elements of the array are : "<<"\n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\n";
    }
}

//----------------------------------------stack----------------------------;

template<class T>
struct Snode
{
    T data;
    struct Snode * next;
};

template<class T>
class Stack
{
    public:
        struct Snode<T> * First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T no);
        T Pop();
        void Display();
};

template<class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
bool Stack<T> :: IsStackEmpty()
{
    bool flag = false;

    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template<class T>
void Stack<T> :: Push(T no)
{
    struct Snode<T> * newn = new Snode<T>;
    newn -> data = no;
    newn -> next = NULL;

    if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;

    cout<<no<<" gets pushed in the stack successfully."<<"\n";

}

template<class T>
T Stack<T> :: Pop()
{
    if(First == NULL)
    {
        cout<<"Unable to pop element as Stack is empty,"<<"\n";
        return -1;
    }
    else
    {
        T value = First -> data;
        struct Snode<T> *temp = First;

        First = First -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"stack is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of stack : "<<"\n";

        struct Snode<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}


//--------------------------------- Queue-------------------------------;

template<class T>
struct Qnode
{
    T data;
    struct Qnode * next;
};

template<class T>
class Queue
{
    public:
        struct Qnode<T> * First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void Enqueue(T no);
        T Dequeue();
        void Display();
};

template<class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
bool Queue<T> :: IsQueueEmpty()
{
    bool flag = false;

    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template<class T>
void Queue<T> :: Enqueue(T no)
{
    struct Qnode<T> * newn = new Qnode<T>;
    newn -> data = no;
    newn -> next = NULL;

    if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        struct Qnode<T> * temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;

    }
    iCount++;

    cout<<no<<" gets enqueued in the stack successfully."<<"\n";

}

template<class T>
T Queue<T> :: Dequeue()
{
    if(First == NULL)
    {
        cout<<"Unable to Dequeue element as Stack is empty,"<<"\n";
        return -1;
    }
    else
    {
        T value = First -> data;
        struct Qnode<T> *temp = First;

        First = First -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void Queue<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"queue is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of queue : "<<"\n";

        struct Qnode<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}

//-------------------------------SinglyLL-----------------



template <class T>
struct SLLnode
{
    T Data;
    struct SLLnode *next;
};


template <class T>
class SinglyLL
{
    public:
        struct SLLnode<T> * First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();


};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct SLLnode<T> * newn = new SLLnode<T>;

    newn->Data=no;
    newn->next=NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct SLLnode<T> * newn = new SLLnode<T>;
    newn -> Data = no;
    newn -> next = NULL;

     if(First == NULL)
    {
        First = newn;
    }
    else
    {
       struct SLLnode<T> * temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no , int ipos)
{
    int iNodeCount = Count();

     if((ipos<1) || (ipos>iNodeCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (iNodeCount+1))
    {
        InsertLast(no);
    }
    else
    {
        struct SLLnode<T> * newn = new SLLnode<T>;
        struct SLLnode<T> * temp = First;
        newn -> Data = no;
        newn -> next = NULL;

        for(int iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{

    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        struct SLLnode<T> * temp=First;

        First=First->next;
        delete temp;
    }

}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
     if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct SLLnode<T> * temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCount = Count();

    if((ipos < 1) || (ipos > iNodeCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCount)
    {
        DeleteLast();
    }
    else
    {
        struct SLLnode<T> * temp1 = First;
        struct SLLnode<T> * temp2 = NULL;

        for(int iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete temp2;

    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct SLLnode<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->Data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";

}

template <class T>
int SinglyLL<T> :: Count()
{
    struct SLLnode<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }

    return iCnt;
}


//-----------------------------------DoublyLL---------------------




template<class T>
struct DLLnode
{
    T data;
    struct DLLnode<T> * next;
    struct DLLnode<T> * prev;

};

template<class T>
class DoublyLL
{
    public:
        struct DLLnode<T> * First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();

};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DLLnode<T> * newn = new DLLnode<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First;
        First = newn;
    }
}

template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DLLnode<T> * newn = new DLLnode<T>;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct DLLnode<T> * temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;

    }
}

template<class T>
void DoublyLL<T> :: InsertAtPos(T no , int ipos)
{
    int iCount = Count();

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid input";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct DLLnode<T> * temp = First;
        struct DLLnode<T> * newn = new DLLnode<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> prev = temp;
        temp -> next -> prev = newn;
        temp -> next = newn;
    }
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct DLLnode<T> * temp = First;

        First = temp -> next;
        delete temp;
        First -> prev = NULL;

    }
}

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct DLLnode<T> * temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;

        temp -> next = NULL;
    }
}

template<class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    int iCount = Count();

    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid input";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
         struct DLLnode<T> * temp1 = First;
         struct DLLnode<T> * temp2 = NULL;

         for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
         {
             temp1 = temp1 -> next;
         }

         temp2 = temp1 -> next;
         temp1 -> next = temp2 ->next;
         temp2 -> next -> prev = temp1;

         delete temp2;

    }
}

template<class T>
void DoublyLL<T> :: Display()
{
    struct DLLnode<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<"<=>NULL\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
    int iCnt = 0;
    struct DLLnode<T> * temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}


//--------------------------------------SinglyCL---------------------



template<class T>
struct CLnode
{
    T data;
    struct CLnode *next;
};


template<class T>
class SinglyCL
{
    public:
        struct CLnode<T> * First;
        struct CLnode<T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, T ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T ipos);

        void Display();
        int Count();
};

template<class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct CLnode<T> * newn = new CLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct CLnode<T> * newn = new CLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T> :: Display()
{
    struct CLnode<T> * temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
    struct CLnode<T> * temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
    struct CLnode<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    struct CLnode<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T> :: InsertAtPos(T no, T ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct CLnode<T> * newn = NULL;
    struct CLnode<T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new CLnode<T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyCL<T> :: DeleteAtPos(T ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct CLnode<T> * temp1 = First;
    struct CLnode<T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}



//----------------------------------- DoublyCL-----------------------------


template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    public:
        struct node<T> *First;
        struct node<T> *Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, T ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T ipos);

        void Display();
        int Count();
};


template<class T>
DoublyCL<T> :: DoublyCL()  // Default constructor
{
    First = NULL;
    Last = NULL;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct node<T> *newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct node<T> *newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template<class T>
void DoublyCL<T> :: Display()
{
    struct node<T> *temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct node<T> *temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no, T ipos)
{
    int iNodeCnt = Count();
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(T ipos)
{
    int iNodeCnt = Count();
    struct node<T> *temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}


//------------------------------------------------------------------------------------------------




int main()
{
    printf("Array :\n");
    ArrayX <int>obj1(5);
    obj1.Accept();
    obj1.Display();

//-----------------------------------------------

    printf("\n");
    printf("Stack :\n");

    Stack <int>obj3;

    obj3.Push(11);
    obj3.Push(21);
    obj3.Push(51);
    obj3.Push(101);

    obj3.Display();

    int SiRet = obj3.Pop();
    cout<<"popped element is : "<<SiRet<<"\n";

    SiRet = obj3.Pop();
    cout<<"Poped element is : "<<SiRet<<"\n";

    obj3.Display();

//------------------------------------------------------


    printf("\n");
    printf("Queue :\n");

    Queue <int>obj5;
    obj5.Enqueue(11);
    obj5.Enqueue(21);
    obj5.Enqueue(51);
    obj5.Enqueue(101);

    obj5.Display();

    int QiRet = obj5.Dequeue();
    cout<<"popped element is : "<<QiRet<<"\n";

    QiRet = obj5.Dequeue();
    cout<<"Poped element is : "<<QiRet<<"\n";

    obj5.Display();

//-------------------------------------------------------------------


    printf("\n");
    printf("Singly linked list :\n");

    SinglyLL <int>obj6;

    obj6.InsertFirst(101);
    obj6.InsertFirst(51);
    obj6.InsertFirst(21);
    obj6.InsertFirst(11);

    obj6.InsertLast(201);
    obj6.InsertLast(301);

    obj6.InsertAtPos(250,6);

    obj6.Display();
    int SLLiRet = obj6.Count();

    cout<<"Number of nodes are : "<<SLLiRet<<"\n";

    obj6.DeleteFirst();
    obj6.DeleteLast();
    obj6.DeleteAtPos(3);

    obj6.Display();
    SLLiRet = obj6.Count();

    cout<<"Number of nodes are : "<<SLLiRet<<"\n";

//-------------------------------------------------------------------------

    printf("\n");
    printf("Doubly linked list :\n");

     DoublyLL <int>obj7;

    obj7.InsertFirst(51);
    obj7.InsertFirst(21);
    obj7.InsertFirst(11);

    obj7.InsertLast(101);
    obj7.InsertLast(201);
    obj7.InsertLast(301);

    obj7.Display();

    int DLLiRet = obj7.Count();
    cout<<"the no of elements : "<<DLLiRet<<"\n";

    obj7.InsertAtPos(250,6);
    obj7.InsertAtPos(275,7);
    obj7.Display();

    DLLiRet = obj7.Count();
    cout<<"the no of elements : "<<DLLiRet<<"\n";

    obj7.DeleteFirst();
    obj7.DeleteLast();
    obj7.DeleteAtPos(5);
    obj7.Display();

    DLLiRet = obj7.Count();
    cout<<"the no of elements : "<<DLLiRet<<"\n";

//-------------------------------------------------------------------


 printf("\n");
    printf("singly circular linked list :\n");

    SinglyCL <int>obj8;

    int CLiRet = 0;
    
    obj8.InsertFirst(51);
    obj8.InsertFirst(21);
    obj8.InsertFirst(11);
    
    obj8.InsertLast(101);
    obj8.InsertLast(111);
    obj8.InsertLast(121);

    obj8.InsertAtPos(105,5);

    obj8.Display();
    CLiRet = obj8.Count();

    cout<<"Number of elements are : "<<CLiRet<<"\n";

    obj8.DeleteAtPos(5);


    obj8.Display();
    CLiRet = obj8.Count();

    cout<<"Number of elements are : "<<CLiRet<<"\n";

    obj8.DeleteFirst();
    obj8.DeleteLast();

    obj8.Display();
    CLiRet = obj8.Count();

    cout<<"Number of elements are : "<<CLiRet<<"\n";


//--------------------------------------------------------------------

    printf("\n");
    printf("DOubly Circular Linked list :\n");

    DoublyCL <int>obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";



//---------------------------------------------------------------

    return 0;
}