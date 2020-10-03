### This is tutorial of stress testing a C++ program

Sometimes when your most optimized program fail on some test cases during a contest and you don't have any idea what is going on then you don't just simply code a 
whole new program, you try some test cases and check manually but you are not going to do this manually because you know bruteforce version of this program and you're
sure your bruteforce solution is going to work.

## Setup
You need 3 cpp file, code.cpp, gen.cpp, brute.cpp and one bash script file. 
Note:You can rename these files anything you want.

### code.cpp
Your code with bugs.

### brute.cpp
Your bruteforce version of program

### gen.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
// Random n numbers between l and r
void num(int l, int r, int n) {
  for (int i = 0; i < n; ++i) {
    cout << rand(l, r) << " ";
  }
}

// Random n string number b/w l and r
void string_num(int l, int r, int n) {
  for (int i = 0; i < n; ++i) {
    cout << to_string(rand(l, r));
  }
}

// Random n real numbers between l and r with dig decimal places
void real(int l, int r, int dig, int n) {
  for (int i = 0; i < n; ++i) {
    cout << rand(l, r) << "." << rand(0, pow(10, dig) - 1) << " ";
  }
}
// Random n strings of length l
void str(int l, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      int v = rand(1, 150);
      if (v % 3 == 0)
        cout << (char)rand('a', 'z');
      else if (v % 3 == 1)
        cout << (char)rand('A', 'Z');
      else
        cout << rand(0, 9);
    }
    cout << " ";
  }
}
// Random n strings of max length l
void strmx(int mxlen, int n) {
  for (int i = 0; i < n; ++i) {
    int l = rand(1, mxlen);
    for (int j = 0; j < l; ++j) {
      int v = rand(1, 150);
      if (3 % 3 == 0)
        cout << (char)rand('a', 'z');
      else if (v % 3 == 1)
        cout << (char)rand('A', 'Z');
      else
        cout << rand(0, 9);
    }
    cout << " ";
  }
}
// Random tree of n nodes
void tree(int n) {
  int prufer[n - 2];
  for (int i = 0; i < n; i++) {
    prufer[i] = rand(1, n);
  }
  int m = n - 2;
  int vertices = m + 2;
  int vertex_set[vertices];
  for (int i = 0; i < vertices; i++)
    vertex_set[i] = 0;
  for (int i = 0; i < vertices - 2; i++)
    vertex_set[prufer[i] - 1] += 1;
  int j = 0;
  for (int i = 0; i < vertices - 2; i++) {
    for (j = 0; j < vertices; j++) {
      if (vertex_set[j] == 0) {
        vertex_set[j] = -1;
        cout << (j + 1) << " " << prufer[i] << '\n';
        vertex_set[prufer[i] - 1]--;
        break;
      }
    }
  }
  j = 0;
  for (int i = 0; i < vertices; i++) {
    if (vertex_set[i] == 0 && j == 0) {
      cout << (i + 1) << " ";
      j++;
    } else if (vertex_set[i] == 0 && j == 1)
      cout << (i + 1) << "\n";
  }
}
signed main() {

  int t = rand(1, 3);
  cout << t << endl;
  for (int i = 0; i < t; i++) {
    int n = rand(1,10);
    cout << n << endl;
    for(int i=0;i<n;i++){
        cout << rand(1,n) << " ";
    }
    cout << endl;
  }
}
```
You need to change main() function according to you input.
eg. (int t = rand(l,r)) = number of test cases.
(int n = rand(l,r)) = number of elements in array.
(rand(l,r)) = array elements.

### bash.sh
```python
set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
```
## Usage
Make sure your all files mentioned above is in same folder and you generated test cases according to input and printed them. Then open terminal and run
```python
bash bash.sh
```

If your code have bug(assuming your bruteforce solution is 100% correct) then it will stop running as soon as it find a test case where your actual program failed 
and print it  out in terminal. If your code is bugless then it will run infinity times and this is how you know you code is fixed now.

```python
Note: Try to make big test case gen.cpp in the case you program still give WA.
```
