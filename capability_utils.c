# include	<sys/types.h>
# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>
# include	<sys/prctl.h>
# include	<sys/capability.h>


void	display_caps (cap_t caps) {
	printf ("caps %s\n", cap_to_text (caps, 0));
}

int	cap_is_set (cap_t caps, cap_flag_t eip, cap_value_t capability) {
	int	result	= 0;
	cap_flag_value_t	value;
	cap_get_flag (caps,  capability, eip,  &value);
	result	= (value == CAP_SET);
	return	result;
}

int	cap_effective_is_set (cap_t caps, cap_value_t capability) {
	return	cap_is_set (caps, CAP_EFFECTIVE, capability);
}
int	cap_inheritable_is_set (cap_t caps, cap_value_t capability) {
	return	cap_is_set (caps, CAP_INHERITABLE, capability);
}
int	cap_permitted_is_set (cap_t caps, cap_value_t capability) {
	return	cap_is_set (caps, CAP_PERMITTED, capability);
}
int	cap_is_inheritable (cap_value_t capability) {
	cap_t	caps	= cap_get_proc();
	return	cap_inheritable_is_set (caps, capability);
}
int	cap_is_effective (cap_value_t capability) {
	cap_t	caps	= cap_get_proc();
	return	cap_effective_is_set (caps, capability);
}
int	cap_is_permitted (cap_value_t capability) {
	cap_t	caps	= cap_get_proc();
	return	cap_permitted_is_set (caps, capability);
}
int	cap_do_set (cap_value_t capability, cap_flag_t eip) {
	cap_t   caps    = cap_get_proc();
	cap_value_t cap_set []        =  {capability,};
	int	result	= cap_set_flag (caps, eip, 1, cap_set,  CAP_SET);
	if (result==0) {
		cap_set_proc (caps);
	}
	return	result;
}
