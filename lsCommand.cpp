#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include "lsCommand.h"

lsCommand::lsCommand(const std::vector<std::string>& args) {
    if (std::find(args.begin(), args.end(), "-h") != args.end()) {
        setFlag(HELP);
        clearFlag(DEFAULT);
    }
    if (std::find(args.begin(), args.end(), "-v") != args.end()) {
        setFlag(VERBOSE);
    }
    if (std::find(args.begin(), args.end(), "-a") != args.end()) {
        setFlag(LIST_ALL);
    }
}

void lsCommand::Execute(CommandEngine& cmdEngine) const {
    if (hasFlag(DEFAULT)) {
        try {
            for (const auto& entry : std::filesystem::directory_iterator("./")) {
                if (std::filesystem::is_regular_file(entry.status())) {
                    cmdEngine.printLine(entry.path().string());
                }
            }
        }
        catch (const std::filesystem::filesystem_error& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
    else if (hasFlag(HELP)) {
        cmdEngine.printLine("Provides a list of files in the directory.");
    }
}