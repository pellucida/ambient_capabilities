# include	<sys/types.h>
# include	<sys/wait.h>
# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>


main() {
	run ("/sbin/ip", "ip", "link", "show", "dev", "lo", (char*)0);
	run ("/sbin/ip", "ip", "link", "set", "mtu", "65500", "dev", "lo", (char*)0);
	run ("/sbin/ip", "ip", "link", "show", "dev", "lo", (char*)0);
}
