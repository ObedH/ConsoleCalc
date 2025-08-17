#pragma once
#include <cstdlib>
#include <filesystem>
#include "Command.h"

class lsCommand : public Command
{
private:
	std::filesystem::path getHomeDir() const;
public:
	lsCommand(const std::vector<std::string>& args);
	void Execute(CommandEngine& engine) const override;
};