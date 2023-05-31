#include<iostream>
using namespace std;

class tree
{
	int a[20][20],l,u,w,i,j,v,e,visited[20];

    public:
		void input();
		void display();
		void minimum();
};

void tree::input()   // Taking inut from the user regarding branches connections
{
	cout<<"Enter the no. of branches: ";    // ask user about no of braches as v = no.of branches
	cin>>v;

	for(i=0;i<v;i++)
	{
		visited[i]=0;                   // put 0 at entry city visited as 0
		for(j=0;j<v;j++)
		{
			a[i][j]=-1;         
		}
	}

	cout<<"\nEnter the no. of connections: ";           // ask user for no of connctions required as e
	cin>>e;

	for(i=0;i<e;i++)                                    // for that much no. of connection
	{
		cout<<"Enter the end branches of connections:  "<<endl;         //ask for two ends point of each connection 
		cin>>l>>u;
		cout<<"Enter the phone company charges for this connection:  ";  // ask for charges of that connection
		cin>>w;
		a[l-1][u-1]=a[u-1][l-1]=w;
	}
}

void tree::display()
{
	cout<<"\nAdjacency matrix:";
	for(i=0;i<v;i++)
	{
		cout<<endl;
		for(j=0;j<v;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void tree::minimum()                // To find minimum cost using prims algo
{
	int p=0,q=0,total=0,min;
	visited[0]=1;                   // Declare & initialize variables 
	for(int count=0;count<(v-1);count++)        //Count Variable declared in for loop itself
	{
		min=999;                                //Initially min = 999
		for(i=0;i<v;i++)
		{
			if(visited[i]==1)                   // If first node is visited
			{
				for(j=0;j<v;j++)
				{
					if(visited[j]!=1)           // second node is not visited
					{
						if(min > a[i][j])       // then compare their wt with min var. & if it less then
						{
							min=a[i][j];        // put that wt in min
							p=i;                // update that min node 
							q=j;
						}
					}
				}
			}
		}
		visited[p]=1;                       // make both p&q as visited node by inserting 1
		visited[q]=1;
		total=total + min;                  // add their min to total cost
		cout<<"Minimum cost connection is"<<(p+1)<<" -> "<<(q+1)<<"  with charge : "<<min<< endl; // print that cost with their nodes
		
	}  // continue the search until all nodes are visited
	cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;  // Print total cost of connection
}

int main()
{
	int ch;
	tree t;
	do
	{
		cout<<"==========PRIM'S ALGORITHM================="<<endl;
		cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
	
	switch(ch)
	{	
	    case 1: cout<<"*******INPUT YOUR VALUES*******"<<endl;	
		t.input();
		break;

	    case 2: cout<<"*******DISPLAY THE CONTENTS********"<<endl;
		t.display();
		break;

	    case 3: cout<<"*********MINIMUM************"<<endl;
		t.minimum();
		break;
	}
	
	}while(ch!=4);
	return 0;
}
