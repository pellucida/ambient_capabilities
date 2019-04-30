//
// @(#) example_setmtu_ioctl.c
//
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netinet/ip.h>
# include	<sys/ioctl.h>
# include	<net/if.h>
# include       <sys/capability.h>

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
	
	if (cap_is_effective (CAP_NET_ADMIN)) {
		fprintf (stdout, "CAP_NET_ADMIN already in effective\n");
	}
	else if (cap_is_permitted (CAP_NET_ADMIN)) {
		int	result	= cap_do_set (CAP_NET_ADMIN, CAP_EFFECTIVE);
		if (result==0) {
			fprintf (stdout, "CAP_NET_ADMIN added to effective\n");
		}
		else	{
			
			fprintf (stderr, "CAP_NET_ADMIN failed to add to effective\n");
		}
			
	}
	else	{
		fprintf (stderr, "CAP_NET_ADMIN not in permitted\n");
	}

	if (ioctl_setmtu ("lo", 64000) != 0) {
		perror ("ioctl SIOCSIFMTU");
	}
	else	{
		mtu	= ioctl_getmtu (interface);
		printf ("interface %s mtu now set to %d\n", interface, mtu);
	}
}
