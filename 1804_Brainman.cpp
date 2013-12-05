#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;
    for (int scenario=1; scenario<=t; ++scenario) {
        if (scenario > 1)
            puts("");
        printf("Scenario #%d:\n", scenario);
        int N;
        std::cin >> N;
        std::vector<int> elements(N);
        for (int i=0; i<N; ++i)
            std::cin >> elements[i];

        int k = 0;
        for (int i=0; i<N; ++i)
            for (int j=1; j<N-i; ++j)
                if (elements[j-1] > elements[j]) {
                    ++k;
                    std::swap(elements[j-1], elements[j]);
                }

        printf("%d\n", k);
    }
}
