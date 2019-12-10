### [Why do we need to free memory?](http://www.cplusplus.com/forum/beginner/186031/)
Your stupid operation might introduce some behavior you don't know for sure.
Even if the OS take care for you when the program close, for sure you still don't want the OS  to close your out-of-control program abruptly without a warning.

### Problem unsolved
```sh
$ gcc test_array.c
test_array.c:112:1: error: unterminated function-like macro invocation
RUN_TESTS(all_tests);
^
./../minunit.h:18:5: note: expanded from macro 'RUN_TESTS'
    debug("------RUNNING: %s", argv[0];\
    ^
./../dbg.h:11:9: note: macro 'debug' defined here
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
        ^
test_array.c:112:22: error: expected '}'
RUN_TESTS(all_tests);
                     ^
test_array.c:112:1: note: to match this '{'
RUN_TESTS(all_tests);
^
./../minunit.h:16:57: note: expanded from macro 'RUN_TESTS'
#define RUN_TESTS(name) int main(int argc, char *argv[]){\
                                                        ^
2 errors generated.
```
