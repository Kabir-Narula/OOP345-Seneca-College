# Workshop 1: Across Translation Units

In this workshop, you implement aspects of linkage, storage duration, namespaces, header guards, and operating system interfaces.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:
- receive program arguments from the command line
- guard a class definition from duplication in a translation unit
- access a variable defined in a different translation unit
- declare a local variable that resides in memory throughout the lifetime of the program
- upgrade code to accept and manage a user-defined string of any length

## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

## Ride Requests

This application records ride requests made by customers and calculates the price with relation to the current tax rate and special discount for certain customers.

The application loads the request information from multiple files. Each file read represents rides taken from a certain day. The rides are handled somewhat differently depending on whether they are an `Office` ride or a `Home` ride.

## Part 1 (0%)

This workshop consists of two modules:
- `w1` (partially supplied)
- `RideRequest`

### `w1` Module (partially supplied)

Study the code supplied and make sure you understand it.

Finish the implementation of the `main` function, by completing the parts marked with `TODO`:

- write the prototype of the `main` function to receive a set of standard command line arguments
- echo the set of arguments to standard output in the following format:
```
  1: first argument
  2: second argument
  3: third argument
  4: ...
```

**Do not modify this module in any other place!**

### `RideRequest` Module

The `RideRequest` module defines the current tax rate and discount for special customers, as two global variables named `g_taxrate` and `g_discount` as floating-point numbers in double precision.  The value of the tax rate and discount may change from day to day. These two variables will be accessed when a new day of rides starts from the `main` function.

This module also defines a class named `RideRequest` in the namespace `sdds` that stores some information about a ride:

- a C-style null-terminated string of up to 10 characters *including the null byte terminator* representing the name of the customer.

- a C-style null-terminated string of up to 25 characters *including the null byte terminator* representing the extra details about the ride (e.g., a description or special requirements the customer made).

- the price of the ride as a floating-point number in double precision.

- a Boolean flag indicating whether the ride receives a discount

**Public Members**

- Default constructor
- `read()`: a modifier that receives an `istream` reference.

    - If the `istream` is in a good state, this function will attempt to read from the `istream` and store the information read into the current object. The data read in will be in the following format:
        ```
        <Customer Name>,<Ride Description>,<Rate>,<Discount Status>[newline]
        ```
        The discount status can be of two values: `'Y'` if a discount should be applied and `'N'` otherwise.
    - If the `istream` object is not in a good state then this function will do nothing.

    When implementing the read function, it may be advisable to review the Input/Output Objects chapter from the 200/244 [Course Notes](http://intro2oop.sdds.ca/F-Refinements/input-and-output-refinements).

- `display()`: a query that displays to the screen the content of an `Ride Request` instance in the following format:

    ```
    COUNTER. CUSTOMER_NAME|RIDE_DESCRIPTION|PRICE_WITH_TAX|PRICE_WITH_DISCOUNT
    ```
    If no customer name has been stored in the current object, this query should print:
    ```
    COUNTER. No Ride Request
    ```
    where
    - `COUNTER` is a *left aligned* field of size 2, that holds the number of times that this function has been called (use a *local-to-function variable* that remains in memory for the lifetime of the program) **Do not use global/member variables to store the counter!**
    - `CUSTOMER_NAME` is a  *left aligned* field of size 10 that represents the name of the customer that made the order.
    - `RIDE_DESCRIPTION` is a *left aligned* field of size 25 that represents the description of the ride requested.
    - `PRICE_WITH_TAX` is a *left aligned* field of size 12 with 2 decimal point precision that represents the rate of the ride requested with tax calculated based on the current tax rate.
    - `PRICE_WITH_DISCOUNT` is a *right aligned* field of size 13 that represents the taxed price of the ride request with the discount applied on top for special customers. If the ride isn't discounted, then nothing is printed here.

Add any other **private** members that your design requires (without changing the specs above)!

### Sample Output

The input files `rides1.txt` and `rides2.txt` are already provided; the main module contains a description of the structure for these files.

When the program is started with the command:
```
ws rides1.txt rides2.txt
```
the output should look like the one from the `sample_output.txt` file.

### Test Your Code

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 305_w1_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***

## Part 2 (100%)

For this part of the workshop, upgrade your `RideRequests` class to accept a ride description in the form of a C-style null-terminated string of any length. Allocate memory as much is needed, but no more.  **Make sure your program doesn't have memory leaks.**

To facilitate the changes needed for this part, consider the use of these `std::string` related functions:

- [std::getline](https://en.cppreference.com/w/cpp/string/basic_string/getline)
- [std::string::c_str](https://en.cppreference.com/w/cpp/string/basic_string/c_str)
- [std::string::length](https://en.cppreference.com/w/cpp/string/char_traits/length)

### Sample Output

When the program is started with the command:
```
ws rides1.txt rides2.txt deleted.txt rides4.txt
```
the output should look like the one from the `sample_output.txt` file.

### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your ***detailed*** description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- the difference between internal and external linkage citing examples from your code
- what are `static` variables and how are they useful in your solution.
- the changes that you made in upgrading your `RideRequest` class in part 2.

To avoid deductions, refer to code snippets in your solution as examples to support your explanations.

### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 305_w1_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
