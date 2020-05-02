# HW7: micro optimization

#### Completed by Vinay Gopalan

Our aim is to optimize an algorithm's pipeline. The algorithm converts strings with numbers (no decimal points) to `uint32_t`.

## Part 1: Naive implementation

For this part, instead of using `atoi()`, a library function, I decided to calculate the number using a while loop and basic arithmetic. In order to get a digit from a number I just use the expression `*str - '0'`, where `*str` is the pointer to a char in the current string.

Not including library calls in each iteration reduces the runtime overhead considerably. The `atoi()` implementation on my Linux VM takes approx. `0.0648s`, whereas my naive implementation takes about `0.01215s` without any optimization.

The initial value of `num` is 0 here. Tweaking this is useful during optimization. In each iteration of the while loop, I verify that the current char at `*str` is a digit by checking if it is between '0' and '9'.

## Part 2: Optimized implementation

Since we know the data only contains digits, we necessarily need not check if `*str` is between '0' and '9'. Instead, the  condition we can use is simply `while(*str != '\0')`. This change brings a slight decrease in runtime (about 6% decrease).

The next bit of optimization is done by building a helper function `make_digit(char c)` which returns the `quote_t` value `c - '0'`. This allows us to initialize `num = make_digit(*str)`, which reduces iterations in the while loop. With this function, we also no longer need to check if `*str` is between '0' and '9', but just need to check if it's less than '9'. Secondly, a new variable `checker` is declared which stores the value returned by `make_digit`, therefore reducing further computational overhead.

With these changes, the optimized implementation on the same machine takes approx. `0.010311s`, which is about a 15% decrease in runtime.
