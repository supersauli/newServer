#include<stdio.h>
#include<string>
#include<string.h>
#include <map>
#include <iostream>
using namespace std;

typedef char Yes;
typedef Yes No[2];


template<typename T>
struct HashFunc{
    template<typename U>
    static Yes& Check(decltype(U::GetSecondKey));
    template<typename U>
    static  No &Check(...);
    static const constexpr int value = sizeof(Check<T>(0)) == sizeof(Yes);
};




template<class T,class M>
struct smap:public std::map<T,M>
{
    std::map<T,M>& Push(M m){
        if(HashFunc<M>::value)
        {
            //this->insert(std::make_pair(m.GetFirstKey(),m));
            this->insert(maker_pair(m.GetSecondKey(), m.Push(m));
        }
        else{
            this->insert(std::make_pair(m.GetFirstKey(),m));
        }
        return *this;
    }

    std::map<T,M> & Push(std::map<T,M>&m){
    {

        

    
    }





};

struct Friend{
    std::string GetFirstKey(){return name;}
    int GetSecondKey(){return age;}
    std::string  name;
    int age;

};



int main()
{

    smap<std::string ,Friend> friendList;
    smap<std::string ,smap<int,Friend> > f1;

    Friend f;
    f.name = "a";
    f.age = 10;

    friendList.Push(f);

    f1.Push(f);

    for(auto it:friendList)
    {
        cout<<"name="<<it.second.name.c_str()<<"  age="<<it.second.age<<endl;
    
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
