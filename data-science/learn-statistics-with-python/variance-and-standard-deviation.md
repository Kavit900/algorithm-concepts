### Variance

Variance is a descriptive statistic that describes how spread out the points in a data set are.

If our data is closer then each data point will tend to be close to the mean and the difference will be small. If the data is spread out, the difference between every data point and the mean will be larger.

Mathematically we can write the comparison as:-

difference = X - mu

where `X` is the single data point and `mu` is the mean.

##### Average Distances

We now have five different values that describe how far away each point is from the mean. That seems to be a good start in describing the spread of the data. But the whole point of calculating variance was to get one number that describes the dataset. We don’t want to report five values — we want to combine those into one descriptive statistic.

To do this, we’ll take the average of those five numbers. By adding those numbers together and dividing by 5, we’ll end up with a single number that describes the average distance between our data points and the mean.

Note that we’re not quite done yet — our final answer is going to look a bit strange here. There’s a small problem that we’ll fix in the next exercise.

##### Square The Differences

Consider this very small dataset:

[-5, 5]

The mean of this dataset is 0, so when we find the difference between each point and the mean we get -5 - 0 = -5 and 5 - 0 = 5.

When we take the average of -5 and 5 to get the variance, we get 0!

Now think about what would happen if the dataset were [-200, 200]. We’d get the same result! That can’t possibly be right — the dataset with 200 is much more spread out than the dataset with 5, so the variance should be much larger!

The problem here is with negative numbers. Because one of our data points was 5 units below the mean and the other was 5 units above the mean, they canceled each other out!

When calculating variance, we don’t care if a data point was `above or below the mean` — all we care about is how far away it was. To get rid of those pesky negative numbers, we’ll square the difference between each data point and the mean.

Our equation for finding the difference between a data point and the mean now looks like this:

`difference = (X - mu) ^ 2`


Full formula for variance is :-

![variance formula](/images/variance.jpg)

##### Variance in NumPy

We can make use of numpy's `var()` library that takes in a list of numbers and returns us the variance of that dataset

```
import numpy as np

dataset = [3, 5, -2, 49, 10]
variance = np.var(dataset)
```

##### Standard Deviation

Variance is a tricky statistic to use because its units are different from both the mean and the data itself. For example, the mean of our NBA dataset is 77.98 inches. Because of this, we can say someone who is 80 inches tall is about two inches taller than the average NBA player.

However, because the formula for variance includes squaring the difference between the data and the mean, the variance is measured in units squared. This means that the variance for our NBA dataset is 13.32 inches squared.

This result is hard to interpret in context with the mean or the data because their units are different. This is where the statistic standard deviation is useful.

Standard deviation is computed by taking the square root of the variance. `sigma` is the symbol commonly used for standard deviation. Conveniently, `sigma` squared is the symbol commonly used

In Python, you can take the square root of a number using ** 0.5:

```
num = 25
num_square_root = num ** 0.5
```

There is a NumPy function dedicated to finding the standard deviation of a dataset — we can cut out the step of first finding the variance. The NumPy function std() takes a dataset as a parameter and returns the standard deviation of that dataset:

```
import numpy as np

dataset = [4, 8, 15, 16, 23, 42]
standard_deviation = np.std()
```

##### Variance in weather (Project)

```
import codecademylib3_seaborn
import pandas as pd
import numpy as np
from weather_data import london_data

#print(london_data.head())
print(len(london_data))

temp = london_data["TemperatureC"]

average_temp = np.average(temp)
temperature_var = np.var(temp)

temperature_standard_deviation = np.std(temp)

june = london_data.loc[london_data["month"] == 6]["TemperatureC"]

july = london_data.loc[london_data["month"] == 7]["TemperatureC"]

june_month_temperature_mean = np.average(june)

july_month_temperature_mean = np.average(july)

june_month_sd = np.std(june)
july_month_sd = np.std(july)

for i in range(1, 13):
  month = london_data.loc[london_data["month"] == i]["TemperatureC"]
  print("The mean temperature in month "+str(i) +" is "+ str(np.mean(month)))
  print("The standard deviation of temperature in month "+str(i) +" is "+ str(np.std(month)) +"\n")
```

