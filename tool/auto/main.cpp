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
    template<class Z>
    void Push(Z z){
        cout<<"value="<<HashFunc<Z>::value<<endl;
        if(HashFunc<Z>::value)
        {
            //this->insert(std::make_pair(m.GetFirstKey(),m));
            //this->insert(make_pair(m.GetSecondKey(), Push(m)));
               //this->insert(make_pair(z.GetFirstKey(),make_pair(z.GetSecondKey(),z)));
               cout<<"push"<<endl;
               (*this)[z.GetFirstKey()][z.GetSecondKey()] =z;
               //pp(this,z);

        }
        else{
//            this->insert(std::make_pair(z.GetFirstKey(),z));
        }
    }
    template<typename U>
    void pp(std::map<T,M>* m,U& u){
        (*m)[u.GetFirstKey()][u.GetSecondKey()] = u;
    }
 //   template<typename X,typename Y>
 //   void Push(std::map<X,Y>&m){
 //       this->insert(std::make_pair(m.seocnd.GetFirstKey(),m));
 //   }





};

struct Friend{
    std::string GetFirstKey(){return name;}
    int GetSecondKey(){return age;}
    std::string  name;
    int age;
    int id;

};



int main()
{

    smap<std::string ,Friend> friendList;
    smap<std::string ,smap<int,Friend> > f1;

    Friend f;
    f.name = "a";
    f.age = 10;

    //friendList.Push(f);

    f1.Push(f);

    for(auto it:friendList)
    {
        cout<<"name="<<it.second.name.c_str()<<"  age="<<it.second.age<<endl;
    
    }

    for(auto it:f1)
    {
        //cout<<"name="<<it.second.name.c_str()<<"  age="<<it.second.age<<endl;
        //
        cout<<"firstkey = "<<it.first;

        for(auto its:it.second){
            cout<<"second="<<its.first<<"id="<<its.second.id;
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
