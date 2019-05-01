//
// @(#) ioctl_mtu.h
//
# if	!defined(IOCTL_MTU_H)
# define	IOCTL_MTU_H	1

int	ioctl_getmtu (char* interface);
int	ioctl_setmtu (char* interface, int mtu);

# endif
