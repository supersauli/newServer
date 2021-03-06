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

//这个版本不能检测模板 但不需要提供参数
#define DEFINE_CHECK_FUNC(X) \
	template<typename T>  \
struct Check##X{  \
	private:\
			template<typename U> \
				static Yes& Check(decltype(&U::X));\
			template<typename U>   \
				static No &Check(...);   \
	public:\
		   static const constexpr int value = (sizeof(Check<T>(0))==sizeof(Yes)); \
};

//这个版本可以检测模板 但需要提供参数
#define DEFINE_CHECK_FUNC_EX(X) \
	template<typename T,typename ...Args>  \
struct Check##X##EX{  \
	private:\
			template<typename U> \
				static auto Check(std::nullptr_t)-> decltype(std::declval<U>().X(std::declval<Args>()...),std::true_type()); \
			template<typename U> \
				static auto Check(...) -> decltype(std::false_type()); \
	public:\
		   static const constexpr int value = decltype(Check<T>(0))::value ; \
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
 * @brief 根据对象有没有iterator 判断当前对象是不是容器
 *
 * @tparam T
 */
template<typename T>
struct is_containers
{
    template<typename U>
    static const Yes& Check(typename U::iterator*);
     template<typename U>
    static const No& Check(...);
    static const constexpr int value = sizeof(Check<T>(nullptr)) == sizeof(Yes);
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
using namespace std;

template<typename T>
typename std::enable_if<CheckM<T>::value,typename T::mapped_type>::type
ValueType(){
}

template<typename T>
typename std::enable_if<!CheckM<T>::value,typename T::value_type>::type
ValueType(){
}




/**
 * @brief 检测容器深度 如 map<int,int> 深度是1 map<int,std::vector<int>> 深度是2
 *
 * @tparam T
 *
 * @return 
 */
template<typename T>
constexpr typename std::enable_if<!is_containers<T>::value,int>::type
ContainersDepth(){
    return 0;
}

template<typename T>
 constexpr typename std::enable_if<is_containers<T>::value,int>::type
 ContainersDepth (){
	using valueType  = decltype(ValueType<T>());
    return ContainersDepth<valueType>()+1;
}





/**
 * @brief  对应深度类型 如map<int,std::vector<int>> 深度0时是map<int,std::vector<int>> 1 std::vector<int> 2是int
 *
 * @tparam depth
 * @tparam T
 */
template<int depth,typename T>
struct ContainersDepthType{
	using valueType  = decltype(ValueType<T>());
    using type = typename  ContainersDepthType<depth-1,valueType>::type;
};

template<typename T>
struct ContainersDepthType<0,T>{
	using type  = T;
};



DEFINE_CHECK_FUNC(Hash3Key);
DEFINE_CHECK_FUNC(Hash2Key);
DEFINE_CHECK_FUNC(Hash1Key);
DEFINE_CHECK_FUNC_EX(push_back);
DEFINE_CHECK_FUNC_EX(insert);
DEFINE_CHECK_FUNC(begin);



/**
 * @brief 判断容器深度
 *
 * @tparam T
 * @tparam expectDepth
 */
template<typename T,int expectDepth>
struct CheckContainersDepth
{
    static const constexpr  bool value = ContainersDepth<T>() == expectDepth;
};


/**
 * @brief 是否有push_back函数
 *
 * @tparam T
 * @tparam ...Args
 */
template<typename T,typename ...Args>
struct CheckPushBack{
    static const bool value = Checkpush_backEX<T,Args ...>::value;
};

/**
 * @brief 是否有insert函数
 *
 * @tparam T
 * @tparam ...Args
 */
template<typename T,typename ...Args>
struct CheckInsert{
    static const bool value = CheckinsertEX<T,Args ...>::value;
};

/**
 * @brief 是否是容器
 *
 * @tparam T
 */
template<typename T>
struct CheckContainers{
   static const constexpr bool value = is_containers<T>::value;
};


template<bool key ,typename ... FuncList>
struct CheckFunc{
 static const constexpr bool value =  CheckFunc<key,FuncList...>::value;
};

template<typename ... FuncList>
struct CheckFunc<false,FuncList ...>{
 static const constexpr bool value =  false;
};
template<typename ... FuncList>
struct CheckFunc<true,FuncList ...>{
 static const constexpr bool value =CheckFunc<true,FuncList...>::value;
;
};



//template<typename T>
//struct CheckFF{
//    template<typename U>
//    static typename  std::enable_if<CheckM<U>::value,std::true_type>::type
//        Check();
//    template<typename U>
//    static typename std::enable_if<!CheckM<U>::value,std::false_type>::type
//        Check();
//    static constexpr const auto  type = decltype(Check<T>());
//
//};
//




template<int depth, typename T,typename IT>
struct CheckIt{
    template<typename U>
   static  Yes&Check(typename ContainersDepthType<depth,U>::type::iterator);
    template<typename U>
   static  No&Check(...);
    static const constexpr bool value= sizeof(Check<T>(IT())) == sizeof(Yes);
};







template<class T,class M>
class smap:public std::map<T,M>
{
    public:
	using SelfType = std::map<T,M>;


	private:
	template <typename U>
		void Push3KeyMap(const U&u)
		{
			(*this)[u.GetFirstKey()][u.GetSecondKey()][u.GetThreeKey()] =u;
		}

	template <typename U>
		void Push2KeyMap(const U&u)
		{
			(*this)[u.GetFirstKey()][u.GetSecondKey()] = u;
		}

	template <typename U>
		void Push1KeyMap(const U&u)
		{
			(*this)[u.GetFirstKey()] = u;
		}

	template <typename U>
		void Push2KeyMapVec(const U&u)
		{
			(*this)[u.GetFirstKey()][u.GetSecondKey()].push_back(u);
		}

	template <typename U>
		void Push1KeyMapVec(const U&u)
		{
			(*this)[u.GetFirstKey()].push_back(u);
		}


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
        &&CheckContainersDepth<SelfType,3>::value
        &&CheckMM<typename SelfType::mapped_type>::value
        ,void>::type 
            Push(const U&u){
				Push3KeyMap(u);
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
        &&CheckContainersDepth<SelfType,3>::value
        &&CheckMV<typename SelfType::mapped_type>::value
        ,void>::type 
        Push(const U&u){
			Push2KeyMapVec(u);
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
        //&&!CheckMV<typename SelfType::mapped_type>::value
        //&&!CheckMM<typename SelfType::mapped_type>::value
        &&CheckContainersDepth<SelfType, 2>::value
        ,void>::type
            Push(const U&u){
				Push2KeyMap(u);
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
			Push1KeyMapVec(u);
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
		&&!CheckContainers<typename SelfType::mapped_type>::value
    //    &&!CheckV<typename SelfType::mapped_type>::value
     //   &&!CheckM<typename SelfType::mapped_type>::value
        ,void>::type
        Push(const U&u){
			Push1KeyMap(u);
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
			Push2KeyMapVec(u);
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
			Push1KeyMapVec(u);
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
			Push2KeyMap(u);
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
		&&!CheckContainers<typename SelfType::mapped_type>::value
      //  &&!CheckM<typename SelfType::mapped_type>::value
       // &&!CheckV<typename SelfType::mapped_type>::value
        ,void>::type
            Push(const U&u){
				Push1KeyMap(u);
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
			Push1KeyMap(u);
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
        &&CheckContainersDepth<SelfType,2>::value
        ,void>::type
            Push(const U&u){
				Push1KeyMapVec(u);
        }

// 删除操作





    template<typename U>
    typename   std::enable_if<!Empty<U>::value,void>::type
         Pop1Key(U&delIt){
        }
    template<typename U>
    typename   std::enable_if<CheckHash1Key<typename U::value_type>::value,void>::type
         Pop2Key(U&delIt){
                 cout<<"true pop"<<endl;
        }

    template<typename U>
        typename   std::enable_if<!CheckHash1Key<typename U::value_type>::value,void>::type
        Pop2Key(U&delIt){
         auto firstIt = find(delIt->GetFirstKey());
              if(firstIt != this->end())
              {
                  firstIt->erase(delIt);
              }


            cout<<"error pop"<<endl;
        }



    template<typename U>

        void Pop3Key(U&delIt){
            auto firstIt = find(delIt->GetFirstKey());
            if(firstIt != this->end())
            {
                auto secondIt = firstIt.find(delIt->GetSecondKey);
                if(secondIt!=firstIt.end())
                {
                    secondIt->erase(delIt);
                }
            }

        }





       template<typename U>
       typename std::enable_if<CheckIt<0,SelfType,U>::value,void>::type
       Del(U&delIt){
            this->erase(delIt);
       }

       template<typename U>
       typename std::enable_if<CheckIt<1,SelfType,U>::value
	   &&CheckContainersDepth<SelfType,3>::value
	   ,void>::type
       Del(U&delIt){
           auto firstIt = this->find(delIt->second.begin()->second.GetFirstKey());
           if(firstIt != this->end())
           {
               firstIt->second.erase(delIt);
           }
       }

       template<typename U>
       typename std::enable_if<CheckIt<1,SelfType,U>::value
	   &&CheckContainersDepth<SelfType,2>::value
	   ,void>::type
       Del(U&delIt){
           auto firstIt = this->find(delIt->GetFirstKey());
           if(firstIt != this->end())
           {
               firstIt->second.erase(delIt);
           }
       }





       template<typename U>
           typename std::enable_if<CheckIt<2,SelfType,U>::value,void>::type
           Del(U&delIt){
               auto firstIt = this->find(delIt->GetFirstKey());
               if(firstIt != this->end())
               {
                   auto secondIt = firstIt.find(delIt->GetSecondKey());
                   if(secondIt!=firstIt.end())
                   {
                       secondIt->second.erase(delIt);
                   }
               }
           }



       //    template<typename U>
//        typename std::enable_if<CheckM<SelfType>::value
//        &&!Empty<U>::value
//        &&CheckContainersDepth<SelfType, 1>::value
//        , void>::type
//        Del(U&delIt) {
//            if(std::is_same<typename ContainersDepthType<0,SelfType>::type::iterator ,U>::value)
//            {
//                Pop1Key(delIt);
//            } 
//
//
//        }
//    template<typename U>
//        typename std::enable_if<CheckM<SelfType>::value
//        &&!Empty<U>::value
//        &&CheckContainersDepth<SelfType, 2>::value
//        , void>::type
//        Del(U&delIt) {
//            if(std::is_same<typename ContainersDepthType<0,SelfType>::type::iterator ,U>::value)
//            {
//                cout<<"del111111"<<endl;
//               // Pop1Key(delIt);
//            }else if(std::is_same<typename ContainersDepthType<1,SelfType>::type::iterator ,U>::value)
//            {
//                cout<<"del22222"<<endl;
//                Pop2Key(delIt);
//            }
//        }
//
//    template<typename U>
//        typename std::enable_if<CheckM<SelfType>::value
//        &&!Empty<U>::value
//        &&CheckContainersDepth<SelfType, 3>::value
//        , void>::type
//        Del(U&delIt) {
//              if(std::is_same<typename ContainersDepthType<0,SelfType>::type::iterator ,U>::value)
//            {
//                this->erase(delIt);
//            }else if(std::is_same<typename ContainersDepthType<1,SelfType>::type::iterator ,U>::value)
//            {
//                auto firstIt = find(delIt->GetFirstKey());
//                if(firstIt != this->end())
//                {
//                    firstIt->erase(delIt);
//                }
//
//            }else if(std::is_same<typename ContainersDepthType<2,SelfType>::type::iterator ,U>::value)
//            {
//                            }
//
//        }
//
//


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


#endif
