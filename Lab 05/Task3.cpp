#include <iostream>
using namespace std;

int sumTail(int n, int total = 0) {
    if (n == 0)
        return total;
    return sumTail(n - 1, total + n);
}

int sumNonTail(int n) {
    if (n == 0)
        return 0;
    return n + sumNonTail(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Tail Recursion Sum (1 to " << num << "): " << sumTail(num) << endl;
    cout << "Non-Tail Recursion Sum (1 to " << num << "): " << sumNonTail(num) << endl;

    return 0;
}

/*
Difference:
- In tail recursion (sumTail), the recursive call is the last operation,
  so no pending operations remain and the stack can be optimized or reused.
- In non-tail recursion (sumNonTail), operations (addition) are performed
  after the recursive call returns, so each call must remain on the stack
  until its child call completes, leading to deeper stack usage.
*/
