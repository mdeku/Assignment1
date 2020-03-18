#include <stdio.h>
#include <stdlib.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <Ws2tcpip.h>

int main(int argc, char* argv[]) {
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	addrinfo* info;
	SOCKADDR_IN addr;
	
	//char *name = new char;
	char domain[64];
	char correct_domain[64];
	printf("Enter domain: ");
	scanf_s("%s", domain, (unsigned)_countof(domain));
	scanf_s("%[[a-zA-Z\d-](\.[a-zA-Z\d-])]", correct_domain, (unsigned)_countof(correct_domain));
	if (strcmp(domain, correct_domain) == 0) {
		printf("Domain is correct");
		int ret = getaddrinfo(domain, "http", NULL, &info);
		if (ret == 0) {
			memcpy(&addr, info->ai_addr, info->ai_addrlen);
			printf("IP address is: %s", inet_ntoa(addr.sin_addr));
		}
		else
		{
			printf("IP not found");
		}
	}
	else
	{
		printf("Domain isn't correct");
		printf("Do you mean your domain is %s", correct_domain);
	}
}
