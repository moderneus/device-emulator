#ifndef MOD_DEVICE_H
#define MOD_DEVICE_H

#include "def.h"

struct device {
	u32     handle;
	void    *heap;
	u32     heap_len;
};

void device_init(struct device *dev);

void device_destroy(struct device *dev);

#endif
