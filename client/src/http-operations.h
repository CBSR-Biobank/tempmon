#ifndef __INC_HTTP_OPERATIONS_H
#define __INC_HTTP_OPERATIONS_H

#include <curl/curl.h>
#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

void write_callback_func(void *buffer, size_t size,
				  size_t nmemb, void *userp);
size_t read_callback(void *ptr, size_t size, size_t nmemb, void *stream);
char *do_web_get(char *url, char *user, char *pwd);
char *do_web_put(char *url, char *to_put, char *user, char *pwd);

int get_runtime_specifications(char *url, char *user, char *pwd,
			       float *wait_duration, char **upload_url, 
			       int *product_id, int *vendor_id);
#ifdef __cplusplus
}
#endif

#endif /* __INC_HTTP_OPERATIONS_H */
