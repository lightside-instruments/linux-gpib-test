AC_INIT([linux-gpib-test], [1.0], [vladimir@lightside-instruments.com])

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])

AC_PROG_CC
AC_PROG_CXX
AM_PROG_AS
AC_PROG_LIBTOOL

linuxgpibmoduledir="$libdir/linux-gpib"
AC_SUBST(linuxgpibmoduledir)

CFLAGS="$CFLAGS -g -fPIC -DDEBUG=1 -DLINUX=1 -DGCC=1 -DRELEASE=1"
AC_SUBST(CFLAGS)

AC_CONFIG_FILES([
        Makefile \
        idn/Makefile \
        srq/Makefile
])

AC_OUTPUT
