#include "HidDevice.h"
#include <string.h>

HidDevice::HidDevice(hid_device *targetDeviceHandle) {
	deviceHandle = targetDeviceHandle;
}

HidDevice::~HidDevice() {
}

HidDevice* HidDevice::createFromConnectedDevice(unsigned short vendorID, unsigned short productID) {
	if (hid_init()) return NULL;
	hid_device *targetDeviceHandle = hid_open(vendorID, productID, NULL);
	if (targetDeviceHandle == NULL) return NULL;

	return new HidDevice(targetDeviceHandle);
}

bool HidDevice::isConnected() {
	return deviceHandle != NULL;
}

bool HidDevice::writeData(unsigned char* data, int dataSize) {
	unsigned char new_data[dataSize + 1];
	memcpy(&new_data[1], data, dataSize);
	new_data[0] = 0x00;

	int result = hid_write(deviceHandle, new_data, dataSize + 1);

	return result == dataSize + 1;
}

int HidDevice::readData(unsigned char *data, int size, int timeout) {
	return hid_read_timeout(deviceHandle, data, size, timeout);
}

void HidDevice::close() {
	hid_close(deviceHandle);
}
