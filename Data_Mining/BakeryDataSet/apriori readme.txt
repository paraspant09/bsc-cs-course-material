The XXXX-out1.csv file format is: receipt# followed by item #'s that are on that receipt. (sparse vector representation) 
The XXXX-out2.csv file format is: receipt# followed by 0's and 1's indicating if an item was on a given receipt. (full binary vector representation). 
The XXXXi.csv file format is: receipt# followed by item number and quantity ( CSV version of the Items tables ) 


-------------------
Based on what is discussed in class (4 Feb'2021):

--------------------------
for XXXXi.csv 

#if you are Appying column names as
names(receipt_df) <- c("Receipt_Number","Food","Quantity")

#then for preprocessing you can Create a dataframe containing each item and its corresponding id like this
id<-c(1:5)
food<-c("milk","sugar","chocolate","apples","curd")

df <- data.frame(id, food)

-------------------
or
------------------

#if you are appying column names as
names(receipt_df) <- c("Receipt_Number","Quantity","Food")

#then for preprocessing you can Create a dataframe containing each item and its corresponding id like this
id <- c(0:49)
food <- c("Chocolate Cake","Lemon Cake","Casino Cake","Opera Cake", "Strawberry Cake", "Truffle Cake", "Chocolate Eclair", "Coffee Eclair", "Vanilla Eclair", "Napolean Cake", "Almond Tart", "Apple Pie", "Apple Tart","Apricot Tart", "Berry Tart", "Blackberry Tart", "Blueberry Tart", "Chocolate Tart", "Cherry Tart", "Lemon Tart", "Pecan Tart", "Ganache Cookie", "Gongolais Cookie", "Raspberry Cookie", "Lemon Cookie", "Chocolate Meringue", "Vanilla Meringue", "Marzipan Cookie", "Tuile Cookie", "Walnut Cookie", "Almond Croissant", "Apple Croissant", "Apricot Croissant", "Cheese Croissant", "Chocolate Croissant", "Apricot Danish", "Apple Danish", "Almond Twist", "Almond Bear_Claw", "Blueberry Danish", "Lemon Lemonade", "Raspberry Lemonade", "Orange Juice", "Green Tea", "Bottled Water", "Hot Coffee", "Chocolate Coffee", "Vanilla Frappucino", "Cherry Soda", "Single Espresso")

df <- data.frame(id, food)

