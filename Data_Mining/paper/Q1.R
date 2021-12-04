library(editrules)
people=read.table("C:/Users/Girish/Desktop/paras/DM/paper/People.txt",TRUE,"\t")
people
E=editset(expression(
  Age>=10,
  Age<=70
))
E
ve=violatedEdits(E,people)
ve
summary(ve)
plot(ve)

library(caret)

preprocessValue=preProcess(data.frame(income=people[,3]),method = c("center"))
pp2=(people$Income - mean(people$Income)) / (max(people$Income) - min(people$Income))
norm_income=predict(preprocessValue,data.frame(income=people[,3]))
round(mean(norm_income$income))

sapply(people,is.infinite)
sapply(people,is.nan)

people[sapply(people,is.infinite)]=NA
people[sapply(people,is.nan)]=NA

boxplot(people$Height,horizontal = T)
boxplot.stats(people$Height)
