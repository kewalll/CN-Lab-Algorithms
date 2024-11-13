#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int frames = 6;
    int N = 4;
    int count = 0;
    srand(time(NULL));

    bool acked[frames + 1] = {false};
    int i = 1;

    while (i <= frames) {
        for (int j = i; j < i + N && j <= frames; j++) {
            if (!acked[j]) {
                cout << "Sending Frame " << j << endl;
                count++;
            }
        }

        for (int j = i; j < i + N && j <= frames; j++) {
            if (!acked[j]) {
                int flag = rand() % 2;
                if (flag) {
                    cout << "Acknowledgment received for Frame " << j << endl;
                    acked[j] = true;
                } else {
                    cout << "Frame " << j << " not acknowledged, will retransmit." << endl;
                }
            }
        }

        while (i <= frames && acked[i]) {
            i++;
        }

        cout << endl;
    }

    cout << "Total number of transmissions: " << count << endl;
    return 0;
}
