
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
	
utils:	$(UTILS)

clean:
	rm -f *.o $(PROGS)

example_setmtu_exec.o: example_setmtu_exec.c
example_setmtu_exec_cap.o: example_setmtu_exec_cap.c
example_setmtu_exec_prctl.o: example_setmtu_exec_prctl.c
example_setmtu_ioctl.o: example_setmtu_ioctl.c
example_setmtu_ioctl_nocap.o: example_setmtu_ioctl_nocap.c
capability_utils.o: capability_utils.c capability_utils.h
ioctl_mtu.o: ioctl_mtu.c ioctl_mtu.h
run_utils.o: run_utils.c run_utils.h
