
LIBS	= -lcap

UTILS	= ioctl_mtu.o run_utils.o capability_utils.o


PROGS	= example_setmtu_ioctl example_setmtu_ioctl_nocap \
	example_setmtu_exec example_setmtu_exec_cap example_setmtu_exec_prctl

ALL: $(PROGS)

example_setmtu_exec: example_setmtu_exec.o run_utils.o
	$(CC) -o $@ example_setmtu_exec.o run_utils.o 

example_setmtu_exec_cap: example_setmtu_exec_cap.o run_utils.o capability_utils.o
	$(CC) -o $@ example_setmtu_exec_cap.o run_utils.o capability_utils.o $(LIBS)

example_setmtu_exec_prctl: example_setmtu_exec_prctl.o run_utils.o capability_utils.o
	$(CC) -o $@ example_setmtu_exec_prctl.o run_utils.o capability_utils.o $(LIBS)

example_setmtu_ioctl:	example_setmtu_ioctl.o $(UTILS)
	$(CC) -o $@ example_setmtu_ioctl.o $(UTILS) $(LIBS)

example_setmtu_ioctl_nocap:	example_setmtu_ioctl_nocap.o ioctl_mtu.o
	$(CC) -o $@ example_setmtu_ioctl_nocap.o ioctl_mtu.o
	
clean:
	rm -f *.o $(PROGS)
