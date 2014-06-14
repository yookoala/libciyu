AC_PREREQ(2.63)
AC_INIT([libciyu], [0.1], [https://github.com/Cangjians/libciyu/issues], [libciyu], [https://github.com/Cangjians/libciyu])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.11 no-dist-gzip dist-xz tar-ustar foreign])
AC_PROG_MKDIR_P

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

# Check library versions
# then substitute the revelant cflag with actual library information
PKG_CHECK_MODULES([GLIB],[glib-2.0 > 2.19.0])
PKG_CHECK_MODULES([GOBJECT],[gobject-2.0])
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GOBJECT_CFLAGS)

GOBJECT_INTROSPECTION_CHECK(1.30.0)

# Search Python if introspection is enabled, to find the overrides install dir
# No need to make Python mandatory otherwise
AS_IF([test "x$found_introspection" = "xyes"],
      [
        AM_PATH_PYTHON(2.7)
      ]
)

# Check if python exists
AM_PATH_PYTHON(,, [:])
AM_CONDITIONAL([HAVE_PYTHON], [test "$PYTHON" != :])


# Initialize libtool
LT_INIT([disable-static])

# OUTPUT files
AC_CONFIG_FILES([
  Makefile
  data/ciyu.pc
])


AC_OUTPUT
