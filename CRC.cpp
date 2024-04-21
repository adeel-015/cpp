#include <iostream>
#include <bitset>

using namespace std;

// Calculate CRC using XOR operation
unsigned int calculateCRC(unsigned int message, unsigned int divisor) {
  // Initialize CRC to 0
  unsigned int crc = 0;

  // Iterate over each bit in the message
  for (int i = 31; i >= 0; i--) {
    // Check if the current bit in the message is 1
    if ((message >> i) & 1) {
      // XOR the current bit in the message with the corresponding bit in the divisor
      crc ^= divisor << i;
    }
  }

  // Return the calculated CRC
  return crc;
}

int main() {
  // Define the message and the divisor
  unsigned int message = 0b110100110111;
  unsigned int divisor = 0b10011;

  // Calculate the CRC
  unsigned int crc = calculateCRC(message, divisor);

  // Convert the CRC to a bitset for easy display
  bitset<32> crc_bitset(crc);

  // Print the original message, the divisor, and the calculated CRC
  cout << "Message: " << bitset<32>(message) << endl;
  cout << "Divisor: " << bitset<32>(divisor) << endl;
  cout << "CRC: " << crc_bitset << endl;

  return 0;
}
