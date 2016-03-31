#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n = atoi (argv[1]);
	srand(argc==3? atoi(argv[2]): time(NULL));
	drawCharSquare(charSquare(n), n);
	printf("\n");	
}

char **charSquare(int n)
{
	char **square = new char *[n];
	
	for (int i=0; i<n; i++) square[i] = new char[n];
	

	for (int j=0; j<n*n; j++) 
		square[j/n][j%n] = 'a' + rand()%('z'-'a');

	return square;
}

void drawCharSquare(char **square, int n)
{
	for(int i=0; i<n*n; i++)
		(i%n==0 && i!=0) ? printf("\n%c ", square[i/n][i%n]): printf("%c ", square[i/n][i%n]);

	for (int j=0; j<n; j++) delete[] square[j];

	delete[] square;

}