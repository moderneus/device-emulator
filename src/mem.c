#include "device/device.h"
#include "device/mem.h"
#include "device/err.h"

#include <stdlib.h>

void device_malloc(struct device *dev, u32 len) 
{
	err(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	warn(dev->heap != NULL, "device already has allocated mem");

	if(dev->heap)
		free(dev->heap);

	dev->heap_len = len;
	dev->heap = malloc(dev->heap_len);

	err(!dev->heap, "failed to alloc mem");
}

void device_free(struct device *dev)
{
	err(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	warn(!dev->heap, "device has not allocated mem");

	free(dev->heap);

	dev->heap = NULL;
	dev->heap_len = 0;
}
