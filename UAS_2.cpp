#include <stdio.h>

int count;

int check(int a, int b, int n){
	if(a < 0 || b < 0 || a >= n || b >= n) {
		return 0;
	}
	return 1;	
}

void countSteps(char maze[][1000], char visited[][1000], int a, int b, int count, int n){
    if (a == n-1 && b == n-1){
        count++;
        return;
    }
    visited[a][b] = '#';
    if (check(a, b, n) == 1 && maze[a][b] == '.'){
        if (a + 1 < n && visited[a + 1][b] == '.'){
            countSteps(maze, visited,  + 1, b, count, n);
        }
        if (a - 1 >= 0 && visited[a - 1][b] == '.'){
            countSteps(maze, visited, a - 1, b, count, n);
        }
        if (b + 1 < n && visited[a][b + 1] == '.'){
            countSteps(maze, visited, a, b + 1, count, n);
        }
        if (b - 1 >= 0 && visited[a][b - 1] == '.'){
            countSteps(maze, visited, a, b - 1, count, n);
        }
    }
    visited[a][b] = '.';
}
int main(){
	int tc;
	scanf("%d", &tc);getchar();
	char maze[1000][1000];
	char visited[1000][1000];
	
	for(int i=0;i<tc;i++){
		for(int j=0;j<tc;j++){
			scanf("%c", &maze[i][j]);getchar();
		}	
	}
	for(int i=0;i<tc;i++){
		for(int j=0;j<tc;j++){
			countSteps(maze, visited, i, j, count, tc);
		}	
	}
	printf("%d\n", count);
	return 0;
}
