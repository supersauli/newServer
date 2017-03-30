#ifndef __HELP_TEMPLATE_H__
#define __HELP_TEMPLATE_H__


template<typename T>
struct EmptyValue{
	T value;
};


/**
 * @brief 检查类型T 和 M 是否相同
 *
 * @tparam T
 * @tparam M
 */
template<typename T,typename M>
struct CheckType{
	typedef char YES;
	typedef YES NO[2];

	template<typename U>
		static NO& Check(U);

	static YES& Check(T);

	static const bool value = sizeof(Check(EmptyValue<M>::value)) == sizeof(YES);
};


template<class T>
struct error{
	enum{
		value =0,
	};
};
#endif
