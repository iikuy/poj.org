#include <string>
#include <iostream>
#include <vector>

typedef std::vector<std::string> Table;

Table table;

bool start_of_across(int r, int c) {
    return c == 0 || table[r][c-1] == '*';
}

bool start_of_down(int r, int c) {
    return r == 0 || table[r-1][c] == '*';
}

std::string across_string(int r, int c) {
    std::string ret;
    while (c < table.front().size() && table[r][c] != '*')
        ret.push_back(table[r][c++]);
    return ret;
}

std::string down_string(int r, int c) {
    std::string ret;
    while (r < table.size() && table[r][c] != '*')
        ret.push_back(table[r++][c]);
    return ret;
}

int main() {
    int r, c;
    int puzzle=0;
    while (std::cin >> r && r) {
        std::cin >> c;
        if (puzzle)
            puts("");
        printf("puzzle #%d:\n", ++puzzle);


        table.resize(r);
        for (int j=0; j<r; ++j)
            std::cin >> table[j];

        typedef std::pair<int, std::string> entry;
        std::vector<entry> across;
        std::vector<entry> down;

        int k=0;
        for (int i=0; i<r; ++i)
            for (int j=0; j<c; ++j) {
                if (table[i][j] == '*')
                    continue;

                bool facross = start_of_across(i, j);
                bool fdown = start_of_down(i, j);
                if (facross || fdown) {
                    ++k;
                    if (facross)
                        across.push_back(std::make_pair(k, across_string(i, j)));
                    if (fdown)
                        down.push_back(std::make_pair(k, down_string(i, j)));
                }
            }

        puts("Across");
        for (int i=0; i<across.size(); ++i)
            printf("%3d.%s\n", across[i].first, across[i].second.c_str());
        puts("Down");
        for (int i=0; i<down.size(); ++i)
            printf("%3d.%s\n", down[i].first, down[i].second.c_str());

    }
}
