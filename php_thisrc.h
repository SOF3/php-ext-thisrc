/* thisrc extension for PHP */

#ifndef PHP_THISRC_H
# define PHP_THISRC_H

extern zend_module_entry thisrc_module_entry;
# define phpext_thisrc_ptr &thisrc_module_entry

# define PHP_THISRC_VERSION "0.1.1"

# if defined(ZTS) && defined(COMPILE_DL_THISRC)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_THISRC_H */

