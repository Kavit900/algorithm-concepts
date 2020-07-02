## R basics

**Assign a value to a name**

x = 5

### Vectors

**Create a vector**

use c()

for example:-
```
x = c(1,2,3)
y = c(5,6,7,8)
z = c(x,y)
a = c(1:20)
a = 1:20
```

**Arithmetic with vectors**

c(1,2) + 2
c(1,2) * 3
c(1,2) + c(4,5)

**Subsetting**

A = c(3,1,5,2,6)
elements of A can be extracted using
A[index]
 index must be a number or a vector(numeric or logical), indicating the locations of elements to be extracted.

B = A[3]
C = A[c(1,3,5)]
D = A[-2]

### Data Manipulation

Read a csv file - read.csv() -

ex:- friends = read.csv("friends.csv", header = T);

The above variable friends is a data frame.

**To extract a variable/column from a data frame**

For example:- If you want to whole column name `Score`.

friends$Score[5:9]

**Data Frame: Subsetting**

-> For a matrix-like structure, elements are extracted.

friends[4,3] or friends[c(2,5)] - 2nd and 5th rows.

**Create a data frame**

Example:-
name = c("Mary", "Mike")
midterm = c(86, 90)
major = c("Math", "Management")
df1 = data.frame(name, midterm, major)

df2 = data.frame(name="Alex", age=30, creditlimit=5000)

**Manipulating Data**

rbind() - combine rows
cbind() - combine columns

data1 = data.frame(name="Mike", income=50)
data2 = data.frame(name="Jack", income=60)
data3 = rbind(data1, data2)

data4 = data.frame(experience=c(10,12))
data5 = cbind(data3, data4)


### Multiple Regression

**Correlation**

𝑟 is always between -1 and +1
𝑟=0:  no linear association
𝑟 is close to +1:  strong positive linear association
𝑟 is close to -1:  strong negative linear association

CODE:-
// read data
data1 = read.csv("Wine-HeartDisease.csv",header=T)
// scatter plot
plot(data1$wine, data1$deaths)
// correlation
cor(data1$wine, data1$deaths)
identify(data1$wine, data1$deaths, data1$Country)

**Simple Regression Model (SRM)**

Theoretical model is y = intercept + slope * x;

CODE:-

f = lm(deaths ~ wine, data = data1)
summary(f)

-> Prediction from above linear regression model

data2 = data.frame(wine=8)
predict(f, data2)

**Explaining Variation**

-> We get that value from - R-squared (r^2)

For wine consumption, r^2 = 0.71, that means the fitted line explains 71% of the variation in heart disease deaths.

**Linear Regression for more than 1 variable**

Theoretical model is y = intercept + b1*x1 + b2*x2;

-> Residual = (observed values) - (predicted / fitted values)

The residuals estimate the errors e in the regression model

y = intercept + b1x1 + b2x2 + ... + bkxk + e;

CODE:-

// Example: product_ratings.csv
// Read data
PR <- read.csv("product_ratings.csv", header=T)
// Fit a linear model
g1 = lm(Rating~Age+Income, data=PR)
// predicted rating
predicted = predict(g1, PR)
// residuals
residuals = PR$Rating- predicted

-> It measures the dispersion of data around the regression equation
