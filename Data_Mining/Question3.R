###iris Dataset

iris
summary(iris)
#mean(iris$Sepal.Length)
sapply(iris[,-5],sd)
#install.packages("caret",dependencies = TRUE)
library(caret)

#preProcess()
#"center" subtracts the mean,"scale" divides by the standard deviation

preprocessValue=preProcess(iris[,-5],method = c("scale","center"))
iris_transformed=predict(preprocessValue,iris[,1:4])
sapply(iris_transformed,sd)
summary(iris_transformed)

###Wine Dataset

wine=read.csv("C:/Users/Girish/Desktop/paras/DM/wine.csv")
summary(wine)
sapply(wine[,-1],sd)

#preProcess()
preprocessValue=preProcess(wine[,-1],method = c("scale","center"))
wine_transformed=predict(preprocessValue,wine[,2:14])
sapply(wine_transformed,sd)
summary(wine_transformed)
