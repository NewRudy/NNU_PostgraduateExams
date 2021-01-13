#include <stdio.h>
#include <string.h>
void mknext(char const*T, int *next) {
	int len = strlen(T);
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < len) {
		if (j == -1 || T[i] == T[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
    for(int i=0;i<strlen(T);++i)
        printf("%d:%d\t",i,next[i]);
    printf("\n");
}
int KMP(char const*S, char const*T) {
	int i = -1,j = -1;
	int next[20];
	mknext(T, next);
	int S_len, T_len;
	S_len = strlen(S);
	T_len = strlen(T);
	while (i < S_len && j < T_len) {
		if (S[i] == T[j] || j == -1) {
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= T_len)
		return i - T_len;
	else
		return -1;
}

int main() {
    char S[100],P[30];
    printf("Enter your S and P:\n");
    scanf("%s",S);
    scanf("%s",P);
    printf("%S\n%S",S,P);
    int i=KMP(S,P);
    printf("%d\n",i);
    return 0;
}