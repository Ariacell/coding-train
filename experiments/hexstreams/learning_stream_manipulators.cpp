#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
namespace hexatrigesimals {

inline std::string to_base36(int value) {
    if (value == 0) return "0";

    static constexpr char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool negative = value < 0;
    unsigned int v = negative ? -value : value;

    std::string result;
    while (v > 0) {
        result.push_back(digits[v % 36]);
        v /= 36;
    }

    if (negative)
        result.push_back('-');

    reverse(result.begin(), result.end());
    return result;
}

struct hexatrigesimal_proxy {
    explicit hexatrigesimal_proxy(ostream& os): os(os){}

    friend ostream& operator<<(hexatrigesimal_proxy const& h, int rhs) {
        return h.os << to_base36(rhs);
    }
private:
ostream& os;
};

struct hexatrigesimal_maker {} hexatrigesimal;
hexatrigesimal_proxy operator<<(ostream& os, hexatrigesimal_maker) {
    return hexatrigesimal_proxy(os);
}
}

int main() {
    // cout << "hello" << endl;
    // int i = 43;
    // stringstream ss;
    // ss << hexatrigesimals::hexatrigesimal << i;
    // string result = ss.str();
    // cout << result <<endl;

    int i = 13;
    int nsqr = i * i;
    int ncub = i * nsqr;


    stringstream hexss;
    hexss << uppercase << hex << nsqr; 
    stringstream triss;
    triss << hexatrigesimals::hexatrigesimal << ncub;
    hexss << triss.str();
    cout<< hexss.str() << endl;
}