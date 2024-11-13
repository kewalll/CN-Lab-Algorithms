#include <iostream>
using namespace std;

int main() {
    int bucket_size, output_rate, input_packet, storage = 0, time = 0;
    cout << "Enter bucket size: ";
    cin >> bucket_size;
    cout << "Enter output rate: ";
    cin >> output_rate;
    while (true) {
        cout << "\nAt time " << ++time << endl;
        cout << "Enter incoming packet size (0 to stop): ";
        cin >> input_packet;
        if (input_packet == 0) break;
        if (input_packet + storage > bucket_size) {
            cout << "Packet overflow! Dropped: " << input_packet + storage - bucket_size << endl;
            storage = bucket_size;
        } else {
            storage += input_packet;
            cout << "Packet added, Current storage: " << storage << endl;
        }
        if (storage >= output_rate) {
            cout << "Sent: " << output_rate << ", Remaining: " << storage - output_rate << endl;
            storage -= output_rate;
        } else {
            cout << "Sent: " << storage << ", Remaining: 0" << endl;
            storage = 0;
        }
    }
    return 0;
}
