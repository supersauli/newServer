#ifndef __SAVE_MANAGE_H__
#define __SAVE_MANAGE_H__

enum class AttrType
{
    ATTR_TYPE_FLOAT,
    ATTR_TYPE_INT,
    ATTR_TYPE_DOUBLE,
    ATTR_TYPE_STR,
    ATTR_TYPE_LONG_LONG, 
    ATTR_TYPE_MAP,
};

template<typename T>
AttrType GetType(T){
    return AttrType::ATTR_TYPE_STR;
}

template<>
AttrType GetType(int){
    return  AttrType::ATTR_TYPE_INT;
}

template<>
AttrType GetType(DWORD){
    return  AttrType::ATTR_TYPE_INT;
}


template<>
AttrType GetType(float){
    return  AttrType::ATTR_TYPE_FLOAT;
}

template<>
AttrType GetType(double){
    return  AttrType::ATTR_TYPE_DOUBLE;
}


template<>
AttrType GetType(const char*){
    return  AttrType::ATTR_TYPE_STR;
}
template<typename T,typename M>
AttrType GetType(std::map<T,M>){
   return AttrType::ATTR_TYPE_MAP; 
}

template<>
AttrType GetType(char*){
    return  AttrType::ATTR_TYPE_STR;
}








#endif
