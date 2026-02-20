#include "device.h"
#include "io.h"
#include "err.h"

void device_write(struct device *dev, u32 data, u32 idx)
{
	err(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	err(idx >= dev->heap_len / sizeof(u32), "cannot write out of array");

	((u32*)dev->heap)[idx] = data;
}

void device_read(struct device *dev, u32 *data, u32 idx)
{
	err(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	err(idx >= dev->heap_len / sizeof(u32), "cannot read out of array");

	*data = ((u32*)dev->heap)[idx];
}
