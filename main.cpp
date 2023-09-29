#include <array>
#include <cstring>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fstream>

auto main(int argc, char** argv) -> int
{
    if (argc > 1) {
        std::string line = { "" };
        std::ifstream file(argv[1]);
        const char* delim = ",";
        std::array<std::string, 4> fields { "NAME", "YEAR", "LANG", "MAIL" };
        int i = {};

        if (file.is_open()) {
            while (std::getline(file, line)) {
                char* buf = &line[0];
                char* pline = strsep(&buf, delim);
                while (pline != NULL) {
                    fmt::print("{} : {}\n", fields[i], pline);
                    pline = strsep(&buf, delim);
                    ++i;
                    if (i > 3) {
                        fmt::print("-------\n");
                        i = 0;
                    }
                }
            }
            file.close();
        }
    } else {
        fmt::print(stderr, "use: {} file.csv\n", argv[0]);
    }

    return 0;
}
