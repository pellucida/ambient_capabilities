
//
//  @(#) capability_utils.h
//
# if !defined(CAPABILITY_UTILS_H)
# define	CAPABILITY_UTILS_H 1

# include	<sys/capability.h>

int	cap_is_set (cap_t caps, cap_flag_t eip, cap_value_t capability);
int	cap_effective_is_set (cap_t caps, cap_value_t capability);
int	cap_inheritable_is_set (cap_t caps, cap_value_t capability);
int	cap_permitted_is_set (cap_t caps, cap_value_t capability);
int	cap_is_inheritable (cap_value_t capability);
int	cap_is_effective (cap_value_t capability);
int	cap_is_permitted (cap_value_t capability);
int	cap_do_set (cap_value_t capability, cap_flag_t eip);

# endif
