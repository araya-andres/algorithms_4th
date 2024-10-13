## Build

```
bazel build //ch01:binary_search
```

## Run

```
echo 42 | bazel-bin/ch01/binary_search data/ints.txt
```

## Unit tests

```
bazel test tests
```

or

```
bazel run //tests:tests
```