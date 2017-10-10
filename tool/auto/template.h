#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#include <map>
#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include <typeinfo>
#include "Define.h"
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
struct Empty:std::false_type{};

template<typename T>
struct is_int:std::false_type{};

template<>
struct is_int<int>:std::true_type{};

template<typename T>
struct is_double:std::false_type{};

template<>
struct is_double<double>:std::true_type{};

template<typename T>
struct is_float:std::false_type{};

template<>
struct is_float<float>:std::true_type{};

template<typename T>
struct is_int64:std::false_type{};

template<>
struct is_int64<INT64>:std::true_type{};

template<typename T>
struct is_char:std::false_type{};

template<>
struct is_char<char*>:std::true_type{};

template<>
struct is_char<const char*>:std::true_type{};















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
    static const constexpr bool value = sizeof(Check<T>(T())) == sizeof(Yes);
};

/**
 * @brief 查看T是不是map
 *
 * @tparam T
 */
template<typename T>
struct CheckM{

    template<typename U,typename M,typename Z>
    static Yes& Check(std::map<M,Z>);
    template <typename U>
    static No &Check(...);
    static const constexpr bool value = sizeof(Check<T>(T())) == sizeof(Yes);
    typedef T Type;
};

/**
 * @brief 查看T是不是map<A,map<B,C>>
 *
 * @tparam T
 */
template<typename T>
struct CheckMM{

    template<typename U,typename A,typename B,typename C >
    static Yes& Check(std::map<A,std::map<B,C>>);
    template <typename U>
    static No &Check(...);
    static const constexpr bool value = sizeof(Check<T>(T())) == sizeof(Yes);
    typedef T Type;
};

/**
 * @brief 查看T是不是map<A,map<B,map<C,D>>>
 *
 * @tparam T
 */
template<typename T>
struct CheckMMM{
    template<typename U,typename A,typename B,typename C ,typename D>
    static Yes& Check(std::map<A,std::map<B,std::map<C,D>>>);
    template <typename U>
    static No &Check(...);
    static const constexpr bool value = sizeof(Check<T>(T())) == sizeof(Yes);
    typedef T Type;
};



/**
 * @brief 查看T是不是map<A,std::vector<B>> 结构
 *
 * @tparam T
 */
template<typename T>
struct CheckMV{
    template<typename U,typename A,typename B>
    static Yes& Check(std::map<A,std::vector<B>>);
    template <typename U>
    static No &Check(...);
    static const constexpr bool value = sizeof(Check<T>(T())) == sizeof(Yes);
};

/**
 * @brief 查看T是不是map<A,map<B,std::vector<C>>> 结构
 *
 * @tparam T
 */
template<typename T>
struct CheckMMV{
	template<typename U,typename A,typename B,typename C>
	static Yes&Check(std::map<A,std::map<B,std::vector<C>>>);
	template<typename U>
	static No&Check(...);
	static const constexpr bool value = sizeof(Check<T>(T())) == sizeof(Yes);
};




DEFINE_CHECK_FUNC(Hash3Key);
DEFINE_CHECK_FUNC(Hash2Key);
DEFINE_CHECK_FUNC(Hash1Key);



template<class T,class M>
class smap:public std::map<T,M>
{
	using SelfType = std::map<T,M>;
	public:

    /**
     * @brief 3Key MMM
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash3Key<U>::value
        &&CheckMM<typename SelfType::mapped_type>::value
        ,void>::type 
            Push(const U&u){
                (*this)[u.GetFirstKey()][u.GetSecondKey()][u.GetThreeKey()] =u;
            }


    /**
     * @brief 
     *
     * @tparam U 3Key MMV
     * @param u
     *
     * @return 
     */
	template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash3Key<U>::value
        &&CheckMV<typename SelfType::mapped_type>::value
        ,void>::type 
        Push(const U&u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()].push_back(u);
        }

    /**
     * @brief 3Key MM
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash3Key<U>::value
        &&CheckM<typename SelfType::mapped_type>::value
        &&!CheckMV<typename SelfType::mapped_type>::value
        &&!CheckMM<typename SelfType::mapped_type>::value
        ,void>::type
            Push(const U&u){
                (*this)[u.GetFirstKey()][u.GetSecondKey()]=u;
            }

    /**
     * @brief 3Key MV
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash3Key<U>::value
        &&CheckV<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
            (*this)[u.GetFirstKey()].push_back(u);
        }


    /**
     * @brief 3Key M
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash3Key<U>::value
        &&!CheckV<typename SelfType::mapped_type>::value
        &&!CheckM<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
            (*this)[u.GetFirstKey()] = u;
        }

    /**
     * @brief 2Key MMV
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash2Key<U>::value
        &&CheckMV<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()].push_back(u);
        }


    /**
     * @brief 2Key MV
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash2Key<U>::value
        &&CheckV<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
            (*this)[u.GetFirstKey()].push_back(u);
        }


    /**
     * @brief 2Key MM
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash2Key<U>::value
        &&CheckM<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
            (*this)[u.GetFirstKey()][u.GetSecondKey()]=u;
        }

    /**
     * @brief 2Key M
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
	template<typename U>
		typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash2Key<U>::value
        &&!CheckM<typename SelfType::mapped_type>::value
        &&!CheckV<typename SelfType::mapped_type>::value
        ,void>::type
            Push(const U&u){
                (*this)[u.GetFirstKey()] = u;
            }

    /**
     * @brief 1Key M
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash1Key<U>::value
        &&!CheckV<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
            (*this)[u.GetFirstKey()]=u;
        }

    /**
     * @brief 1Key MV
     *
     * @tparam U
     * @param u
     *
     * @return 
     */
    template<typename U>
        typename std::enable_if<CheckM<SelfType>::value
        &&CheckHash1Key<U>::value
        &&CheckV<typename SelfType::mapped_type>::value
        ,void>::type
            Push(const U&u){
                (*this)[u.GetFirstKey()].push_back(u);
            }

};

template<typename T,typename... Args >
struct ResultOfType{
	using type  = decltype(std::declval<T>()(std::declval<Args>()...));
};
template<typename T,typename... Args >
using resultOfType = decltype(std::declval<T>()(std::declval<Args>()...));

/**
 * @brief 检查参数合法性
 *
 * @tparam U
 * @tparam Args
 */
template<typename U,typename ... Args>
struct CheckParamConsis{
	template<typename T,typename = resultOfType<T, Args...>>
	static constexpr std::true_type check(decltype(std::declval<Args>())...){return std::true_type{};}
	template<typename>
	static constexpr std::false_type check(...){return std::false_type{}; };
	typedef decltype(check<U>(std::declval<Args>()...)) type;
	static constexpr bool value = type::value;
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
    const int GetSecondKey()const {return sex;};
    const int GetThreeKey()const{return level;};

    std::string name;
    int sex;
    int level;



};

#endif
