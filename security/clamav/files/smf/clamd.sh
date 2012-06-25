#!@SMF_METHOD_SHELL@
#
# $NetBSD$
#
# Init script for clamd(8)
#

. /lib/svc/share/smf_include.sh

PIDFILE="@CLAMAV_DBDIR@/clamd.pid"

case "$1" in
start)
	@PREFIX@/sbin/clamd
	;;
stop)
	kill `@HEAD@ -1 ${PIDFILE}`
	;;
refresh)
	# Re-open any log files and reload the database
	kill -HUP `@HEAD@ -1 ${PIDFILE}`
	kill -USR2 `@HEAD@ -1 ${PIDFILE}`
	;;
*)
	echo "Usage: $0 {start|stop|refresh}" >&2
	exit 1
	;;
esac

exit $SMF_EXIT_OK
