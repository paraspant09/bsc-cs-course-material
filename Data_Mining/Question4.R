#install.packages("arules")
library(arules)
data("Groceries")
?Groceries
str(Groceries)
head(Groceries)
inspect(head(Groceries))
summary(Groceries)
itemFrequencyPlot(Groceries,topN=20,type="absolute")
#Most Popular=Whole milk,other vegetables
#Not so popular=brown bread, domestic eggs
rules=apriori(Groceries,parameter = list(supp=0.001,conf=0.8))
rules=apriori(Groceries,parameter = list(supp=0.5,conf=0.75)) #0 rules in it
rules=apriori(Groceries,parameter = list(supp=0.6,conf=0.6)) #0 rules in it
inspect(rules)
head(rules)
inspect(head(rules))
inspect(rules[1:10])

rules=sort(rules,by="confidence",decreasing = T)

#install.packages("arulesViz")
library(arulesViz)
library(plyr)
library(dplyr)
plot(rules[1:5],method="graph",engine='interactive',shading=NA)

#Bakery Dataset
bakery=read.csv("C:/Users/Girish/Desktop/paras/DM/BakeryDataSet/1000/1000i.csv")

#will not work
bakeryrules=apriori(bakery,parameter = list(supp=0.001,conf=0.8))

#this method will work
names(bakery) <- c("Receipt_Number","Food","Quantity")  #add column names
id<-c(1:5)
food<-c("milk","sugar","chocolate","apples","curd")

df <- data.frame(id, food)

bakery$Food=df$food[bakery$Food]

bakery=ddply(bakery,"Receipt_Number",function(bakery) paste(bakery$Food,collapse = ','))
bakery$Receipt_Number=NULL
names(bakery) <- c("item")

write.csv(bakery, "C:/Users/Girish/Desktop/paras/DM/tmp/1000transac.csv",quote = FALSE,row.names = FALSE)

bakeryTransacs <- read.transactions(
  file = "C:/Users/Girish/Desktop/paras/DM/tmp/1000transac.csv",
  format = "basket",
  sep = ",",
  header = TRUE
)

inspect(head(bakeryTransacs))

bakeryrules=apriori(bakeryTransacs,parameter = list(supp=0.002,conf=0.08))

inspect(head(bakeryrules))

plot(bakeryrules[1:5],method="graph",engine='interactive',shading=NA)
