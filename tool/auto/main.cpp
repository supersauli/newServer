#include<stdio.h>
#include<string>
#include<string.h>
#include <vector>
#include <map>
#include <iostream>
#include "template.h"
#include<utility>
#include <typeinfo>
#include"Data.h"
using namespace std;


#define CheckVector CheckV



int main()
{

    cout<<is_int<int>::value<<endl;
    cout<<is_int<double>::value<<endl;

    Data data;
    data.InitAttrCallBack();
    data.SetLevel(10);
    data.SetAge(122);
    data.SetName("test");
    data.Set("level",11111);
    data.Set("age",11111);
    data.Set("name","uuuu");

    auto attrList = data.GetAttrList();
    for(auto it :attrList)
    {
        cout<<it.c_str()<<"="<<data.GetInt(it.c_str())<<endl;;
    }

   for(auto it :attrList)
    {
        cout<<it.c_str()<<"="<<data.GetStr(it.c_str())<<endl;;
    }


























////cout<<CheckM<std::vector<std::string>>::value<<endl;
//cout<<CheckM<std::map<int,int>>::value<<endl;
//cout<<CheckM<std::vector<std::pair<int,int>>>::value<<endl;
//












//    cout<<CheckMV<std::map<int,std::vector<std::string>>>::value <<endl;
//
//    vector<int> a111;
//    cout<<typeid(a111).name()<<endl;
//
//
//
//    std::vector<std::string> ff;
//    std::map<int,int> fff;
//    cout<<CheckVector<decltype( ff)>::value<<endl;
//    cout<<CheckVector<decltype( fff)>::value<<endl;
//
//
//    typedef smap<std::string,smap<int,smap<int,Npc>>>  NPC;
//    NPC npcList;
//    Npc npc;
//    npc.name="npc";
//
//    typename enable_if<CheckVector<decltype(ff)>::value,int>::type a;
//    a = 10;
//

   // cout<<"xxx="<<HashFunc1<Npc>::value<<endl;
   // cout<<"xxx="<<HashFunc2<Npc>::value<<endl;
   // cout<<"xxx="<<HashFunc3<Npc>::value<<endl;
 //   npcList.Push(npc); 
 //   for(auto it:npcList)
 //   {
 //      cout<<"npc name"  <<it.second.begin()->second.begin()->second.name.c_str()<<endl;
 //   }


 //   smap<std::string ,User> userList;
 //   smap<std::string,std::vector<User>> userVec;
 //   smap<std::string ,smap<int,Friend> > f1;

 //   Friend f;
 //   f.name = "a";
 //   f.age = 10;

 //   User user;
 //   user.userName = "abc";
 //   userList.Push(user);

 //   f1.Push(f);

 //   userVec.Push(user);



 //   for(auto it:userList)
 //   {
 //       cout<<"name="<<it.second.userName.c_str()<<endl;
 //   
 //   }

 //   for(auto it:f1)
 //   {
 //       //cout<<"name="<<it.second.name.c_str()<<"  age="<<it.second.age<<endl;
 //       //
 //       cout<<"firstkey = "<<it.first.c_str()<<endl;;

 //       for(auto its:it.second){
 //           cout<<"second="<<its.first<<"\n"<<"id="<<its.second.id;
 //       }
 //   
 //   }








//    char buf [1023];
//    std::string str;
//   const  char*a = str.c_str();
//
//    memcpy(&buf,a,strlen(a)+1);
//


 //   printf("%s",buf);



    return 0;
}
