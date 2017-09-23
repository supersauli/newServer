#include<stdio.h>
#include<string>
#include<string.h>
#include <map>
#include <iostream>
using namespace std;

typedef char Yes;
typedef Yes No[2];


#define DEFINE_CHECK_FUNC(X) \
    template<typename T>  \
struct Check##X{  \
    template<typename U> \
    static Yes& Check(decltype(&U::X));\
    template<typename U>   \
    static No &Check(...);   \
    static const constexpr int value = (sizeof(Check<T>(0))==sizeof(Yes)); \
};

DEFINE_CHECK_FUNC(Hash3Key);
DEFINE_CHECK_FUNC(Hash2Key);
DEFINE_CHECK_FUNC(Hash1Key);

template<class T,class M>
struct smap:public std::map<T,M>
{
   template<typename U>
   typename enable_if<CheckHash3Key<U>::value,void>::type Push(U u){
           (*this)[u.GetFirstKey()][u.GetSecondKey()][u.GetThreeKey()] =u;
   };

    template<typename U>
    typename enable_if<CheckHash2Key<U>::value,void>::type Push(U u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()] =u;
    };

    template<typename U>
     typename enable_if<CheckHash1Key<U>::value,void>::type Push(U u){
            this->insert(std::make_pair(u.GetFirstKey(),u));
    };

};

struct Friend{
    void Hash2Key();
    std::string GetFirstKey(){return name;}
    int GetSecondKey(){return age;}
    std::string  name;
    int age;
    int id{111};

};

struct User{

    void Hash1Key();
    std::string GetFirstKey(){return userName;}
    std::string userName;
};



struct Npc{
    
    void Hash3Key();
    std::string GetFirstKey(){return name;};
    int GetSecondKey(){return id;};
    int GetThreeKey(){return att;};

    std::string name;
    int id;
    int att;



};

#include<utility>

int main()
{
    typedef smap<std::string,smap<int,smap<int,Npc>>>  NPC;
    NPC npcList;
    Npc npc;
    npc.name="npc";

    


   // cout<<"xxx="<<HashFunc1<Npc>::value<<endl;
   // cout<<"xxx="<<HashFunc2<Npc>::value<<endl;
   // cout<<"xxx="<<HashFunc3<Npc>::value<<endl;
    npcList.Push(npc); 
    for(auto it:npcList)
    {
       cout<<"npc name"  <<it.second.begin()->second.begin()->second.name.c_str()<<endl;
    }











    smap<std::string ,User> userList;
    smap<std::string ,smap<int,Friend> > f1;

    Friend f;
    f.name = "a";
    f.age = 10;

    User user;
    user.userName = "abc";
    userList.Push(user);

    f1.Push(f);

    for(auto it:userList)
    {
        cout<<"name="<<it.second.userName.c_str()<<endl;
    
    }

    for(auto it:f1)
    {
        //cout<<"name="<<it.second.name.c_str()<<"  age="<<it.second.age<<endl;
        //
        cout<<"firstkey = "<<it.first.c_str()<<endl;;

        for(auto its:it.second){
            cout<<"second="<<its.first<<"\n"<<"id="<<its.second.id;
        }
    
    }








//    char buf [1023];
//    std::string str;
//   const  char*a = str.c_str();
//
//    memcpy(&buf,a,strlen(a)+1);
//


 //   printf("%s",buf);



    return 0;
}
