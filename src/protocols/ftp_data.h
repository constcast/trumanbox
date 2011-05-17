#ifndef _PROTO_FTP_DATA_H_
#define _PROTO_FTP_DATA_H_

#include "configuration.h"
#include <netinet/in.h>

class FTPDataHandler;
class FTPDataHandler : public ProtoHandler
{
	public:
		FTPDataHandler(const Configuration& config);	
		virtual int payloadServerToClient(connection_t* conn, const char* payload, ssize_t* len);
		virtual int payloadClientToServer(connection_t* conn, const char* payload, ssize_t* len);
		virtual int determineTarget(struct sockaddr_in* addr);


};


void* ph_ftp_data_create();
int ph_ftp_data_destroy(void*);

int ph_ftp_data_init(void* handler, struct configuration_t* c);
int ph_ftp_data_deinit(void* handler);
int ph_ftp_data_handle_payload_stc(void* handler, connection_t* conn, const char* payload, ssize_t* len);
int ph_ftp_data_handle_payload_cts(void* handler, connection_t* conn, const char* payload, ssize_t* len);
int ph_ftp_data_handle_packet(void* handler, const char* packet, ssize_t len);
int ph_ftp_data_determine_target(void* handler, struct sockaddr_in*);

#endif
