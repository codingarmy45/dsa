#include<iostream>
#define max 20
using namespace std;

class stud
{
    int mks[max];                   // array of marks
    public:
    stud()                         // constructor
    {
        for(int i=0;i<max;i++)     // mks
        {
            mks[i]=0;
        }
    }

    void insertheap(int tot);       // To insert element into heap
    void displayheap(int tot);      // To display data from heap
    void showmax(int tot);          // To show max heap
    void showmin();                 // To show min heap
};

void  stud::insertheap(int tot)
{
    for(int i=1;i<=tot;i++)
    {
        cout<<"enter marks: ";
        cin>>mks[i];
        int j=i;
        int par=j/2;
        while(mks[j]<=mks[par] && j!=0)
        {
            int tmp = mks[j];
            mks[j]=mks[par];
            mks[par]=tmp;
            j=par;
            par=j/2;
        }       
    }
}

void stud::displayheap(int tot)
{
    int i=1,space=6;
    cout<<endl;
    while(i<=tot)
    {
        if(i==1 || i==2 || i==4 || i==8 || i==16)
        {
            cout<<endl<<endl;
            for(int j=0;j<space;j++)
            cout<<" ";
            space-=2;   
        }
        cout<<" "<<mks[i];
        i++;
    }
}

void stud::showmax(int tot)
{
    int max1=mks[1];            // start from 1st entry copy in max1
    for(int i=2;i<=tot;i++)
    {
        if(max1<mks[i])        // compare with all next elements if max value found then update max1
        max1= mks[i];
    }
    cout<<"Max marks: "<<max1;     // after search finishes print max1
}

void stud::showmin()
{
    cout<<"Min marks: "<<mks[1];  // as this is min heap so min element will be top(root) | first element from array
}

int main()
{
    int ch,cont,total,tmp;
    int n;
    stud s1;
    do
    {
        cout<<endl<<"Menu";
        cout<<endl<<"1.Read marks of the student ";
        cout<<endl<<"2.Display  Min heap";
        cout<<endl<<"3.Find Max Marks";
        cout<<endl<<"4.Find Min Marks";
        cout<<endl<<"Enter Choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            cout<<"how many students: ";
            cin>>total;
            s1.insertheap(total);           // call insert function to insert elements
            break;
            
            case 2:
            s1.displayheap(total);          // call display function
            break;

            case 3:    
            s1.showmax(total);              // To find max element
            break;
            
            case 4:
            s1.showmin();                   // To find min element
            break;
        }
        cout<<endl<<"do u want to continue?(1 for continue)";
        cin>>cont;
    }while(cont==1);
return 0;
}
