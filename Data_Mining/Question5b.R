cancer=read.csv("C:\\Users\\Girish\\Desktop\\paras\\DM\\breast-cancer-wisconsin.csv")

#pre processing
cancer_preprcs=cancer[,2:11]
sum(is.na(cancer_preprcs))
sum(complete.cases(cancer_preprcs))

#conversion of y class labels from {2,4} to {benign,malignant}
cancer_preprcs$Class=cancer_preprcs$Class/2
v=c("benign","malignant")
cancer_preprcs$Class=v[cancer_preprcs$Class]

#remove ? values in 6th column
for (i in 1:10) {
  cat(i,which(cancer_preprcs[,i]=="?"),"\n") 
}

length(which(cancer_preprcs[,6]=="?"))
#cancer_preprcs$Bare_Nuclei[which(cancer_preprcs[,6]=="?")]=NA
cancer_preprcs=cancer_preprcs[-which(cancer_preprcs[,6]=="?"),]

#important: type of bare nuclei is character convert to integer
typeof(cancer_preprcs$Bare_Nuclei)
cancer_preprcs$Bare_Nuclei=as.integer(cancer_preprcs$Bare_Nuclei)
typeof(cancer_preprcs$Bare_Nuclei)

# y values should be {factor}categorical(here after conversion{from int to categorical} they become character so convert them into factor)
typeof(cancer_preprcs$Class)
cancer_preprcs$Class=as.factor(cancer_preprcs$Class)
typeof(cancer_preprcs$Class)
str(cancer_preprcs)
#data scaled to standard format------------------

preprocessValue=preProcess(cancer_preprcs[,],method = c("scale","center"))
cancer_trans=predict(preprocessValue,cancer_preprcs[,])
sapply(cancer_trans[,-10],sd)
summary(cancer_trans)

#cancer_trans=cancer_preprcs

# no need of scaling because all values are between 1-10
#install.packages("caret",dependencies = TRUE)
library(caret)

#using sample

#breast cancer data set

#1)r-part==========================

#hold out method(75%)--------------------------

n=nrow(cancer_trans)
trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
cancer_train=cancer_trans[trainIndex,]
cancer_test=cancer_trans[-trainIndex,]

model=train(Class~.,data=cancer_train,'rpart')
pred=predict(model,cancer_test[,-10])

conf=confusionMatrix(as.factor(pred),as.factor(cancer_test$Class))$table
dt_acchold75=((sum(diag(conf)))/sum(conf))*100

#hold out method(66.6%)--------------------------

n=nrow(cancer_trans)
trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
cancer_train=cancer_trans[trainIndex,]
cancer_test=cancer_trans[-trainIndex,]

model=train(Class~.,data=cancer_train,'rpart')
pred=predict(model,cancer_test[,-10])

conf=confusionMatrix(as.factor(pred),as.factor(cancer_test$Class))$table
dt_acchold66=((sum(diag(conf)))/sum(conf))*100


#random sub sampling(75%)-------------------------

n=nrow(cancer_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
  cancer_train=cancer_trans[trainIndex,]
  cancer_test=cancer_trans[-trainIndex,]
  
  model=train(Class~.,data=cancer_train,'rpart')
  pred=predict(model,cancer_test[,-10])
  
  conf=confusionMatrix(as.factor(pred),as.factor(cancer_test$Class))$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
dt_accsubsample75=acctotal/k
cat("dt Aggregate(75%) :",dt_accsubsample75)

#random sub sampling(66%)-------------------------

n=nrow(cancer_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
  cancer_train=cancer_trans[trainIndex,]
  cancer_test=cancer_trans[-trainIndex,]
  
  model=train(Class~.,data=cancer_train,'rpart')
  pred=predict(model,cancer_test[,-10])
  
  conf=confusionMatrix(as.factor(pred),as.factor(cancer_test$Class))$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
dt_accsubsample66=acctotal/k
cat("dt Aggregate(66%) :",dt_accsubsample66)

#cross validation-------------------------

model=train(cancer_trans[,-10],cancer_trans$Class,'rpart',trControl=trainControl(method = 'cv',number = 10))
pred=predict(model,cancer_trans[,-10])

conf=confusionMatrix(as.factor(pred),as.factor(cancer_trans$Class))$table
dt_acccv=((sum(diag(conf)))/sum(conf))*100

#comparing all accuracies----------------

barplot(c(dt_acchold75,dt_acchold66,dt_accsubsample75,dt_accsubsample66,dt_acccv),xlab="decision tree method",ylab="accuracies(in %)"
        ,ylim = c(0,100), names.arg=c("dt_acchold75","dt_acchold66","dt_accsubsample75","dt_accsubsample66","dt_acccv"),col="red")

#install.packages("e1071",dependencies = TRUE)
library(e1071)

#2)naive-Bayes classifier=====================

#hold out method(75%)--------------------------

n=nrow(cancer_trans)
trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
cancer_train=cancer_trans[trainIndex,]
cancer_test=cancer_trans[-trainIndex,]

model=naiveBayes(Class~.,data=cancer_train)
pred=predict(model,cancer_test[,-10])

conf=confusionMatrix(pred,cancer_test$Class)$table
nb_acchold75=((sum(diag(conf)))/sum(conf))*100

#hold out method(66%)--------------------------

n=nrow(cancer_trans)
trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
cancer_train=cancer_trans[trainIndex,]
cancer_test=cancer_trans[-trainIndex,]

model=naiveBayes(Class~.,data=cancer_train)
pred=predict(model,cancer_test[,-10])

conf=confusionMatrix(pred,cancer_test$Class)$table
nb_acchold66=((sum(diag(conf)))/sum(conf))*100

#random sub sampling(75%)-------------------------

n=nrow(cancer_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
  cancer_train=cancer_trans[trainIndex,]
  cancer_test=cancer_trans[-trainIndex,]
  
  model=naiveBayes(Class~.,data=cancer_train)
  pred=predict(model,cancer_test[,-10])
  
  conf=confusionMatrix(pred,cancer_test$Class)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
nb_accsubsample75=acctotal/k
cat("nb Aggregate(75%) :",nb_accsubsample75)

#random sub sampling(66%)-------------------------

n=nrow(cancer_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
  cancer_train=cancer_trans[trainIndex,]
  cancer_test=cancer_trans[-trainIndex,]
  
  model=naiveBayes(Class~.,data=cancer_train)
  pred=predict(model,cancer_test[,-10])
  
  conf=confusionMatrix(pred,cancer_test$Class)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
nb_accsubsample66=acctotal/k
cat("nb Aggregate(66%) :",nb_accsubsample66)


#cross validation-------------------------

model=naiveBayes(cancer_trans[,-10],cancer_trans$Class,trControl=trainControl(method = 'cv',number = 10))
pred=predict(model,cancer_trans[,-10])

conf=confusionMatrix(pred,cancer_trans$Class)$table
nb_acccv=((sum(diag(conf)))/sum(conf))*100

#comparing all accuracies----------------

barplot(c(nb_acchold75,nb_acchold66,nb_accsubsample75,nb_accsubsample66,nb_acccv),xlab="naive-Bayes method",ylab="accuracies(in %)"
        ,ylim = c(0,100), names.arg=c("nb_acchold75","nb_acchold66","nb_accsubsample75","nb_accsubsample66","nb_acccv"),col="red")


#3)knn ==========================
library(class)

#hold out method(75%)----------------------------
n=nrow(cancer_trans)
trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
cancer_train=cancer_trans[trainIndex,]
cancer_test=cancer_trans[-trainIndex,]

classlabels=cancer_train[,10]
testclasslabels=cancer_test[,10]

model=knn(train = cancer_train[,-10],test = cancer_test[,-10],cl=classlabels,k=13)

conf=confusionMatrix(testclasslabels,model)$table
knn_acchold75=((sum(diag(conf)))/sum(conf))*100

#hold out method(66%)----------------------------
n=nrow(cancer_trans)
trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
cancer_train=cancer_trans[trainIndex,]
cancer_test=cancer_trans[-trainIndex,]

classlabels=cancer_train[,10]
testclasslabels=cancer_test[,10]

model=knn(train = cancer_train[,-10],test = cancer_test[,-10],cl=classlabels,k=13)

conf=confusionMatrix(testclasslabels,model)$table
knn_acchold66=((sum(diag(conf)))/sum(conf))*100

#random sub sampling(75%)-------------------------

n=nrow(cancer_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.75*n),replace = FALSE)
  cancer_train=cancer_trans[trainIndex,]
  cancer_test=cancer_trans[-trainIndex,]
  
  classlabels=cancer_train[,10]
  testclasslabels=cancer_test[,10]
  
  model=knn(train = cancer_train[,-10],test = cancer_test[,-10],cl=classlabels,k=13)
  
  conf=confusionMatrix(testclasslabels,model)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
knn_accsubsample75=acctotal/k
cat("knn Aggregate(75%) :",knn_accsubsample75)

#random sub sampling(66%)-------------------------

n=nrow(cancer_trans)
k=10
i=0
acctotal=0
while(i<k){
  
  trainIndex=sample(1:n,size=round(0.666*n),replace = FALSE)
  cancer_train=cancer_trans[trainIndex,]
  cancer_test=cancer_trans[-trainIndex,]
  
  classlabels=cancer_train[,10]
  testclasslabels=cancer_test[,10]
  
  model=knn(train = cancer_train[,-10],test = cancer_test[,-10],cl=classlabels,k=13)
  
  conf=confusionMatrix(testclasslabels,model)$table
  acc=((sum(diag(conf)))/sum(conf))*100
  
  acctotal=acctotal+acc
  print(acc)
  i=i+1
}
knn_accsubsample66=acctotal/k
cat("knn Aggregate(66%) :",knn_accsubsample66)

#cross validation-------------------------

classlabels=cancer_trans[,10]

model=knn.cv(train = cancer_trans[,-10],cl=classlabels,k=13)

conf=confusionMatrix(cancer_trans$Class,model)$table
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
