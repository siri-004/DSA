#include<stdio.h>
#define MAX 100

int queue[MAX];
int front=-1, rear =-1;

void enqueue(int val){
    if(rear==MAX-1){
        return;
    }
    if(front==-1){
        front++;
        queue[++rear]=val;
    }
    else{
        queue[++rear]=val;
    }
}
int dequeue(){
    if(front==-1||front>rear){
        return -1;
    }
    return queue[front++];
}
void bfs(int adj[][MAX],int visited[],int start,int n){
    enqueue(start);
    visited[start]=1;
    while(front<=rear){
        int node=dequeue();
        printf("%d ",node);
        for(int i=0;i<n;i++){
            if(adj[node][i]==1&&visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    int n,start;
    int adj[MAX][MAX];
    int visited[MAX]={0};
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d",&start);
    printf("BFS Traversal: ");
    bfs(adj,visited,start,n);
    return 0;
}