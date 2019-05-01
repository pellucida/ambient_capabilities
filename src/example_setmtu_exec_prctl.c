//
// @(#) example_setmtu_exec_prctl.c
//
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>
# include	<sys/prctl.h>
# include	<sys/capability.h>


main() {
	int	result	= -1;
	if (cap_is_permitted (CAP_NET_ADMIN)) {
		cap_do_set (CAP_NET_ADMIN, CAP_INHERITABLE);
	}

	result  =  prctl (PR_CAP_AMBIENT, PR_CAP_AMBIENT_RAISE, CAP_NET_ADMIN, 0, 0);
	if (result != 0) {
		perror ("prctl: ");
	}

	run ("/sbin/ip", "ip", "link", "show", "dev", "lo", 0);

	run ("/sbin/ip", "ip", "link", "set", "mtu", "65500", "dev", "lo", 0);

	run ("/sbin/ip", "ip", "link", "show", "dev", "lo", 0);
}
