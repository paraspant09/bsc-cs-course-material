#install.packages("caret",dependencies = TRUE)
library(caret)

#data scaled to standard format------------------

preprocessValue=preProcess(iris[,],method = c("scale","center"))
iris_trans=predict(preprocessValue,iris[,])
sapply(iris_trans[,-5],sd)
summary(iris_trans)

#using sample

#iris data set

#1)r-part==========================

#hold out method(75%)--------------------------

n=nrow(iris_trans)
trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
iris_train=iris_trans[trainIndex,]
iris_test=iris_trans[-trainIndex,]

model=train(Species~.,data=iris_train,'rpart')
pred=predict(model,iris_test[,-5])

conf=confusionMatrix(pred,iris_test$Species)$table
dt_acchold75=((sum(diag(conf)))/sum(conf))*100

#hold out method(66%)--------------------------

n=nrow(iris_trans)
trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
iris_train=iris_trans[trainIndex,]
iris_test=iris_trans[-trainIndex,]

model=train(Species~.,data=iris_train,'rpart')
pred=predict(model,iris_test[,-5])

conf=confusionMatrix(pred,iris_test$Species)$table
dt_acchold66=((sum(diag(conf)))/sum(conf))*100

#random sub sampling(75%)-------------------------

n=nrow(iris_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
  iris_train=iris_trans[trainIndex,]
  iris_test=iris_trans[-trainIndex,]
  
  model=train(Species~.,data=iris_train,'rpart')
  pred=predict(model,iris_test[,-5])
  
  conf=confusionMatrix(pred,iris_test$Species)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
dt_accsubsample75=acctotal/k
cat("dt Aggregate(75%) :",dt_accsubsample75)

#random sub sampling(66%)-------------------------

n=nrow(iris_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
  iris_train=iris_trans[trainIndex,]
  iris_test=iris_trans[-trainIndex,]
  
  model=train(Species~.,data=iris_train,'rpart')
  pred=predict(model,iris_test[,-5])
  
  conf=confusionMatrix(pred,iris_test$Species)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
dt_accsubsample66=acctotal/k
cat("dt Aggregate(66%) :",dt_accsubsample66)

#cross validation-------------------------

model=train(iris_trans[,-5],iris_trans$Species,'rpart',trControl=trainControl(method = 'cv',number = 10))
pred=predict(model,iris_trans[,-5])

conf=confusionMatrix(pred,iris_trans$Species)$table
dt_acccv=((sum(diag(conf)))/sum(conf))*100

#comparing all accuracies----------------

barplot(c(dt_acchold75,dt_acchold66,dt_accsubsample75,dt_accsubsample66,dt_acccv),xlab="decision tree method",ylab="accuracies(in %)"
        ,ylim = c(0,100), names.arg=c("dt_acchold75","dt_acchold66","dt_accsubsample75","dt_accsubsample66","dt_acccv"),col="red")


#install.packages("e1071",dependencies = TRUE)
library(e1071)

#2)naive-Bayes classifier=====================

#hold out method(75%)--------------------------

n=nrow(iris_trans)
trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
iris_train=iris_trans[trainIndex,]
iris_test=iris_trans[-trainIndex,]

model=naiveBayes(Species~.,data=iris_train)
pred=predict(model,iris_test[,-5])

conf=confusionMatrix(pred,iris_test$Species)$table
nb_acchold75=((sum(diag(conf)))/sum(conf))*100

#hold out method(66%)--------------------------

n=nrow(iris_trans)
trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
iris_train=iris_trans[trainIndex,]
iris_test=iris_trans[-trainIndex,]

model=naiveBayes(Species~.,data=iris_train)
pred=predict(model,iris_test[,-5])

conf=confusionMatrix(pred,iris_test$Species)$table
nb_acchold66=((sum(diag(conf)))/sum(conf))*100

#random sub sampling(75%)-------------------------

n=nrow(iris_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
  iris_train=iris_trans[trainIndex,]
  iris_test=iris_trans[-trainIndex,]
  
  model=naiveBayes(Species~.,data=iris_train)
  pred=predict(model,iris_test[,-5])
  
  conf=confusionMatrix(pred,iris_test$Species)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
nb_accsubsample75=acctotal/k
cat("nb Aggregate(75%) :",nb_accsubsample75)

#random sub sampling(66%)-------------------------

n=nrow(iris_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
  iris_train=iris_trans[trainIndex,]
  iris_test=iris_trans[-trainIndex,]
  
  model=naiveBayes(Species~.,data=iris_train)
  pred=predict(model,iris_test[,-5])
  
  conf=confusionMatrix(pred,iris_test$Species)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
nb_accsubsample66=acctotal/k
cat("nb Aggregate(66%) :",nb_accsubsample66)

#cross validation-------------------------

model=naiveBayes(iris_trans[,-5],iris_trans$Species,trControl=trainControl(method = 'cv',number = 10))
pred=predict(model,iris_trans[,-5])

conf=confusionMatrix(pred,iris_trans$Species)$table
nb_acccv=((sum(diag(conf)))/sum(conf))*100

#comparing all accuracies----------------

barplot(c(nb_acchold75,nb_acchold66,nb_accsubsample75,nb_accsubsample66,nb_acccv),xlab="naive-Bayes method",ylab="accuracies(in %)"
        ,ylim = c(0,100), names.arg=c("nb_acchold75","nb_acchold66","nb_accsubsample75","nb_accsubsample66","nb_acccv"),col="red")


#3)knn ==========================
library(class)

#hold out method(75%)--------------------------

n=nrow(iris_trans)
trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
iris_train=iris_trans[trainIndex,]
iris_test=iris_trans[-trainIndex,]

classlabels=iris_train[,5]
testclasslabels=iris_test[,5]

model=knn(train = iris_train[,-5],test = iris_test[,-5],cl=classlabels,k=13)

conf=confusionMatrix(testclasslabels,model)$table
knn_acchold75=((sum(diag(conf)))/sum(conf))*100

#hold out method(66%)--------------------------

n=nrow(iris_trans)
trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
iris_train=iris_trans[trainIndex,]
iris_test=iris_trans[-trainIndex,]

classlabels=iris_train[,5]
testclasslabels=iris_test[,5]

model=knn(train = iris_train[,-5],test = iris_test[,-5],cl=classlabels,k=13)

conf=confusionMatrix(testclasslabels,model)$table
knn_acchold66=((sum(diag(conf)))/sum(conf))*100

#random sub sampling(75%)-------------------------

n=nrow(iris_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
  iris_train=iris_trans[trainIndex,]
  iris_test=iris_trans[-trainIndex,]
  
  classlabels=iris_train[,5]
  testclasslabels=iris_test[,5]
  
  model=knn(train = iris_train[,-5],test = iris_test[,-5],cl=classlabels,k=13)
  
  conf=confusionMatrix(testclasslabels,model)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
knn_accsubsample75=acctotal/k
cat("knn Aggregate(75%) :",knn_accsubsample75)


#random sub sampling(66%)-------------------------

n=nrow(iris_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.66*n),replace = FALSE)
  iris_train=iris_trans[trainIndex,]
  iris_test=iris_trans[-trainIndex,]
  
  classlabels=iris_train[,5]
  testclasslabels=iris_test[,5]
  
  model=knn(train = iris_train[,-5],test = iris_test[,-5],cl=classlabels,k=13)
  
  conf=confusionMatrix(testclasslabels,model)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
knn_accsubsample66=acctotal/k
cat("knn Aggregate (66%):",knn_accsubsample66)

#cross validation-------------------------

classlabels=iris_trans[,5]

model=knn.cv(train = iris_trans[,-5],cl=classlabels,k=13)

conf=confusionMatrix(iris_trans$Species,model)$table
knn_acccv=((sum(diag(conf)))/sum(conf))*100


#comparing all accuracies----------------

barplot(c(knn_acchold75,knn_acchold66,knn_accsubsample75,knn_accsubsample66,knn_acccv),xlab="knn method",ylab="accuracies(in %)"
        ,ylim = c(0,100), names.arg=c("knn_acchold75","knn_acchold66","knn_accsubsample75","knn_accsubsample66","knn_acccv"),col="red")


#matrix of comparison of all models
chart=matrix(c(
  c(dt_acchold75,dt_acchold66,dt_accsubsample75,dt_accsubsample66,dt_acccv),
  c(nb_acchold75,nb_acchold66,nb_accsubsample75,nb_accsubsample66,nb_acccv),
  c(knn_acchold75,knn_acchold66,knn_accsubsample75,knn_accsubsample66,knn_acccv)
),5,3,
dimnames = list(
  c("accuracy_holdout_75%","accuracy_holdout_66%","accuracy_subsample_75%","accuracy_subsample_66%","accuracy_cross_vaidation"),
  c("decision tree","naive bayes","KNN")
)
)


#using caTool
library(caTools)
set.seed(123)
split=sample.split(iris$Species,SplitRatio = 0.75)
training_set=subset(iris,split==TRUE)
test_set=subset(iris,split==FALSE)
dim(training_set)
dim(test_set)

x=training_set
y=rownames(training_set)
model=train(x,y,'rpart',trControl=trainControl(method = 'cv',number = 10))

#using random numbers by sample
s=sample(150,50)
iris_train=iris[s,]
iris_test=iris[-s,]
dim(iris_train)
dim(iris_test)

x=iris_train
y=rownames(iris_train)
model=train(x,y,'rpart',trControl=trainControl(method = 'cv',number = 10))
