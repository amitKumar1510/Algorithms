#include <stdio.h>
# define max 10
int arr[max][max],i,j,n;
int visited[max],indegree[max];

void AdjacencyMatrix(){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
}

void Initialization(){
	for(i=0;i<n;i++){
		visited[i]=0;
		indegree[i]=0;
		for(j=0;j<n;j++){
			indegree[i]= indegree[i]+arr[j][i];
		}
	}	
}





int main(){
	printf("Enter the no of nodes in graph : ");
	scanf("%d",&n);
	AdjacencyMatrix();
	Initialization();
	
	return 0;
}
