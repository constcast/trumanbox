#include "proto_ident.h"
#include "proto_ident_truman.h"
#include "proto_ident_opendpi.h"
#include "msg.h"

#include <stdlib.h>

struct proto_identifier_t* pi_create(operation_mode_t mode, pi_type type)
{
	struct proto_identifier_t* result = (struct proto_identifier_t*)malloc(sizeof(struct proto_identifier_t));
	result->mode = mode;
	result->type = type;
	switch (type) {
	case inbuild:
		result->init = pi_buildin_init;
		result->deinit = pi_buildin_deinit;
		result->byport = pi_buildin_port;
		result->bypayload = pi_buildin_payload;
		break;
	case opendpi:
#ifdef WITH_OPENDPI
		result->init = pi_opendpi_init;
		result->deinit = pi_opendpi_deinit;
		result->byport = pi_opendpi_port;
		result->bypayload = pi_opendpi_payload;

#else
		msg(MSG_FATAL, "TrumanBox was compiled without OpenDPI support."
				"Please recompile TrumanBox with OpenDPI support or disable opendpi in the config file!");
		exit(-1);
#endif
	}
	return result;
}

void pi_destroy(struct proto_identifier_t* p)
{
	free(p);
}

