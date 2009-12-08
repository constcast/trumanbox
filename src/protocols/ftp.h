#ifndef _PROTO_FTP_H_
#define _PROTO_FTP_H_

#include "configuration.h"

void* ph_ftp_create();
int ph_ftp_destroy(void*);

int ph_ftp_init(void* handler, struct configuration_t* c);
int ph_ftp_deinit(void* handler);
int ph_ftp_handle_payload_stc(void* handler, const char* payload);
int ph_ftp_handle_payload_cts(void* handler, const char* payload);
int ph_ftp_handle_packet(void* handler, const char* packet);


#endif
