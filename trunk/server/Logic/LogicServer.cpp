#include "LogicServer.h"
#include "Package.h"
int main(){

	PackageBase<Item,100>	 pack("test");
	pack.Add("id",1);
	pack.Add("id",1);
	
	PackageBase<Hero,100>	 pack1("test");

	pack1.Add("id",1);
	pack1.Add("id",1);
	return 0;
}
