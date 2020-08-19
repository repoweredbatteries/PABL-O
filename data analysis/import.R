

#create loop where pack number and cell number are dynamic
P1C7<-read.csv("1-7.TXT")
P1C7<-P1C7[(max(which((is.na(as.numeric(as.character(P1C7[,4]))))))+2):nrow(P1C7),1:4]
P1C7$State<-as.numeric(as.character(P1C7$State)) #0 is discharge
P1C7$Times<-as.numeric(as.character(P1C7$Times))
P1C7$V<-as.numeric(as.character(P1C7$V))
names(P1C7)[4] <- "I"
P1C7$I<-as.numeric(as.character(P1C7$I))
P1C7$I[P1C7$I < 0.01] <- 0
P1C7$Ah<-P1C7$I/360

P1C7discharge<-as.data.frame(tapply( P1C7$Ah[P1C7$State == 0], P1C7$Times[P1C7$State == 0], sum))
#remove first and last cycles due to partial data
P1C7discharge<-as.data.frame(P1C7discharge[2:(nrow(P1C7discharge)-1),])
names(P1C7discharge)[1]<- "Ah"

plot(tapply( P1C7$Ah[P1C7$State == 0], P1C7$Times[P1C7$State == 0], sum), type = "l")