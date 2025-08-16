#pragma once
#include "CommandEngine.h"

class Command {
protected:
	std::vector<std::string> output;
	enum Flags : uint16_t {
		DEFAULT = 1 << 1,
		INCORRECT_SYNTAX = 1 << 15,
		HELP = 1 << 9,
		VERBOSE = 1 << 2,
		LIST_ALL = 1 << 7,
		DIRECTORY = 1 << 8
	};
	uint16_t flags = DEFAULT;
public:
	bool hasFlag(Flags f) const { return flags & f;}
	void setFlag(Flags f) { flags |= f;  }
	void clearFlag(Flags f) { flags &= ~f; }
	~Command() = default;
	virtual void Execute(CommandEngine& ce) const = 0;
};