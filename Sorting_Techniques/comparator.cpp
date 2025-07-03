// 1. Using a Free Function
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}
sort(arr.begin(), arr.end(), cmp);
// Use static bool cmp(){} if using it inside a class as stl algorithms expects a regular function pointer or callable, not a member function pointer.
----------------------------------------------------------------------------------------------------------


// 2. Using Lambda Function (Inline with std::sort) — Most Common
sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
});

auto cmp = [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
};
sort(arr.begin(), arr.end(), cmp);

// Lambda Function Syntax
// [capture](parameters) -> return_type {
//     function_body
// }
// Capture Clause
// []	Capture nothing
// [=]	Capture all external variables by value
// [&]	Capture all external variables by reference
// [x]	Capture x by value which is constant inside the lambda
// [x] mutable	Capture x by value but allow modification inside the lambda
// [&x]	Capture x by reference
----------------------------------------------------------------------------------------------------------


// 3. Using a Functor
// A functor (short for function object) is any object that can be called like a function.
// This is achieved by overloading the operator() in a class or struct.
struct Cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[1] < b[1];
    }
};
sort(arr.begin(), arr.end(), Cmp());

struct CmpUtil {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
};
sort(arr.begin(), arr.end(), CmpUtil::cmp);
// Avoids instance creation, no state needed.
// Does not rely on any member variables and runtime data to be stored inside object.
// static cant be used with operator() because operator is meant to be called on an object, not on class.
// const is used to ensure that the operator does not modify the state of the object. static functions cannot be const because they are not called on an instance of the class.
// const qualified functions cant be used when you need to change states inside the object.
----------------------------------------------------------------------------------------------------------

// Note:
// 🔹 NTTPs Lambdas work well with STL algorithms (like sort, find_if, etc.) because:
// 1. They are short-lived
// 2. You can define them inline
// 3. They can capture local variables
// 4. STL algorithms accept any callable, including lambdas

// 🔹 TTPs Functors are ideal for STL containers (like set, map, priority_queue) because:
// 1. Containers require template parameters, which must be for its internal template logic
// 2. Functors are named types and work cleanly as template arguments
// 3. Lambdas are anonymous types and harder to use before C++20
// 4. We pass struct/class as type in containers as these constructs object internally while algorithms expect callable object or function pointer.
// 5. function of class should be const qualified to be used with containers.
----------------------------------------------------------------------------------------------------------


// STL Standard Comparator Functors
// These are defined in the <functional> header and include:    
// 1. std::less<T> - Less than comparison
// 2. std::greater<T> - Greater than comparison
    template<class T>
    struct greater {
        constexpr bool operator()(const T& a, const T& b) const {
            return a > b;
        }
    };
----------------------------------------------------------------------------------------------------------


struct MinHeap {
    bool operator()(int a, int b) const {
        return a > b;  // Reverse: smaller numbers come first
    }
};
priority_queue<int, vector<int>, MinHeap> pq;
