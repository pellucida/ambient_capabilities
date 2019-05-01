/*
// @(#) ioctl_mtu.c - ioctls to get/set MTU of an interface
*/
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netinet/ip.h>
# include	<sys/ioctl.h>
# include	<net/if.h>

# include	<string.h>

# include	"ioctl_mtu.h"
//
// Retrieve MTU from "interface" eg "em1"  [no privilege required]
// 
int	ioctl_getmtu (char* interface) {
	int	result	= -1;
	int	sock	= socket (AF_INET, SOCK_STREAM, IPPROTO_IP); 
	if (sock >= 0) {
		struct ifreq	ifr;
		memcpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name));

		result	= ioctl (sock, SIOCGIFMTU, &ifr);
		if (result == 0) {
			result	= ifr.ifr_mtu;
		}
		close (sock);
	}
	return	result;
}
//
// Set MTU for "interface" eg "em1"  [requires CAP_NET_ADMIN]
//
int	ioctl_setmtu (char* interface, int mtu) {
	int	result	= -1;
	int	sock	= socket (AF_INET, SOCK_STREAM, IPPROTO_IP); 
	if (sock >= 0) {
		struct ifreq	ifr;
		memcpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name));
		ifr.ifr_mtu	= mtu;
		result	= ioctl (sock, SIOCSIFMTU, &ifr);
		close (sock);
	}
	return	result;
}	
