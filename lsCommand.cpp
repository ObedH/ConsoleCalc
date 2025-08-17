#include <iostream>
#include <algorithm>
#include <string>
#include "lsCommand.h"

std::filesystem::path lsCommand::getHomeDir() const {
    #ifdef _WIN32
        char* buf = nullptr;
        size_t len = 0;
        if (_dupenv_s(&buf, &len, "USERPROFILE") == 0 && buf != nullptr) {
            std::filesystem::path home(buf);
            free(buf);
            return home;
        }
    #else
        const char* home = std::getenv("HOME");
        if (home) return std::filesystem::path(home);
    #endif
        return std::filesystem::current_path();
}

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
            for (const auto& entry : std::filesystem::directory_iterator(getHomeDir())) {

                if (!entry.path().filename().string().starts_with(".") || hasFlag(LIST_ALL)) {
                    if (entry.path().filename().string().starts_with(".")) {
                        if (std::filesystem::is_regular_file(entry.status())) {
                            cmdEngine.printLine("\033[31m" + entry.path().string() + "\033[0m");
                        }
                        else if (std::filesystem::is_directory(entry.status())) {
                            cmdEngine.printLine("\033[35m" + entry.path().string() + "\033[0m");
                        }
                        continue;
                    }
                    if (std::filesystem::is_regular_file(entry.status())) {
                        cmdEngine.printLine(entry.path().string());
                    }
                    else if (std::filesystem::is_directory(entry.status())) {
                        cmdEngine.printLine("\033[34m" + entry.path().string() + "\033[0m");
                    }
                }
                
            }
        }
        catch (const std::filesystem::filesystem_error& ex) {
            std::cerr << "\033[31mError: " << ex.what() << "\033[0m\n";
        }
    }
    else if (hasFlag(HELP)) {
        cmdEngine.printLine("Provides a list of files in the directory.");
    }
}