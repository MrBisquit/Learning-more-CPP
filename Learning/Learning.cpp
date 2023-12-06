#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_sum(int a, int b) { cout << a << " + " << b << " = " << a + b; }

void print_block(int n, char c) {
    {
        unique_lock<mutex> locker(mtx);
        for (int i = 0; i < n; i++)
        {
            cout << c;
        }
        cout << endl;
    }
}

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

class Resource {
public:
    Resource() { }
    ~Resource() { }
};

class MyClass {
    MyClass();
    MyClass(const MyClass& other); // Copy constructor
    MyClass& operator=(const MyClass& other); // Copy assignment operator
    ~MyClass(); // Deconstructor
};

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };

    vec.push_back(6); // Push back and add element I guess

    cout << "Vector contains: ";
    // Print out the numbers
    for (int x : vec) {
        cout << ' ' << x;
    }

    cout << endl;

    // Maps?

    map<string, int> m;

    m["one"] = 1;
    m["two"] = 2;

    cout << "Map contains: ";
    // Print out the map
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << ' ';
    }

    cout << endl;

    // Unordered map?

    unordered_map<string, int> um;

    um["one"] = 1;
    um["two"] = 2;

    cout << "Unordered map contains: ";
    // Print out the map
    for (const auto& pair : um) {
        cout << pair.first << ": " << pair.second << ' ';
    }

    cout << endl;

    // Sorting

    cout << endl << "Sorting" << endl;

    vector<int> nums = {};
    for (size_t i = 10; i > 4; i--)
    {
        nums.push_back(i); // This is my code, just to make the array for me lol
    }

    cout << "Original: ";
    // Prints the numbers out
    for (int num : nums) {
        cout << num << ' ';
    }

    sort(nums.begin(), nums.end());

    cout << endl << "Inverted: ";
    // Prints the numbers out
    for (int num : nums) {
        cout << num << ' ';
    }

    cout << endl;

    // Finding

    cout << endl << "Finding" << endl;

    vector<int> numsf = nums;
    
    // Print the numbers out
    for (int num : numsf) {
        cout << num << ' ';
    }

    // Find the number 9 in the array numsf and assign it to an automatic variable it
    auto it = find(numsf.begin(), numsf.end(), 9);

    if (it != numsf.end()) {
        cout << "Found 9 at position: " << (it - numsf.begin());
    }
    else {
        cout << "9 not found.";
    }

    cout << endl;

    // Modifying sequences

    cout << endl << "Modifying sequences" << endl;

    vector<int> numsm = { 5, 6, 7, 6, 8, 6, 9, 6, 10 };

    // Print the numbers out
    for (int num : numsm) {
        cout << num << ' ';
    }

    cout << endl;

    // Removes all of the 6s from the numsm array
    numsm.erase(remove(numsm.begin(), numsm.end(), 6), numsm.end());

    // Print the numbers out
    for (int num : numsm) {
        cout << num << ' ';
    }

    // Threading
    cout << endl << "Threading" << endl;
    
    thread t(print_sum, 3, 5);
    t.join();

    cout << endl;

    // Mutex and locks
    cout << endl << "Threading - Mutex and Locks" << endl;

    thread t1(print_block, 50, '*');
    thread t2(print_block, 50, '$');

    t1.join();
    t2.join();

    // Idioms (Resource allocation)

    cout << endl << "Idioms (Resource Allocation)" << endl;

    {
        Resource r = Resource();
        cout << "Allocated" << endl;
        r.~Resource();
        cout << "Deallocated";
    }

    return 0;
}