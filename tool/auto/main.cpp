#include "Template.h"
#include<iostream>
#include<map>
#include<vector>
#include"ReflectData.h"
#include "Data.h"
using namespace std;

int main(){
    smap<string,std::vector<User>> userMap;
    {
        User user;
        user.userName = "abc";
        userMap.Push(user);
    }
    {
        User user;
        user.userName = "def";
        userMap.Push(user);
    }
    cout<<ContainersDepth<decltype(userMap)>()<<endl;
    cout<<CheckContainersDepth<decltype(userMap),0>::value<<endl;
    cout<<CheckContainersDepth<decltype(userMap),1>::value<<endl;
    cout<<CheckContainersDepth<decltype(userMap),2>::value<<endl;
    cout<<CheckContainersDepth<decltype(userMap),3>::value<<endl;

    smap<string,map<int,map<int,Npc>>> npcMap;
    Npc npc;
    npc.name = "11111";
    npc.sex = 10;
    npc.level = 112;
    npcMap.Push(npc);
    {
        auto it = npcMap.begin();
        npcMap.Del(it);
        if(!npcMap.empty())
        {
            printf("error Del \n");
        }

        npcMap.Push(npc);
        it = npcMap.begin();
        for(;it!= npcMap.end();it++)
        {
            auto its = it->second.begin();
            for(;its!= it->second.end();its++)
            {
                //npcMap.Del(its); 
            }
        }


     if(!npcMap.empty())
        {
            printf("error Del \n");
        }


 if(!npcMap.empty())
        {
            printf("error Del \n");
        }




    }








    std::map<string,std::vector<User>>::iterator it = userMap.begin(); 
    for(;it!=userMap.end();it++)
    {
        //userMap.Del(it);
        cout<<"itvalue0 = "<<CheckIt<0,decltype(userMap),decltype(it)>::value<<endl;
        cout<<"itvalue1 = "<<CheckIt<1,decltype(userMap),decltype(it)>::value<<endl;
        cout<<"itvalue2 = "<<CheckIt<2,decltype(userMap),decltype(it)>::value<<endl;
        break;
        //userMap.erase(it);
    }




    cout<<"#########################################################"<<endl;

      it = userMap.begin(); 



    for(;it!=userMap.end();it++)
    {
        auto its = it->second.begin();
        //decltype(it)::value_type f;
         //cout<<"x1="<<Checkbegin<decltype(it)>::value<<endl;

         //cout<<"  "<<typeid(f).name()<<endl;
         //cout<<" b1 "<<CheckHash1Key<typename decltype(it)::value_type>::value <<endl;
        for(;its!=it->second.end();its++)
        {
        cout<<"itvalue0 = "<<CheckIt<0,decltype(userMap),decltype(its)>::value<<endl;
        cout<<"itvalue1 = "<<CheckIt<1,decltype(userMap),decltype(its)>::value<<endl;
        cout<<"itvalue2 = "<<CheckIt<2,decltype(userMap),decltype(its)>::value<<endl;
         userMap.Del(its);
         //cout<<"x2="<<Checkbegin<decltype(its)>::value<<endl;
        decltype(its)::value_type f1;
        it->second.erase(its);

         cout<<"  "<<typeid(f1).name()<<endl;
         cout<<" b2 "<<CheckHash1Key<typename decltype(its)::value_type>::value <<endl;
         break;

        }
        break;
    }





    cout<<"del"<<endl;
    for(auto it:userMap )
    {
        for(auto its:it.second) {
            cout<<its.userName.c_str()<<endl;
        }
    }









    return 0;
}


