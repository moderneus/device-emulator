#include <stdio.h>

#include "device/device.h"
#include "device/mem.h"
#include "device/def.h"
#include "device/io.h"

int main(void)
{
	struct device dev;
	u32 buf[4];
	u32 i;

	device_init(&dev);
	device_malloc(&dev, sizeof(u32) * 4);

	for(i = 0; i < dev.heap_len / sizeof(u32); ++i)
		device_write(&dev, i, i);

	for(i = 0; i < dev.heap_len / sizeof(u32); ++i)
		device_read(&dev, &buf[i], i);

	for(i = 0; i < sizeof(buf) / sizeof(buf[0]); ++i)
		printf("buf[%i] = %i\n", i, buf[i]);

	device_free(&dev);
	device_destroy(&dev);

	return 0;
}
