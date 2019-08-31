#ifndef __CLIENT_H__
#define __CLIENT_H__

#define _POSIX_C_SOURCE 200112L

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

#include "../common/common_socket.h"

typedef struct{
	socket_t socket;
	struct addrinfo hints;
	struct addrinfo *result, *ptr;
} client_t;

//starts a new instance of the client
void client_start(client_t* self, const char* hostname, const char* servicename);

//attemps to connect and starts listening for input
//POS: returns exit value
int client_connect(client_t* self);

//finalize the client
void client_shutdown(client_t* self);

#endif