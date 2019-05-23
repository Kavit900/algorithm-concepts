## Virtual Environments

To avoid conflicts between different python libraries try to always use virtual environments.

Install Anaconda Python distributions. 

To create an Anaconda virual environment

`conda create -n dsfs python=3.6`

The above command will create a virtual environment called `dsfs`.

To activate the virtual environment, type the command 

`source activate dsfs`

or

`conda activate dsfs`

To deactivate a virtual environment, type the command

`source deactivate`

or 

`conda deactivate`

Now, after activating virtual environment, let's install IPython, using the command

`python -m pip install ipython`

Note:- Anaconda comes with it's own package manager, conda, but you can also use the standard Python package manager pip, which is what we'll be doing.

To start jupyter notebook, run the command
`jupyter notebook`

To install required dependencies, use a similar command as provided below

`pip3 install numpy scipy scikit-learn`

## defaultdict

Imagine that you’re trying to count the words in a document. An obvious approach is to create a dictionary in which the keys are words and the values are counts. As you check each word, you can increment its count, if it’s already in the dictionary and add it to the dictionary if it’s not

```
from collections import defaultdict

word_counts = defaultdict(int)          # int() produces 0
for word in document:
    word_counts[word] += 1
```

They can also be useful with list or dict or even your own functions:

```
dd_list = defaultdict(list)             # list() produces an empty list
dd_list[2].append(1)                    # now dd_list contains {2: [1]}

dd_dict = defaultdict(dict)             # dict() produces an empty dict
dd_dict["Joel"]["City"] = "Seattle"     # {"Joel" : {"City": Seattle"}}

dd_pair = defaultdict(lambda: [0, 0])
dd_pair[2][1] = 1                       # now dd_pair contains {2: [0, 1]}
```

## Counter

A Counter turns a sequence of values into a defaultdict(int)-like object mapping keys to counts.

```
from collections import Counter
c = Counter([0, 1, 2, 0])          # c is (basically) {0: 2, 1: 1, 2: 1}
```

A Counter instance has a most_common method that is frequently useful:

```
# print the 10 most common words and their counts
for word, count in word_counts.most_common(10):
    print(word, count)
```

## Sets

Another useful data structure is set, which represents a collection of distinct elements. You can define a set by listing its elements between curly braces:

`primes_below_10 = {2, 3, 5, 7}`

However, that doesn’t work for empty sets, as {} already means “empty dict“. In that case you’ll need to use set() itself:

```
s = set()
s.add(1)       # s is now {1}
s.add(2)       # s is now {1, 2}
s.add(2)       # s is still {1, 2}
x = len(s)     # equals 2
y = 2 in s     # equals True
z = 3 in s     # equals False
```


## enumerate function

Python provides a way to turn values into pairs (index, value)

```
names = ["Alice", "Bob", "Charlie", "Debbie"]

# not Pythonic
for i in range(len(names)):
    print(f"name {i} is {names[i]}")

# also not Pythonic
i = 0
for name in names:
    print(f"name {i} is {names[i]}")
    i += 1

# Pythonic
for i, name in enumerate(names):
    print(f"name {i} is {name}")
```

## Randomness

In data science, we will frequently need to generate random numbers, which we can do with random module:

```
import random
random.seed(10)  # this ensures we get the same results every time

four_uniform_randoms = [random.random() for _ in range(4)]

# [0.5714025946899135,       # random.random() produces numbers
#  0.4288890546751146,       # uniformly between 0 and 1
#  0.5780913011344704,       # it's the random function we'll use
#  0.20609823213950174]      # most often
```


We’ll sometimes use random.randrange, which takes either 1 or 2 arguments and returns an element chosen randomly from the corresponding range():

```
random.randrange(10)    # choose randomly from range(10) = [0, 1, ..., 9]
random.randrange(3, 6)  # choose randomly from range(3, 6) = [3, 4, 5]
```

There are a few more methods that we’ll sometimes find convenient. random.shuffle randomly reorders the elements of a list:

```
up_to_ten = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
random.shuffle(up_to_ten)
print(up_to_ten)
# [7, 2, 6, 8, 9, 4, 10, 1, 3, 5]   (your results will probably be different)
```

If you need to randomly pick one element from a list you can use random.choice:

```
my_best_friend = random.choice(["Alice", "Bob", "Charlie"])     # "Bob" for me
```

And if you need to randomly choose a sample of elements without replacement (i.e., with no duplicates), you can use random.sample:

```
lottery_numbers = range(60)
winning_numbers = random.sample(lottery_numbers, 6)  # [16, 36, 10, 6, 25, 9]
```

To choose a sample of elements with replacement (i.e., allowing duplicates), you can just make multiple calls to random.choice:

```
four_with_replacement = [random.choice(range(10)) for _ in range(4)]
print(four_with_replacement)  # [9, 4, 4, 2]
```

