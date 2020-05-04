PHP_ARG_ENABLE(thisrc, whether to enable thisrc support,
[  --enable-thisrc          Enable thisrc support], no)

if test "$PHP_THISRC" != "no"; then
  AC_DEFINE(HAVE_THISRC, 1, [ Have thisrc support ])

  PHP_NEW_EXTENSION(thisrc, thisrc.c, $ext_shared)
fi
