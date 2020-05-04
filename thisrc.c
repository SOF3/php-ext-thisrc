/* thisrc extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_thisrc.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void thisrc()
 */
PHP_FUNCTION(thisrc)
{
	ZEND_PARSE_PARAMETERS_NONE();

	zend_object *object = zend_get_this_object(EG(current_execute_data));

	if(!object) {
		zend_throw_error(NULL, "thisrc() must be called from within a class");
		return;
	}

	RETURN_LONG(object->gc.refcount);
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(thisrc)
{
#if defined(ZTS) && defined(COMPILE_DL_THISRC)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(thisrc)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "thisrc support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_thisrc, 0)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ thisrc_functions[]
 */
static const zend_function_entry thisrc_functions[] = {
	PHP_FE(thisrc,		arginfo_thisrc)
	PHP_FE_END
};
/* }}} */

/* {{{ thisrc_module_entry
 */
zend_module_entry thisrc_module_entry = {
	STANDARD_MODULE_HEADER,
	"thisrc",					/* Extension name */
	thisrc_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(thisrc),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(thisrc),			/* PHP_MINFO - Module info */
	PHP_THISRC_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_THISRC
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(thisrc)
#endif

