#ifndef __SUID__H__
#define __SUID__H__

typedef char[36] UuidStr;

void GetStrUid(UuidStr* uidStr )
{
	uuid_t uid; 
	uuid_generate_time(uid);
	uuid_unparse(uu,uidStr);
}


#endif
