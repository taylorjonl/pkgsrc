#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vmtools.sh,v 1.1 2008/08/31 06:36:47 scottr Exp $
#

# PROVIDE: vmtools
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="vmtools"
rcvar="vmtools"
pidfile="/var/run/vmware-guestd.pid"
command="@PREFIX@/sbin/vmware-guestd"
command_args="--background ${pidfile}"

load_rc_config $name
run_rc_command "$1"
