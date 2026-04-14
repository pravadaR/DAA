#include<iostream>    //allows cin cout 
#include<climits>     //give access to INT_MAX (the largest possible int value, used as "infinity")
using namespace std;  //for not writing std::cout, std::cin every time

#define MAX 100  //sets a constant MAX=100, meaning our graph can have at most 100 vertices
#define INF INT_MAX //INF is just a shorthand for "infinity"

int graph[MAX][MAX];  //a 2D array representing the graph 
int dist[MAX];        //stores the shortest known distance from source to every vertex
bool visited[MAX];    //tracks whether a vertex has been permanently finalized (true or false)
int V, E;             //number of vertices and edges entered by the user

void dijkstra(int src)  //declares a function called dijkstra that takes the source vertex as input
{                       // FIX 1: added missing {
    for(int i=0; i<V; i++)
    {
        dist[i]=INF;       //we don't know any distance yet, so assume all are infinity
        visited[i]=false;  //no vertex has been visited yet 
    }
    dist[src]=0;   // FIX 2: moved inside function — distance from source to itself is always 0

    for(int count=0; count<V-1; count++)
    {
        int u=-1;    //start with no vertex selected
        for(int i=0; i<V; i++) //loop through all vertices to find the unvisited one with the smallest distance
        {
            if(!visited[i] && (u==-1 || dist[i]<dist[u]))  //only consider unvisited vertices 
            //if no vertex picked yet, pick this one or if this vertex has a shortest distance pick it instead
            //after the loop, u holds the closest unvisited vertex
                u=i;
        }

        if(dist[u]==INF) break;  //if closest vertex is still INF, rest are unreachable

        visited[u]=true;  //mark as visited — shortest path to u is finalized

        for(int v=0; v<V; v++)
        {
            if(!visited[v] && graph[u][v] != 0)  //only consider unvisited neighbors with an edge
            {
                int newDist=dist[u] + graph[u][v];  //calculate new distance through u
                if(newDist<dist[v])                  //if new path is shorter, update it
                    dist[v]=newDist;                 
            }
        }
    }
}           

int main()
{
    cout<<"Enter number of vertices: ";
    cin>>V;

    cout<<"Enter number of edges: ";
    cin>>E;
  //start of the program
  //ask the user to input how vertices(V) and edges(E) the graph has

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)  
            graph[i][j]=0;  //fill the entire graph matrix with 0
    
  cout<<"Enter edges (u v weight) - vertices are 0-indexed:\n"; 
    for(int i=0; i<E; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;   //ask user to enter each edge as u v weight
        graph[u][v]=w;  //store weight in both directions
        graph[v][u]=w;  //because graph is undirected(you can travel both ways)
    }

    int src;
    cout<<"Enter source vertex: ";
    cin>>src; //ask user which vertex to start from 

    dijkstra(src);  //call dijkstra with the source vertex

    cout<<"\nShortest distances from vertex "<<src<<":\n";
    for(int i=0; i<V; i++)      //loop through all vertices and print the shortest distance from source to each one 
    {
        cout<<"  To vertex "<<i<<": ";
        if(dist[i]==INF)          //if dist[i] is still INF, that vertex was never reachable, so print unreachable
            cout<<"unreachable\n";  
        else
            cout<<dist[i]<<"\n";   //otherwise print the actual shortes distance
    }

    return 0;  //tell th OS the program finished successfully 
} //closes the main function 
