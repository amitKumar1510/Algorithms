
#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,parent[9];
int cost[9][9];
//int cost[9][9] = {
//        {999, 2, 999, 999, 999, 999, 999, 999, 1},
//        {2, 999, 3, 999, 999, 999, 999, 999, 999},
//        {999, 3, 999, 4, 999, 999, 999, 999, 999},
//        {999, 999, 4, 999, 5, 999, 999, 999, 999},
//        {999, 999, 999, 5, 999, 6, 999, 999, 999},
//        {999, 999, 999, 999, 6, 999, 7, 999, 999},
//        {999, 999, 999, 999, 999, 7, 999, 8, 999},
//        {999, 999, 999, 999, 999, 999, 8, 999, 9},
//        {1, 999, 999, 999, 999, 999, 999, 9, 999}
//    };
int find(int);
int uni(int, int);
void costAdjMatrix(int);
void printEdges();

int main(){
	printf("kruskal algorithm to find minimum cost spannin tree :");
	printf("\n Enter the number of vertices: \n");
	scanf("%d",&n);
	costAdjMatrix(n);
	printEdges();
	printf("\n minimum cost = %d",mincost);
	return 0;
}
void costAdjMatrix(int n){
	printf("Enter the cost adjancency matrix:\n");
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=999;
			}
		}
	}
}
void printEdges(){
	printf("The edges of minimum cost spanning tree are \n");
	while(ne<n){
		for(i=0,min=999;i<n;i++){
			for(j=0;j<n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
	u=find(u);
	v=find(v);
	if(uni(u,v)){
		printf("%d edge (%d %d) = %d\n",ne++,a,b,min);
		mincost = mincost+min;
	}
	cost[a][b]=cost[b][a]=999;	
	}
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}





