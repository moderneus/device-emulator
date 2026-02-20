#include "device.h"
#include "err.h"

#include <stdlib.h>

void device_init(struct device *dev)
{
	warn(dev->handle != DEVICE_NONE_HANDLE, "device is already inited");
	dev->handle = rand();
	dev->heap = NULL;
	dev->heap_len = 0;
}

void device_destroy(struct device *dev)
{
	warn(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	warn(dev->heap != NULL, "device heap pointer is not NULL");
	dev->handle = DEVICE_NONE_HANDLE;
	dev->heap = NULL;
	dev->heap_len = 0;
}
