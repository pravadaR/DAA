#include<iostream>    //allows cin cout 
#include<climits>     //give access to INT_MAX (the largest possible int value, used as "infinity")
using namespace std;  //for not writing std::cout, std::cin every time

#define MAX 100  //sets a constant MAX=100, meaning our graph can have at most 100 vertices
#define INF INT_MAX //INF is just a shorthand for "infinity"

int graph[MAX][MAX];  //a 2D array representing the graph 
int dist[MAX];        //stores the shortest known distance from source to every vertex
bool visited[MAX];    //tracks whether a vertex has been permanently finalized (true or false)
int V, E;              //number of vertices and edges entered by the user

void dijkstra(int src)  //declares a function called dijkstra that takes the source vertex as input
{
  for(int i=0;i<V; i++)
    {
        dist[i]=INF;  //we don't know any distance yet, so assume all are infinity
        visited[i]=false;  //no vertex has been visited yet 
    }
dist[src]=0;   //distance from source to itself is always 0
  for(int count=0; count<V-1;count++)
int U =-1;    //start with no vertex selected
for(int i=0; i<V;i++) //loop through all vertices to find the unvisited one with the smallest distance
{
  if(!visited[i] && (U==-1 || dist[i]<dist[U]))  //only consider unvisited vertices 
//if no vertex pickes yet , pick this one or if this vertex has a shortest distance pick it instead
//after the loop, U holds the closest unvisited vertex
