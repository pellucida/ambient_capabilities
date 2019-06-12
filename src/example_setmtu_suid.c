//
// @(#) example_setmtu_suid.c
//
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netinet/ip.h>
# include	<sys/ioctl.h>
# include	<net/if.h>
# include       <sys/capability.h>
# include       <sys/prctl.h>

# include	<string.h>
# include	<stdio.h>

//
// Try to set the mtu of loopback interface to 64000
// using an ioctl(2) syscall which requires CAP_NET_ADMIN
//
main() {
	char	interface[]	= "lo";
	uid_t	uid	= getuid ();
	uid_t	euid	= geteuid ();
	gid_t	gid	= getgid ();

	int	mtu	= ioctl_getmtu (interface);
	printf ("interface %s mtu=%d\n", interface, mtu);
	
	// euid==0 then process has all caps
	if (cap_is_effective (CAP_NET_ADMIN)) {
		fprintf (stdout, "Pre setuid(): CAP_NET_ADMIN already in effective\n");
	}
	if (euid==0) {	// Drop root 
		setregid (gid, gid);
		setreuid (uid, uid);
	}
	// switching uids 0 -> uid looses caps
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
