#include "ZoneManage.h"

bool ZoneManage::AddZoneGate(std::shared_ptr<ZoneGate> zoneGate)
{
	if(zoneGate == nullptr){
		return false;
	}

	int zoneID = zoneGate->_zoneID;
	_zoneGroup[zoneID].push_back(zoneGate);		

	return true;
}

bool ZoneManage::RemoveZone(int zoneID)
{
	auto it = _zoneGroup.find(zoneID);
	if(it!=_zoneGroup.end())
	{
		_zoneGroup.erase(it);
		return true;
	}
	return false;
}

bool ZoneManage::RemoveZoneGate(int zoneID,std::string gateIP)
{
	auto it = _zoneGroup.find(zoneID);
	if(it!=_zoneGroup.end())
	{
		for(auto its:it->second)
		{
			if(its->_zoneGateIP.compare(gateIP) == 0){
				its->_isValid = false;
				//it->second.erase(its);
				return true;
			}
		}
	}
	return false;
}
