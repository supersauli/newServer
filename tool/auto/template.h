#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#include <map>
#include<string>
#include<vector>
#include<iostream>
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


template<typename T>
struct CheckVector{

    template<typename U,typename M>
    static Yes& Check(std::vector<M>);
    template <typename U>
    static No &Check(...);

    static const constexpr int value = sizeof(Check<T>(T())) == sizeof(Yes);
};


DEFINE_CHECK_FUNC(Hash3Key);
DEFINE_CHECK_FUNC(Hash2Key);
DEFINE_CHECK_FUNC(Hash1Key);

void Print(const char* str){
    std::cout<<str<<std::endl;

};
template<class T,class M>
struct smap:public std::map<T,M>
{
   template<typename U>
   typename std::enable_if<CheckHash3Key<U>::value,void>::type Push(U u){
    (*this)[u.GetFirstKey()][u.GetSecondKey()][u.GetThreeKey()] =u;
   };

    template<typename U>
    typename std::enable_if<CheckHash2Key<U>::value,void>::type Push(U u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()] =u;
    };

   template<typename U>
   typename std::enable_if<CheckHash1Key<U>::value&&CheckVector<M>::value,void >::type Push(U u){
           (*this)[u.GetFirstKey()].push_back(u);
   };

   template<typename U>
   typename std::enable_if<CheckHash1Key<U>::value&&!CheckVector<M>::value,void >::type Push(U u){
            Print("map");
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

#endif
