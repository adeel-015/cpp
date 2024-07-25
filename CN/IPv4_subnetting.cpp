#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

string binary_to_dotted_decimal(string binary_address) {
    if (binary_address.length() != 32) {
        throw invalid_argument("Invalid binary IPv4 address: " + binary_address);
    }

    vector<string> octets;
    for (size_t i = 0; i < 32; i += 8) {
        octets.push_back(binary_address.substr(i, 8));
    }

    string dotted_decimal_address;
    for (size_t i = 0; i < octets.size(); ++i) {
        int decimal_octet = stoi(octets[i], nullptr, 2);
        dotted_decimal_address += to_string(decimal_octet);
        if (i < octets.size() - 1) {
            dotted_decimal_address += ".";
        }
    }

    return dotted_decimal_address;
}

string dotted_decimal_to_binary(string dotted_decimal_address) {
    size_t pos = 0;
    vector<string> decimal_octets;
    while ((pos = dotted_decimal_address.find('.')) != string::npos) {
        decimal_octets.push_back(dotted_decimal_address.substr(0, pos));
        dotted_decimal_address.erase(0, pos + 1);
    }
    decimal_octets.push_back(dotted_decimal_address);

    if (decimal_octets.size() != 4) {
        throw invalid_argument("Invalid dotted decimal IPv4 address: " + dotted_decimal_address);
    }

    string binary_address;
    for (const auto& octet : decimal_octets) {
        int decimal = stoi(octet);
        if (decimal < 0 || decimal > 255) {
            throw invalid_argument("Invalid dotted decimal IPv4 address: " + dotted_decimal_address);
        }
        string binary_octet = bitset<8>(decimal).to_string();
        binary_address += binary_octet;
    }

    return binary_address;
}

string get_class(string dotted_decimal_address) {
    int first_octet = stoi(dotted_decimal_address.substr(0, dotted_decimal_address.find('.')));
    if (first_octet >= 0 && first_octet <= 127) {
        return "Class A";
    } else if (first_octet >= 128 && first_octet <= 191) {
        return "Class B";
    } else if (first_octet >= 192 && first_octet <= 223) {
        return "Class C";
    } else {
        return "Invalid class";
    }
}

string get_netid(string dotted_decimal_address, string subnet_mask) {
    string binary_address = dotted_decimal_to_binary(dotted_decimal_address);
    string binary_subnet_mask = dotted_decimal_to_binary(subnet_mask);

    string network_id;
    for (size_t i = 0; i < 32; ++i) {
        network_id += to_string((binary_address[i] - '0') & (binary_subnet_mask[i] - '0'));
    }

    return binary_to_dotted_decimal(network_id);
}

string get_host_id(string dotted_decimal_address, string subnet_mask) {
    string binary_address = dotted_decimal_to_binary(dotted_decimal_address);
    string binary_subnet_mask = dotted_decimal_to_binary(subnet_mask);

    string host_id;
    for (size_t i = 0; i < 32; ++i) {
        if (binary_subnet_mask[i] == '0') {
            host_id += binary_address[i];
        } else {
            host_id += '0'; // Network ID bit, set to 0
        }
    }

    return binary_to_dotted_decimal(host_id);
}

int main() {
    string ip_address = "22.14.13.1";
    string subnet_mask = "255.0.0.0";

    cout << "Binary Representation of " << ip_address << ": " << dotted_decimal_to_binary(ip_address) << endl;
    cout << "Class of " << ip_address << ": " << get_class(ip_address) << std::endl;
    cout << "Network ID of " << ip_address << " with subnet mask " << subnet_mask << ": " << get_netid(ip_address, subnet_mask) << endl;
    cout << "Host ID of " << ip_address << " with subnet mask " << subnet_mask << ": " << get_host_id(ip_address, subnet_mask) << endl;

    return 0;
}
