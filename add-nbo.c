#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	uint32_t a, b;

	FILE *fp_a = fopne(argv[1],'rb');
	FILE *fp_b = fopen(argv[2],'rb');
	
	fread(&a, sizeof(a), 1, fp_a);
	fread(&b, sizeof(b), 1, fp_b);

	a = htonl(a);
	b = htonl(b);

	printf("%d(%x) + %d(%x) = %d(%x)\n", a, a, b, b, a+b, a+b);

	fclose(a);
	fclose(b);

	return 0;
}
