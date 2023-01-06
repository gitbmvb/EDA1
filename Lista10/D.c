#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *v, int l, int r, int aim, int aux){
	if(l > r) return (aim > v[aux]) ? aux + 1: aux;
	int m = (l + r)/2;
	if(v[m] == aim) return m;
	else if(aim < v[m]) return binarysearch(v, l, m - 1, aim, m);
	else return binarysearch(v, m + 1, r, aim, m);
}

int main(void){
	int N, M, aim;
	scanf("%d %d", &N, &M);
	int elements[N];
	for(int i = 0; i < N; i++) scanf("%d", &elements[i]);
	for(int j = 0; j < M; j++){
		scanf("%d", &aim);
		printf("%d\n", (aim > elements[N-1]) ? N: binarysearch(elements, 0, N - 1, aim, N));
	}
}
