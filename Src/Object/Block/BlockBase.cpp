#include "../../Manager/Generic/Resource.h"
#include "../../Manager/Generic/ResourceManager.h"
#include "BlockBase.h"

void BlockBase::Init(void)
{
	//‰æ‘œŠi”[
	auto& res = ResourceManager::GetInstance();

	blockImg_ = res.Load(ResourceManager::SRC::STONE_BLOCK).handleId_;
	lavaImg_ = res.Load(ResourceManager::SRC::LAVA_BLOCK).handleId_;
}
