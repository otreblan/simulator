AC_INIT([hello], [0.0.1])
#AC_CONFIG_AUX_DIR([aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Language
AC_LANG([C++])

# Checking if some programs are installed
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_CHECK_PROG([ASCII], [asciidoctor])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
				Makefile
				src/Makefile
				doc/Makefile
])

AC_OUTPUT
