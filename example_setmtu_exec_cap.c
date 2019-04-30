# include	<sys/types.h>
# include	<sys/wait.h>
# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>
# include	<sys/prctl.h>
# include	<sys/capability.h>

main() {
	if (cap_is_permitted (CAP_NET_ADMIN)) {
		cap_do_set (CAP_NET_ADMIN, CAP_INHERITABLE);
	}
	run ("/sbin/ip", "ip", "link", "show", "dev", "lo", (char*)0);

	run ("/sbin/ip", "ip", "link", "set", "mtu", "65500", "dev", "lo", (char*)0);

	run ("/sbin/ip", "ip", "link", "show", "dev", "lo", (char*)0);
}
