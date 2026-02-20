#ifndef MOD_IO_H
#define MOD_IO_H

#include "def.h"

struct device;

void device_write(struct device *dev, u32 data, u32 idx);

void device_read(struct device *dev, u32 *data, u32 idx);

#endif
