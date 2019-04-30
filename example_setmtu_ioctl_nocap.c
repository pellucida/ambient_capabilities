//
// @(#) example_setmtu_ioctl_nocap.c
//
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netinet/ip.h>
# include	<sys/ioctl.h>
# include	<net/if.h>

# include	<string.h>
# include	<stdio.h>

//
// Try to set the mtu of loopback interface to 64000
// using an ioctl(2) syscall which requires CAP_NET_ADMIN
//
main() {
	char	interface[]	= "lo";
	int	mtu	= ioctl_getmtu (interface);
	printf ("interface %s mtu=%d\n", interface, mtu);
	
	if (ioctl_setmtu ("lo", 64000) != 0) {
		perror ("ioctl SIOCSIFMTU");
	}
	else	{
		mtu	= ioctl_getmtu (interface);
		printf ("interface %s mtu now set to %d\n", interface, mtu);
	}
}
