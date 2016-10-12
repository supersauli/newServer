#include "sdk/VarList.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{

	VarList var;
	var<<10<<100;
	for(auto i = 0;i<var.size();i++)
	{
		cout<<var.GetValue(i)<<endl;	
	}



}

