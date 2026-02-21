#include "device/err.h"

#include <stdlib.h>
#include <stdio.h>

void err(u32 expr, const char *msg)
{
	if (expr) {
		printf("error: %s\n", msg);
		abort();
	}
}

void warn(u32 expr, const char *msg)
{
	if (expr)
		printf("warning: %s\n", msg);
}
