#include<stdio.h>

int main()	{
	int a;
	int i, j;
	int p[1000] = {0};
	int n;
	int result;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)	{
		scanf("%d", &p[i]);
		if(p[i] > 1000 || p[i] < 1)
			return 0;
	}
	for(int j = 0; j < n; j++)	{
		for(int i = j; i < n; i++)	{
			if(p[j] >= p[i])	{
				a = p[j];
				p[j] = p[i];
				p[i] = a;
			}
		}
	}
	result = p[0];

	for(int i = 0; i < n - 1; i++)	{
		p[i + 1] = p[i] + p[i + 1];
		result = result + p[i + 1];
	}
	printf("%d\n",result);

	return 0;
}