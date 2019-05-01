
### Linux Ambient Capabilities
Linux capabilities are described in the manual page
[capabilities(7)](http://man7.org/linux/man-pages/man7/capabilities.7.html)

While ambient capabilities were add to the linux kernel from version 4.3,
Redhat has back ported the patches to RHEL 7 since kernel-3.10.0-514.el7
[https://access.redhat.com/solutions/1264083]

### SYNOPSIS
A set of simple programs that require a kernel capability to work
are used to illustrated linux capabilities.
In this case setting the MTU of the loopback interface "lo" which 
requires the CAP_NET_ADMIN capability.

When we attempt to change the MTU by an exec(2) of /sbin/ip
from a process holding CAP_NET_ADMIN we find capabilities are
not preserved across execs.
Hence the need for ambient capabilities.

### EXAMPLES
See Ambient_Capabilities.txt for a description of examples in "src/"

### PREREQUISITES
Linux kernel with ambient capability support and libcap-devel.

### SEE ALSO
[Linus Torvald's post](https://github.com/torvalds/linux/commit/58319057b7847667f0c9585b9de0e8932b0fdb08)

[S2hh's Blog "Ambient capabilities" 2015-07-25] (https://s3hh.wordpress.com/2015/07/25/ambient-capabilities/)

### LICENSE
Creative Commons CC0
[http://creativecommons.org/publicdomain/zero/1.0/legalcode]
(http://creativecommons.org/publicdomain/zero/1.0/legalcode)


### AUTHOR
[James Sainsbury](mailto:toves@sdf.lonestar.org)
