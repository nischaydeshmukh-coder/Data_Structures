#include<iostream>
using namespace std;

template <class T>
struct DoublyLLLnode 
{
    T data;
    struct DoublyLLLnode<T> * next;
    struct DoublyLLLnode<T> * prev;
};

template <class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};
        
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;

}

template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;    
    }
    this->iCount++;
}

template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    struct DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = first->next;
        delete temp;
        this->first->prev = NULL;
    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    struct DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        
    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T>::Display()
{
    struct DoublyLLLnode<T> * temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template <class T>
int DoublyLLL<T>::Count()
{

    return this->iCount;
}

template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        temp->next->prev = temp;
        delete target;

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new struct DoublyLLLnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
        temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }

}

int main()
{
    DoublyLLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    obj.InsertAtPos(105, 4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    
    return 0;
}
