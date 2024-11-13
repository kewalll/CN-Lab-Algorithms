#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int frames = 6;
    int N = 4;
    int count = 0;
    srand(time(NULL));
    int i = 1;
    while (i <= frames) {
        int x = i;
        for (int j = i; j < i + N && j <= frames; j++) {
            cout << "Sending the Frame " << j << endl;
            count++;
        }
        for (int j = i; j < i + N && j <= frames; j++) {
            int flag = rand() % 2;
            if (flag) {
                cout << "\n Acknowledgment for Window Received whose first packet is " << j;
                x++;
            } else {
                cout << "\n Data Packet in Cumulative Acknowledgement Not Received whose first packet is " << j;
                cout << "\n Retransmitting the Same Window \n";
                break;
            }
        }
        cout << endl;
        i = x;
    }
    cout << "\n Total number of transmissions :" << count;
    return 0;
}
