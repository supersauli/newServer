#include "XmlFile.h"

bool XmlFile::InitXml(const char *fileName)
{

	if(fileName == nullptr){
		return false;
	}

	if(_doc != NULL){
		xmlFreeDoc(_doc);
	}
	_doc = xmlParseFile(fileName);

	if(_doc == nullptr){
		return false;
	}

	return true;
};


xmlNodePtr XmlFile::GetRootElement()
{
	CHECK_NULL_RETURN(_doc);
	return xmlDocGetRootElement(_doc);
}

xmlNodePtr XmlFile::GetChildNode(const xmlNodePtr node,const char* name)
{
	if(node == nullptr){
		return nullptr;
	}
	xmlNodePtr cur = node->xmlChildrenNode;
	do{
		if(cur == nullptr){
			break;
		}
	
		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name)))	
		{
			return cur;	
		}
	
	
		cur = cur->next;
	
	}while(true);

	return nullptr;

}

xmlNodePtr XmlFile::GetRootElement(const char* name)
{

		CHECK_NULL_RETURN(_doc);
		_cur = xmlDocGetRootElement(_doc);
		CHECK_NULL_RETURN(_cur);
		
		do
		{
			if(!xmlStrcmp(_cur->name, reinterpret_cast <const xmlChar*>(name))){
					return _cur;
			}
			 _cur = _cur->xmlChildrenNode;

			 if(_cur == nullptr){
				 break;
			 }
		}while(true);


	return nullptr;
}


xmlNodePtr XmlFile::GetNode(const xmlNodePtr node,const char*name)
{
	xmlNodePtr cur = node;

	do{
		if(cur == nullptr){
			break;
		}

		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name))){
			return cur;
		}
	cur = cur->next;	
	}while(true);

	return nullptr;

}




const char* XmlFile::GetNodeAttrStr(const xmlNodePtr node,const char*attrName)
{

	auto attrPtr = node->properties;
	while (attrPtr != nullptr)
	{
		if (!xmlStrcmp(attrPtr->name,BAD_CAST attrName))
		{
			return (char*) (xmlGetProp(node, BAD_CAST attrName));
		}
		attrPtr = attrPtr->next;
	}


	return nullptr;
}

void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,DWORD&value,DWORD defaultValue )
{

	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr)
	{
		value = atoi(rValue);
	}
	else
	{
		value = defaultValue;
	}


}



void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,std::string&value,std::string defaultValue)
{

	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = reinterpret_cast<const char*>(rValue);
	}
	else
	{
		value = defaultValue;
	}

}

void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,float &value,float defaultValue)
{
	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = atof(rValue);
	}
	else
	{
		value = defaultValue;
	}
}

void XmlFile::GetNodeValue(const xmlNodePtr node,const char*name,double &value,double defaultValue)
{
	auto rValue = GetNodeAttrStr(node,name);
	if(rValue != nullptr){
		value = strtod(rValue,nullptr);
	}
	else
	{
		value = defaultValue;
	}
}


xmlNodePtr XmlFile::GetNext(xmlNodePtr node)
{

	CHECK_NULL_RETURN(node);

	node = node->next;
	while(node !=nullptr)
	{
		if(node->type == XML_ELEMENT_NODE){
			return node;
		}
		node = node->next;
	}


	return nullptr;

}


