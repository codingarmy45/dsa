#include<iostream>
using namespace std;
class node
{
    int vertex;
    node*link;
public:
    node()
    {
         vertex=0;
         link=NULL;
    }
    node(int vertex)
    {
        this->vertex=vertex;
        link=NULL;
    }
    friend class graph;
    friend class queue;
};
class queue
{
    node*front,*rear;
public:
    queue()
    {
         front=NULL;
         rear=NULL;
    }
    int Front()
    {
        if(isempty())
         {
            return -1;
         }
        return front->vertex;
    }
    bool isempty()
    {
        return (front==NULL);
    }
    void push(int element)
    {   node*newnode=new node(element);
        if(front==NULL)
        {
           front=newnode;
           rear=newnode;
        }
        else
        {
            rear->link=newnode;
            rear=rear->link;
        }
    }
    void pop()
    {
        if(isempty())
        {   cout<<"Queue is empty";
            return;
        }
        else
        {
            if(front->link==NULL)
            {
                delete front;
                front=NULL;
                rear=NULL;
            }
            else
            {
                node*temp=front->link;
                front->link=NULL;
                delete front;
                front=temp;
            }
        }

    }

};

class graph
{    node*head[100];
     bool visited[100];
     int vertices,edges;
public:
     void creategraph()
     { 
        cout<<"Enter no of vertices:"<<endl;
        cin>>vertices;
        for(int i=1;i<=vertices;i++)
        {
            head[i]=NULL;
            visited[i]=false;
        }
        cout<<"Enter the no of Edges:"<<endl;
        cin>>edges;
        while(edges--)
        {
            int startvertex,endvertex;
            cout<<"Enter the vertices in which u want edge(startvertex,Endvertex):"<<endl;
            cin>>startvertex>>endvertex;
            insertedge(startvertex,endvertex);
            insertedge(endvertex,startvertex);

        }   
     }
     void insertedge(int startvertex,int endvertex)
     {
          node*newnode=new node(endvertex);
          if(head[startvertex]==NULL)
          {
              head[startvertex]=newnode;
          }
          else
          {
              node*temp=head[startvertex];
               
                while(temp->link!=NULL)
                {
                    temp=temp->link;
                }
                 temp->link=newnode;  
          }
     }
    void display()
    { for(int i=1;i<=vertices;i++)
      {  cout<<i<<"->";
         node*temp=head[i];
         while(temp!=NULL)
         {
            cout<<temp->vertex;
            if(temp->link!=NULL)
            {
                cout<<",";
            }
            temp=temp->link;
         }
         cout<<endl;
      }
      cout<<endl;
    }
    void bfs()
    {    int vertex;
         cout<<"Enter the starting vertex of bfs:"<<endl;
         cin>>vertex;
         bfs(vertex);
         for(int i=1;i<=vertices;i++)
         {
            visited[i]=false;
         }
         cout<<endl;
    }
    void dfs()
    {    int vertex;
         cout<<"Enter the starting vertex of bfs:"<<endl;
         cin>>vertex;
         dfs(vertex);
         for(int i=1;i<=vertices;i++)
         {
            visited[i]=false;
         }
         cout<<endl;
    }
    void dfs(int vertex)
    {
        cout<<vertex<<"->";
        visited[vertex]=true;
        node*temp=head[vertex];
        while(temp!=NULL)
        {  vertex=temp->vertex;
            if(!visited[vertex])
            {
                dfs(vertex);
            }
           temp=temp->link;
        }
    }
    void bfs(int vertex)
    {
        queue q;
        q.push(vertex);
        visited[vertex]=true;
        while(!q.isempty())
       { int current=q.Front();
         cout<<current<<"->";
         q.pop();
         node*temp=head[current];
         while(temp!=NULL)
         {
            current=temp->vertex;
            if(!visited[current])
            {
                q.push(current);
                visited[current]=true;
            }
            temp=temp->link;
         }
         
       }
    }

};
int main()
{
    graph obj;
    int option;
    do
    {
        cout << "-------------------Menu-------------------" << endl;
        cout << "1. Create a Graph" << endl;
        cout << "2. Display the Graph" << endl;
        cout << "3. Depth First Traversal (DFS) of the Graph" << endl;
        cout << "4. Breadth First Traversal (BFS) of the Graph" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter the option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            obj.creategraph();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.dfs();
            break;
        case 4:
            obj.bfs();
            break;
        case 5:
            exit(0);
        }
        cout << endl;
    } while (option >= 1 && option <= 4);
    return 0;
}
