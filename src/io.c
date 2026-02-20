#include "device.h"
#include "io.h"
#include "err.h"

void device_write(struct device *dev, u32 data, u32 idx)
{
	void *tmp;

	err(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	err(dev->heap_len <= sizeof(u32) * idx, "cannot write out of array");

	tmp = dev->heap;
	dev->heap = (char*)dev->heap + sizeof(data) * idx;
	*(u32*)dev->heap = data;
	dev->heap = tmp;
}

void device_read(struct device *dev, u32 *data, u32 idx)
{
	void *tmp;

	err(dev->handle == DEVICE_NONE_HANDLE, "device is not inited");
	err(dev->heap_len <= sizeof(u32) * idx, "cannot read out of array");

	tmp = dev->heap;
	dev->heap = (char*)dev->heap + sizeof(u32) * idx;
	*data = *(u32*)dev->heap;
	dev->heap = tmp;
}
