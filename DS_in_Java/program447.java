// Singly Circular

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created.");
        
        this.first = null;
        this.last = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn =null;

        newn = new node(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }
        this.last.next = this.first;
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn =null;

        newn = new node(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
        }
        this.last.next = this.first;
        this.iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            this.first = this.first.next;
            temp = null;
        }
        this.last.next = this.first;
        System.gc();
        this.iCount--;

    }
    
    public void DeleteLast()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            while (temp.next != this.last)
            {
                temp = temp.next;
            }
            this.last = null;
            this.last = temp;
        }
        this.last.next = this.first;
        System.gc();
        this.iCount--;
    }

    public void Display()
    {
        node temp = this.first;
        
        if(this.first == null)
        {
            return;
        }
        do
        {
            System.out.print("|"+ temp.data+ "|-> ");
            temp = temp.next;
        }while(temp != this.first);

        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        node temp = null;
        int iCnt = 0;
        node newn = null;

        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid input position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
            return;
        }
        else if(pos == iCount + 1)
        {
            this.InsertLast(no);
            return;
        }
        else
        {
            temp = this.first;

            newn = new node(no);

            for(iCnt = 1; iCnt < pos-1 ; iCnt++)
            {
                temp = temp.next;
            }
            
            newn.next = temp.next;
            temp.next = newn;

            this.iCount++;
        }
        
    }
    
    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;
        node target = null;

        if(pos < 1 || pos > iCount )
        {
            System.out.println("Invalid input position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
            return;
        }
        else if(pos == iCount )
        {
            this.DeleteLast();
            return;
        }
        else
        {
            temp = this.first;

            for(iCnt =1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            target = temp.next;

            temp.next = target.next;
            target = null;
            System.gc();
            this.iCount--;
        }
        
    }
    
}

class program447
{
    public static void main(String A[])
    {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,3);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(3);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}