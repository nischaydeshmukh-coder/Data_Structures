#include<iostream>
using namespace std;

template<class T>
struct SinglyLLLnode 
{
    T data;
    struct SinglyLLLnode<T> * next;
};

template<class T>
class SinglyLL
{
    private:        //IMPORTANT
        struct SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor of SinglyLL\n";

    this->first = NULL;
    this->iCount = 0;
}
template <class T>
void SinglyLL<T>::InsertFirst(T no)           //Updated..
{
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn;
          
    this->iCount++;   
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct SinglyLLLnode<T> *  newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->iCount == 0)                 //Updated...
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
            temp->next = newn;
                
    }
            this->iCount++;             
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL) 
    {
        return;
    }
    else if(this->first->next == NULL)             // (this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }
        this->iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct SinglyLLLnode<T> * temp = NULL;
            
    if(this->first == NULL) 
    {
        return;
    }
    else if(this->first->next == NULL)             // (this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

       delete temp->next;
       temp->next = NULL;

    }

       this->iCount--;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;
            
    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)        //Updated..
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>:: Count()
{

        return this->iCount;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    temp = this->first;

    for(iCnt = 1; iCnt < pos-1; iCnt++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;

    this->iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
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
        delete target;
        this->iCount--;
    
    }
}

int main()
{
    SinglyLL<int> obj;
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
