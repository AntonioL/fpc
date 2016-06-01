#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim_trailing_zeros(char *s)
{
	int len = strlen(s) - 1;
	while(s[len] == '0' || isspace(s[len]))
		s[len--] = 0x00;
}

int required_number_bits(char *s, int *integral, int *rational)
{
	int a = 0, b = 0;
	trim_trailing_zeros(s);
	sscanf(s, "%d.%d", &a, &b);
	int _integral = floor(( log(a) / log(2) )) + 1;
	int _rational = floor(( log(b) / log(2) )) + 1;
	if(_integral > *integral)
		*integral = _integral;
	if(_rational > *rational)
		*rational = _rational;
}

int main(void)
{
	int integral = 0, rational = 0;
	FILE* file = fopen("example.dat", "r");
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		required_number_bits(&line[0], &integral, &rational);
	}
	fclose(file);
	printf("Integral Part = %d bits\nDecimal Part = %d bits\n", integral, rational);
}



