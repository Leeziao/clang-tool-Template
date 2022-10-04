#include <stdio.h>

#pragma macro_arg_guard val
#define PRINT(val) \
	printf("%d\n", val * 94 + (val) * 2);

int main() {
	PRINT(1+3);
	return 0;
}
