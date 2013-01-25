#ifndef USBDEVICE_H_
#define USBDEVICE_H_

#include <hidapi/hidapi.h>

class HidDevice {
public:
	static HidDevice* createFromConnectedDevice(unsigned short vendorID, unsigned short productID);

	HidDevice(hid_device *targetDeviceHandle);

	bool writeData(unsigned char* data, int dataSize);
	int readData(unsigned char *data, int size, int timeout = 500);
	virtual ~HidDevice();

	bool isConnected();
	void close();

private:
	hid_device *deviceHandle;
};

#endif /* USBDEVICE_H_ */
