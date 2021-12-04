###--------------Iris data set --------------------------


#install.packages("caret",dependencies = TRUE)
library(caret)
library(ggplot2)

#data scaled to standard format------------------

preprocessValue=preProcess(iris[,],method = c("scale","center"))
iris_trans=predict(preprocessValue,iris[,])
sapply(iris_trans[,-5],sd)
summary(iris_trans)

#### kmeans

k=list()
for(i in 1:10){
  k[[i]]=kmeans(iris_trans[,-5],i)
}

betweenss_totss=list()
for(i in 1:10){
  betweenss_totss[[i]]=k[[i]]$betweenss/k[[i]]$totss
}

plot(1:10,betweenss_totss,type = "b",ylab = "betweenss ss/total ss",xlab = "Cluster(k)")

for(i in 1:10){
  print(table(iris_trans$Species,k[[i]]$cluster))
}

ggplot(iris_trans,aes(Petal.Length,Petal.Width,color=Species)) + geom_point()
ggplot(iris_trans,aes(Petal.Length,Petal.Width,color=k[[3]]$cluster)) + geom_point()

#### hierarchical clustering

d=dist(iris_trans)
fitH=hclust(d,"ward.D2")
plot(fitH)

rect.hclust(fitH,k=3,border = "red")
cluster<-cutree(fitH,3)
cluster
plot(iris_trans,col=cluster)
table(iris_trans$Species,cluster)

ggplot(iris_trans, aes(Petal.Length, Petal.Width, color = Species)) +
  geom_point(alpha = 0.4, size = 3.5) + geom_point(col = cluster) +
  scale_color_manual(values = c('black', 'red', 'green'))

#### dB-Scan algorithm

#install.packages("dbscan")
library(dbscan)

kNNdistplot(iris_trans[,-5],k=3) # to decide value of eps
abline(h=0.7,col="red",lty=2)
fitD = dbscan(iris_trans[,-5],eps =0.7 ,minPts =5 )
plot(iris_trans,col=fitD$cluster)
table(iris_trans$Species,fitD$cluster)


###--------------HTRU_2 data set --------------------------
#install.packages("caret",dependencies = TRUE)
library(caret)
library(ggplot2)

htru<-read.csv("C:\\Users\\Girish\\Desktop\\paras\\DM\\HTRU2\\HTRU_2.csv",header=FALSE)
names(htru)<-c("Profile_mean","Profile_stdev","Profile_skewness","Profile_kurtosis"," DM_mean","DM_stdev","DM_skewness", "DM_kurtosis","class")

sum(is.na(htru))  #no missing values
sum(complete.cases(htru))   #all are complete cases

unique(htru[,9])  #two classes positive(1) and negative(0)
sum(htru[,9])   #number of positive classes(1639)
nrow(htru) - sum(htru[,9])   #number of negative classes(16259)

#data scaled to standard format------------------

preprocessValue=preProcess(htru[,],method = c("scale","center"))
htru_trans=predict(preprocessValue,htru[,])
sapply(htru_trans[,-9],sd)
summary(htru_trans)

short_htru=htru_trans[1:(nrow(htru_trans)/2),]

#### kmeans

k=list()
for(i in 1:10){
  k[[i]]=kmeans(htru_trans[,-9],i)
}

betweenss_totss=list()
for(i in 1:10){
  betweenss_totss[[i]]=k[[i]]$betweenss/k[[i]]$totss
}

plot(1:10,betweenss_totss,type = "b",ylab = "betweenss ss/total ss",xlab = "Cluster(k)")

for(i in 1:10){
  print(table(htru_trans$class,k[[i]]$cluster))
}

ggplot(htru_trans,aes(Profile_mean,Profile_stdev,color=class)) + geom_point()
ggplot(htru_trans,aes(Profile_mean,Profile_stdev,color=k[[2]]$cluster)) + geom_point()

#### hierarchical clustering

d=dist(short_htru)
fitH=hclust(d,"ward.D2")
plot(fitH)

rect.hclust(fitH,k=4,border = "red")
cluster<-cutree(fitH,4)
cluster
plot(short_htru,col=cluster)
table(short_htru$class,cluster)

###ggplot not working for hierarchical
ggplot(short_htru, aes(Profile_mean, Profile_stdev, color = class)) +
  geom_point(alpha = 0.4, size = 3.5) + geom_point(col = cluster) +
  scale_color_manual(values = c('black', 'red', 'green'))

#### dB-Scan algorithm

#install.packages("dbscan")
library(dbscan)

kNNdistplot(htru_trans[,-9],k=3) # to decide value of eps
abline(h=0.7,col="red",lty=2)
fitD = dbscan(htru_trans[,-9],eps =0.7 ,minPts =5 )
plot(htru_trans,col=fitD$cluster)
table(htru_trans$class,fitD$cluster)
