#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])

AC_INIT([cmdline], VERSION)
AC_CONFIG_SRCDIR([source/main.c++])
AM_INIT_AUTOMAKE(cmdline, 0.1)
AC_CONFIG_HEADERS([config.h])

VERSION="0.1"
AC_SUBST(VERSION)



# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

AC_LANG_CPLUSPLUS

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([memory.h stdint.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strtol])

AC_CONFIG_FILES([Makefile source/Makefile])

AC_OUTPUT
