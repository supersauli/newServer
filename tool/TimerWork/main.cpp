#include<iostream>
#include<stdio.h>
#include <time.h>
#include <vector>
#include <assert.h>
#include <stdlib.h>
using namespace std;


void split(const string& s, vector<string>& v, const char* c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
         
        pos1 = pos2 + 1;
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}
enum CheckType
{
    CHECK_TYPE_HOUR,

};
bool CheckV(int value,CheckType type){
return true;
}


std::vector<int> ParseStr(const char* str){

    vector<int> res;
	std::vector<string>	 result1;
	split(str,result1,"(");
    if(result1.size()==2)
    {
        std::vector<string>	 result2;
        split(result1[1].c_str(),result2,")");
        if(result2.size()==0){
            assert(0);
        }	
        

        std::vector<string>	 result3;

        split(result2[0].c_str(),result3,"-");
        if(result3.size() !=2){
            assert(0);
        }
        int begin = atoi(result3[0].c_str());
        int end = atoi(result3[1].c_str());

        for(int i =begin; i<=end;i++)
        {
            res.push_back(i);
        }
    }

    
	std::vector<string>	 result4;

    if(res.size() == 0)
    {
        res.push_back(atoi(str)); 
    }


	split(str,result4,"/");
    if(result4.size() == 2)
    {
        int interval = atoi(result4[1].c_str());
        assert(interval !=0 );
        int begin =  res[0];
        auto it = res.begin();
        for( ;it !=res.end();) 
        {
            if ((*it - begin)%interval != 0 ){
                it = res.erase(it); 
            }
			else
            {
                it++;
            }
        }
    }

   
    return res;




};


void Print(std::vector<int>&res)
{
    for(auto it:res)
    {
        cout<<it <<endl; 
    }
}


int GetNextRunTimer(const char* str)
{
	std::vector<string>  timerVec;
	split(str,timerVec,",");
	if(timerVec.size() !=5)	{
		return 0;
	}
    
    std::vector<int> min = ParseStr(timerVec[0].c_str());
    Print(min);

    std::vector<int> hour = ParseStr(timerVec[1].c_str());
    Print(hour);

    std::vector<int> day = ParseStr(timerVec[2].c_str());
    Print(day);

    std::vector<int> month = ParseStr(timerVec[3].c_str());
    Print(month);

    




}


int main()
{

    GetNextRunTimer("0,0,(1-31)/2,*,*");





    return 0;

};







