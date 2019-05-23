#### Numpy Average

numpy's `.average()` function can do the work of finding the average 

#### Numpy Median

numpy's `.median()` function to calculate the median of the array

#### SciPy Mode

scipy stats library is used to get the mode of the array

`stats.mode()`

Note:- In case of more than one mode, the above library will always return the mode with the smallest value

Mode is not always a great measure to find where the data is centered.

#### Central Tendency for Housing Data

In this project, you will find the mean, median, and mode cost of one-bedroom apartments in three of the five New York City boroughs: Brooklyn, Manhattan, and Queens.

Using your findings, you will make conclusions about the cost of living in each of the boroughs. We will also discuss an important assumption that we make when we point out differences between the boroughs.

We’ve imported data about one-bedroom apartments in three of New York City’s boroughs: Brooklyn, Manhattan, and Queens. We saved the values to:

    - brooklyn_one_bed
    - manhattan_one_bed
    - queens_one_bed

In this project, we only care about the price of apartments, so we saved the price of apartments in each borough to:

    - brooklyn_one_bed
    - manhattan_one_bed
    - queens_one_bed

Code:- 

```
# Import packages
import numpy as np
import pandas as pd
from scipy import stats

# Read in housing data
brooklyn_one_bed = pd.read_csv('brooklyn-one-bed.csv')
brooklyn_price = brooklyn_one_bed['rent']

manhattan_one_bed = pd.read_csv('manhattan-one-bed.csv')
manhattan_price = manhattan_one_bed['rent']

queens_one_bed = pd.read_csv('queens-one-bed.csv')
queens_price = queens_one_bed['rent']

# Add mean calculations below 
brooklyn_mean = np.average(brooklyn_price)

manhattan_mean = np.average(manhattan_price)

queens_mean = np.average(queens_price)

# Add median calculations below
brooklyn_median = np.median(brooklyn_price)

manhattan_median = np.median(manhattan_price)

queens_median = np.median(queens_price)

# Add mode calculations below
brooklyn_mode = stats.mode(brooklyn_price)

manhattan_mode = stats.mode(manhattan_price)

queens_mode = stats.mode(queens_price)







##############################################
##############################################
##############################################







# Don't look below here
# Mean
try:
    print("The mean price in Brooklyn is " + str(round(brooklyn_mean, 2)))
except NameError:
    print("The mean price in Brooklyn is not yet defined.")
try:
    print("The mean price in Manhattan is " + str(round(manhattan_mean, 2)))
except NameError:
    print("The mean in Manhattan is not yet defined.")
try:
    print("The mean price in Queens is " + str(round(queens_mean, 2)))
except NameError:
    print("The mean price in Queens is not yet defined.")
    
    
# Median
try:
    print("The median price in Brooklyn is " + str(brooklyn_median))
except NameError:
    print("The median price in Brooklyn is not yet defined.")
try:
    print("The median price in Manhattan is " + str(manhattan_median))
except NameError:
    print("The median price in Manhattan is not yet defined.")
try:
    print("The median price in Queens is " + str(queens_median))
except NameError:
    print("The median price in Queens is not yet defined.")
    
    
#Mode
try:
    print("The mode price in Brooklyn is " + str(brooklyn_mode[0][0]) + " and it appears " + str(brooklyn_mode[1][0]) + " times out of " + str(len(brooklyn_price)))
except NameError:
    print("The mode price in Brooklyn is not yet defined.")
try:
    print("The mode price in Manhattan is " + str(manhattan_mode[0][0]) + " and it appears " + str(manhattan_mode[1][0]) + " times out of " + str(len(manhattan_price)))
except NameError:
    print("The mode price in Manhattan is not yet defined.")
try:
    print("The mode price in Queens is " + str(queens_mode[0][0]) + " and it appears " + str(queens_mode[1][0]) + " times out of " + str(len(queens_price)))
except NameError:
    print("The mode price in Queens is not yet defined.")



```

