#include <stdio.h>
#include <stdlib.h> // Include this header for using malloc

# define max 10
int arr[max][max], i, j, n, top = -1;
int visited[max], indegree[max], stack[max];

void AdjacencyMatrix() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void Initialization() {
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            indegree[i] = indegree[i] + arr[j][i];
        }
    }
}

void push(int node) {
    stack[++top] = node;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void TopologicalSort() {
    int i, node;
    
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0 && !visited[i]) {
            push(i);
            visited[i] = 1;
        }
    }

    while (!isEmpty()) {
        node = pop();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (arr[node][i] == 1 && !visited[i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    push(i);
                    visited[i] = 1;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    AdjacencyMatrix();
    Initialization();

    printf("Topological Sorting: ");
    TopologicalSort();

    return 0;
}
