#include "PurgeItem.h"
/**
class for making objects that contains an items time and position in the grid.
Craig Pennell
*/
namespace Manage {
	PurgeItem::PurgeItem(time_t t, int index)
	{
		this->t = t;
		this->index = index;
	}

	int PurgeItem::getIndex() {
		return this->index;
	}

	time_t PurgeItem::getTime() {
		return this->t;
	}

	int PurgeItem::GetHashCode() {
		return this->index;
	}
}
