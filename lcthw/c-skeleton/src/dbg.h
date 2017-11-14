#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>
#ifdef NDEBUG
#define debug(arg,...)
/*... means the number of remain arguments is unknow*/
#else   //The alternative for #if
#define debug(arg,...)fprintf(stderr, "DEBUG %s :%d: " arg "\n", __FILE__, __LINE__, ##__VA_ARGS__)
/*##__VA_ARGS__ tell the preprocess to replace what's in ##__VA_ARGS__ with what's in the position ...
 * log_err("Age: %d, name:%s", age, name); expand into
 * fprintf(stderr,"[ERROR](%s :%d: errno:%s Age: %d, name: %s \n", __FILE__, __LINE__, clean_errno(), age, name */
#endif  

#define clean_errno()(errno == 0? "None": strerror(errno)) 
/* use strerror() get an human-readable string to the error number 
 * a ? b : c if a is logically true (does not evaluate to zero) then 
 * evaluate expression b, otherwise evaluate expression c */

#define log_err(arg,...)fprintf(stderr, "[ERROR] (%s :%d: errno: %s)" arg "\n", __FILE__, __LINE__, clean_errno(),##__VA_ARGS__)

#define log_warn(arg,...)fprintf(stderr, "[WARN] (%s :%d: errno: %s)" arg "\n", __FILE__, __LINE__, clean_errno(),##__VA_ARGS__)

#define log_info(arg,...)fprintf(stderr, "[INFO] (%s :%d)" arg "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, arg,...) if(!(A)){log_err(arg, ##__VA_ARGS__); errno = 0; goto error;}

#define sentinel(arg,...) {log_err(arg, ##__VA_ARGS__);errno = 0;  goto error;}

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A,arg, ...) if(!(A)){ debug(arg, ##__VA_ARGS__); errno = 0; goto error; }

#endif

