#ifndef MOD_MEM_H
#define MOD_MEM_H

#include "def.h"

struct device;

void device_malloc(struct device *dev, u32 len);

void device_free(struct device *dev);

#endif
