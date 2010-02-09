#ifndef _PROTO_UNKNOWN_H_
#define _PROTO_UNKNOWN_H_

#include "configuration.h"
#include <netinet/in.h>

void* ph_unknown_create();
int ph_unknown_destroy(void*);

int ph_unknown_init(void* handler, struct configuration_t* c);
int ph_unknown_deinit(void* handler);
int ph_unknown_handle_payload_stc(void* handler, const char* payload, size_t len);
int ph_unknown_handle_payload_cts(void* handler, const char* payload, size_t len);
int ph_unknown_handle_packet(void* handler, const char* packet, size_t len);
int ph_unknown_determine_target(void* handler, struct sockaddr_in*);


#endif