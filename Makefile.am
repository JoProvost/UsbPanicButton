# set the include path found by configure
INCLUDES = $(all_includes)

.cpp.o:
	@CXXCOMPILE@ $@ $<

bin_PROGRAMS = panicbutton
panicbutton_SOURCES = src/main.cpp  src/HidDevice.cpp  src/HidDevice.h  src/USBPanicButton.cpp  src/USBPanicButton.h
panicbutton_LDADD  = @LIBHIDAPI@ -lm
