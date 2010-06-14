/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 297205 2010-03-30 21:09:07Z johannes $ */

#ifndef PHP_SHADOW_H
#define PHP_SHADOW_H

extern zend_module_entry shadow_module_entry;
#define phpext_shadow_ptr &shadow_module_entry

#ifdef PHP_WIN32
#	define PHP_SHADOW_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_SHADOW_API __attribute__ ((visibility("default")))
#else
#	define PHP_SHADOW_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(shadow);
PHP_MSHUTDOWN_FUNCTION(shadow);
PHP_RINIT_FUNCTION(shadow);
PHP_RSHUTDOWN_FUNCTION(shadow);
PHP_MINFO_FUNCTION(shadow);

#define SHADOW_DEBUG_FULLPATH 	(1<<0)
#define SHADOW_DEBUG_OPEN 		(1<<1)
#define SHADOW_DEBUG_STAT 		(1<<2)
#define SHADOW_DEBUG_MKDIR		(1<<3)
#define SHADOW_DEBUG_OPENDIR	(1<<4)
#define SHADOW_DEBUG_RESOLVE	(1<<5)
#define SHADOW_DEBUG_UNLINK		(1<<6)
#define SHADOW_DEBUG_RENAME		(1<<7)
#define SHADOW_DEBUG_PATHCHECK	(1<<8)
#define SHADOW_DEBUG_ENSURE		(1<<9)
#define SHADOW_DEBUG_FAIL		(1<<10)
#define SHADOW_DEBUG_TOUCH		(1<<11)
#define SHADOW_DEBUG_CHMOD		(1<<11)

ZEND_BEGIN_MODULE_GLOBALS(shadow)
	/* config vars */
	zend_bool enabled;
	long mkdir_mask;
	long debug;
	/* runtime data */
	char *template;
	char *instance;
	int template_len;
	int instance_len;
	char **instance_only;
	int instance_only_count;
	HashTable cache;
ZEND_END_MODULE_GLOBALS(shadow)

#ifdef ZTS
#define SHADOW_G(v) TSRMG(shadow_globals_id, zend_shadow_globals *, v)
#else
#define SHADOW_G(v) (shadow_globals.v)
#endif

ZEND_EXTERN_MODULE_GLOBALS(shadow)

#endif	/* PHP_SHADOW_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
