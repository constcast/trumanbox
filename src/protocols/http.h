#ifndef _PROTO_HTTP_H_
#define _PROTO_HTTP_H_

#include "configuration.h"

void* ph_http_create();
int ph_http_destroy(void*);

int ph_http_init(void* handler, struct configuration_t* c);
int ph_http_deinit(void* handler);
int ph_http_handle_payload_stc(void* handler, const char* payload);
int ph_http_handle_payload_cts(void* handler, const char* payload);
int ph_http_handle_packet(void* handler, const char* packet);


#endif
