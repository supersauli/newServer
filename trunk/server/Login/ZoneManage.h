#ifndef __ZONE_MANAGE_H__
#define __ZONE_MANAGE_H__
#include "../sdk/sdk.h"

struct ZoneGate
{
	int _zoneID;
	std::string _zoneGateIP;
	bool _isValid;
	//人数
	int _userNumber;
};


/**
 * @brief 区服管理
 */
class ZoneManage
{
	public:
	
		




	private:

	
		/**
		 * @brief 增加区服网关
		 *
		 * @param zoneInfo
		 *
		 * @return 
		 */
	    bool AddZoneGate(std::shared_ptr<ZoneGate> zoneGate);

		/**
		 * @brief 移除区服网关 
		 *
		 * @param zoneID
		 * @param gateIP
		 *
		 * @return 
		 */
		bool RemoveZoneGate(int zoneID,std::string gateIP);
		/**
		 * @brief 移除区服
		 *
		 * @param zoneID
		 *
		 * @return 
		 */
		bool RemoveZone(int zoneID);

	private:

			/**
			 * @brief 区列表
			 */
		std::map<int ,std::vector<std::shared_ptr<ZoneGate> > > _zoneGroup;







};







#endif
