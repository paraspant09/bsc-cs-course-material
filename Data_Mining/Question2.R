library(editrules)
dirty_iris=read.csv("https://raw.githubusercontent.com/edwindj/datacleaning/master/data/dirty_iris.csv")
dirty_iris
cmplt_cases=complete.cases(dirty_iris)
as.numeric(cmplt_cases)
sum(as.numeric(cmplt_cases))
num_of_cmplt_obsrvn=sum(cmplt_cases)
num_of_obsrvn=nrow(dirty_iris)
percentage=(num_of_cmplt_obsrvn/num_of_obsrvn)*100

sapply(dirty_iris,is.infinite)
sapply(dirty_iris,is.nan)

dirty_iris[sapply(dirty_iris,is.infinite)]=NA
dirty_iris[sapply(dirty_iris,is.nan)]=NA

E=editfile("C:/Users/Girish/Desktop/paras/DM/Q2Rules.txt","all")
E

ve=violatedEdits(E,dirty_iris)
ve
summary(ve)
plot(E)
plot(ve)
plot(E,layout=layout.circle)

sepal_length=dirty_iris$Sepal.Length
hist(sepal_length)
boxplot(sepal_length,horizontal = T)
boxplot.stats(sepal_length)

new_sepal_length=sepal_length[sepal_length<20]
new_sepal_length=new_sepal_length[new_sepal_length>4]
boxplot(new_sepal_length,horizontal = T)
boxplot.stats(new_sepal_length)
hist(new_sepal_length)
