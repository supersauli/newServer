#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#include <map>
#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include <typeinfo>
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






/**
 * @brief  查看T 类型是不是vector
 *
 * @tparam T
 */
template<typename T>
struct CheckV{
    template<typename U,typename M>
    static Yes& Check(std::vector<M>);
    template <typename U>
    static No &Check(...);
    static const constexpr int value = sizeof(Check<T>(T())) == sizeof(Yes);
};

/**
 * @brief 查看T是不是map<M,std::vector<Z>> 结构
 *
 * @tparam T
 */
template<typename T>
struct CheckMV{
    template<typename U,typename M,typename Z>
    static Yes& Check(std::map<M,std::vector<Z>>);
    template <typename U>
    static No &Check(...);
    static const constexpr int value = sizeof(Check<T>(T())) == sizeof(Yes);
};

template<typename T>
struct CheckM{

    template<typename U,typename M,typename Z>
    static Yes& Check(std::map<M,Z>);
    template <typename U>
    static No &Check(...);
    static const constexpr int value = sizeof(Check<T>(T())) == sizeof(Yes);
    typedef T Type;
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
        typename std::enable_if<CheckHash3Key<U>::value,void>::type Push(const U& u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()][u.GetThreeKey()] =u;
        };

    template<typename U>
        typename std::enable_if<CheckHash2Key<U>::value,void>::type Push(const U& u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()] =u;
        };


    template<typename U>
        typename std::enable_if<CheckHash1Key<U>::value&&CheckV<M>::value,void >::type Push(const U& u){
            (*this)[u.GetFirstKey()].push_back(u);
        };

    template<typename U>
        typename std::enable_if<CheckHash1Key<U>::value&&!CheckV<M>::value,void >::type Push(const U& u){
            (*this)[u.GetFirstKey()]=u;
        };

};





struct Friend{
    void Hash2Key();
    const std::string GetFirstKey()const {return name;}
    const int GetSecondKey()const{return age;}
    std::string  name;
    int age;
    int id{111};

};

struct User{

    void Hash1Key();
    const std::string GetFirstKey()const {return userName;}
    std::string userName;
};



struct Npc{
    
    void Hash3Key();
    const std::string GetFirstKey()const{return name;};
    const int GetSecondKey()const {return id;};
    const int GetThreeKey()const{return att;};

    std::string name;
    int id;
    int att;



};

#endif
