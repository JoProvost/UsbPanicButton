/*
 * USBPanicButton.h
 *
 *  Created on: 2013-01-02
 *      Author: thierry
 */

#ifndef USB_PANIC_BUTTON_H
#define	USB_PANIC_BUTTON_H

#include "HidDevice.h"

#define ID_VENDOR 0x1d34
#define ID_PRODUCT 0x000d

enum ButtonState {
	DOWN, UP, UNKNOWN
};

class USBPanicButton {
public:
	static USBPanicButton* createFromConnectedDevice();

	USBPanicButton(HidDevice* panicButtonDevice);
	bool isConnected();
	ButtonState getButtonState();
	bool isDown();
	void close();
private:

	HidDevice* panicButtonDevice;
};

#endif
