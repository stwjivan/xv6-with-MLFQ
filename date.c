#include "types.h"
#include "date.h"
#include "user.h"

int main()
{
	/* code */
	struct rtcdate d;
	date(&d);
	printf(1,"%d/%d/%d %d:%d:%d\n",d.month,d.day,d.year,d.hour,d.minute,d.second);
	exit();
}