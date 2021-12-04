library(editrules)
people=read.table("C:/Users/Girish/Desktop/paras/DM/Q1Table.txt",TRUE,"\t")
people
E=editset(expression(
  Age>=0,
  Age<=150,
  Age>yearsmarried,
  status %in% c("married","single","widowed"),
  if(Age<18) agegroup == "child",
  if(Age>=18 && Age<65) agegroup == "adult",
  if(Age>=65) agegroup == "elder"
))
E
ve=violatedEdits(E,people)
ve
summary(ve)
plot(E)
plot(ve)
plot(E,layout=layout.circle)
