TC<-read.csv("TC1.csv")
TC<-TC[TC$V >= 2,] #remove values captured due to slow relay

#change to numeric keeping only sensical values
TC$I <- as.numeric(as.character(TC$I)) 
TC<-TC[!is.na(TC$I),]
TC <- TC[TC$I > 0.1,]

TC$Ims <- TC$I / 36000;
Ah <- tapply(TC$Ims, list(TC$State, TC$Cycle), FUN = sum)
avgV <- tapply(TC$V, list(TC$State, TC$Cycle), FUN = mean)
Ah*avgV

tapply(TC$I, list(TC$State, TC$Cycle), FUN = mean)
