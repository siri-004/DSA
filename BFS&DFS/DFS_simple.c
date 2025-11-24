#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1,i,j;
int visited[MAX];
void push(int value){
    stack[++top] = value;
}
int pop(){
    if(top==-1)
        return -1;
    return stack[top--];
}
void dfs_stack(int adj[][MAX], int start,int n){
    push(start);
    while(top!=-1){
        int node = pop();
        if(visited[node] == 0){
            printf("%d ", node);
            visited[node] = 1;
            for(i = n - 1; i >= 0; i--){
                if (adj[node][i] == 1 && visited[i] == 0){
                push(i);
                }
            }
        }
    }
}
int main(){
    int n, start;
    int adj[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting node: ");
    scanf("%d",&start);
    for(i=0;i<n;i++){
    visited[i] = 0;
    }
    printf("DFS Traversal: ");
    dfs_stack(adj, start, n);
    return 0;
}