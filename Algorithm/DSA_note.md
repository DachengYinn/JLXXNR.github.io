# DSA on GFG
## Index
- [01_Analysis_Of_Algorithm](#01analysis-of-algorithm)
    - [01_01_Asymptotic_Analysis](#01--01--asymptotic-analysis)
    - [01_02_Analysis_Of_Loops](#0102-analysis-of-loops) 
    - [01_03_Analysis_Of_Recursion](#0103-analysis-of-recursion)
    - [01_04_Space_Complexity](#0104-space-complexity)
- [02_Mathematics](#mathematics)
    - [02_01_Count_Digits](#0201-count-digits)
    - [02_02_Palindrome_Numbers](#0202-palindrome-numbers)
    - [02_03_Factorial_Of_A_Number](#0203-factorial-of-a-number) 
    - [02_04_Trailing_Zeros_In_Factorial](#0204-trailing-zeros-in-factorial)
    - [02_05_GCD_or_HCF_For_Two_Numbers](#0205-gcd-or-hcf-for-two-numbers)
    - [02_06_LCM_Of_Two_Numbers](#0206-lcm-of-two-numbers)
    - [02_07_Check_For_Prime](#0207-check-for-prime)
    - [02_08_Prime_Factors](#0208-prime-factors)
    - [02_09_All_Divisors_Of_A_Number](#0209-all-divisors-of-a-number)
    - [02_10_Sieve_Of_Eratoshenes](#0210-sieve-of-eratoshenes)
    - [02_11_Computing_Power](#0211-computing-power)
    - [02_12_Iterative_Power](#0212-iterative-power)
- [03_Big_Magic](#big_magic)
- [04_Recursion](#recursion)
- [05_Arrays](#arrays)
- [06_Searching](#searching)
- [07_Sorting](#sorting)
- [08_Matrix](#matrix)
- [09_Hashing](#hashing)
- [10_Strings](#strings)
- [11_Linked_List](#linked_list)
- [12_Stack](#stack)
- [13_Queue](#queue)
- [14_Deque](#deque)
- [15_Tree](#tree)
- [16_Binary_Search_Tree](#binary_search_tree)
- [17_Heap](#heap)
- [18_Graph](#graph)
- [19_Greedy](#greedy)
- [20_Backtraking](#backtraking)
- [21_Dynamic_Programming](#dynamic_programming)
- [22_Trie](#trie)
- [23_Segment_And_Binary_Indexed_Tree](#segment_and_binary_indexed_tree)
- [24_Disjoint_Set](#disjoint_set)

- [25_Project_Examples](#project_examples)



## 01<p style="text-align: center;">Analysis Of Algorithm</p>

>Definition: 
Analysis of algorithms is a branch of computer science that studies the performance of algorithms, especially their run time and space requirements.

The practical goal of algorithm analysis is to predict the performance of different algorithms in order to guide design decisions.

The goal of algorithm analysis is to make meaningful comparisons between algorithms, but there are some problems:
 $\cdot$ The relative performance of the algorithms might depend on characteristics of the hardware, so one algorithm might be faster on Machine A, another on Machine B. The general solution to this problem is to specify a machine model and analyze the number of steps, or operations, an algorithm requires under a given model.
 $\cdot$ Relative performance might depend on the details of the dataset. For example, some sorting algorithms run faster if the data are already partially sorted; other algorithms run slower in this case. A common way to avoid this problem is to analyze the worst case scenario. It is sometimes useful to analyze average case performance, but that’s usually harder, and it might not be obvious what set of cases to average over.
 $\cdot$ Relative performance also depends on the size of the problem. A sorting algorithm that is fast for small lists might be slow for long lists. The usual solution to this problem is to express run time (or number of operations) as a function of problem size, and to compare the functions asymptotically as the problem size increases.

The good thing about this kind of comparison that it lends itself to simple classification of algorithms. For example, if I know that the run time of Algorithm A tends to be proportional to the size of the input, $n$, and Algorithm B tends to be proportional to $n^2$, then I expect A to be faster than B for large values of n.

### 01.01. Asymptotic Analysis
> Definition: Order of growth (of an algorithm) is **a set of functions** whose asymptotic growth behavior is considered **equivalent**. For example, 2n, 100n and n+1 belong to the same order of growth, which is written $O(n)$ in Big-Oh notation and often called linear because every function in the set grows linearly with n.

#### Why Performance Analysis? 
There are many important things that should be taken care of, like user-friendliness, modularity, security, maintainability, etc. Why worry about performance?  The answer to this is simple, we can have all the above things only if we have performance. So performance is like currency through which we can buy all the above things. Another reason for studying performance is – speed is fun! To summarize, performance == scale. Imagine a text editor that can load 1000 pages, but can spell check 1 page per minute OR an image editor that takes 1 hour to rotate your image 90 degrees left OR … you get it. If a software feature can not cope with the scale of tasks users need to perform – it is as good as dead. 

#### Better Algorithms
One naive way of doing this is – to implement both the algorithms and run the two programs on your computer for different inputs and see which one takes less time. There are many problems with this approach for the analysis of algorithms. 

It might be possible that for some inputs, the first algorithm performs better than the second. And for some inputs second performs better. 
It might also be possible that for some inputs, the first algorithm performs better on one machine, and the second works better on another machine for some other inputs.

Asymptotic Analysis is the big idea that handles the above issues in analyzing algorithms. In Asymptotic Analysis, we evaluate the performance of an algorithm in terms of input size (we don’t measure the actual running time). We calculate, how the time (or space) taken by an algorithm increases with the input size. 

For example, let us consider the search problem (searching a given item) in a sorted array. 

The solution to above search problem includes: 
Linear Search (order of growth is linear) 
Binary Search (order of growth is logarithmic). 

To understand how Asymptotic Analysis solves the problems mentioned above in analyzing algorithms, 

>  Let us say:  we run the Linear Search on a fast computer A and Binary Search on a slow computer B and pick the constant values for the two computers so that it tells us exactly how long it takes for the given machine to perform the search in seconds.  Let’s say the constant for A is 0.2 and the constant for B is 1000 which means that A is 5000 times more powerful than B. For small values of input array size n, the fast computer may take less time. But, after a certain value of input array size, the Binary Search will definitely start taking less time compared to the Linear Search even though the Binary Search is being run on a slow machine. 

[ Input Size ] = = = [ Running time on A ] = = = [ Running time on B ]
[ 10 ] = = = = = = = = [ 2 sec ] = = = = = = = = = = [ ~ 1 h ]
[ 100 ] = = = = = = = [ 20 sec ] = = = = = = = = = = [ ~ 1.8 h ]
[ 10 ^ 6 ] = = = = = = [ ~ 55.5 h ] = = = = = = = = = [ ~ 5.5 h ]
[ 10 ^ 9 ] = = = = = = [ ~ 6.3 years ] = = = = = = = = [ ~ 8.3 h ]

The reason is the order of growth of Binary Search with respect to input size is logarithmic while the order of growth of Linear Search is linear. 
So the machine-dependent constants can always be ignored after a certain value of input size. 

Running times for this example: 
Linear Search running time in seconds on A: 0.2 * n 
Binary Search running time in seconds on B: 1000*log(n) 

#### Does Asymptotic Analysis Always Work? 
Asymptotic Analysis is not perfect, but that’s the best way available for analyzing algorithms. For example, say there are two sorting algorithms that take 1000nLogn and 2nLogn time respectively on a machine. Both of these algorithms are asymptotically the same (order of growth is nLogn). So, With Asymptotic Analysis, we can’t judge which one is better as we ignore constants in Asymptotic Analysis. 

Also, in Asymptotic analysis, we always talk about input sizes larger than a constant value. It might be possible that those large inputs are never given to your software and an asymptotically slower algorithm always performs better for your particular situation. So, you may end up choosing an algorithm that is Asymptotically slower but faster for your software.

#### Big O Notation
> Definition: 
For $f(n) = O(g(n))$, if there exist constant $c$ where $(c > 0)$ and $n_{o}$ where $(n_{o}\geq0)$ such that $c\times{g(n)}\geq{f(n)}$ for all $n \geq n_{0}$.

$$C_{0}<n\cdot\log({\log{n}})<\log{n}< n^\frac{1}{3}<n^\frac{1}{2}<\textcolor{black}{\textbf{n}}<n^2<...<n^4<2^n<n^n$$

##### Example 1: 
For Algorithm $A(n) = 100n+10$ and Algorithm $B(n) = n^2+n+1$, performance  differs as $n$ changes:

```
|      n     |    A(n)    |    B(n)    |
----------------------------------------
|      1     |    110     |     3      |
|     10     |   1010     |    111     |
|    100     |   10010    |   10101    |
|   10000    |  10^6+10   |   10^8     |
```
In general, we expect an algorithm with a smaller leading term to be a better algorithm for large problems, but for smaller problems, there may be a crossover point where another algorithm is better. The location of the crossover point depends on the details of the algorithms, the inputs, and the hardware, so it is usually ignored for purposes of algorithmic analysis. But that doesn’t mean you can forget about it.

If two algorithms have the same leading order term, it is hard to say which is better; again, the answer depends on the details. So for algorithmic analysis, functions with the same leading term are considered equivalent, even if they have different coefficients.

##### Example 2: 
The worse case for following function is $C_{1}\sqrt{n}$, it is written as $O(\sqrt{n})$ in Big O notation.

```c++
bool IsPrimNumber(int x){
    int nx = x < 0 ? 0 : x;
    if(nx == 1) return false;
    if(nx == 2 || nx == 3) return true;
    if(nx % 2 == 0 || nx % 3 == 0) return false;
    for(int i = 5; i * i <= nx; i = i + 6)
        if(nx % i == 0 || nx % (i + 2) == 0) return false;
    return true;
}
```
#### Omega Notation
> Definition: 
For $f(n) = \Omega(g(n))$, if there exist constant $c$, where $c > 0$ and $n_{o}$ where $n_{o}\geq0$ such that $c\times{g(n)}\leq{f(n)}$ for all $n \geq n_{0}$.

##### Example 1: 
Sets of $f(n)$and their $\Omega(n)$: 
$${\{n^2, 2n^2+5, 1000n^2, 2n^3+n,...\}}\in\Omega(n^2)$$

$$\cup{\{n, 2n+5, 1000n, \log n+n,...\}}\in{\Omega(n)}$$

$$\cup{\{5000, 10^5, \log 12, 2n^0,...\}}\in{\Omega(1)}$$

#### Theta Notation
> Definition: 
For $f(n) = \theta(g(n))$, if there exist constants $c_{1}$, $c_{2}$ where $c_{1}>0$, $c_{2}>0$  and $n_{o}$ where $n_{o}\geq0$ such that $c_{1}\times{g(n)}\leq{f(n)}\leq{c_{2}\times{g(n)}}$ for all $n \geq n_{0}$.

Theta is the exact bound of a function, in this case, $f(n) = \theta(g(n)) = \Omega(g(n)) = O(g(n))$.

##### Example 1: 
Code to calculate $Nth$ fibonacci number will run exactly $N-2$ times:
```c++
template <typename T>
void foo(vector<T>& n){
    size_t ln = n.size();
    if (ln<1) return;
    n[0] = 1;
    if (ln <2) return;
    n[1] = 1;
    for (size_t i{2}; i < ln; ++i)
    {
        n[i] = n[i-1] + n[i-2];
    }
}
```

### 01.02. Analysis of Loops
#### Commom Loops
The complexity of func01 is $[f_{1}(n)=\theta(\frac{n}{c})]$, the complexity of func02 is $[f_{2}(n)=\theta(\log_{c}n)]$, whereas the complexity of func03 is $[f_{3}(n)=\theta(\log_{2}\log_{c}n)]$.

```c++
void func01(int n, int c){   
    for (std::size_t i{}; i <  n; i = i + c){
        ...
    }
}

void func02(int n, int c){   
    for (std::size_t i{1}; i <  n; i = i * c){
        ...
    }
}

void func03(int n, int c){   
    for (std::size_t i{2}; i <  n; i = std::pow(i, c)){
        ...
    }
}
```
#### Multiple Loops
For sequential loops, thier complexity adds up; for nested loops, their complexity multiplies; and for nested loops that increte based on outer loop, see example `func06()` and `func07()`:
```c++
void func01(int n){
    for(int i{}; i < n; ++i){...} //theta(n)
    for(int j{1}; j < ; j *=2){...} //theta(log(n))
    for(int k{1}; k<100; k+=6){...} //theta(1)
}
void func02(int n){
    for(int j{1}; j < ; j *=2){
        for(int k{1}; k<100; k+=6){
            for(int i{}; i < n; ++i){
                ...
            } //theta(n)
        } //theta(1)
    } //theta(log(n))
}//theta(n*log(n))

void func03(int n){
    for(int i{}; i < n; ++i){
        for(int j{}; j < n; ++j){
            ...
        } //theta(n)
    } //theta(n)
} //theta(n*n)

void func04(int n1, int n2){
    func02(n1); //theta(n1*log(n1))
    func03(n2); //theta(n2*n2)
} //theta(n1*log(n1) + n2*n2)

void func05(int n1, int n2){ //== func04(n1, n1)
    func02(n1); //theta(n1*log(n1))
    func03(n1); //theta(n1*n1)
} //theta(n1*n1)

void func06(int n, int c){
    for(int i{}; i < n; i += c){
        for (int j{}; j < i; j++;){
            ...
        } 
    } // theta(n/c)
} //theta(????)

void func07(int n, int c, int ex){
    //force exp > 2 to avoid that the loop runs forever
    int d = ex > 1 ? ex : 2; 
    for(int i{}; i < n; i += c){
        for (int j{1}; j < i; j*=d;){
            ...
        } 
    } // theta(n/c)
} //theta(????)
```
In `func07()`, the outer loop has a complexity of $\Theta(\frac{n}{c})$, the inside loop has a complexity of $\Theta(\log_{d}(n))$. We can count each term and add them up sequentially:
$$f(n) = \sum_{i=1}^{[\frac{n}{c}]}\log_{d}i$$
Comparing the result of `func07(90, 8, 2);` and `func07(90, 8, 3)`:
```
---------------------------------------------------------------------------
| d \ i  | 00 | 08 | 16 | 24 | 32 | 40 | 48 | 56 | 64 | 72 | 80 | 88 | 96 |
---------------------------------------------------------------------------
|   2^i  | nan| 08 | 16 | 32 | 32 | 64 | 64 | 64 | 64 | 128| 128| 128| 128|
|   3^i  | nan| 09 | 27 | 27 | 81 | 81 | 81 | 81 | 81 | 81 | 81 | 243| 243|
|  log2  | nan| 03 | 04 | 05 | 05 | 06 | 06 | 06 | 06 | 07 | 07 | 07 | 07 |
|  log3  | nan| 02 | 03 | 03 | 04 | 04 | 04 | 04 | 04 | 04 | 04 | 05 | 05 |
---------------------------------------------------------------------------
```

### 01.03. Analysis of Recursion
#### Introduction
>Difinition: 
Recursive function, in logic and mathematics, a type of function or expression predicating some concept or property of one or more variables, which is specified by a procedure that yields values or instances of that function by **repeatedly** applying a given relation or routine operation to known values of the function.

```c++
void func01(int n){
    if(n<=0) return;
    std::cout << "f1_01";
    func01( n / 2);
    std::cout << "f1_02";
    func01( n / 2);
    std::cout << "f1_03";
}

void func02(int n){
    if(n<=0) return;
    for ( int i = 0; i < n; i++) std::cout << "f2_01";
    func02( n / 2);
    std::cout << "f2_02";
    func02( n / 3);
    std::cout << "f2_03";
}

void func03(int n){
    if(n<=0) return;    
    std::cout << "f3_01";
    func03( n - 1);
}

```
#### Recursion Tree
Steps to draw a Recursive Tree: First we consider the recursion tree and compute total work done. Then we write non-recursive part as root of the tree and write the recursive part as children, and last we keep expanding until we see a pattern.

##### Example 1:
$T(n) = 2\times{T(n-1)+C_{1}}, T(1) = C_{2}.$
$ =2\times T(n-1) + C_{1}$
$ = 4\times T(n-2) + 2\times C_{1} + C_{1}$
$ = 8\times T(n-3) + 4\times C_{1} +2\times C_{1} + C_{1}$
$ = \dots$
$ = 2^{n-1} \times T(1)+ 2^{n-2} \times C_{1}+2^{n-3} \times C_{1}+ \dots + C_{1}$
$ = C_{2}\times 2^{n-1}  + C_{1}\times (2^{n-1}-1)$ 

$ = \Theta(2^n)$

##### Example 2:
$T(n) ={T(\frac{n}{2})+C_{1}}, T(1) = C_{2}.$
$ = T(\frac{n}{2^2}) + C_{1} + C_{1}$
$ = T(\frac{n}{2^3}) + 3\times C_{1}$
$ = T(\frac{n}{2^k}) + k\times  C_{1}$

as $[\frac{n}{2^k}]$ equals to 1, whereas $T(1) = C_{2}$ and $k = \log_{2}{n}$,

$T(n) = C_{2} + C_{1}\times\log_{2}{n}$

$ =\Theta(\log_{2}{n})$

##### Example 3:
$T(n) = 2\times {T(\frac{n}{2})+C_{1}}, T(1) = C_{2}.$
$ = 2^2\times T(\frac{n}{2^2}) + 2^1\times C_{1} + C_{1}$
$ = 2^3\times T(\frac{n}{2^3}) + 2^2\times C_{1} + 2\times C_{1} + C_{1}$
$ = 2^k\times T(\frac{n}{2^k}) + 2^{k-1}\times  C_{1}+\dots +  C_{1}$

as $[\frac{n}{2^k}]$ equals to 1, whereas $T(1) = C_{2}$ and $k = \log_{2}{n}$,

$T(n) = 2^k \times C_{2} + \frac{(k+1)\times k}{2}\times C_{1} $.
$ = C_{2} \times n + C_{1}\times \frac{(\log_{2}{n}+1)\times \log_{2}{n}}{2}$

$ =\Theta(n)$

##### Example 4: Upper Bound Using Recursive Tree
$T(n) = T(\frac{n}{2}) +T(\frac{n}{2^2}) + C_{1}\times n, T(1) = C_{2}.$
$ = (T(\frac{n}{2^{1+1}}) +T(\frac{n}{2^{1+2}}) +C_{1})+(T(\frac{n}{2^{2+1}}) +T(\frac{n}{2^{2+2}}) +C_{1})+C_{1}$
$= T(\frac{n}{2^{1+1+1}})+T(\frac{n}{2^{1+1+2}}) + C_{1} + \dots + T(\frac{n}{2^{1+2+2}})+ T(\frac{n}{2^{2+2+2}}) + C_{1} $
Term $T(n/2^k)$ grows slower than $T(n/4^k)$, when $[\frac{n}{4^k}] = 1$ whereas $T(1) = C_{2}$ and $k= \log_{4}n$, this branch would reach the end of recursion. Term $T(n/2^k)$ is however still in half way, and terms in between would reach $T(1)$ in a complex pattern, and makes it hard to find Exact.
For the slower term, it takes $k= \log_{2}n$ times, and there exist $T_{2}(n) = T_{2}(\frac{n}{2}) +T_{2}(\frac{n}{2})+C_{3}, T_{2}(1) = C_{2}$ that satisfy:
$O(T_{2}(n)) =O(\Theta(n)) \geq O(T(n))$.

##### Example 5: Upper Bound Using Recursive Tree
$T(n) = T(n-1) + T(n-2) + C_{1}, T(1) =C_{2}, T(0) = C_{3}.$
Let $T_{2}(n) = T_{2}(n-1)+ T_{2}(n-1) + C_{3}, T_{2}(1) =C_{4}, T_{2}(0) = C_{3}.$

$O(T_{2}(n))=O(\Theta(n))≥O(T(n)).$

### 01.04. Space Complexity
>Definition: 
Space complexity refers to the total amount of memory space used by an algorithm/program, including the space of input values for execution. Calculate the space occupied by variables in an algorithm/program to determine space complexity. However, people frequently confuse Space-complexity with auxiliary space.

#### Auxiliary Space
>Definition: 
Auxiliary space refers to the extra space or the temporary space that an algorithm uses. Space complexity is the total space taken up by the algorithm with respect to the input size. Space complexity includes auxiliary space as well as the space used by input. Space complexity = Auxiliary space + Input space.

##### Example 1:
```c++
int GetSum01(int n){
    return n*(n+1)/2;
}

int GetSum02(int n){
    int sum = 0;
    for(int i = 0; i<n; i++) sum += i;
    return sum;
}

int GetSum03(int n){
    return n < 1 GetSum03(n - 1) ?  0;
}
```
##### Example 2: Fibo
```c++
int func_fibo(int n){
    return (n == 0 || n==1 ) ? n : (func_fibo(n-1) + func_fibo(n-2));
} //Auxiliary Space Theta(1)

int func_fibo_arr(int n){
    int a[n+1]{0};
    a[1] = 1;
    for(int i=2;i<=n; i++){
        a[n] = a[n-1] + a[n-2];
    }
}  //Auxiliary Space O(n)

int func_fibo_t(int n){
    if(n == 0 || n == 1) return n;
    int a = 0, b = 1, c = -1;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}//Auxiliary Space Theta(1)
```

## 02<p style="text-align: center;">Mathematics</p>
### 02.01. Count Digits
```c++
int CountDigit(int n){
    int i =0;
    while(n > 0){
        n/=10;
        i++;
    }
    return i;
}

```
### 02.02. Palindrome Numbers
>Definition: Palindrome number is a number that remains the same when its digits are reversed. In other words, it has reflectional symmetry across a vertical axis.

[Function_Link_GetDigit](#0201-count-digits)
```c++
#include <math.h>

int GetDigit(int number, int index){
    if (number < std::pow(10, index) )return -1;
    return  int((number *std::pow(10, - index)))%10;
}

bool IsPalindromeNumber(int n){
    int count_num = CountDigit(n);
    bool result = true;
    for(int i{}; i < count_num/2; i++){
        result = result && (GetDigit(n, i)==GetDigit(n, count_num - i - 1));
    }
    return result;
}
```
### 02.03. Factorial Of A Number
```c++
unsigned long long FactorialOf(int n){
    return n<=1 ? 1 : n* Factorial(n-1);
} 
```
### 02.04. Trailing Zeros In Factorial
> Definition: Trailing zeros in fractorial is to count how many zeros are there in the factorial of a given number. For example when n = 10, FactorialOf(10) = 362800, and there are 2 zeros. The problem is when n grows say n = 20, the factorial will be 90 digits long and it quickly overflows the number type.
```c++
int TrailingZeroInFactorial(int n){
    int m5 =0;
    for(int i = 5; i < n; i*=5){
        m5 += n/i; // Counting 5s 25s 125s....
    }
    return m5;
} //Theta(log_{5} n)
```
### 02.05. GCD or HCF For Two Numbers
> Definition: The greatest common divisor (GCD) of two or more numbers is the greatest common factor number that divides them, exactly. It is also called the highest common factor (HCF). For example, the greatest common factor of 15 and 10 is 5, since both the numbers can be divided by 5.
```c++
int GreatestCommonDivision_Simple(int a, int b){
    int gcd = a < b ? a : b;
    while (gcd > 0){
        if  (a % gcd == 0 && b % gcd == 0) break;
        gcd--;
    }
    return gcd;
}

//Euclid's division algorithm
int GreatestCommonDivision_Fast(int a, int b){
    if (a<b) std::swap(a, b);
    return (b == 0) ? a : GreatestCommonDivision_Fast(b, a%b);
} //O(log(min(a, b)))
```
#### Visualised Euclid Division
We use $=$ to  represent a number with its length:
+ $$26 ===============================$$$$6======$$
+ `GreatestCommonDivision(26, 6);`
+ $$26 ===============================$$$$6======6======6======6======$$ leaving $2==$
+ `GreatestCommonDivision(6, 2);`
+ $$6======$$$$2==2==2==$$
+ `GreatestCommonDivision(2, 0); return 2;`

For the `a%b` part of the calculation, each `b` shares the same factor, so the `GCD(a, b)` task is equivalent to `GCD(b, a%b)`.

### 02.06. LCM Of Two Numbers
> Definition The Least Common Multiple (LCM) is also referred to as the Lowest Common Multiple (LCM) and Least Common Divisor (LCD). For two integers a and b, denoted LCM(a,b), the LCM is the smallest positive integer that is evenly divisible by both a and b. For example, LCM(2,3) = 6 and LCM(6,10) = 30.
The LCM of two or more numbers is the smallest number that is evenly divisible by all numbers in the set.
```c++
int LeastCommonMultiple_Simple(int a, int b){
    int lcm = a > b ? a : b;
    while (1){
        if ((lcm % a == 0) && (lcm % b == 0)) return lcm;
        lcm++;
    }
    return lcm;
}//O(a * b - max(a, b))

int LeastCommonMultiple_Fast(int a, int b){
    return a * b / GreatestCommonDivision_Fast(a, b);
}//O(log(min(a, b)))
```
#### Relationship Between GCD And LCM
For number $a = fc_{1}\times fc_{2} \times \dots \times fc_{n} \times fa_{1}\times \dots fa_{n}$, 
and $b = fc_{1}\times fc_{2} \times \dots \times fc_{n} \times fb_{1}\times \dots fb_{n}$.
Number a, b have common factor $fc_{i}$s and each unique $fa_{i}$ s, and $fb_{i}$ s.
GCD(a, b) $ = fc_{1}\times fc_{2} \times \dots \times fc_{n} = \prod_{1}^n fc$,
LCM(a, b) $ = \prod_{1}^n fc \times \prod_{1}^n fa \times \prod_{1}^n fb$;
$ a * b = \prod_{1}^n fc \times \prod_{1}^n fc \times \prod_{1}^n fa \times \prod_{1}^n fb = $ GCD(a, b) $*$ LCM(a, b);

### 02.07. Check For Prime
> Definition: A prime number is a number that can only be divided by itself and 1 without remainders.
```c++
bool IsPrime_Simple(int n){
    if (n <= 1) return false;
    for (int i = 2; i * i < n; i++){
        if (n % i == 0) return false;
    }
    return true;
} //O(sqrt(n))

bool IsPrime_Optimized(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 ||  n % 3 == 0) return false;
    for (int i = 5; i * i < n; i += 2){ //skip even numbers [1/2]
        if (n % i == 0) return false;
    }
    return true;
} //O(sqrt(n))

bool IsPrime_Fast(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 ||  n % 3 == 0) return false;
    for (int i = 5; i * i < n; i += 6){ //skip evens[3] and n%3 == 0 [2]
        // the even n%3==0 would be counted twice [4/6]
        if (n % i == 0 || n % (i + 2) == 0) return false; //check the other [2/6]
    }
    return true;
}
```
### 02.08. Prime Factors
```c++
void PrimeFactor_Simple(vector<int>& factors, int n){
    for(int i = 2; i < n; i++){ //O(n)
        if(IsPrime(i)){
            int m = i;
            while(n % m == 0){ //O(log(n))
                factors.push_back(i);
                m *= i;
            }
        }
    }
} //O(n*log(n))

void PrimeFactor_Optimized(vector<int >& factors, int n){
    if(n <= 1) return;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factors.push_back(n);
}


void PrimeFactor_PrimesOnly(vector<int>& factors, int n){
    if(n <= 1) return;
    while(n % 2 == 0){
        factors.push_back(2);
        n /= 2;
    }
    while(n % 3 == 0){
        factors.push_back(3);
        n /= 3;
    }
    for(int i = 5; i * i <= n; i + =6){
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
        while(n % (i + 2) == 0){
            factors.push_back(i + 2);
            n /= i + 2
        }
    }
    if(n > 3) factors.push_back(n);
}
```
### 02.09. All Divisors Of A Number
```c++
void GetAllDivisors(std::vector<int>& divisors, int n){
    for(int i = 1; i * i < n; i++){ //break into 2 parts
        if(n%i==0){
            divisors.push_back(i);
            if(i != n / i)
                divisors.push_back(n / i);
        }
    }
}
```
### 02.10. Sieve Of Eratoshenes
> Definition: In a realm where numbers hold secrets, a captivating challenge awaits, which is to, Find all the Prime Numbers less than or equal to a given Number !!!
Problem Description: Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
Example: 
Input : n =10
Output: 2 3 5 7 
Input : n = 20 
Output: 2 3 5 7 11 13 17 19
Sieve of Eratosthenes is the algorithm to find all the prime numbers less than or equal to a given integer n. The algorithm terminates, all the numbers in the list that are not marked are prime
Let n = 50
We create a boolean array of size n+1 from 0 to n, i.e. 0 to 50 in this case.Time Complexity: O(n*log(log(n)))
Auxiliary Space: O(n)

[FunctionLink](#0207-check-for-prime)
```c++
void Sieve_Simple(int n){
    std::vector<bool> prime_map(n + 1, true);
    for(int i = 2; i * i <= n; i++){
        if(IsPrime(i)){ // check for a prime
            for(int j = 2 * i; j < = n; j += i){
                 // clear all the n-timed-numbers of this prime
                prime_map[j] = false;
            }
        }
    }
    for(int m = 2; m <= n; m++){
        if(prime_map[m]) std::cout << m << '\n'; 
    }
}
```
to optimize the alg, we move the second loop ahead of the first loop's scope
1st Loop: $1, 2, 3, ..., i, i+1, ..., \textbf{i*i}$; 
2nd Loop: $i, i*2, ..., \textbf{i*i}, i*(i+1), ..., n$;
```c++
void Sieve_Fast(int n){
    std::vector<bool> prime_map(n+1, true);
    for(int i = 2; i <= n; i++){
        if(IsPrime(i)){
            for(int j = i * i; j <= n; j += i){
                prime_map[j] = false;
            }
        }
    }
}
```
### 02.11. Computing Power

```c++
long long PowerOf_Simple(int base, int exp){
    long long result = 1;
    for(int i = 0; i<exp; i++){
        result *= base;
    }
    return result;
}
// Theta(n)

template <typename T = int, typename RT = long long>
RT PowerOf_Opti(T base, T exp){
    if(exp < 0) return 1.0/ PowerOf_Opti<double>(base, -exp);
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(static_cast<long long>(exp) % 2 == 0){
        RT p = PowerOf_Opti(base, exp / 2);
        return p * p;
    }else{
        return base*PowerOf_Opti(base, exp - 1);
    }
}

long long PowerOf_Fast_Cal(int base, long long exp){
    //using bit wise ops to break down exp
    long long result = 1;
    long long mask = 0x1;
    long long base_bit = base;
    while(exp >= mask){
        if(exp & mask){
            result *= base_bit;
        }
        mask = mask << 1;
        base_bit = base_bit * base_bit;
    }
    return result;
}

template <typename T, typename RT>
RT PowerOf_Fast(T base, T exp){
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp < 0) return 1.0/PowerOf_Fast_Cal(base, -exp);
    return PowerOf_Fast_Cal(base, exp);
}
```
## 03<p style="text-align: center;">Big Magic</p>
### 03.01. Bitwise Algorithms Basics
> Deffinition: The Bitwise Algorithms are used to perform operations at bit-level or to manipulate bits in different ways. The bitwise operations are found to be much faster and are some times used to improve the efficiency of a program. For example: To check if a number is even or odd. This can be easily done by using Bitwise-AND(&) operator. If the last bit of the operator is set than it is **odd** otherwise it is **even**. Therefore, if num & 1 not equals to zero than num is odd otherwise it is even.

#### Bitwise Operators
> Definition: The **operators** that works at Bit level are called bitwise operators. In general there are six types of Bitwise Operators as described below:
+ & (bitwise AND) Takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1. Suppose A = 5 and B = 3, therefore `A & B` = 1.
+ | (bitwise OR) Takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. Suppose A = 5 and B = 3, therefore `A | B `= 7.
+ ^ (bitwise XOR) Takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. Suppose A = 5 and B = 3, therefore `A ^ B` = 6.
+ << (left shift) Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
+ \>\> (right shift) Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
+ ~ (bitwise NOT) Takes one number and inverts all bits of it. Suppose A = 5, therefore `~A` = -6.

#### Important Facts
+ The left shift and right shift operators cannot be used with negative numbers.
+ The bitwise XOR operator is the most useful operator from technical interview perspective. We will see some very useful applications of the XOR operator later in the course.
+ The bitwise operators should not be used in place of logical operators.
+ The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively.
+ The & operator can be used to quickly check if a number is odd or even.
+ The value of expression (x & 1) would be non-zero only if x is odd, otherwise the value would be zero.

##### Example 1 Set A Bit At N'th Position In 'num' 
If we want to set a bit at nth position in number 'num' ,it can be done using 'OR' operator( | ).
`num = 0x100001000001;`
First we left shift '1' to n position via `bitwise = (1 << (n-1));`
Assign `n = 8;` where `bitwise = 0x100000000;`
Then, use 'OR' operator to set bit at that position.'OR' operator is used because it will set the bit even if the bit is unset previously in binary representation of number 'num'.`num = num | bitwise;`
`A: 0x...100001000001`
`B: 0x...000100000000`
`R: 0x...100101000001`

##### Example 2 Clear A Bit At N'th Position In 'num' 
Suppose we want to unset a bit at nth position in number 'num' then we have to do this with the help of 'AND' (&) operator.
`num = 0x...100001000001;`
First we left shift '1' to n position via `bitwise = (1 << (n-1))` than we use bitwise NOT operator '~' to unset this shifted '1'.
Assign `n = 6;` where `bitwise = 0x...1000000 = 0x0000 0000 0100 0000;`
`bitwise = ~bitwise = 0x1111 1111 1011 1111;`
Now after clearing this left shifted '1' i.e making it to '0' we will 'AND'(&) with the number 'num' that will unset bit at nth position.
`A: 0x0000 1000 0100 0001`
`B: 0x1111 1111 1011 1111`
`R: 0x0000 1000 0000 0001`

##### Example 3 Toggle A Bit At N'th Position In 'num' 
Toggling means to turn bit 'on'(1) if it was 'off'(0) and to turn 'off'(0) if it was 'on'(1) previously.We will be using 'XOR' operator here which is this '^'. The reason behind 'XOR' operator is because of its properties.
Properties of 'XOR' operator.
1^1 = 0
0^0 = 0
1^0 = 1
0^1 = 1
If two bits are different then 'XOR' operator returns a set bit(1) else it returns an unset bit(0).
`num = 0x100001000001;`
First we left shift '1' to n position via `bitwise = (1001 << (n-1));`
Assign `n = 8;` where `bitwise = 0x100100000000;`
`num = num ^ bitwise;`
`A: 0x0000 1000 0100 0001`
`B: 0x0000 1001 0000 0000`
`R: 0x0000 0001 0100 0001`

##### Example 4 Checking If Bit At N'th Position Is Set Or Unset
Left shift given number 1 by n-1 to create a number that has only set bit as n-th bit. temp = 1 << (n-1) 
If bitwise AND of n and temp is non-zero, then result is **set** else result is **not set**.
```c++
bool IsKthBitSet_L(int n, int k)
{
	return (n & (1 << (k - 1)));
}
bool IsKthBitSet_R(int n, int k)
{
	return ((n >> (k - 1)) & 1);
}
```
##### Example 5 Divide by 2
Logic: When we do arithmetic right shift, `x = x >> 1;`, every bit is shifted to right and blank position is substituted with sign bit of number, 0 in case of positive and 1 in case of negative number. Since every bit is a power of 2, with each shift we are reducing the value of each bit by factor of 2 which is equivalent to division of x by 2.
x = 18(00010010)
x >> 1 = 9 (00001001)

##### Example 5 Multiply by 2
Logic: When we do arithmetic left shift, `x =  << 1;`, every bit is shifted to left and blank position is substituted with 0 . Since every bit is a power of 2, with each shift we are increasing the value of each bit by a factor of 2 which is equivalent to multiplication of x by 2.
x = 18(00010010)
x << 1 = 36 (00100100)

##### Example 6 Log Base 2 Of A 32 Bit Int
Logic: We right shift x repeatedly until it becomes 0, meanwhile we keep count on the shift operation. This count value is the log2(x).
```C++
int log2(int x) 
{ 
    int res = 0; 
    while (x >>= 1) 
        res++; 
    return res; 
} 
```

##### Example 7 Flipping The Bits Of A Number
It can be done by a simple way, just simply subtract the number from the value obtained when all the bits are equal to 1 .
For example:
Number : Given Number
Value  : A number with all bits set in given number.
Flipped number = Value – Number:
Number = 23, Binary form: 10111;
After flipping digits number will be: 01000; Value: 11111 = 31;

##### Example 8 Swapping Two Numbers
We can easily swap two numbers say a and b by using the XOR(^) operator by applying below operations:
a ^= b;
b ^= a; 
a ^= b;

##### Example 9 Check Whether A Number Is A Power Of 2 Or Not
Bitwise Solution: If we subtract a number which is a power of 2 with 1 then all of it's unset bits after the only set bit become set and the set bit become unset. For example, consider 4 ( Binary representation: 100) and 16(Binary representation: 10000), we get following after subtracting 1 from them:
3 –> 011
15 –> 01111
Bitwise-AND(&) of 4 and 3 gives zero, similarly 16 and 15 also gives zero. So, if a number N is a power of 2 then bitwise-AND(&) of N and N-1 will be zero. We can say that N is a power of 2 or not based on the value of **N&(N-1)**.

##### Example 10 Given A Number N, Find The Most Significant Set Bit In The Given Number
The Most-Significant Bit in binary representation of a number is the highest ordered bit, that is it is the bit-position with highest value. 
One of the solution is first find the bit-position corresponding to the MSB in the given number, this can be done by calculating logarithm base 2 of the given number, i.e., log2(N) gives the position of the MSB in N. 
Once, we know the position of the MSB, calculate the value corresponding to it by raising 2 by the power of calculated position. That is, value = 2log2(N).
Input : N = 10
Output : 8
Binary representation of 10 is 1010
The most significant bit corresponds
to decimal number 8.

##### Example 11 Given A Number N,  Find The XOR Of All Numbers From 1 to N
`int result = CalXORFrom(2) // 1 ^ 2 = 0b11 = 3`
`int result = CalXORFrom(3) // 1 ^ 2 ^ 3 = 0b00 = 0`
`int result = CalXORFrom(4) // 1 ^ 2 ^ 3 ^ 4 = 0b100 = 4`
`int result = CalXORFrom(5) // 1 ^ 2 ^ 3 ^ 4 ^ 5 = 0b001 = 1`
`int result = CalXORFrom(6) // 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 0b111 = 7 ...`
+ Find the remainder of N by moduling it with 4.
+ If rem = 0, then xor will be same as N.
+ If rem = 1, then xor will be 1.
+ If rem = 2, then xor will be N+1.
+ If rem = 3 ,then xor will be 0.

##### Example 12 Count Set Bits
```c++
int CountSetBits_Simple(int n){
    int sum = 0;
    while(n > 0){
        if(n % 2 == 1) sum++;
        n /= 2;
    }
    return sum;
}
int CountSetBits_Opti(int n){
    int sum = 0;
    while(n > 0){
        n = n & (n - 1); 
        sum++;
    }
    return sum;
}
static int bitmask_table[256];
static void InitTable(){
    bitmask_table[0] = 0;
    for(int i = 1; i < 256; i++){
        //i & (i -1 ) to remove the last "1", 
        //and get a smaller number that has already been saved in map.
        bitmask_table[i] = bitmask_table[i & (i -1 )] +1;
    }
}
int CountSetBits_Fast(int n){
    return bitmask_table[n&255]+
                 bitmask_table[(n>>8)&255]+
                 bitmask_table[(n>>16)&255]+
                 bitmask_table[(n>>24)];
}
```

##### Example 13 Is Number Power Of 2
```c++
bool IsPower2_Simple(int n){
    if(n == 0) return false;
    while(n != 1){
        if(n % 2 != 0) return false;
        n /= 2;
    }
    return true;
}
bool IsPower2_Fast(int n){
    if (n==0) return false;
    return (n & (n - 1) == 0);
}
bool IsPower2_Short(int n){
    return (n && (n & (n - 1)) == 0)
}
```

#####  Example 14 Find Two Odd Appearing Numbers
I/O: arr[] = { 3, 4, 3, 4, 5, 4, 4, 6, 7, 7} / 5 6
I/O: arr[] = { .1, 3, 2, 3, 3, 1} / 2 3
```c++
void FindOdd_Simple(std::vector<int>& arr, int sizearr, std::vector<int>& result){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]) count++;
        }
        if((count & 1) == 0) result.push_back(arr[i]);
    }
}
// in case 1, arr[] = { 3, 4, 3, 4, 5, 4, 4, 6, 7, 7}
// 3 ^4 ^3 ^4 ^5 ^4 ^4 ^6 ^7 ^7
// = 5^6 = 00..0101 ^ 00..0110 = 00..0011 = 3
int ArrayMemberXOR(const std::vector<int>& arr){
    int result = 0;
    for(auto a : arr){
        result ^= a;
    }
    return result;
}
void FindOdd(std::vector<int>& arr, int sizearr, std::vector<int>& result){
    int r = ArrayMemberXOR(arr);
    r = r&(~(r - 1));
    int r1 = 0, r2 = 0;
    for(auto a:arr){
        if ((a & r) != 0){
            s1 ^= a;
        }else{
            s2 ^= a;
        }
    }
    result.push_back(r1);
    result.push_back(r2);
}
```

#### Two's Complement
> Definition: Two's complement works by interpreting binary numbers in the same way that you would for positive numbers, but giving the most significant digit a negative weight. For example, if our numbers are 4 digits wide, then the binary number 1110 has the value -2:
Here's a full list of 4 digit binary represenations and their unsigned and signed (two's complement) values:
```
binary  decimal(unsigned)   decimal(two's complement)
  0000                 0                            0
  0001                 1                            1
  0010                 2                            2
  0011                 3                            3
  0100                 4                            4
  0101                 5                            5
  0110                 6                            6
  0111                 7                            7
  1000                 8                           -8
  1001                 9                           -7
  1010                10                           -6
  1011                11                           -5
  1100                12                           -4
  1101                13                           -3
  1110                14                           -2
  1111                15                           -1

Formula: -x = ~x + 1
Example: x = 5 (assume 4-bit numbers)
x      = 0101
~x     = 1010
~x + 1 = 1011

1011 = (1 * -2^3) + (0 * 2^2) + (1 * 2^1) + (1 * 2^0) = -8 + 2 + 1 = -5
```
#### Bit Op Magics
```
i        = 0x0010 0100    // origin number
i - 1    = 0x0010 0011    // filp 0s after the last 1, and remove it
```
##### i ^= i
```
i     = 0x0010 0100    // origin number
0     = 0x0000 0000
i ^ 0 = 0x0010 0100
i ^ i = 0x0000 0000
``` 
##### i & (i  - 1)
```
i            = 0x0010 0100    // origin number
i & (i  - 1) = 0x0010 0000    // remove last 1
```
##### i $ (~(i - 1))
```
i              = 0x0010 0100    // origin number
~ (i - 1)      = 0x1101 1100
i $ (~(i - 1)) = 0x0000 0100    // get last 1 pos
```
#### Grey Code
> Definition: Gray Code is a form of binary that uses a different method of incrementing from one number to the next. With Gray Code, only one bit changes state from one position to another. This feature allows a system designer to perform some error checking (i.e., if more than one bit changes, the data must be incorrect). 
```c++
int b2g(int n){
    return n ^ (n>>1);
}
int g2b(int n){
    int binary = n;
    for (int bit = n >> 1; bit != 0; bit >>= 1) {
        binary ^= bit;
    }
    return binary;
}
```
## 04<p style="text-align: center;">Recursion</p>
## 05<p style="text-align: center;">Arrays</p>
## 06<p style="text-align: center;">Searching</p>
## 07<p style="text-align: center;">Sorting</p>
## 08<p style="text-align: center;">Matrix</p>
## 09<p style="text-align: center;">Hashing</p>
## 10<p style="text-align: center;">Strings</p>
## 11<p style="text-align: center;">Linked List</p>
## 12<p style="text-align: center;">Stack</p>
## 13<p style="text-align: center;">Queue</p>
## 14<p style="text-align: center;">Deque</p>
## 15<p style="text-align: center;">Tree</p>
## 16<p style="text-align: center;">Binary Search Tree</p>
## 17<p style="text-align: center;">Heap</p>
## 18<p style="text-align: center;">Graph</p>
## 19<p style="text-align: center;">Greedy</p>
## 20<p style="text-align: center;">Backtraking</p>
## 21<p style="text-align: center;">Dynamic Programming</p>
## 22<p style="text-align: center;">Trie</p>
## 23<p style="text-align: center;">Segment And Binary</p>Indexed Tree
## 24<p style="text-align: center;">Disjoint Set</p>

## 25<p style="text-align: center;">Project Examples</p>

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>