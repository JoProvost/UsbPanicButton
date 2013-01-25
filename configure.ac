AC_INIT([UsbPanicButton], [1.0], [jprovost.sh@gmail.com], [panic-button], [https://github.com/JoProvost/UsbPanicButton])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define foreign])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX

# Checks for libraries.
AH_TEMPLATE([HAVE_HIDAPI],
            [Define if USB support is enabled via HIDAPI])
AC_CHECK_LIB([hidapi], [hid_init], [have_hidapi=yes])

if test x$have_hidapi = xyes; then
   case $target in
       *-*-darwin*)
               LIBHIDAPI="-lhidapi -framework CoreFoundation -framework IOKit"
               ;;
       *)
               LIBHIDAPI="-lhidapi"
               ;;
   esac
   AC_DEFINE([HAVE_HIDAPI])
   AC_CHECK_HEADERS([hidapi/hidapi.h])
fi
AC_SUBST(LIBHIDAPI, $LIBHIDAPI)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

if test x$have_hidapi = x; then
   echo "DON'T HAVE HIDAPI!"
fi

