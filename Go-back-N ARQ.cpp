#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WINDOW_SIZE = 4;
const int TOTAL_FRAMES = 9;

bool simulateLoss() {
    // Simulate frame loss, return true for loss, false for no loss
    return rand() % 5 == 0; // 1 out of every 5 frames is lost
}

void sender() {
    vector<bool> ackReceived(TOTAL_FRAMES, false);
    srand(time(0));

    int base = 0;
    int nextSeqNum = 0;
    int totalFramesSent = 0;

    while (base < TOTAL_FRAMES) {
        // Send frames within window
        for (int i = base; i < min(base + WINDOW_SIZE, TOTAL_FRAMES); ++i) {
            if (!ackReceived[i]) {
                cout << "Sender: Sending frame " << i + 1 << endl;
                nextSeqNum = i + 1;
                totalFramesSent++;
            }
        }

        // Simulate acknowledgment reception
        if (!simulateLoss()) {
            cout << "Receiver: Acknowledgment received for frames " << base + 1 << " to " << nextSeqNum << endl;

            // Mark frames as acknowledged
            for (int i = base; i < nextSeqNum; ++i) {
                ackReceived[i] = true;
            }

            // Move window
            base = nextSeqNum;
        } else {
            cout << "Sender: Frame(s) lost, no acknowledgment received." << endl;
        }
    }

    cout << "Total frames sent: " << totalFramesSent << endl;
}

int main() {
    sender();
    return 0;
}
