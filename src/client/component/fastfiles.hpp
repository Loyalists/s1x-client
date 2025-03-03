#pragma once

#include "game/game.hpp"

namespace fastfiles
{
	std::string get_current_fastfile();

	bool exists(const std::string& zone);

	void enum_assets(game::XAssetType type, const std::function<void(game::XAssetHeader)>& callback, bool include_override);
}
